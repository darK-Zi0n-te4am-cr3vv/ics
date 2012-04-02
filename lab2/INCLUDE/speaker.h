/* speaker.h */

#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include "types.h"
#include "music.h"

VOID PlayNote(Note *note, BYTE volume);
VOID PlayTune(Note *tune, BYTE volume);
VOID InitSound(BYTE timer);

#endif /* _SPEAKER_H_ */