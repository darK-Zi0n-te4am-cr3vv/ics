/*
	nointr.c
*/

#include "nointr.h"
#include "aduc812.h"

#ifdef __NOINTR_USE_ASSEMBER

__bit _testea_() __naked
{
	__asm 
		jbc	_EA, 00001$
		clr	c
		ret
		
00001$:
		setb c
		ret
		
	__endasm;
}

#else

__bit _testea_() 
{
	if (EA) 
	{
		EA = 0;
		return 1;
	}
	
	return 0;
}

#endif

