#include "header.h"

typedef struct Process{ 
	int pid; 
	int ppid;
}process;
void main(){
	process parent = {.pid = getpid(), .ppid = getppid()};
	printf("PPID: %d PID: %d PARENT\n", parent.ppid, parent.pid);
	fork();
	process child = {.pid = getpid(), .ppid = getppid()};
	printf("PPID: %d PID: %d CHILD\n", child.ppid, child.pid);
}
