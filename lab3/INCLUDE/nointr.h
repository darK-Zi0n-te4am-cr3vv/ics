#ifndef _NOINTR_H_
#define _NOINTR_H_

#include "types.h" 

#define __xchangeIE__USE_ASSEMBER

#ifdef __xchangeIE__USE_ASSEMBER
BYTE __xchangeIE(BYTE __ie) __naked;
#else
BYTE __xchangeIE(BYTE __ie);
#endif

#define NOINTR(code) { BYTE __old_IE = __xchangeIE(0x00); IE = __old_IE & 0x7f; { code ; } IE = __old_IE; }
//#define NOINTR(code) { BYTE __old_EA = EA; EA = 0; { code ; } EA = __old_EA; }

#endif /* _NOINTR_H_ */