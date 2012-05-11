/* ccdef.h */

#ifndef _CCDEF_H_
#define _CCDEF_H_

#include "aduc812.h" 
#include "types.h"
#include "nointr.h"

#define STRUCT(name, fields) typedef struct  fields  name
#define FUNCPTR(rtype, name, args) typedef rtype (* name ) args

#define EXTERN extern 

#endif /* _CCDEF_H_ */
