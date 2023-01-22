#include "header.h"
void main(){
	system("date");
	printf("Process id : %d\n", getpid());
	printf("Parent process id : %d\n", getppid());
	printf("**************************************\n");
	system("ps -f");
	fork();
	system("ps -f");
	printf("Hello");
}
