/*
* Author     : Syamili S N
* Program    : p1_fork
* Description: return value of fork
*/


#include "run/headers.h"

int main(){
	printf("[Parent~PID:%d]\n", getpid());
	pid_t processid = fork();
	if (processid == 0)	//fork() returns zero for child process (child running)
		printf("[runningChild~PID:%d]\n", getpid());
	else if (processid < 0)	//fork() failed
	{
		fprintf(stderr, "Fork failed!!\n");
		return 1;
	}
	else			//fork() returns child process id to parent (parent running)
		printf("[runningParent~PID:%d]\n", getpid());
	printf("[PID: %d] Hello World!!\n", getpid());
	return 0;
}
