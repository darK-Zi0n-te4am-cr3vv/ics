#include "except.h"

PRIVATE ExceptionHandlingContext Context;
PRIVATE ExceptionHandlingContext* pContext = &Context;

Exception __exc_get_current()
{
	return pContext->CurrentException;
}

VOID __exc_throw(Exception e)
{
	pContext->CurrentException = e;
	longjmp(pContext->Handler->jb, 1);
}

ExceptionHandler *__exc_set_handler(ExceptionHandler *hdl)
{
	hdl->Previsious = pContext->Handler;
	return pContext->Handler = hdl;
}

BOOL __exc_remove_handler()
{
	pContext->Handler = pContext->Handler->Previsious;
	return TRUE;
}