CC = gcc

BUILD_DIR = build/

CFLAGS = -I -Wall

LFLAGS =

SRC = lzw.c compress.c extract.c table.c

TARGET = lzw

build: ${SRC}
	${CC} ${CFLAGS} ${LFLAGS} ${SRC} -o ${BUILD_DIR}${TARGET}

clean:
	rm ${BUILD_DIR}*

.PHONY: build clean
