#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc, char *argv[]){
	pid_t process;		//process to be killed
	int killsignum;	//signum = 9 for process kill
	printf("Enter process to be killed: ");
	if(argc < 2){
		perror("Usage: Enter process_id and signal number.\n");
		exit(1);
	}
	process = argv[1];
	killsignum = argv[2];
	if(kill(process, killsignum) == -1){
		perror("Kill error.\n");
		exit(1);
	}
	printf("signum: %d--->kills process %d \n", killsignum, process);
}
