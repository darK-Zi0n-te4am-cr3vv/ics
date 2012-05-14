#ifndef _FIFO_H_
#define _FIFO_H_

#include "types.h"
#include "ccdef.h"

#define FIFO_SIZE 16
#define FIFO_PTR_MASK (FIFO_SIZE - 1)

TYPEDEF USHORT FifoReadStatus;

#define FIFO_READ_STATUS(s, b) ((s << 8) | b)
#define FIFO_READ_STATUS_IS_EMPTY(st) (!(st & 0xff00))
#define FIFO_READ_STATUS_BYTE(st) ((BYTE)(st & 0xff))

STRUCT(Fifo, {
	BYTE Buffer[FIFO_SIZE];
	BYTE WPtr;
	BYTE RPtr;
	BOOL IsEmpty;
});


FifoReadStatus TryReadFifo(Fifo *fifo);
BOOL TryWriteFifo(Fifo *fifo, BYTE b);

VOID InitFifo(Fifo *fifo);

#endif