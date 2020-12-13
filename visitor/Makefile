TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

libvisitor:	src/visitor.c
	$(CC)	-g -O -c src/visitor.c
	ar	rc	libvisitor.a	visitor.o
	rm	visitor.o

demo: main.c	libvisitor.a
	$(CC)	main.c -o demo libvisitor.a

test:	tests/test.c	libvisitor.a
	$(CC)	tests/test.c -o	test	libvisitor.a