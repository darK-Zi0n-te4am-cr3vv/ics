#ifndef _TYPES_H_
#define _TYPES_H_

 /* заголовочный файл прееопределений стандартных типов */

#define VOLATILE volatile
#define TYPEDEF typedef
 
#define XDATA xdata
#define CONST const


#define VOID void

/* 8 bit types */
#define BYTE unsigned char
#define SBYTE signed char

/* 16 bit types */
#define SHORT int
#define USHORT unsigned int 

/* 32 bit types */
#define INT long 
#define UINT unsigned long 

/* float-point */
#define FLOAT float 
#define DOUBLE double 

/* machine-dependent */
#define WORD BYTE
#define XADDR USHORT
#define ADDR XADDR
TYPEDEF VOID XDATA *XPTR; 
 

#define INTERRUPT  __interrupt

#endif /* _TYPES_H_ */