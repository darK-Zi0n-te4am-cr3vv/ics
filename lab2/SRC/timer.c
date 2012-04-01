/* timer.c */

#include "aduc812.h"
#include "types.h"
#include "ccdef.h"

#include "timer.h"
#include "vector.h"

VOID StartTimer(BYTE timer)
{
	switch (timer)
	{
		case TM_TMR0: TR0 = 1; break;
		case TM_TMR1: TR1 = 1; break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID StopTimer(BYTE timer)
{
	switch (timer)
	{
		case TM_TMR0: TR0 = 0; break;
		case TM_TMR1: TR1 = 0; break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID SetTimerMode(BYTE timer, BYTE mode)
{
	switch (timer)
	{
		case TM_TMR0:
			NOINTR({ TMOD &= 0xf0; TMOD |= mode; });
		break;
		
		case TM_TMR1:
			NOINTR({ TMOD &= 0x0f; TMOD |= (mode << 4); });
		break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID ReloadTimer16bit(BYTE timer, USHORT val)
{
	switch (timer)
	{
		case TM_TMR0:
			NOINTR({ TL0 = (val & 0xff); TH0 = (val >> 8); });
		break;
		
		case TM_TMR1:
			NOINTR({ TL1 = (val & 0xff); TH1 = (val >> 8); });
		break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID ReloadTimer13bit(BYTE timer, USHORT val) 
	/* i have only theoretical experience about 13 bit timers lol */
{
	switch (timer)
	{
		case TM_TMR0:
			NOINTR({ TL0 = (val & 0x1f); TH0 = (val >> 5); });
		break;
		
		case TM_TMR1:
			NOINTR({ TL1 = (val & 0x1f); TH1 = (val >> 5); });
		break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID SetTimer8bitAuto(BYTE timer, BYTE val) 
	/* and about 8 bit ones too */
{
	switch (timer)
	{
		case TM_TMR0: TH0 = val; break;
		case TM_TMR1: TH1 = val; break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID SetTimer8bitSplitHi(BYTE timer, BYTE val) 
{
	switch (timer)
	{
		case TM_TMR0: TH0 = val; break;
		case TM_TMR1: TH1 = val; break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID SetTimer8bitSplitLo(BYTE timer, BYTE val) 
{
	switch (timer)
	{
		case TM_TMR0: TL0 = val; break;
		case TM_TMR1: TL1 = val; break;
		
		default:
			/* oh shi- */
		break;
	}
}

VOID SetTimerIsrHandler(BYTE timer, Vector isr)
{
	switch (timer)
	{
		case TM_TMR0: SetVector(VC_TMR0, isr); EnableIntr(VC_TMR0); break;
		case TM_TMR1: SetVector(VC_TMR1, isr); EnableIntr(VC_TMR1); break;
		
		default:
			/* oh shi- */
		break;
	}
}