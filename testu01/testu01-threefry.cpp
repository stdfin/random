#include <stdfin/random/threefry_engine.hpp>


extern "C"
{
#include "unif01.h"
#include "bbattery.h"
}
 
stdfin::threefry_engine<uint32_t,32,20> engine;
 
uint32_t rnd_function() 
{
	return engine();
}
 
int main (void)
{
	unif01_Gen *gen;
	gen = unif01_CreateExternGenBits("stdfin::threefry4x64_engine<uint32_t,32,20>", rnd_function);	
	bbattery_BigCrush (gen);
	unif01_DeleteExternGenBits (gen);
	return 0;
}

