#ifndef _STRIO_H_
#define _STRIO_H_

#include "types.h" 
#include "asyncuart.h"

VOID Print(CHAR *s);
VOID ReadStr(CHAR *str, SIZE maxlen);

#endif /* _STRIO_H_ */