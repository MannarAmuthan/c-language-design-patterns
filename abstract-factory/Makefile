TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libfactory:	src/factory.c
	$(CC) -g -O -c src/factory.c
	ar rc libfactory.a factory.o
	rm factory.o

demo: main.c	libfactory.a
	$(CC) main.c -o demo libfactory.a

test:	tests/test.c	libfactory.a
	$(CC) tests/test.c -o test libfactory.a