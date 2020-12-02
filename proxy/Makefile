TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libproxy:	src/proxy.c
	$(CC) -g -O -c src/proxy.c
	ar rc libproxy.a proxy.o
	rm proxy.o

demo: main.c	libproxy.a
	$(CC) main.c -o demo libproxy.a

test:	tests/test.c	libproxy.a
	$(CC) tests/test.c -o test libproxy.a