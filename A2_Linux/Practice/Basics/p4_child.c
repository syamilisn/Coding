#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){

	int value = 5;
	pid_t child = fork();
	if (child==0){
		value = value+15;
		return 0;
	}
	else if(child>0){	//parent
		wait(NULL);
		printf("[%d~parent] value=%d\n", getpid(), value );
		return 0;
	}
}
