#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/shm.h>

int main(){

	key_t key = ftok("shfile", 65);
	size_t size = 1024;
	int shmflg = 0666|IPC_CREAT;
	int sh_id = shmget(key, size, shmflg);
	while(1){
		char *str = (char *) shmat(sh_id, (void *)0, 0);
		printf("Send mssg: \n");
		fgets(str, 30, stdin);
		shmdt(str);
	}

	return 0;
}

