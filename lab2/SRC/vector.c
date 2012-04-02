/* vector.c */

#include "types.h"
#include "vector.h"

#define VECTOR_START	0x2000 /* used on SDK 1.1; on original mcs-51/52 it is 0x0000, of course */
#define VECTOR(vecid) (BYTE XDATA *)(VECTOR_START + (vecid << 3) + 3)

#define LCALL			0x12
#define RETI			0x32

VOID SetVector(BYTE vecid, Vector vector) /* producing code like this: lcall Vector; reti */
{
	BYTE XDATA *addr = VECTOR(vecid);
	XADDR v = (XADDR)vector;
	
	*addr++ = LCALL;
	*addr++ = (BYTE)(v >> 8);
	*addr++ = (BYTE)(v & 0xff);
	
	*addr = RETI;
}

VOID SetInterruptsMode(BYTE mode)
{
	EA = mode;
}

VOID SetInterruptMode(BYTE irq, BYTE mode)
{
	NOINTR(IE = (IE &~ (1 << irq)) | (mode << irq));
}

VOID SetIntrPriority(BYTE irq, BYTE pri)
{
	NOINTR(IP = (IP &~ (1 << irq)) | (pri << irq));
}


VOID EnableIntr(BYTE intr)
{
	SetInterruptMode(intr, EM_ENABLED);
}

VOID DisableIntr(BYTE intr)
{
	SetInterruptMode(intr, EM_DISABLED);
}

VOID EnableAllIntrs()
{
	SetInterruptsMode(EM_ENABLED);
}

VOID DisableAllIntrs()
{
	SetInterruptsMode(EM_DISABLED);
}
