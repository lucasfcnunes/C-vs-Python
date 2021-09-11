SHELL = /bin/sh

EXECS = freq

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
	$< "    " || true
	$< "    oi"
	$< "    oi       oi    batata"
	$< "a"
	$< "oi oi tchau tchau não"
	$< "oi tchau     tchau não"
	$< "A aA a"
	# $<

