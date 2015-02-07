#include "include/test_distribution.hpp"
#include <stdfin/random/non_central_chi_squared_distribution.hpp>

int main()
{
	typedef stdfin::non_central_chi_squared D;
	test_distribution<D>();
	
}

