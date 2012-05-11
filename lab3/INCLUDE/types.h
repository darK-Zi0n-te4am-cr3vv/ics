#ifndef _TYPES_H_
#define _TYPES_H_

#define VOLATILE volatile
#define TYPEDEF typedef
 
#define XDATA xdata
#define CONST const

#define VOID void

#define STATIC static
#define PRIVATE static

/* 8 bit types */
#define BYTE unsigned char
#define SBYTE signed char

#define CHAR char
#define BOOL BYTE

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
#define SIZE USHORT 

#define NULL ((VOID*)0)

#define FALSE 0
#define TRUE 1

#endif /* _TYPES_H_ */