# stdfin-random
A collection of C++11 compatible random engines and distributions.

## Random engines
### Threefry engine
The Threefry  random number engine is a fast and high quality random number generator used for large scale parallel processing.

The implementation is based on a paper by *John Salmon and Mark Moraes* and described in their paper **Parallel Random Numbers: As Easy as 1, 2, 3**. (Proceedings of 2011 International Conference for High Performance Computing, Networking, Storage and Analysis). The algorithm is based on the Threefish cryptographic cipher.

* Fast. Faster than the C++ Mersenne Twister.
* High quality. Passes ALL the BigCrush test in the TestU01 framework.
* Cyle length 2^258

Usable for large scale parallel processing:

* O(1) discard() / jump-ahead makes is very easy to give each thread its own subsequence.
* 32 bit seed offers 2^32 parallel random streams of length 2^258.
* Streams are guaranteed to be non-overlapping,

#### example:

    #include <iostream>
    #include "stdfin/random/threefry.hpp"
 
    int main()
    {
        std::cout << "\nTwo independent streams.\n";
 
        stdfin::threefry_engine eng1, eng2;
 
        eng1.seed(0);  // reset the first engine (not really necessary)
        eng2.seed(1); // 2nd engine gets a different seed
 
        for (int i=0; i<4; ++i)
            std::cout <<  eng1() << " " << eng2() << "\n";
    }

gives

	Two independent streams.
	3871888695 1931275270
	153194173 145858287
	1725456645 3604276868
	1435770706 3225543903

### Vandercorput engine

A van der Corput sequence is the simplest one dimensional low-discrepancy sequence over the unit interval first published in 1935 by the Dutch mathematician J. G. van der Corput. It is constructed by reversing the base n representation of the sequence of natural numbers (1, 2, 3, …). 

Low-discrepancy sequence have an advantage over pure random numbers in that they cover the domain of interest quickly and evenly. They have an advantage over grids in that those  only give high accuracy when the number of datapoints is pre-set whereas in using low-discrepancy sequence the accuracy improves continually as more datapoints are added.


    #include <iostream>
    #include "stdfin/random/vandercorput_engine.hpp"
 
    int main()
    { 
        stdfin::vandercorput_engine eng;
        for (int i=0; i<10; ++i)
            std::cout << eng() << "\n";        
    }
    

## Random distributions

### Non-central Chi Squared distribution


The noncentral chi-squared distribution is a real valued distribution with two parameter, **k** and **lambda**.  The distribution produces values > 0.
 
 This is the distribution of the sum of squares of **k** Normal distributed variates each with variance one and **lambda** the sum of squares of the normal means.

The distribution function is
$$
\displaystyle P(x) = \frac{1}{2} e^{-(x+\lambda)/2} \left( \frac{x}{\lambda} \right)^{k/4-1/2} I_{k/2-1}( \sqrt{\lambda x} )
$$

where 

$$\displaystyle I_\nu(z)$$ is a modified Bessel function of the first kind.