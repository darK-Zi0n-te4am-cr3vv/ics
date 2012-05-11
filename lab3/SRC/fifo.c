#include "fifo.h"
#include "led.h"

#define FIFO_NEXT(b) ((b + 1) & FIFO_PTR_MASK)

BOOL TryReadFifo(Fifo *fifo, BYTE *b)
{
	if (fifo->WPtr == fifo->RPtr) 
		return FALSE;		
		
	*b = fifo->Buffer[fifo->RPtr];
	fifo->RPtr = FIFO_NEXT(fifo->RPtr);
	
	return TRUE;
}

BOOL TryWriteFifo(Fifo *fifo, BYTE b)
{
	BYTE nextWPtr = FIFO_NEXT(fifo->WPtr);
	
	if (nextWPtr == fifo->RPtr) 
		return FALSE;
		
	fifo->Buffer[fifo->WPtr] = b;
	fifo->WPtr = nextWPtr;
		
	return TRUE;
}


VOID InitFifo(Fifo *fifo)
{
	fifo->WPtr = 0;
	fifo->RPtr = 0;
}