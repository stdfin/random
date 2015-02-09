#include "include/test_distribution.hpp"
#include <stdfin/random/non_central_chi_squared_distribution.hpp>

int main()
{

	typedef stdfin::non_central_chi_squared D;
	D d1(1,3);
	test_distribution<D>(d1);
}

