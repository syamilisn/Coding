all:
	gcc p1_killcmd.c -o p1.o -Wall
	gcc p2_isr.c -o p2.o -Wall
	gcc p3_alarm.c -o p3.o -Wall
	gcc p4_disablesig.c -o p4.o -Wall
	gcc p5_sigkill.c -o p5.o -Wall
	gcc p678_sigaction.c -o p6.o -Wall
	gcc p9_filesize.c -o p9.o -Wall

p1:
	gcc p1_killcmd.c -o p1.o -Wall
	./p1.o

clean:
	rm -rf *.o
