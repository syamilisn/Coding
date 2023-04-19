clean:
	rm -rf *.o

client:
	gcc client.c -o  client.o
	./client.o

server:
	gcc server.c -o server.o
	./server.o server.o 19 &

