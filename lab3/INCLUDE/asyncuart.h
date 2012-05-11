#ifndef _ASYNCUART_H_
#define _ASYNCUART_H_

#include "aduc812.h"
#include "vector.h"
#include "uart.h"
#include "types.h"
#include "ccdef.h"
#include "fifo.h"


VOID InitAsyncUart(BYTE speed);
VOID WriteUartAsync(CHAR c);

CHAR ReadUartAsync();

#endif /* _ASYNCUART_H_ */