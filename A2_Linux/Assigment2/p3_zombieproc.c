/*
* Author     : Syamili S N
* Program    : p3_zombieproc
* Description: demo zombie process
*/


#include "run/headers.h"

int main(){
	printf("[Parent~PID: %d]\n", getpid());
	pid_t child = fork();
	
	if(child < 0)
	{
		fprintf(stderr, "fork failed!!\n");
		return 1;
	}
	else if(child == 0)	//child prints and terminates
	{
		printf("[runningChild~PID: %d] I am child!\n", getpid());
	}
	else{			//parent is put to sleep while child finishes executing
		printf("[runningParent~PID: %d] I am parent!\n", getpid());
		sleep(10);
	}
	return 0;
}
