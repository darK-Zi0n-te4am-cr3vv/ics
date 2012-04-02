/* vector.h */

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "types.h"
#include "ccdef.h"

#define VC_INT0 0
#define VC_TMR0 1
#define VC_INT1 2
#define VC_TMR1 3
#define VC_UART 4

#define EM_ENABLED 1
#define EM_DISABLED 0

#define IP_HIGH		0
#define IP_LOW		1


FUNCPTR(VOID, Vector, ());

VOID SetVector(BYTE vecId, Vector vector);

VOID SetIntrPriority(BYTE irq, BYTE pri);

VOID EnableIntr(BYTE intr);
VOID DisableIntr(BYTE intr);
VOID EnableAllIntrs();
VOID DisableAllIntrs();



 
#endif /* _VECTOR_H_ */