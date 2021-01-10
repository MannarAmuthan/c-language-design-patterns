TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libstate:	src/state.c
	$(CC) -g -O -c src/state.c
	ar rc libstate.a state.o
	rm state.o

demo: main.c	libstate.a
	$(CC) main.c -o demo libstate.a

test:	tests/test.c	libstate.a
	$(CC) tests/test.c -o test libstate.a