TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libobserver:	src/publisher.c	src/subscriber.c
	$(CC) -g -O -c src/publisher.c src/subscriber.c
	ar rc libobserver.a publisher.o subscriber.o
	rm publisher.o subscriber.o

demo: main.c	libobserver.a
	$(CC) main.c -o demo libobserver.a

test:	tests/test.c	libobserver.a
	$(CC) tests/test.c -o test libobserver.a
