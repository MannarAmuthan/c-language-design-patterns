TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libnull:	src/user.c
	$(CC) -g -O -c src/user.c
	ar rc libnull.a user.o
	rm user.o

demo: main.c	libnull.a
	$(CC) main.c -o demo libnull.a

test:	tests/test.c	libnull.a
	$(CC) tests/test.c -o test libnull.a