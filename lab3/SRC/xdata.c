/* xdata.c */

#include "aduc812.h" 
#include "types.h" 
#include "ccdef.h" 

#include "xdata.h"

VOID WriteXData(BYTE page, USHORT offset, BYTE _byte)
{
	NOINTR({
		BYTE olddpp = DPP; 
		DPP = page; 
		*((BYTE XDATA*)offset) = _byte; 
		DPP = olddpp; 
	});
}

BYTE ReadXData(BYTE page, USHORT offset)
{
	BYTE _byte;
	NOINTR({
		BYTE olddpp = DPP; 
		DPP = page; 
		_byte = *((BYTE XDATA*)offset); 
		DPP = olddpp; 
	});
	
	return _byte; 
}

VOID WriteMax(USHORT offset, BYTE byte)
{
	WriteXData(MAX_PAGE, offset, byte);
}

BYTE ReadMax(USHORT offset)
{
	return ReadXData(MAX_PAGE, offset);
}
