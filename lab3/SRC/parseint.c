#include "parseint.h"

PRIVATE BOOL CheckSymbol(CHAR c)
{
	return c >= '0' && c <= '9';
}

CHAR *TryParseInt(CHAR *str, INT *out)
{	
	CHAR *end = str;
	
	while (*end)
	{
		if (!CheckSymbol(*end)) 
			return end;
		
		end++;
	}
	
	while (end != str)
	{
		*out *= 10;
		*out += *(--end) - '0';
	}
	
	return NULL;
}