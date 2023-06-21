#include <stdio.h>
#include <stdlib.h>

void main(){
	pid_t pid;
	pid = fork();
	pid = fork();
	pid = fork();
	if(pid != 0)
	printf("HI\n");
}
