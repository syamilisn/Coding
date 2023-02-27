/*
* Author     : Syamili S N
* Program    : p2_isr
* Description: send pause and raise signal to the interrupt service routine
*/


#include "run/headers.h"

void sig_handler(int sig) {
	printf("Received signal %d\n", sig);
}

int main() {
	pid_t pid;
	signal(SIGINT, sig_handler);
	pid = fork();

    	if (pid == -1) 
    	{
        	perror("fork");
        	exit(1);
    	} 
    	else if (pid == 0)
    	{
        	while (1){
			if (pid == 0)
			{printf("[child~PID: %d]\n", pid);}
			else
			{printf("[parent~PID: %d]\n", pid);}
           	 sleep(1);
        }
    } 
    else 
    {
        sleep(3);
        printf("[childpause~PID: %d]\n", pid);
        kill(pid, SIGSTOP);

        sleep(3);
        printf("[childresume~PID: %d]\n", pid);
        kill(pid, SIGCONT);

        sleep(3);
        printf("[childkill~PID: %d]\n", pid);
        kill(pid, SIGTERM);
    }

    return 0;
}

