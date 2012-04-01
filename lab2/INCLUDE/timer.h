/* timer.h */

#ifndef _TIMER_H_
#define _TIMER_H_

#include "types.h"
#include "ccdef.h"

#include "vector.h"

/* timer modes */

#define TMM_13BIT		0x00
#define TMM_16BIT		0x01
#define TMM_8BIT_AUTO	0x02
#define TMM_SPLIT		0x03

#define TMM_MODE_MASK	0x03



#define TMM_COUNTER		0x04
#define TMM_GATE		0x08

/* timers */

#define TM_TMR0			0
#define TM_TMR1			1

VOID SetTimerMode(BYTE timer, BYTE mode);

VOID ReloadTimer16bit(BYTE timer, USHORT val);
VOID ReloadTimer13bit(BYTE timer, USHORT val);
VOID SetTimer8bitAuto(BYTE timer, BYTE val);
VOID SetTimer8bitSplitHi(BYTE timer, BYTE val);
VOID SetTimer8bitSplitLo(BYTE timer, BYTE val);

VOID SetTimerIsrHandler(BYTE timer, Vector isr);

#endif /* _TIMER_H_ */