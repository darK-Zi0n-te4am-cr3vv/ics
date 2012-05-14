#include "fifo.h"
#include "led.h"

#define FIFO_NEXT(b) ((b + 1) & FIFO_PTR_MASK)

FifoReadStatus TryReadFifo(Fifo *fifo)
{
	BYTE b; 
	
	if (fifo->WPtr == fifo->RPtr) 
	{
		fifo->IsEmpty = TRUE;
		return FIFO_READ_STATUS(FALSE, 0x00);
	}		
		
	b = fifo->Buffer[fifo->RPtr];
	fifo->RPtr = FIFO_NEXT(fifo->RPtr);
	
	return FIFO_READ_STATUS(TRUE, b);
}

BOOL TryWriteFifo(Fifo *fifo, BYTE b)
{	
	if (fifo->IsEmpty || fifo->WPtr != fifo->RPtr) 
	{
		fifo->Buffer[fifo->WPtr] = b;
		fifo->WPtr = FIFO_NEXT(fifo->WPtr);
		fifo->IsEmpty = FALSE;
		
		return TRUE;
	}
	
	return FALSE;
}


VOID InitFifo(Fifo *fifo)
{
	fifo->WPtr = 0;
	fifo->RPtr = 0;
	fifo->IsEmpty = TRUE;
}