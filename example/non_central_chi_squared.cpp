#include <iostream>
#include <random>
#include <stdfin/random/non_central_chi_squared_distribution.hpp>


int main()
{
	std::default_random_engine engine;
	stdfin::non_central_chi_squared distribution(1,3);
	
	for (int i = 0; i < 10; ++i)
		std::cout << distribution(engine) << std::endl;

	return 0;
}