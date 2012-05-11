#ifndef _NOINTR_H_
#define _NOINTR_H_

#include "types.h" 

#define __NOINTR_USE_ASSEMBER

#ifdef __NOINTR_USE_ASSEMBER
__bit _testea_() __naked;
#else
__bit _testea_();
#endif

#define NOINTR(code) { __bit __ea = _testea_(); { code ; } EA = __ea; }

#endif /* _NOINTR_H_ */