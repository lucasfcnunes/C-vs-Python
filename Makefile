SHELL = /bin/sh

OBJS = freq.c
CFLAG = -Wall -g
CC = gcc
INCLUDE =
LIBS = -lm

OUTPUT_PATH = bin

# .PHONY: freq
freq: ${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o ${OUTPUT_PATH}/$@ ${OBJS} ${LIBS}

test: ${OUTPUT_PATH}/freq
	$< ""
	$< "oi oi tchau tchau não"
	$< "oi tchau tchau não"

