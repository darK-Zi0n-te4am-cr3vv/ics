#include "strio.h"

#define K_ENTER 0x0D
#define K_BKSPACE 0x08


VOID Print(CHAR *s)
{
	while (*s) WriteUartAsync(*s++);
}

VOID ReadStr(CHAR *str, SIZE maxlen)
{
	SIZE cnt = 0;
	
	while (cnt < maxlen)
	{
		CHAR c = ReadUartAsync();
		
		switch (c)
		{
			case K_ENTER:
				goto Ret; 
			break;
				
			case K_BKSPACE:
				if (cnt > 0) 
				{
					str--;
					cnt--;
				
					WriteUartAsync('\b');
					WriteUartAsync(' ');
					WriteUartAsync('\b');
				}
			break;
				
			default:
				*str++ = c;
				cnt++;
				
				WriteUartAsync(c);
				break;
		}
	}	

Ret:
	*str = '\0';
}