p1:
	gcc p1_fork.c -o p1.o -Wall
	./p1.o
p2:
	gcc p2_orphanproc.c -o p2.o -Wall
	./p2.o
p3:
	gcc p3_zombieproc.c -o p3.o -Wall
	./p3.o
p4:
	gcc p4_exit.c -o p4.o -Wall
	./p4.o
p5:
	gcc p5_wait.c -o p5.o -Wall
	./p5.o
p6:
	gcc p6_setjmp.c -o p6.o -Wall
	./p6.o
p7:
	gcc p7_fcntl.c -o p7.o -Wall
	./p7.o simple.txt
p8:
	gcc -g -pthread p8_simpthread.c -o p8.o
	./p8.o
p9:
	gcc -g -pthread p9_thread.c -o p9.o
	./p9.o
p12:
	gcc -g -pthread p12_mutex.c -o p12.o
	./p12.o


clean:
	rm -rf *.o
