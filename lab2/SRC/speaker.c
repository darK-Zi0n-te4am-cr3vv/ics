/* speaker.c */

#include "aduc812.h"
#include "types.h"
#include "ccdef.h"
#include "music.h"
#include "vector.h"
#include "ena.h"
#include "led.h"
#include "timer.h"

PRIVATE BYTE SndTmr, Spk, LastVol, Volume;
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
}

VOID PlayNote(Note *note, BYTE volume)
{
	ToneTmrConst = GetToneTMRConst(note->Tone);
	ValueTmrConst = GetValueTMRConst(note->Value);
	CurrentTicks = 0;
	Spk = note->Tone != TN_PAUSE;
	Volume = volume;
	
	NoteDone = 0;
	StartTimer(SndTmr);
	while(!NoteDone);
	
}

VOID __PlayNote(Note *note, BYTE volume)
{
	UINT ToneTmrConst = GetToneTMRConst(note->Tone);
	UINT ValueTmrConst = GetValueTMRConst(note->Value);
	UINT CurrentTicks = 0;
	BYTE LastSnd = 0;
	BYTE spk = note->Tone != TN_PAUSE;
	
	TMOD = 0x10;
	
	TR1 = 1;
	
	TL1 = 0x00;
	TH1 = 0x00;
	
	while ((CurrentTicks += ToneTmrConst) < ValueTmrConst)
	{
		while ((TH1 << 8) + TL1 < ToneTmrConst);
		TL1 = 0x00;
		TH1 = 0x00;
	
		if (spk)
		{
			if (LastSnd) WriteSoundBits(LastSnd = 0);
			else WriteSoundBits(LastSnd = volume);
		}
	}
	
	TR1 = 0;
}

VOID PlayTune(Note *tune, BYTE volume)
{
	do {
		PlayNote(tune, volume);
	} while ((++tune)->Value != TUNE_END_VALUE);
}