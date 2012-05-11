#ifndef _FIFO_H_
#define _FIFO_H_

#include "types.h"
#include "ccdef.h"

#define FIFO_SIZE 16
#define FIFO_PTR_MASK (FIFO_SIZE - 1)


STRUCT(Fifo, {
	BYTE Buffer[FIFO_SIZE];
	BYTE WPtr;
	BYTE RPtr;
	BOOL IsEmpty;
});


BOOL TryReadFifo(Fifo *fifo, BYTE *b);
BOOL TryWriteFifo(Fifo *fifo, BYTE b);

VOID InitFifo(Fifo *fifo);

#endif