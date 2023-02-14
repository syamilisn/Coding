#include "headers.h"
int main(){
	pid_t pid = fork();
	if (pid < 0){
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if	(pid == 0){
		execlp("/bin/ls", "ls", NULL);
	}
	else{
		wait(NULL);	//Parent waits till child terminates.
		printf("child complete!\n");
	}
	return 0;
}
