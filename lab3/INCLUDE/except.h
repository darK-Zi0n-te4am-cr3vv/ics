#ifndef _EXCEPT_H_
#define _EXCEPT_H_

#include "ccdef.h"
#include <setjmp.h>

TYPEDEF UINT Exception;

STRUCT(ExceptionHandler, {
	jmp_buf jb;
	ExceptionHandler *Previsious;
});

STRUCT(ExceptionHandlingContext, {
	ExceptionHandler *Handler;
	Exception CurrentException;
});

Exception __exc_get_current();
VOID __exc_throw(Exception e);
ExceptionHandler *__exc_set_handler(ExceptionHandler *hdl);
BOOL __exc_remove_handler();

#define throw(exc)		__exc_throw(exc)
#define try				ExceptionHandler __exc_handler;  if (!setjmp(__exc_set_handler(&__exc_handler)->jb)) {
#define EXCEPTION		__exc_get_current()
#define catch(expr)		__exc_remove_handler(); } else if ( __exc_remove_handler() && !( expr ) ) __exc_throw(EXCEPTION); else 

#define rethrow         __exc_throw(EXCEPTION)

#endif /* _EXCEPT_H_ */