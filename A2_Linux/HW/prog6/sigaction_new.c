/*
* Date       : 24-02-2023
* Program    : sigaction_new
* Description: implements new action
*/


#include "../run/headers.h"

void handler(int signum) {
    printf("Received signal %d\n", signum);
    exit(0);
}
int main()
{
   	 struct sigaction sa;
   	 sa.sa_handler = handler;
   	 sigemptyset(&sa.sa_mask);
   	 sa.sa_flags = 0;

    	if (sigaction(SIGINT, &sa, NULL) == -1) {
        	perror("sigaction");
        	return 1;
    	}
	
    	printf("Waiting for SIGINT...\n");
    	while(1) {}
	return 0;
}
