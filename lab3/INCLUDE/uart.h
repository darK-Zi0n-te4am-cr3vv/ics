#ifndef _UART_H_
#define _UART_H_

#include "types.h" 
#include "ccdef.h"


/* 
	assuming cpu clock = 11059200 Hz 
*/

#define BAUD_9600   0xFD
#define BAUD_4800   0xFA
#define BAUD_2400   0xF4
#define BAUD_1200   0xE8

#define UA_SM(val) (val << 6)
#define BIT(bt)	(1 << bt)

#define UA_SM_SHIFT8		UA_SM(0) /* 8-bit Shift Register; Oscillator / 12 */
#define UA_SM_UART8_TMR		UA_SM(1) /* 8-bit UART;	Set by Timer 1 */
#define UA_SM_UART9			UA_SM(2) /* 9-bit UART; Oscillator / 64 */
#define UA_SM_UART9_TMR		UA_SM(3) /* 9-bit UART; Set by Timer 1 */

#define UA_MPC				BIT(5) /* multi processor communication enabled */
#define UA_REN				BIT(4) /* recieving enabled */

VOID InitUart(BYTE speed, BYTE enirq);

#endif /* _UART_H_ */