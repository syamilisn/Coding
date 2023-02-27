/*
* Author     : Syamili S N
* Program    : p8_simpthread
* Description: simple thread program
*/


#include "run/headers.h"

void* display(){
	printf("[thread] Hi! today is a great day.\n");
	sleep(5);
}

int main(){
	pthread_t t1;
	pthread_create(&t1, NULL, &display, NULL);
	pthread_join(t1, NULL);		//waits till thread t1 terminates before continuing main thread.
	printf("main~");
	display();
	return 0;
}
