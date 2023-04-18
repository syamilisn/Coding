#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void main(){
	pid_t process;		//process to be killed
	int killsignum=9;	//signum = 9 for process kill
	printf("Enter process to be killed: ");
	scanf("%d", &process);
	if(kill(process, killsignum) == -1){
		perror("Usage: Kill a background process by entering its process_id and signal\n");
		exit(1);
	}
	printf("signum: %d--->kills process %d \n", killsignum, process);
}
