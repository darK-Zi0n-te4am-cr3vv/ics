
#include "syncuart.h"
#include "aduc812.h"
#include "vector.h"
#include "uart.h"

VOID InitSyncUart(BYTE speed)
{
	InitUart(speed, EM_DISABLED);
}

VOID WriteUartSync(CHAR c)
{
	SBUF = c;

	while(!TI);
	TI = 0;
}

CHAR ReadUartSync()
{
	CHAR c;

	while(!RI);
	c = SBUF;

	RI = 0;	
	return c;
}