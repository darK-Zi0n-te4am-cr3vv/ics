/* ccdef.h */

#ifndef _CCDEF_H_
#define _CCDEF_H_

#include "aduc812.h" 
#include "types.h"

#define NOINTR(code) { BYTE __old_EA = EA; EA = 0; { code ; } EA = __old_EA; }
#define STRUCT(name, fields) typedef struct  fields  name
#define FUNCPTR(rtype, name, args) typedef rtype (* name ) args

#endif /* _CCDEF_H_ */