CC = gcc

CPPFLAGS += -D _GNU_SOURCE

CFLAGS = -Wall -Werror -g -std=gnu11 -pthread

all: main

main: main.c
	${CC} ${CPPFLAGS} ${CFLAGS} -o thread main.c