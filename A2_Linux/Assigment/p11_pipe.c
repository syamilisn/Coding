/*
* Author     : Syamili S N
* Program    : p11_pipe
* Description: demo pipe
*/


#include "run/headers.h"


int main()
{
	int pid;
	
	int fd[2];
	
	pipe(fd);
	
	pid = fork();
	
	if(pid==0)
	{
		//child process to send data through pipe
		
		printf("Child process id = %d",getpid());
		printf("Writing the data : hi there \n");
		write(fd[1],"hi there",8);
		printf("Data written and exiting child process\n");
	}	
	else 
	{
		//parent process to recive data from child
		char buffer[50]={0};
		printf("\nParent process id = %d\n",getpid());
		printf("Reading the data from the pipe\n");
		read(fd[0],buffer,8);
		printf("Read data = %s\n",buffer);
		printf("Exiting parent process\n");
	}
	return 0;
}
