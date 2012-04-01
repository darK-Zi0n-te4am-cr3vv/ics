/* timer.c */

#include "types.h"
#include "ccdef.h"

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

BYTE GetTimerMode(BYTE timer)
{
	switch (timer)
	{
		case TM_TMR0: return TMOD & 0x0f;
		case TM_TMR1: return (TMOD & 0xf0) >> 4;
		
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