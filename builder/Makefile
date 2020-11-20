TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libbuilder:	src/StringBuilder.c
	$(CC) -g -O -c src/StringBuilder.c
	ar rc libbuilder.a StringBuilder.o
	rm StringBuilder.o

demo: main.c	libbuilder.a
	$(CC) main.c -o demo libbuilder.a

test:	tests/test.c	libbuilder.a
	$(CC) tests/test.c -o test libbuilder.a