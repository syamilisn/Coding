#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
	pid_t process;
	process = fork();
	process = fork();
	process = fork();
	printf("[%d] Hello\n", getpid());
}
