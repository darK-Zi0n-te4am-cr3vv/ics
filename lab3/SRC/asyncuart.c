#include "asyncuart.h"
#include "led.h"

PRIVATE Fifo RxFifo, TxFifo; 
PRIVATE BOOL TransferNow = FALSE;

PRIVATE BYTE cnt = 0;
PRIVATE VOID UartInterruptHandler()
{
	FifoReadStatus r;
	
	if (RI) 
	{
		RI = 0;
		TryWriteFifo(&RxFifo, SBUF);
	}
	
	if (TI)
	{		
		TI = 0;
	
		TransferNow = TRUE;
		r = TryReadFifo(&TxFifo);
		
		if (!FIFO_READ_STATUS_IS_EMPTY(r)) 
		{
			SBUF = FIFO_READ_STATUS_BYTE(r);
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

PRIVATE FifoReadStatus TryReadUart()
{
	FifoReadStatus result;
	
	ES = 0;
	result = TryReadFifo(&RxFifo);
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
}

CHAR ReadUartAsync()
{
	FifoReadStatus r;
	do {
		r = TryReadUart();
	} while (FIFO_READ_STATUS_IS_EMPTY(r));
		
	return FIFO_READ_STATUS_BYTE(r);
}







