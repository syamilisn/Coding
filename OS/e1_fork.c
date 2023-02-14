#include "headers.h"
int main(){
	int a = 0;
	if (fork() == 0) {
		printf("Before--> child (PID: %d) %d, %d\n", getpid(), a, &a);
		a += 5;
		printf("After--> child (PID: %d) %d, %d\n", getpid(), a, &a);
		printf("child (PID: %d) %d, %d\n", getpid(), a, &a);
	}
	else {
		printf("Before-->(PID: %d) %d, %d\n", getpid(), a, &a);
		a -= 5;
		printf("After-->(PID: %d) %d, %d\n", getpid(), a, &a);
	}
	return 0;
}
