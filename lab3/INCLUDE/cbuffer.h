/*
	CBUF.h
*/

#ifndef _CBUFFER_H_
#define _CBUFFER_H_

#include "types.h" 
#include "ccdef.h"

#define CBUF_POW	8
#define CBUF_SZ		(1 << CBUF_POW)
#define CBUF_MASK	(CBUF_SZ - 1)

STRUCT(CBUF, {
	SIZE RdIndex, WrIndex;
	BYTE Buffer[CBUF_SZ];
});

VOID InitCBuf(CBUF *CBUF);

BOOL ReadCBuf(CBUF *CBUF, BYTE *b);
BOOL ReadCBuf(CBUF *CBUF, BYTE *b);


#endif /* _CBUFFER_H_ */