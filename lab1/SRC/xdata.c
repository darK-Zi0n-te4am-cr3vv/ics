/*
	xdata.c
*/

#include "aduc812.h" /* ����������� ����� ����� ������ ����������� */
#include "types.h"  /* ������������ ���� ��������������� ����������� ����� */
#include "ccdef.h" /* ������������ ���� ��������� �������������� ����������� ������������� */

#include "xdata.h"

/* ������� ������ ����� �� �������� offset � ��������� page ������ XDATA */
VOID WriteXData(BYTE page, USHORT offset, BYTE byte)
{
	BYTE oldDpp; // ���������� ��� ���������� ����������� �������� �������� ������ ��������
	
	NOINTR({
		oldDpp = DPP; // �������� ������� ������ �������
		DPP = page; // ������� � ������� ������ ������� page
		*((BYTE XDATA*)offset) = byte; // ������� ����
		DPP = oldDpp; // ����������� �������� DPP
	});
}

/* ������� ������ ����� �� �������� offset �� �������� page ������ XDATA */
BYTE ReadXData(BYTE page, USHORT offset)
{
	BYTE oldDpp, // ���������� ��� ���������� ����������� �������� �������� ������ ��������
		byte; // �������� ����
	
	NOINTR({
		oldDpp = DPP; // �������� ������� ������ �������
		DPP = page; // ������� � ������� ������ ������� page
		byte = *((BYTE XDATA*)offset); // ��������� ����
		DPP = oldDpp; // ����������� �������� DPP
	});
	
	return byte; 
	
}

/* ������� ������ ����� �� �������� offset � ���������� ����������� �������� */
VOID WriteMax(USHORT offset, BYTE byte)
{
	WriteXData(MAX_PAGE, offset, byte);
}

BYTE ReadMax(USHORT offset)
{
	return ReadXData(MAX_PAGE, offset);
}
