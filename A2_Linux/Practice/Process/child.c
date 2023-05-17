#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
	for(int i=0; i<3; i++){
		if(fork() == 0)
			printf("[child~%d] hello %d \n", getpid(), getppid());
		//else
			//printf("[parent~%d] hello %d \n", getpid(), getppid());
		//wait(NULL);
	}
}
