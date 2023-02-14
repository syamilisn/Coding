#include "headers.h"
int main()
{	char prompt1[10] = "";
	char prompt2[10] = "\t\t";
	char *ptr_promptc1 = prompt1;
	char *ptr_promptc2= prompt1;
	printf("*******************************************************\n");
	printf("(PID: %d) (Root parent):\n", getpid());
	pid_t child1 = fork();
	pid_t child2 = fork();
	if (child1 == 0)
		ptr_promptc1 = prompt2;
	if (child2 == 0)
		ptr_promptc2 = prompt2;
	

	printf("\t(PID: %d) (PPID: %d) Hello I'm forked.\n", getpid(), getppid());
	printf("%s\t\t(PID: %d) (PPID: %d) (child 1) Process id: %d\n", ptr_promptc1, getpid(), getppid(), child1);
	printf("%s\t\t(PID: %d) (PPID: %d) (child 2) Process id: %d\n", ptr_promptc2, getpid(), getppid(), child2);
	printf("\t(PID: %d) ENDS ************\n", getpid());
	return 0;
}
