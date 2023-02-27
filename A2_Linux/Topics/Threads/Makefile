p1:
	gcc -g -pthread p1_thread.c -o p1.o
	./p1.o
p2:
	gcc -g -pthread p2_pvt.c -o p2.o
	./p2.o
p3:
	gcc p3_process.c -o p3.o 
	./p3.o
p4:
	gcc -g -pthread p4_racecond.c -o p4.o
	./p4.o
p5:
	gcc -g -pthread p5_mutex.c -o p5.o
	./p5.o

clean:
	rm -rf *.o
