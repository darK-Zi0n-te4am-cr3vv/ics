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
