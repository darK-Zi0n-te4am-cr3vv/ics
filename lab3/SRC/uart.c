#include "uart.h"
#include "timer.h"

VOID InitUart(BYTE speed, BYTE enirq)
{
	SetInterruptMode(VC_UART, enirq);
	SetTimer8bitAuto(TM_TMR1, speed);
	SCON = UA_SM_UART8_TMR | UA_REN;
}
