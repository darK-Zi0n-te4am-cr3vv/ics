/* entry.c */

#include "types.h" 
#include "led.h" 
#include "music.h"
#include "speaker.h"
#include "vector.h"
#include "aduc812.h"
#include "timer.h"

#include "ena.h"

/* The Imperial March - Darth Vader's Theme */
/* Drop C tuning ^_^ */

CONST Note tune[] = {
	NOTE(5, 3),	PAUSE(1),
	NOTE(5, 3),	PAUSE(1),
	NOTE(5, 3),	PAUSE(1),
	NOTE(1, 3),	
	NOTE(8, 1),	
	
	NOTE(5, 3),	PAUSE(1),
	
	NOTE(1, 3),	
	NOTE(8, 1),	
	NOTE(5, 6), PAUSE(2),
	
	NOTE(12, 3), PAUSE(1),
	NOTE(12, 3), PAUSE(1),
	NOTE(12, 3), PAUSE(1),
	NOTE(13, 3),	
	NOTE(8, 1),	
	
	NOTE(4, 3),	PAUSE(1),
	NOTE(1, 3),	
	NOTE(8, 1),	
	NOTE(5, 6), PAUSE(2),

	TUNE_END	
};

/* Jane Air - ������� */

CONST Note  __tune[] = {
	NOTE(8, 4),
	NOTE(7+12, 2),
	NOTE(12+5+12, 4),
	NOTE(9+5+12, 4),
	NOTE(10+5+12, 2),
	
	NOTE(12, 4),
	NOTE(12+12, 2),
	NOTE(9+5+12, 4),
	NOTE(12+5, 4),
	NOTE(12+7, 2),
	
	TUNE_END	
};

PRIVATE BYTE Int0Count = 0; 
PRIVATE VOID Int0Isr()
{
	Int0Count++;
	WriteLed(Int0Count);
}

VOID main()
{	
	EnableAllIntrs();
	InitSound(TM_TMR1);
	
	SetVector(VC_INT1, Int0Isr);
	SetIntrPriority(VC_INT1, IP_LOW);
	EnableIntr(VC_INT1);
	
	for (;;) PlayTune(tune, 7);
}
