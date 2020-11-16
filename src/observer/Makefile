TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

build:	publisher.c	subscriber.c
	$(CC) -g -O -c publisher.c subscriber.c
	ar rc libobserver.a publisher.o subscriber.o
	rm publisher.o subscriber.o

compile: main.c
	$(CC) main.c -o main libobserver.a
	rm	libobserver.a