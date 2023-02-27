/*
* Date       : 27-02-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : p3_process
* Description: difference b/w process and thread [see p2_pvt.c]
*/


#include "run/headers.h"


int main(){
	printf("[parent~PID: %d]\n*******************\n", getpid());
	int x = 2;
	pid_t pid = fork();
	if (pid < 0)
		printf("[parent~PID:%d] fork failed! child not created.\n", getpid());
	else if(pid == 0){
		x++;
		printf("[child~PID: %d] x = %d\n", getpid(), x);
	}
	else{
		wait();
		printf("[parent~PID: %d] x = %d\n", getpid(), x);
	}
	return 0;
}
