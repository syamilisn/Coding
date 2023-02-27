/*
* Author     : Syamili S N
* Program    : p2_orphanproc
* Description: demo orphan process
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
	else if(child == 0)	//child prints after sleeping 10 seconds
	{
		printf("[runningChild~PID: %d] I am child! Going to sleep for 10 seconds!\n", getpid());
		sleep(10);
		printf("[runningOrphanChild~PID: %d] I am orphan child! [newParent~PID: %d]!\n", getpid(), getppid());
	}
	else{			//parent is put to sleep while child finishes executing
		printf("[runningParent~PID: %d] I am parent! Finished last task! Exiting...\n", getpid());
	}
	return 0;
}
