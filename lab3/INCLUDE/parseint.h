#ifndef _PARSEINT_H_
#define _PARSEINT_H_

#include "types.h" 

/* NULL if ok and number of symbol if fails */
CHAR *TryParseInt(CHAR *str, INT *out);

#endif