#include <stdio.h>

void main(){
	fork();
	fork();
	fork();
	printf("[%d] hello parent [%d]\n", getpid(), getppid());
}
