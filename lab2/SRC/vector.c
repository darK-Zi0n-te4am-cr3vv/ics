/* vector.c */

#include "types.h"
#include "vector.h"

#define VECTOR_START	0x2000
#define LJMP			0x02

VOID SetVector(BYTE vecId, Vector vector)
{
	ADDR addr = VECTOR_START + vecId * 8 + 3;
	
	*((BYTE XDATA *)addr++) = LJMP;
	*((ADDR XDATA *)addr) = (ADDR)vector;
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
