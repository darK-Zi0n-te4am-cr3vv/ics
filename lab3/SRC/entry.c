/* entry.c */

#include "types.h" 
#include "led.h" 
#include "timer.h"

#include "ena.h"

#include "uart.h"
#include "syncuart.h"

VOID Part1()
{
	InitSyncUart(BAUD_1200);
	
	for (;;)
	{
		CHAR c = ReadUartSync();
		
		WriteUartSync(c);
		WriteUartSync(c - 1);
		WriteUartSync(c - 2);
	}
}

VOID main()
{	
	
}
