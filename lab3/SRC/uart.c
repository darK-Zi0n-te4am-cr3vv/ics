#include "uart.h"
#include "timer.h"
#include "vector.h"

VOID InitUart(BYTE speed, BYTE enirq)
{	
	SetTimerMode(TM_TMR1, TMM_8BIT_AUTO);
	SetTimer8bitAuto(TM_TMR1, speed);
	StartTimer(TM_TMR1);
	
	SCON = UA_SM_UART8_TMR | UA_REN;

	SetInterruptMode(VC_UART, enirq);
}
