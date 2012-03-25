/* ena.c */

#include "types.h"
#include "ccdef.h"
#include "ena.h"
#include "xdata.h"

#define ENA_REGISTER 	0x0004
#define SND_BITS		0x1C

VOID WriteEna(BYTE ena)
{
	WriteMax(ENA_REGISTER, ena);
}

BYTE ReadEna()
{
	return ReadMax(ENA_REGISTER);
}

BYTE ReadEnaBit(BYTE bitn)
{
	return ReadEna() & (1 << bitn);
}

VOID WriteEnaBit(BYTE bitn, BYTE _bit)
{
	NOINTR(WriteEna((ReadEna() &~ (1 << bitn)) | _bit));
}

VOID SetEnaBit(BYTE bitn)
{
	WriteEnaBit(bitn, 1);
}

VOID ClearEnaBit(BYTE bitn)
{
	WriteEnaBit(bitn, 0);
}


VOID WriteSoundBits(BYTE bits)
{
	NOINTR(WriteEna((ReadEna() &~ SND_BITS) | (bits << EN_SND0)));
}
