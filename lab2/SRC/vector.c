/* vector.c */

#include "types.h"
#include "vector.h"

#define VECTOR_START	0x2000
#define LJMP			0x02

#define LCALL			0x12
#define RETI			0x32

VOID __SetVector(BYTE vecId, Vector vector)
{
	ADDR addr = VECTOR_START + vecId * 8 + 3;
	XADDR v = (XADDR)vector;
	
	*((BYTE XDATA *)addr++) = LJMP;
	*((BYTE XDATA *)addr++) = (BYTE)(v >> 8);
	*((BYTE XDATA *)addr) = (BYTE)(v & 0xff);
}

/* EXPERIMENTAL */

VOID SetVector(BYTE vecId, Vector vector) /* producing code like this: lcall Vector; reti */
{
	BYTE XDATA *addr = (BYTE XDATA *)(VECTOR_START + (vecId << 3) + 3);
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
	IE = (IE &~ (1 << irq)) | (mode << irq);
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
