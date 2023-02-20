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
clean:
	rm -rf *.o
