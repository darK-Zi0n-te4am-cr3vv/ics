#include "xdata.h"
#include "types.h"

#define DIP_REGISTER	0x0002 /* адрес регистра переключаетелей */

/* считывает значение из регистра дип переключателя  */
BYTE ReadDip()
{
	return ReadMax(DIP_REGISTER);
}