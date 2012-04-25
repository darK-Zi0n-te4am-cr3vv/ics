#ifndef _SYNCUART_H_
#define _SYNCUART_H_

#include "types.h" 
#include "ccdef.h"

VOID InitSyncUart(BYTE speed);
VOID WriteUartSync(CHAR cc);
CHAR ReadUartSync();

#endif /* _SYNCUART_H_ */