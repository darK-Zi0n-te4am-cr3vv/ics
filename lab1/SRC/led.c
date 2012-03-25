#include "xdata.h"
#include "types.h"

#define LED_REGISTER	0x0007 /* адрес регистра светодиодной линейки */

/* записывает значение в регистр светодиодов */
VOID WriteLed(BYTE led)
{
	WriteMax(LED_REGISTER, led);
}