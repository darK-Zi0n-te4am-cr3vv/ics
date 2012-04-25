/* dip.c */

#include "xdata.h"
#include "types.h"

#define DIP_REGISTER	0x0002 

BYTE ReadDip()
{
	return ReadMax(DIP_REGISTER);
}