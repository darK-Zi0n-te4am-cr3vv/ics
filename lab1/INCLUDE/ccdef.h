#ifndef _CCDEF_H_
#define _CCDEF_H_

/* ������������ ���� ��������� �������������� ����������� ������������� */

#include "aduc812.h" /* ����������� ����� ����� ������ ����������� */

#define NOINTR(code) { BYTE __old_EA = EA; EA = 0; { code ; } EA = __old_EA; }

#endif /* _CCDEF_H_ */