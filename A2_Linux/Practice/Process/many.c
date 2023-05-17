#include <stdio.h>
#include <unistd.h>
#define MAX_PROC 3
int main(){
	int a[MAX_PROC];
	for(int i=0; i<MAX_PROC; i++){
		a[i] = fork();
		//if(a[i] == 0){
		{
			printf("[child~%d] \n", getpid());
			printf("[parent~%d] \n", getppid());
			break;
		}
	}
	while(1);
}
