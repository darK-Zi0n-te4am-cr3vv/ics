/* entry.c */

#include "types.h" 
#include "led.h" 
#include "timer.h"

#include "ena.h"

#include "uart.h"
#include "syncuart.h"
#include "asyncuart.h"

CONST CHAR _i2hex[] = "0123456789ABCDEF";

#define K_ENTER 0x0D

VOID Part1()
{
	InitAsyncUart(BAUD_9600);
	//WriteLed(IE);
	
	for (;;)
	{
		CHAR c = ReadUartAsync();
		WriteLed(c);
	
		/*
		WriteUartSync(c);
		WriteUartSync(c - 1);
		WriteUartSync(c - 2);
		*/
	
		WriteUartAsync(c);	
		//WriteUartAsync(_i2hex[c & 0x0f]);
	}
}

VOID main()
{	
	EnableAllIntrs();	
	//WriteLed(IE);
	
	Part1();
}
