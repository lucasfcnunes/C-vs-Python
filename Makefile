SHELL = /bin/sh

EXECS = freq_exemplo

OBJS = $(EXECS).c
CFLAG = -Wall -g
CC = gcc
INCLUDE =
LIBS = -lm

OUTPUT_PATH = bin/main

.PHONY: ${OUTPUT_PATH}
${OUTPUT_PATH}: ${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

test: ${OUTPUT_PATH}
	$< "  OI "
	$< "oi oi tchau tchau não"
	$< "oi tchau     tchau não"
	# $<

