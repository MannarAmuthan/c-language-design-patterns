TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libmiddleware:	src/middleware.c
	$(CC) -g -O -c src/middleware.c
	ar rc libmiddleware.a middleware.o
	rm middleware.o

demo: main.c	libmiddleware.a
	$(CC) main.c -o demo libmiddleware.a

test:	tests/test.c	libmiddleware.a
	$(CC) tests/test.c -o test libmiddleware.a