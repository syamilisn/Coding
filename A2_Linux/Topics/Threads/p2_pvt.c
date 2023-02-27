/*
* Date       : 27-02-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : p2_pvt
* Description: process vs thread
*
* Threads			vs 			Process
* *******************************************************************************
* 1. share memory			1. own memory space
* 2. share process id			2. unique process id
*/


#include "run/headers.h"
int x = 2;
void* display(){
	x++;
	sleep(2);
	printf("thread1~[PID: %d] x = %d\n", getpid(), x);
}

void* display2(){
	sleep(2);
	printf("thread2~[PID: %d] x = %d\n", getpid(), x);
}
int main(){
	pthread_t t1, t2;
	printf("process~[PID: %d] Main process\n", getpid());
	pthread_create(&t1, NULL, &display, NULL);
	pthread_create(&t2, NULL, &display, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
