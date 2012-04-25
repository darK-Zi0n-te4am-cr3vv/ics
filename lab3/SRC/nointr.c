/*
	nointr.c
*/

#include "nointr.h"
#include "aduc812.h"

#ifdef __xchangeIE__USE_ASSEMBER

BYTE __xchangeIE(BYTE __ie) __naked
{
	__ie; /* to avoid warning */
	
	_asm
		push acc
		
		mov a, dpl /* dpl is 1st arg  */
		xch a, ie  /* atomic exchange */
		mov dpl, a /* dpl is return value */
		
		pop acc
		
		ret
	_endasm;
}

#else

BYTE __xchangeIE(BYTE ie)
{
	BYTE oldIE = IE;
	IE = ie;
	
	return oldIE;
}

#endif

