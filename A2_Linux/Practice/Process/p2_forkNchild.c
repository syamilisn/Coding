#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
	int process;
	if(fork() == 0){
	sleep(5);
		printf("[fork1~%d] Hello %d \n", getpid(), getppid());
		exit(0);}
	if(fork() == 0){
	sleep(5);
		printf("[fork2~%d] Hello %d \n", getpid(), getppid());
		exit(0);}
	if(fork() == 0){
	sleep(5);
		printf("[fork3~%d] Hello %d \n", getpid(), getppid());
		exit(0);}
	//printf("[%d] Hello\n", getpid());
	wait(NULL);
	wait(NULL);
	wait(NULL);
}
