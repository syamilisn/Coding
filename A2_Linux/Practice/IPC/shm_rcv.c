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
		printf("Rcvd mssg: %s\n", str);
		shmdt(str);
	}
	shmctl(sh_id, IPC_RMID, NULL);
	return 0;
}

