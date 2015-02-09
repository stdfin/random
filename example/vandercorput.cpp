#include <iostream>
#include <random>
#include "stdfin/random/vandercorput_engine.hpp"

int main()
{
    {
        std::cout << "\nstandard (Base 2) van der Corpute uniform samples:\n";
        stdfin::vandercorput eng;
        std::uniform_real_distribution<> dist;
        
        for (int i=0; i<10; ++i)
            std::cout << dist(eng) << " ";
        
        std::cout << std::endl;
    }

    {
        std::cout << "\nBase 3  van der Corpute uniform samples:\n";
        stdfin::vandercorput_engine<uint64_t, 3> eng;
        std::uniform_real_distribution<> dist;
        
        for (int i=0; i<10; ++i)
            std::cout << dist(eng) << " ";
        
        std::cout << std::endl;
    }

    {
        std::cout << "\nBase 10 van der Corpute uniform samples:\n";
        stdfin::vandercorput_engine<uint64_t, 10> eng;
        std::uniform_real_distribution<> dist;
        
        for (int i=0; i<23; ++i)
            std::cout << dist(eng) << " ";
        
        std::cout << std::endl;
    }

    return 0;
}