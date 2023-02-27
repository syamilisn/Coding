/*
* Date       : 27-02-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : p1_thread
* Description: basic thread program
*
* pthread_join: to prevent termination of a process before its threads.
*/


#include "run/headers.h"

void* display(){
	printf("Displaying with thread.\n");
	sleep(3);
	printf("Ending thread.\n");
}

int main(){
	pthread_t t1, t2;
	int status1, status2;
	status1 = pthread_create(&t1, NULL, &display, NULL);
	status2 = pthread_create(&t2, NULL, &display, NULL);
	if(status1 != 0){
		printf("Thread 1 creation unsuccessful.\n");
		return 1;
	}
	else 
		printf("Thread 1 creation successful.\n");

	if(status2 != 0){
		printf("Thread 2 creation unsuccessful.\n");
		return 1;
	}
	else 
		printf("Thread 2 creation successful.\n");

	if(pthread_join(t1, NULL) != 0)
		printf("Thread 1 joining unsuccessful.\n");

	if(pthread_join(t2, NULL) != 0)
		printf("Thread 2 joining unsuccessful.\n");
	return 0;
}
