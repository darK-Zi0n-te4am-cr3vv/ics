/* led.c */

#include "xdata.h"
#include "types.h"

#define LED_REGISTER	0x0007 

VOID WriteLed(BYTE led)
{
	WriteMax(LED_REGISTER, led);
}