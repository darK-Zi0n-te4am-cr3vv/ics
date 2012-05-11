# ---------------------------------------------------------------------------
# Имя проекта

NAME	= lab2

# Настройки компилятора и линкера

CC      = sdcc
CFLAGS  = -I./INCLUDE -c --stack-auto 
LFLAGS  = --code-loc 0x2100 --xram-loc 0x6000 --stack-auto --stack-loc 0xA0 

# Настройки системы автоинкремента версии сборки

PROJECT  = $(shell type PROJECT)
VERSION  = $(shell type VERSION)
BUILD    = $(shell type BUILD)
TYPE     = $(shell type TYPE)

# Настройки M3P

M3P		 = m3p
COMPORT	 = com1
COMLOG	 = $(COMPORT)_log.txt
BAUD	 = 9600	

# Каталоги с исходными текстами

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
$(SRC_DIR)/dip.c \
$(SRC_DIR)/ena.c \
$(SRC_DIR)/speaker.c \
$(SRC_DIR)/vector.c \
$(SRC_DIR)/music.c \
$(SRC_DIR)/timer.c \
$(SRC_DIR)/nointr.c \
$(SRC_DIR)/xdata.c 

LIST_OBJ = $(LIST_SRC:.c=.rel)

lab : $(LIST_OBJ) makefile
	$(CC) $(LIST_OBJ) -o lab2.hex $(LFLAGS)
	$(M3P) hb166 lab2.hex lab2.bin bye
	
$(LIST_OBJ) : %.rel : %.c makefile
	$(CC) -c $(CFLAGS) $< -o $@  

