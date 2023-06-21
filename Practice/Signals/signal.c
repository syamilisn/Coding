#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
	void sig_handler(int sig){
		printf("calling handler for signal %d\n", sig);
	}
int main(){
	signal(SIGINT, sig_handler);
	pid_t pid = fork();
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
		return 0;
}
