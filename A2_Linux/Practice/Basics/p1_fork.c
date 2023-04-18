#include <stdio.h>
#include <stdlib.h>
int main(){
	int pid;
	pid = fork();
	if(pid == 0)
		printf("[child]: pid=%d executing; status=...\n", pid);
	else
		printf("[parent]: pid=%d executing; status=...\n", pid);

	if(pid == 0)
		printf("[child]: pid=%d executing; status=...PROCESS ENDS\n", pid);
	else
		printf("[parent]: pid=%d executing; status=...PROCESS ENDS\n", pid);
	return 0;	
}
