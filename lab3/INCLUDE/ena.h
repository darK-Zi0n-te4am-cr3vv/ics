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
