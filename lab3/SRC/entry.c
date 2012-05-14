/* entry.c */

#include "types.h" 
#include "led.h" 
#include "timer.h"

#include "ena.h"

#include "uart.h"
#include "syncuart.h"
#include "asyncuart.h"

CONST CHAR _i2hex[] = "0123456789ABCDEF";


VOID Print(CHAR *s)
{
	while (*s) WriteUartAsync(*s++);
}

#define K_ENTER 0x0D
#define K_BKSPACE 0x08


VOID ReadStr(CHAR *str, SIZE maxlen)
{
	SIZE cnt = 0;
	
	do {
		CHAR c = ReadUartAsync();
		
		if (c == K_ENTER) 
		{
			break;
		}
		else if (c == K_BKSPACE && cnt)
		{
			str--;
			cnt--;
			
			Print("\b \b");
		}
		else
		{
			*str++ = c;
			cnt++;
			
			WriteUartAsync(c);
		}
		
	} while (cnt <= maxlen);

	*str = '\0';
}


VOID Part1()
{
	CHAR str[10];
	BYTE cnt = 0x00;
	

	InitAsyncUart(BAUD_9600);
	
	//Print("123456789ABCDEF\n");
	
	for (;;)
	{
		ReadStr(str, 9);
		Print(str);		
	
		//WriteUartAsync(c);	
		//WriteUartAsync(_i2hex[c & 0x0f]);
	}
}

VOID main()
{	
	EnableAllIntrs();	
	//WriteLed(IE);
	
	Part1();
}
