#include <type_traits>
#include <cassert>
#include <random>



template <typename D>
void test_distribution()
{
	// result_type checks
	typedef typename D::result_type result_type;
	static_assert( std::is_arithmetic<typename D::result_type>::value, "Random distribution result_type must be an arithmetic type.");

	// param_type checks
	typedef typename D::param_type param_type;
	
	// distribution_type check
	typedef typename D::distribution_type distribution_type;
	
	// Distribution check
	static_assert( std::is_copy_constructible<D>::value, "Random distribution must be copy constructible.");
	static_assert( std::is_copy_assignable<D>::value, "Random distribution must be copy assignable.");


	
	D d;
	param_type p = d.param();
	d.param(p);
	
	d.reset();
	
	result_type r;
	r = d.min();
	r = d.max();
	
	D d2(d);
	D d3(p);
	
	std::default_random_engine g;
	r = d(g);
	r = d(g,p);	
	
	{
		// equality comparable
		D d1, d2;
		assert( d1 == d2);
		assert( d1.param() == d2.param() );
	}
	
}
