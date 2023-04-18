#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int c, char* v[]){
	int pid, status;
	pid = fork();
	if(pid == 0)
		printf("[child]: pid=%d executing; status=...\n", pid);
	else
		printf("[parent]: pid=%d executing; status=...\n", pid);

	if(pid == 0)
	{	//Child executes external file
		printf("[child]: pid=%d executing; status=...PROCESS ENDS\n", pid);
		execl("Files/hello.o", v[0], NULL);
		printf("\n\n");
	}
	else
		printf("[parent]: pid=%d executing; status=...PROCESS ENDS\n", pid);

	return 0;	
}
