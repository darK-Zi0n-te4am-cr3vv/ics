/* ccdef.h */

#ifndef _CCDEF_H_
#define _CCDEF_H_

#include "aduc812.h" 
#include "types.h"

#define NOINTR(code) { BYTE __old_EA = EA; EA = 0; { code ; } EA = __old_EA; }
#define STRUCT(name, fields) typedef struct  fields  name
#define FUNCPTR(rtype, name, args) typedef rtype (* name ) args

#endif /* _CCDEF_H_ */
#ifndef _DIP_H_
#define _DIP_H_

/* заголовочный файл дравера дип переключателей */

#include "types.h"  /* заголовочный файл прееопределений стандартных типов */

/* считывает значение из регистра дип переключателя  */
BYTE ReadDip();

#endif
/* ena.h */

#ifndef _ENA_H_
#define _ENA_H_

#include "types.h"

#define EN_LO   0
#define EN_HI   1

#define EN_SND0 2
#define EN_SND1 3
#define EN_SND2 4

#define EN_INT0 5
#define EN_KB 6



VOID WriteEna(BYTE ena);
BYTE ReadEna();

BYTE ReadEnaBit(BYTE bitn);
VOID WriteEnaBit(BYTE bitn, BYTE _bit);

VOID SetEnaBit(BYTE bitn);
VOID ClearEnaBit(BYTE bitn);

VOID WriteSoundBits(BYTE bits);


#endif /* _ENA_H_ */
/* led.h */

#ifndef _LED_H_
#define _LED_H_

#include "types.h"  

VOID WriteLed(BYTE led);

#endif /* _LED_H_ */
/* 
	music.h 
	(c) #D@rK_Zi0n_+e4@m_cr3vv; 2012
*/

#ifndef _MUSIC_H_
#define _MUSIC_H_

#include "types.h"
#include "ccdef.h"

#define WHN 16
#define HLN 8
#define QTN 4
#define EGN 2
#define SXN 1

#define WHN_P WHN + HLN
#define HLN_P HLN + QTN
#define QTN_P QTN + EGN
#define EGN_P EGN + SXN

/* tones */

#define TN_PAUSE	-1

#define TN_C 		0
#define TN_C_SHARP	1

#define TN_D 		2
#define TN_D_SHARP	3

#define TN_E		4

#define TN_F		5
#define TN_F_SHARP	6

#define TN_G		7
#define TN_G_SHARP	8

#define TN_A		9
#define TN_A_SHARP	10

#define TN_B		11

#define OCTAVE(n)	(12 * n)

STRUCT(Note, {
	SHORT Tone;
	USHORT Value;
});

#define NOTE(tone, val) { tone, val }
#define PAUSE(val) NOTE(TN_PAUSE, val)
#define TUNE_END_VALUE	0xffff
#define TUNE_END NOTE(TN_PAUSE, TUNE_END_VALUE)


USHORT GetToneTMRConst(SHORT tone);
UINT GetValueTMRConst(USHORT value);

#endif /* _MUSIC_H_ */
/* speaker.h */

#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include "types.h"
#include "music.h"

VOID PlayNote(Note *note, BYTE volume);
VOID PlayTune(Note *tune, BYTE volume);
VOID InitSound(BYTE timer);

#endif /* _SPEAKER_H_ */
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

/* public routines */

VOID SetTimerMode(BYTE timer, BYTE mode);

VOID ReloadTimer16bit(BYTE timer, USHORT val);
VOID ReloadTimer13bit(BYTE timer, USHORT val);
VOID SetTimer8bitAuto(BYTE timer, BYTE val);
VOID SetTimer8bitSplitHi(BYTE timer, BYTE val);
VOID SetTimer8bitSplitLo(BYTE timer, BYTE val);

VOID SetTimerIsrHandler(BYTE timer, Vector isr);
VOID SetTimerIsrPriority(BYTE timer, BYTE pri);

VOID StopTimer(BYTE timer);
VOID StartTimer(BYTE timer);


#endif /* _TIMER_H_ */
#ifndef _TYPES_H_
#define _TYPES_H_

#define VOLATILE volatile
#define TYPEDEF typedef
 
#define XDATA xdata
#define CONST const

#define VOID void

#define STATIC static
#define PRIVATE static

/* 8 bit types */
#define BYTE unsigned char
#define SBYTE signed char

/* 16 bit types */
#define SHORT int
#define USHORT unsigned int 

/* 32 bit types */
#define INT long 
#define UINT unsigned long 

/* float-point */
#define FLOAT float 
#define DOUBLE double 

/* machine-dependent */
#define WORD BYTE
#define XADDR USHORT
#define ADDR XADDR 

#endif /* _TYPES_H_ *//* vector.h */

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "types.h"
#include "ccdef.h"

#define VC_INT0 0
#define VC_TMR0 1
#define VC_INT1 2
#define VC_TMR1 3
#define VC_UART 4

#define EM_ENABLED 1
#define EM_DISABLED 0

#define IP_HIGH		0
#define IP_LOW		1


FUNCPTR(VOID, Vector, ());

VOID SetVector(BYTE vecId, Vector vector);

VOID SetIntrPriority(BYTE irq, BYTE pri);

VOID EnableIntr(BYTE intr);
VOID DisableIntr(BYTE intr);
VOID EnableAllIntrs();
VOID DisableAllIntrs();



 
#endif /* _VECTOR_H_ */
/* xdata.h */

#ifndef _XDATA_H_
#define _XDATA_H_

#include "types.h"   

#define MAX_PAGE	0x08

VOID WriteXData(BYTE page, USHORT offset, BYTE byte);
BYTE ReadXData(BYTE page, USHORT offset);

VOID WriteMax(USHORT offset, BYTE byte);
BYTE ReadMax(USHORT offset);

#endif /* _XDATA_H_ */
/* dip.c */

#include "xdata.h"
#include "types.h"

#define DIP_REGISTER	0x0002 

BYTE ReadDip()
{
	return ReadMax(DIP_REGISTER);
}/* ena.c */

#include "types.h"
#include "ccdef.h"
#include "ena.h"
#include "xdata.h"

#define ENA_REGISTER 	0x0004
#define SND_BITS		0x1C

VOID WriteEna(BYTE ena)
{
	WriteMax(ENA_REGISTER, ena);
}

BYTE ReadEna()
{
	return ReadMax(ENA_REGISTER);
}

BYTE ReadEnaBit(BYTE bitn)
{
	return ReadEna() & (1 << bitn);
}

VOID WriteEnaBit(BYTE bitn, BYTE _bit)
{
	NOINTR(WriteEna((ReadEna() &~ (1 << bitn)) | _bit));
}

VOID SetEnaBit(BYTE bitn)
{
	WriteEnaBit(bitn, 1);
}

VOID ClearEnaBit(BYTE bitn)
{
	WriteEnaBit(bitn, 0);
}


VOID WriteSoundBits(BYTE bits)
{
	NOINTR(WriteEna((ReadEna() &~ SND_BITS) | (bits << EN_SND0)));
}
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

/* Jane Air - Вулканы */

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
п»ї/* led.c */

#include "xdata.h"
#include "types.h"

#define LED_REGISTER	0x0007 

VOID WriteLed(BYTE led)
{
	WriteMax(LED_REGISTER, led);
}/* music.c */

#include "types.h"

#define TONE_TMR_CONST(freq) ((USHORT)(1000000L / (freq)))

USHORT TonesTmrConsts[] = {
	TONE_TMR_CONST(262), /* C  */
	TONE_TMR_CONST(277), /* C# */
	TONE_TMR_CONST(294), /* D  */
	TONE_TMR_CONST(311), /* D# */
	TONE_TMR_CONST(330), /* E  */
	TONE_TMR_CONST(349), /* F  */
	TONE_TMR_CONST(370), /* F# */
	TONE_TMR_CONST(392), /* G  */
	TONE_TMR_CONST(415), /* G# */
	TONE_TMR_CONST(440), /* A  */
	TONE_TMR_CONST(466), /* A# */
	TONE_TMR_CONST(494)  /* B  */
}; 

USHORT GetToneTMRConst(SHORT tone)
{
	SHORT octave = tone / 12;
	USHORT tmrConst = TonesTmrConsts[tone % 12];
	
	while (octave-- > 0) tmrConst /= 2;
	
	return tmrConst;
}

#define SXN_TMR_CONST 100000L

UINT GetValueTMRConst(USHORT value)
{	
	return value * SXN_TMR_CONST;
}
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
			NOINTR({ TMOD = (TMOD & 0xf0) | mode; });
		break;
		
		case TM_TMR1:
			NOINTR({ TMOD = (TMOD & 0x0f) | (mode << 4); });
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

VOID SetTimerIsrPriority(BYTE timer, BYTE pri)
{	
	switch (timer)
	{
		case TM_TMR0: SetIntrPriority(VC_TMR0, pri); break;
		case TM_TMR1: SetIntrPriority(VC_TMR1, pri); break;
		
		default:
			/* oh shi- */
		break;
	}
}
/* vector.c */

#include "types.h"
#include "vector.h"

#define VECTOR_START	0x2000 /* used on SDK 1.1; on original mcs-51/52 it is 0x0000, of course */
#define VECTOR(vecid) (BYTE XDATA *)(VECTOR_START + (vecid << 3) + 3)

#define LCALL			0x12
#define RETI			0x32

VOID SetVector(BYTE vecid, Vector vector) /* producing code like this: lcall Vector; reti */
{
	BYTE XDATA *addr = VECTOR(vecid);
	XADDR v = (XADDR)vector;
	
	*addr++ = LCALL;
	*addr++ = (BYTE)(v >> 8);
	*addr++ = (BYTE)(v & 0xff);
	
	*addr = RETI;
}

VOID SetInterruptsMode(BYTE mode)
{
	EA = mode;
}

VOID SetInterruptMode(BYTE irq, BYTE mode)
{
	NOINTR(IE = (IE &~ (1 << irq)) | (mode << irq));
}

VOID SetIntrPriority(BYTE irq, BYTE pri)
{
	NOINTR(IP = (IP &~ (1 << irq)) | (pri << irq));
}


VOID EnableIntr(BYTE intr)
{
	SetInterruptMode(intr, EM_ENABLED);
}

VOID DisableIntr(BYTE intr)
{
	SetInterruptMode(intr, EM_DISABLED);
}

VOID EnableAllIntrs()
{
	SetInterruptsMode(EM_ENABLED);
}

VOID DisableAllIntrs()
{
	SetInterruptsMode(EM_DISABLED);
}

/* xdata.c */

#include "aduc812.h" 
#include "types.h" 
#include "ccdef.h" 

#include "xdata.h"

VOID WriteXData(BYTE page, USHORT offset, BYTE _byte)
{
	NOINTR({
		BYTE olddpp = DPP; 
		DPP = page; 
		*((BYTE XDATA*)offset) = _byte; 
		DPP = olddpp; 
	});
}

BYTE ReadXData(BYTE page, USHORT offset)
{
	BYTE _byte;
	NOINTR({
		BYTE olddpp = DPP; 
		DPP = page; 
		_byte = *((BYTE XDATA*)offset); 
		DPP = olddpp; 
	});
	
	return _byte; 
}

VOID WriteMax(USHORT offset, BYTE byte)
{
	WriteXData(MAX_PAGE, offset, byte);
}

BYTE ReadMax(USHORT offset)
{
	return ReadXData(MAX_PAGE, offset);
}
