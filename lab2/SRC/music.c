/* music.c */

#include "types.h"

#define TONE_TMR_CONST(freq) ((USHORT)(125000L / (freq)))

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

#define SXN_TMR_CONST 125000L

UINT GetValueTMRConst(USHORT value)
{
	/* только для 120 BPM */
	
	return value * SXN_TMR_CONST;
}