/*
* Author     : Syamili S N
* Program    : p1_killcmd
* Description: implement kill command
*/


#include "run/headers.h"

int main(){
	printf("[current process~PID : %d]\n", getpid());
	pid_t pid;
	printf("Enter process id: \n");
	scanf("%d", &pid);
	int signum;
	printf("Enter signal num: \n");
	scanf("%d", &signum);

	if(kill(pid, signum) == -1){
		perror("kill");
		exit(1);
	}

	printf("[signal : %d -----> process : %d\n", signum, pid);
	return 0;
}
