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

VOID Print(CHAR *s)
{
	while (*s) WriteUartAsync(*s++);
}

VOID Part1()
{
	BYTE cnt = 0x00;

	InitAsyncUart(BAUD_9600);
	
	Print("123456789ABCDEF\n");
	
	for (;;)
	{
		CHAR c = ReadUartAsync();
		//WriteLed(c);
		
		//WriteUartAsync(cnt+'0');
	
		/*
		WriteUartSync(c);
		WriteUartSync(c - 1);
		WriteUartSync(c - 2);
		*/
	
		WriteUartAsync('H');	
		//WriteUartAsync(_i2hex[c & 0x0f]);
	}
}

VOID main()
{	
	EnableAllIntrs();	
	//WriteLed(IE);
	
	Part1();
}
