#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	pid_t pid;
	int signum;
	if(argc < 3){
		printf("Enter process id and signum (Eg: 9 to kill signal)");
		perror("usage");
		exit(1);
	}
	pid = atoi(argv[1]);
	signum = atoi(argv[2]);
	if(kill(pid, signum) != 0){
		perror("kill");
		exit(1);
	}
	return 0;
}
