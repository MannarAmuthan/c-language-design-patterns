TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libcoffeemaker:	src/coffeemaker.c
	$(CC) -g -O -c src/coffeemaker.c
	ar rc libcoffeemaker.a coffeemaker.o
	rm coffeemaker.o

demo: main.c	libcoffeemaker.a
	$(CC) main.c -o demo libcoffeemaker.a

test:	tests/test.c	libcoffeemaker.a
	$(CC) tests/test.c -o test libcoffeemaker.a