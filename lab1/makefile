# ---------------------------------------------------------------------------
# ��� �������

NAME	= lab1

# ��������� ����������� � �������

CC      = sdcc
CFLAGS  = -I./INCLUDE -c --stack-auto
LFLAGS  = --code-loc 0x2100 --xram-loc 0x6000 --stack-auto --stack-loc 0x80 

# ��������� ������� �������������� ������ ������

PROJECT  = $(shell type PROJECT)
VERSION  = $(shell type VERSION)
BUILD    = $(shell type BUILD)
TYPE     = $(shell type TYPE)

# ��������� M3P

M3P		 = m3p
COMPORT	 = com1
COMLOG	 = $(COMPORT)_log.txt
BAUD	 = 9600	

# �������� � ��������� ��������

SRC_DIR = SRC
# ---------------------------------------------------------------------------

all: lab

clean:
	del *.hex
	del *.bin
	del *.map
	del *.mem
	del *.lnk
	del pm3p_*.txt
	del com?_log.txt
	del $(SRC_DIR)\*.asm
	del $(SRC_DIR)\*.rel
	del $(SRC_DIR)\*.rst
	del $(SRC_DIR)\*.sym
	del $(SRC_DIR)\*.lst 

load:
	$(M3P) lfile load.m3p

LIST_SRC = \
$(SRC_DIR)/entry.c \
$(SRC_DIR)/led.c \
$(SRC_DIR)/nointr.c \
$(SRC_DIR)/dip.c \
$(SRC_DIR)/xdata.c 

LIST_OBJ = $(LIST_SRC:.c=.rel)

lab : $(LIST_OBJ) makefile
	$(CC) $(LIST_OBJ) -o lab1.hex $(LFLAGS)
	$(M3P) hb166 lab1.hex lab1.bin bye
	
$(LIST_OBJ) : %.rel : %.c makefile
	$(CC) -c $(CFLAGS) $< -o $@  

