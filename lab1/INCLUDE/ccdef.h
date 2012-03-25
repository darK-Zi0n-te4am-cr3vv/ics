#ifndef _CCDEF_H_
#define _CCDEF_H_

/* заголовочный файл некоторых дополнительных определений препроцессора */

#include "aduc812.h" /* стандартные порты ввода вывода контроллера */

#define NOINTR(code) { BYTE __old_EA = EA; EA = 0; { code ; } EA = __old_EA; }

#endif /* _CCDEF_H_ */