#ifndef _FIFO_H_
#define _FIFO_H_

#include "types.h"
#include "ccdef.h"

#define FIFO_SIZE 16
#define FIFO_PTR_MASK (FIFO_SIZE - 1)

typedef struct {
	BYTE Buffer[FIFO_SIZE];
	BYTE WPtr, RPtr;
	BOOL IsEmpty;
} Fifo;


BOOL TryReadFifo(Fifo *fifo, BYTE *b);
BOOL TryWriteFifo(Fifo *fifo, BYTE b);

VOID InitFifo(Fifo *fifo);

#endif