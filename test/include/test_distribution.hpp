#include <type_traits>
#include <cassert>
#include <random>
#include <sstream>

                                                                               \
template <typename D>
void test_distribution_interface()
{
	// check availability of public types
	typename D::param_type p;
	typename D::result_type r;
	typename D::param_type::distribution_type d;
	
	static_assert( std::is_arithmetic<typename D::result_type>::value, "Random distribution result_type must be an arithmetic type.");
	static_assert( std::is_copy_constructible<typename D::param_type>::value, "Random distribution param_type must be copy constructible.");
	static_assert( std::is_copy_assignable<typename D::param_type>::value, "Random distribution param_type  must be copy assignable.");
	static_assert( std::is_copy_assignable<typename D::param_type>::value, "Random distribution param_type  must be copy assignable.");

	{	// simple test member functions
		D d;
		std::default_random_engine g;
		p = d.param();
		d.reset();
		r = d.min();
		r = d.max();
		r = d(g);
		r = d(g,p);	
	}
	
	{	// simple test comparable
		D d1,d2;
		assert(d1 == d2);
		assert(! (d1 != d2) );
		assert(d1.param() == d2.param());
		assert(! (d1.param() != d2.param()) );
	}

    {   // test io
        std::stringstream ss;
		D d;
        ss << d;
        ss >> d;
    }
}


template <typename D>
void test_distribution(D& d1)	// d1 must not be the default constructed distribution
{
	test_distribution_interface<D>();
	
	{
		D d;
		assert(d != d1);
		assert(d.param() != d1.param() );
	}
	
	{
		D d(d1.param());
		assert(d == d1);
	}	
	{
		D d;
		d.param(d1.param());
		assert(d == d1);
	}

    {   // test io
        std::stringstream ss;
		D d;
        ss << d1;
        ss >> d;
		assert(d == d1);
    }

}
