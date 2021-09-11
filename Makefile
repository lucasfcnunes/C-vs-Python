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
	$< "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" || true
	$< "A B C D E F G H I J K L M N O P Q R S T U V X W Y Z a b c d e f g h i j k l m n o p q r s t u v x w y z" || true
	$< "A B C D E F G H I J K L M N O P Q R S T U V X W Y Z a b c d e f g h i j k l m n o" || true
	$< "A B C D E F G H I J K L M N O P Q R S T U V X W Y Z a b c d e f g h i j k l m n "
	$< "    oi"
	$< "    oi       oi    batata"
	$< "a"
	$< "oi oi tchau tchau não"
	$< "oi tchau     tchau não"
	$< "A aA a"
	$< "    oi       oi    batata                          "
	# $<

