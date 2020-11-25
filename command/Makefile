TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libcommand:	src/command.c
	$(CC) -g -O -c src/command.c
	ar rc libcommand.a command.o
	rm command.o

demo: main.c	libcommand.a
	$(CC) main.c -o demo libcommand.a

test:	tests/test.c	libcommand.a
	$(CC) tests/test.c -o test libcommand.a