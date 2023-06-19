CC=gcc
CFLAGS=-c -Wall
all:prog

prog: p16.o p17.o
	$(CC) p16.o p17.o -o prog
	gcc p15_ifndef.c -o p15.o -Wall
p16.o: p16_header.h
	$(CC) $(CFLAGS) p16_header.h

p17.o: p17_call.c
	$(CC) $(CFLAGS) p17_call.c
p18:
	gcc p18_storageclass.c -o p18.o
	./p18.o
p19:
	gcc -g p19_stringpattern.c -o p19.o
	./p19.o

p1:
	gcc -g -o p1_helloWorld p1_helloWorld.c
	./p1_helloWorld
test:
	gcc -g -rdynamic Test.c -o Test
	./Test

clean:
	rm -rf *.o
