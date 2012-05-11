#include "asyncuart.h"
#include "led.h"

PRIVATE XDATA Fifo RxFifo, TxFifo; 
PRIVATE BOOL TransferNow = FALSE;

PRIVATE VOID UartInterruptHandler()
{
	BYTE tx;

	if (RI) 
	{
		TryWriteFifo(&RxFifo, SBUF);
		RI = 0;
	}
	
	if (TI)
	{		
		TransferNow = TRUE;
		if (TryReadFifo(&TxFifo, &tx)) 
		{
			SBUF = tx;
			TI = 0;
		}
		else 
		{
			TransferNow = FALSE;
		}
	}	
}

PRIVATE BOOL TryWriteUart(CHAR c)
{     
	ES = 0;		
	
	if (TryWriteFifo(&TxFifo, c)) 
	{
		ES = 1;
		if (!TransferNow) 
		{
			TI = 1;
		}
		
		return TRUE;
	}
	else 
	{
		ES = 1;
		return FALSE; 
	}
}

PRIVATE BOOL TryReadUart(CHAR *c)
{
	BOOL result;
	
	ES = 0;
	result = TryReadFifo(&RxFifo, c);
	ES = 1;
	
	return result;
}

VOID InitAsyncUart(BYTE speed)
{
	InitFifo(&RxFifo);
	InitFifo(&TxFifo);
	
	SetVector(VC_UART, UartInterruptHandler);
	InitUart(speed, EM_ENABLED);
	SetInterruptMode(VC_UART, EM_ENABLED);	
}

VOID WriteUartAsync(CHAR c)
{
	while(!TryWriteUart(c));
	//WriteLed(TryWriteUart(c) ? 0xaa : 0x11);
}

CHAR ReadUartAsync()
{
	CHAR c;
	while(!TryReadUart(&c));
	
//	WriteLed(TryReadUart(&c) ? 0xaa : 0x11);
	
	return c;
}







