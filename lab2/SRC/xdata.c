/*
	xdata.c
*/

#include "aduc812.h" /* стандартные порты ввода вывода контроллера */
#include "types.h"  /* заголовочный файл прееопределений стандартных типов */
#include "ccdef.h" /* заголовочный файл некоторых дополнительных определений препроцессора */

#include "xdata.h"

/* Функция записи байта по смещению offset в странимцу page памяти XDATA */
VOID WriteXData(BYTE page, USHORT offset, BYTE byte)
{
	BYTE oldDpp; // переменная для сохранения предыдущего значения регистра номера страницы
	
	NOINTR({
		oldDpp = DPP; // сохраним регистр номера страниц
		DPP = page; // запишем в регистр номера страниц page
		*((BYTE XDATA*)offset) = byte; // запишем байт
		DPP = oldDpp; // восстановим значение DPP
	});
}

/* Функция чтения байта по смещению offset со страницы page памяти XDATA */
BYTE ReadXData(BYTE page, USHORT offset)
{
	BYTE oldDpp, // переменная для сохранения предыдущего значения регистра номера страницы
		byte; // принятый байт
	
	NOINTR({
		oldDpp = DPP; // сохраним регистр номера страниц
		DPP = page; // запишем в регистр номера страниц page
		byte = *((BYTE XDATA*)offset); // прочитаем байт
		DPP = oldDpp; // восстановим значение DPP
	});
	
	return byte; 
	
}

/* Функция записи байта по смещению offset в микросхему расширителя сознания */
VOID WriteMax(USHORT offset, BYTE byte)
{
	WriteXData(MAX_PAGE, offset, byte);
}

BYTE ReadMax(USHORT offset)
{
	return ReadXData(MAX_PAGE, offset);
}
