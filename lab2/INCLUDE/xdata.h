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