#include <random>
#include <sstream>
#include <cassert>

template <typename E>
void test_engine_interface()
{
    {   // constructors
        E e;                 // default constructor
        E e2(e);
    }
}


template <typename E>
void test_engine(E& e1)
{
    {   // test operator == and !=
        E e1,e2;
        assert( e1 == e2);
        e1();
        assert( e1 != e2);
    }
    
    {   // constructors
        std::seed_seq sseq;

        E e1;                 // default constructor
        E e2 = e1;            // copy constructor
        E e3(e1);             // copy constructor
        E e4(4);              // constructor with seed
        E e5(sseq);           // constructor with seed sequence
        assert( e1 == e2);
        assert( e1 == e3);
        assert( e1 != e4);
        assert( e1 != e5);
    }
    
    {   // seed
        E e;
        std::seed_seq sseq;
        e.seed();
        e.seed(43);
        e.seed(sseq);
    }
    
    {   // result_type, min(), max()
        typename E::result_type x;
        E e;
        x = e();
        assert(x <= E::max() );
        assert(x >= E::min() );
    }
    
    {   // discard()
        E e1,e2;
        e1.discard(42);
        for (int i=0; i<42; ++i) e2();
        assert( e1 == e2 );
    }
    
    {   // test io
        std::stringstream ss;
        E e1,e2;

        e1.seed(42);
        assert (e1 != e2);
        ss << e1;
        ss >> e2;
        assert (e1 == e2);
    }
}
