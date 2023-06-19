#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
	pid_t process;
	process = fork();
	//process = fork();
	//process = fork();
	if(process == 0){
		sleep(10);
		printf("[child~%d] Hello\n", getpid());
	}
	else
		printf("[parent~%d] Hello\n", getpid());
}
