/* speaker.h */

#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include "types.h"
#include "music.h"

VOID PlayNote(Note *note);
VOID PlayTune(Note *tune);
VOID InitSound();

#endif /* _SPEAKER_H_ */