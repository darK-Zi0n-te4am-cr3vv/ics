#ifndef _XDATA_H_
#define _XDATA_H_

#include "types.h"   /* заголовочный файл прееопределений стандартных типов */

#define MAX_PAGE	0x08

/* Функция записи байта по смещению offset в странимцу page памяти XDATA */
VOID WriteXData(BYTE page, USHORT offset, BYTE byte);
/* Функция чтения байта по смещению offset со страницы page памяти XDATA */
BYTE ReadXData(BYTE page, USHORT offset);

/* Функция записи байта по смещению offset в микросхему расширителя сознания */
VOID WriteMax(USHORT offset, BYTE byte);
/* Функция записи байта по смещению offset в микросхему расширителя ввода вывода */
BYTE ReadMax(USHORT offset);

#endif /* _XDATA_H_ */