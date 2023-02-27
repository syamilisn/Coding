/*
* Date       : 24-02-2023
* Program    : p1_defaultSigHandler
* Description: default signal handler
*/


#include "run/headers.h"
void handle_sigint(int num){
	//write(STDOUT_FILENO, "sigint blocked!\n", 13);
}
void handle_sigquit(int num){
	//write(STDOUT_FILENO, "sigquit blocked\n", 13);
}
int main()
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	int sec=1;
	while (1)
	{
		printf("hello world\n");
		sleep(1);
		if(sec <= 10)
		{
			sec++;
		}
		else
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
		}
	}
	return 0;
}
