#include <stdio.h>
#include <stdlib.h>
int main(){
	int pid, status, temp;
	pid = fork();
	if(pid == 0)
		printf("[child]: pid=%d executing; status=%d...\n", pid, temp);
	else
		printf("[parent]: pid=%d executing; status=%d...\n", pid, temp);
	temp = wait(&status);

	if(temp == -1)
		printf("[child]: pid=%d executing; status=%d...FORKING ENDS\n", pid, temp);
	else
		printf("[parent]: pid=%d executing; status=%d...PROCESS ENDS\n", pid, temp);
	return 0;	
}
