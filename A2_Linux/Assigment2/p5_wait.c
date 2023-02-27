/*
* Author     : Syamili S N
* Program    : p5_wait
* Description: remove zombie state of process using wait()/ _waitpid()
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
		//wait(NULL);
		waitpid(child, NULL, 0);
		printf("[runningParent~PID: %d] I am parent!\n", getpid());
		sleep(5);
		printf("[awakeParent~PID: %d] Parent exiting...\n", getpid());
	}
	return 0;
}
