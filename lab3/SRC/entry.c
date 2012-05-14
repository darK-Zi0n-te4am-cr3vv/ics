/* entry.c */

#include "types.h" 
#include "led.h" 
#include "timer.h"

#include "ena.h"

#include "dip.h"

#include "uart.h"
#include "syncuart.h"
#include "asyncuart.h"

#include <string.h>

#include "strio.h"

#define PART1_SWITCH 0x00
#define PART2_SWITCH 0x01


PRIVATE VOID Part1()
{
	CHAR c;
	
	InitSyncUart(BAUD_9600);
	c = ReadUartSync();
	
	WriteUartSync(c - 0);
	WriteUartSync(c - 1);
	WriteUartSync(c - 2);
}

#define STR_LENGTH 10

PRIVATE BOOL IsHex(CHAR c)
{
	return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'); 
}

PRIVATE BYTE HexVal(CHAR c)
{
	return (c >= '0' && c <= '9') ? c - '0' :
	(c >= 'a' && c <= 'f') ? c - 'a' + 10: c - 'A' + 10;
}

PRIVATE VOID PrintDec(BYTE n)
{
	BYTE i;
	CHAR s[4];
	
    i = 0;
	do {
		s[i++] = (n % 10) + '0'; 
    } while ((n /= 10) > 0);  

	while (i--)
	{
		WriteUartAsync(s[i]);
	}
}

PRIVATE VOID Part2()
{
	CHAR str[STR_LENGTH + 1];
	BYTE num;
	
	InitAsyncUart(BAUD_9600);
	ReadStr(str, STR_LENGTH);
	Print("\n");
	
	if(strlen(str)!=2 || !IsHex(str[0]) || !IsHex(str[1]))  
	{
		Print("Error in input\n");
		return;
	}
	
	num = (HexVal(str[0]) << 4) + HexVal(str[1]);
	
	PrintDec(num);
	Print("\n");
}

VOID main()
{	
	EnableAllIntrs();	
		
	switch (ReadDip())
	{
		case PART1_SWITCH:
			for (;;) Part1();
		break;
		
		case PART2_SWITCH:
			for (;;) Part2();
		break;
	}	
}
