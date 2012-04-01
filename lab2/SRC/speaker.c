/* speaker.c */

#include "aduc812.h"
#include "types.h"
#include "ccdef.h"
#include "music.h"
#include "vector.h"
#include "ena.h"
#include "led.h"


PRIVATE VOID TmrIsr()
{
	/* nothing yet */
	/* TODO: test experimental SetVector implementation */
}

VOID InitSound()
{
	EnableIntr(VC_TMR1);
	SetVector(VC_TMR1, TmrIsr);
}

VOID PlayNote(Note *note)
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
			else WriteSoundBits(LastSnd = 7);
		}
	}
	
	TR1 = 0;
}

VOID PlayTune(Note *tune)
{
	do {
		PlayNote(tune);
	} while ((++tune)->Value != TUNE_END_VALUE);
}