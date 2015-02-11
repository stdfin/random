#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <stdfin/random/threefry_engine.hpp>

std::mutex mutex;

long thread_counter;
long total_samples;
long total_sum;

void thread_function()
{
    stdfin::threefry eng;

    
    // Initialize the prng in this thread with a unique seed 
    {   
        std::lock_guard<std::mutex> guard( mutex );
        eng.seed( thread_counter++ );
    }
    
    // Compute the sum or 1 million random samples
    long local_sum = 0;
    for (long i=0; i<1E6; ++i)
        local_sum += eng();
    
    // Add the computed values in this thread to the global sum
    {
        std::lock_guard<std::mutex> guard( mutex );
        total_sum += local_sum;
        total_samples += 1E6;
    }
}


int main()
{
    total_samples = 0;
    total_sum = 0;
    
    // Launch 128 threads
    std::vector<std::thread> threads;
    for(int i=0; i<128; ++i)
        threads.push_back( std::thread( thread_function ) );

    // Wait for all threads to finish
    for(auto& thread : threads)
        thread.join();

    std::cout << thread_counter << " threads generated " << total_samples << " random numbers, the sum of them is " << total_sum << std::endl;
}

