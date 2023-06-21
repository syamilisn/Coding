#include <stdio.h>
#include <stdlib.h>
void main(){
	pid_t pid = fork();
	if (pid == 0)
		printf("[%d] child\n", getpid());
	else{
		wait(NULL);
		printf("[%d] parent\n", getpid());
	}

}
