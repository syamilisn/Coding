#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int c, char* v[]){
	int fd[2];
	pid_t child;
	char buf;
	if(c != 2){
		printf("Usage: %s <string>\n", v[0]);
		exit(EXIT_FAILURE);
	}
	if(pipe(fd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	child = fork();
	if(child == -1){
		printf("Usage: %s <string>\n", v[0]);
		exit(EXIT_FAILURE);
	}
	if(child == 0){	//child process
		close(fd[1]);	//close write end of pipe
		while(read(fd[0], &buf, 1) >0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(fd[0]);
		exit(EXIT_SUCCESS);
	}

	else{		//parent process
		close(fd[0]);	//close parent read
		write(fd[1], v[1], strlen(v[1]));	//parent write
		close(fd[1]);	//EOF
		wait(NULL);	//wait child
		exit(EXIT_SUCCESS);
	}	

	return 0;
}
