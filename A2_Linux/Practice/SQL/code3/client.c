//	client process
#include "headers.h"
int main(){
	printf("**************************************************\n");
	int status;
	pid_t client_pid = getpid();
	key_t key = ftok("progfile", 65);
	if ((key = ftok(".", SEED)) == -1) { 
		perror("Client: key generation");
		return 1;
	}
	if(status = msgget(key, 0) == -1 ){
		status = msgget(key, IPC_CREAT | 0660);
		switch(fork()){
			case -1:
				perror("client: fork");
				return 2;
			case 0:
				sprintf(m_key, "%d", status);
	return 0;
}
