/*
* Author     : Syamili S N
* Program    : p4_exit
* Description: remove zombie state of process using exit()/ _exit()
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
		exit(0);
	}
	else{			//parent is put to sleep while child finishes executing
		printf("[runningParent~PID: %d] I am parent!\n", getpid());
		sleep(60);
	}
	return 0;
}
