/* speaker.c */

#include "aduc812.h"
#include "types.h"
#include "ccdef.h"
#include "music.h"
#include "vector.h"
#include "ena.h"
#include "led.h"
#include "timer.h"

PRIVATE BYTE SndTmr, LastVol, Volume;
PRIVATE UINT ValueTmrConst, CurrentTicks;
PRIVATE USHORT ToneTmrConst;

PRIVATE VOLATILE BYTE NoteDone;


PRIVATE VOID TmrIsr()
{
	CurrentTicks += ToneTmrConst;
	if (CurrentTicks >= ValueTmrConst)
	{
		StopTimer(SndTmr);
		NoteDone = 1;
	}
	else
	{
		ReloadTimer16bit(SndTmr, -ToneTmrConst);
		
		if (LastVol) WriteSoundBits(LastVol = 0);
		else WriteSoundBits(LastVol = Volume);
	}
}

VOID InitSound(BYTE timer)
{
	SndTmr = timer;
	
	SetTimerMode(SndTmr, TMM_16BIT);
	SetTimerIsrHandler(SndTmr, TmrIsr);
	SetTimerIsrPriority(SndTmr, IP_HIGH);
}

VOID PlayNote(Note *note, BYTE volume)
{
	ToneTmrConst = GetToneTMRConst(note->Tone);
	ValueTmrConst = GetValueTMRConst(note->Value);
	CurrentTicks = 0;
	Volume = note->Tone != TN_PAUSE ? volume : 0;
	
	NoteDone = 0;
	StartTimer(SndTmr);
	while(!NoteDone);
	
}

VOID PlayTune(Note *tune, BYTE volume)
{
	do {
		PlayNote(tune, volume);
	} while ((++tune)->Value != TUNE_END_VALUE);
}