#ifndef _XDATA_H_
#define _XDATA_H_

#include "types.h"   /* ������������ ���� ��������������� ����������� ����� */

#define MAX_PAGE	0x08

/* ������� ������ ����� �� �������� offset � ��������� page ������ XDATA */
VOID WriteXData(BYTE page, USHORT offset, BYTE byte);
/* ������� ������ ����� �� �������� offset �� �������� page ������ XDATA */
BYTE ReadXData(BYTE page, USHORT offset);

/* ������� ������ ����� �� �������� offset � ���������� ����������� �������� */
VOID WriteMax(USHORT offset, BYTE byte);
/* ������� ������ ����� �� �������� offset � ���������� ����������� ����� ������ */
BYTE ReadMax(USHORT offset);

#endif /* _XDATA_H_ */