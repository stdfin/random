#include <iostream>
#include <random>
#include <stdfin/random/non_central_chi_squared_distribution.hpp>

#include <cmath>
#include <cstdint>


int countsol(uint64_t n)
{
	typedef uint64_t INT;
	uint64_t c = 0;
	 
	for (INT t=1;t <= std::sqrt(n+1); ++t) {
		for (INT s=(n+1)/t; s<= n/t + std::sqrt(n+n*n/t/t); ++s) {
			for (INT r=s; r<=n*(n+2); ++r) {
				if (r*s*t == n*(r+s+t)) {
					++c;
					//std::cout << " (" << r << "," << s << "," << t << "," << n << ")" << std::endl;
				}
			}
		}
	}

	for (INT t=std::sqrt(n+1)+1; t<=std::sqrt(2*n); ++t) {
		for (INT s=t; s<= n/t + std::sqrt(n+n*n/t/t); ++s) {
			for (INT r=s; r<=n*(n+2); ++r) {
				if (r*s*t == n*(r+s+t)) {
					++c;
					//std::cout << " (" << r << "," << s << "," << t << "," << n << ")" << std::endl;
				}
			}
		}
	}
	
	return c;
}

int main()
{
	
	std::default_random_engine engine;
	stdfin::non_central_chi_squared distribution(1,3);
	
	for (int i = 0; i < 10; ++i)
		std::cout << distribution(engine) << std::endl;

	typedef uint64_t INT;
	for (int i=1; i<10; ++i) {
		std::cout<< i << " " << countsol(i) << std::endl;
	}

	return 0;
}


