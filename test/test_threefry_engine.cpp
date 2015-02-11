#include "include/test_engine.hpp"
#include <stdfin/random/threefry_engine.hpp>

/*
from https://github.com/girving/random123/blob/master/examples/kat_vectors
	threefry4x64 13 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 4071fabee1dc8e05 02ed3113695c9c62 397311b5b89f9d49 e21292c3258024bc
	threefry4x64 13 ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 7eaed935479722b5 90994358c429f31c 496381083e07a75b 627ed0d746821121
	threefry4x64 13 243f6a8885a308d3 13198a2e03707344 a4093822299f31d0 082efa98ec4e6c89 452821e638d01377 be5466cf34e90c6c c0ac29b7c97c50dd 3f84d5b5b5470917 4361288ef9c1900c 8717291521782833 0d19db18c20cf47e a0b41d63ac8581e5
	threefry4x64 20 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000   09218ebde6c85537 55941f5266d86105 4bd25e16282434dc ee29ec846bd2e40b
	threefry4x64 20 ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 29c24097942bba1b 0371bbfb0f6f4e11 3c231ffa33f83a1c cd29113fde32d168
	threefry4x64 20 243f6a8885a308d3 13198a2e03707344 a4093822299f31d0 082efa98ec4e6c89 452821e638d01377 be5466cf34e90c6c be5466cf34e90c6c c0ac29b7c97c50dd   a7e8fde591651bd9 baafd0c30138319b 84a5c1a729e685b9 901d406ccebc1ba4

from https://github.com/DEShawResearch/Random123-Boost/blob/master/libs/random/test/test_threefry.cpp
BOOST_AUTO_TEST_CASE(test_kat_threefry4x64)
{
    dokat<threefry<4, uint64_t, 13> > ("0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 4071fabee1dc8e05 02ed3113695c9c62 397311b5b89f9d49 e21292c3258024bc  ");
    dokat<threefry<4, uint64_t, 13> > ("ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 7eaed935479722b5 90994358c429f31c 496381083e07a75b 627ed0d746821121  ");
    dokat<threefry<4, uint64_t, 13> > ("243f6a8885a308d3 13198a2e03707344 a4093822299f31d0 082efa98ec4e6c89 452821e638d01377 be5466cf34e90c6c c0ac29b7c97c50dd 3f84d5b5b5470917 4361288ef9c1900c 8717291521782833 0d19db18c20cf47e a0b41d63ac8581e5  ");
    dokat<threefry<4, uint64_t, 20> > ("0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000 0000000000000000   09218ebde6c85537 55941f5266d86105 4bd25e16282434dc ee29ec846bd2e40b");
    dokat<threefry<4, uint64_t, 20> > (" ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 29c24097942bba1b 0371bbfb0f6f4e11 3c231ffa33f83a1c cd29113fde32d168 ");
    dokat<threefry<4, uint64_t, 20> > ("243f6a8885a308d3 13198a2e03707344 a4093822299f31d0 082efa98ec4e6c89 452821e638d01377 be5466cf34e90c6c be5466cf34e90c6c c0ac29b7c97c50dd   a7e8fde591651bd9 baafd0c30138319b 84a5c1a729e685b9 901d406ccebc1ba4");
}
*/

#include <iostream>
#include <sstream>
#include <cassert>


int main()
{
	
	stdfin::threefry_20_64 eng;
    test_engine<stdfin::threefry_20_64>(eng);
    
    {   // default 64 bit engine
        stdfin::threefry_20_64 eng;
        assert( eng() == 0x09218ebde6c85537);
        assert( eng() == 0x55941f5266d86105 );
        assert( eng() == 0x4bd25e16282434dc );
        assert( eng() == 0xee29ec846bd2e40b );
    }

    {   // 32 bit version
        stdfin::threefry_20_32 eng;
        assert( eng() == 0xe6c85537 );
        assert( eng() == 0x09218ebd );
        assert( eng() == 0x66d86105 );
        assert( eng() == 0x55941f52 );
        assert( eng() == 0x282434dc );
        assert( eng() == 0x4bd25e16 );
        assert( eng() == 0x6bd2e40b );
        assert( eng() == 0xee29ec84 );
    }
    
    {   // 8 bit version
        stdfin::threefry_engine<uint8_t, 8, 20> eng;
        assert( eng() == 0x37 );
        assert( eng() == 0x55 );
        assert( eng() == 0xc8 );
        assert( eng() == 0xe6 );
        assert( eng() == 0xbd );
        assert( eng() == 0x8e );
    }

    

// threefry4x64 13  0000000000000000 0000000000000000 0000000000000000 0000000000000000 
//					0000000000000000 0000000000000000 0000000000000000 0000000000000000  
//					4071fabee1dc8e05 02ed3113695c9c62 397311b5b89f9d49 e21292c3258024bc
    { 
        stdfin::threefry_engine<uint64_t, 64, 13> eng;
        eng.set_counter(0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000);
        eng.set_key(    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000);
        assert( eng() == 0x4071fabee1dc8e05 );
        assert( eng() == 0x02ed3113695c9c62 );
        assert( eng() == 0x397311b5b89f9d49 );
        assert( eng() == 0xe21292c3258024bc );
    }

// threefry4x64 13 	ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 
//					ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 
//					7eaed935479722b5 90994358c429f31c 496381083e07a75b 627ed0d746821121
    { 
        stdfin::threefry_engine<uint64_t, 64, 13> eng;
        eng.set_counter(0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        eng.set_key(    0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        assert( eng() == 0x7eaed935479722b5 );
        assert( eng() == 0x90994358c429f31c );
        assert( eng() == 0x496381083e07a75b );
        assert( eng() == 0x627ed0d746821121 );
    }

/*
// threefry4x64 13 
    { 
        stdfin::threefry_engine<uint64_t, 64, 13> eng;
        eng.set_counter(0x243f6a8885a308d3, 0x13198a2e03707344, 0xa4093822299f31d0, 0x082efa98ec4e6c89 );
        eng.set_key(    0x452821e638d01377, 0xbe5466cf34e90c6c, 0xc0ac29b7c97c50dd, 0x3f84d5b5b5470917 );
        assert( eng() == 0x4361288ef9c1900c );
        assert( eng() == 0x8717291521782833 );
        assert( eng() == 0x0d19db18c20cf47e );
        assert( eng() == 0xa0b41d63ac8581e5 );
    }
*/


// threefry4x64 20  0000000000000000 0000000000000000 0000000000000000 0000000000000000 
//					0000000000000000 0000000000000000 0000000000000000 0000000000000000  
//					09218ebde6c85537 55941f5266d86105 4bd25e16282434dc ee29ec846bd2e40b
    { 
        stdfin::threefry_engine<uint64_t, 64, 20> eng;
        eng.set_counter(0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000);
        eng.set_key(    0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000);
        assert( eng() == 0x09218ebde6c85537 );
        assert( eng() == 0x55941f5266d86105 );
        assert( eng() == 0x4bd25e16282434dc );
        assert( eng() == 0xee29ec846bd2e40b );
    }

// threefry4x64 20 	ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 
//					ffffffffffffffff ffffffffffffffff ffffffffffffffff ffffffffffffffff 
//					29c24097942bba1b 0371bbfb0f6f4e11 3c231ffa33f83a1c cd29113fde32d168
    { 
        stdfin::threefry_engine<uint64_t, 64, 20> eng;
        eng.set_counter(0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        eng.set_key(    0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        assert( eng() == 0x29c24097942bba1b );
        assert( eng() == 0x0371bbfb0f6f4e11 );
        assert( eng() == 0x3c231ffa33f83a1c );
        assert( eng() == 0xcd29113fde32d168 );
    }

/*
// threefry4x64 20 
    { 
        stdfin::threefry_engine<uint64_t, 64, 20> eng;
        eng.set_key(0x243f6a8885a308d3, 0x13198a2e03707344, 0xa4093822299f31d0, 0x082efa98ec4e6c89);
        eng.set_counter(    0x452821e638d01377, 0xbe5466cf34e90c6c, 0xbe5466cf34e90c6c, 0xc0ac29b7c97c50dd);
        assert( eng() == 0xa7e8fde591651bd9 );
        assert( eng() == 0xbaafd0c30138319b );
        assert( eng() == 0x84a5c1a729e685b9 );
        assert( eng() == 0x901d406ccebc1ba4 );
    }
*/
    return 0;
}