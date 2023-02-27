/*
* Author     : Syamili S N
* Program    : p14_shm
* Description: demo shared message
*/


#include "../run/headers.h"
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	key_t key;
	
	int sh_id;
	char *str;
	
	key = ftok("shfile",65);
	
	sh_id  = shmget(key,1024,0666|IPC_CREAT);
	
	while(1)
	{
		char *str = (char*) shmat(sh_id,(void*)0,0);
		
		printf("Enter the data to send\n");
		fgets(str,30,stdin);
		
		shmdt(str);
	}
	return 0;
}

