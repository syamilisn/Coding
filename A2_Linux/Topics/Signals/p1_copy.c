/*
* Date       : 24-02-2023
* Program    : p1_defaultSigHandler
* Description: default signal handler
*/


#include "run/headers.h"
#include <time.h>
void handle_sigint(int num){
	write(STDOUT_FILENO, "sigint blocked!\n", 13);
}
void handle_sigquit(int num){
	write(STDOUT_FILENO, "sigquit blocked\n", 13);
}
int main()
{
	time_t secs=10, startTime = time(NULL);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	while (1)
	{
		printf("hello world\n");
		sleep(1);
		if (time(NULL) - startTime < secs)
			break;
	}
	return 0;
}
