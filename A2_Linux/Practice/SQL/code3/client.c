//	client process
#include "headers.h"
int main(){
	printf("**************************************************\n");
	int status, n;
	message msg;
	static char m_key[10];
	pid_t client_pid = getpid();
	key_t key;
	if ((key = ftok(".", SEED)) == -1) { 	//	1. generate key
		perror("1_Client: key generation");
		return 1;
	}
	if(status = msgget(key, 0) == -1 ){	//	2. create queue if not present
		status = msgget(key, IPC_CREAT | 0660);
		switch(fork()){
			case -1:
				perror("2_Client: fork");
				return 2;
			case 0:
				sprintf(m_key, "%d", status);	//	3. string: pass message queue ID as string to server via command line
				execlp("./server.o", "server.o", m_key, "&",(char*)NULL);
				perror("3_Client: exec");
				return 3;
		}
	}
	while(1){
		msg.msg_to = SERVER;
		msg.msg_from = client_pid;		//	4.	label client process
		write(fileno(stdout), "cmd> ", 6);	//	returns  the  integer file descriptor used to implement a particular stream
		memset(msg.buffer, 0x0, BUFFSIZE);	//	fill memory with a constant byte
		if((n=read(fileno(stdin), msg.buffer, BUFFSIZE)) == 0)
			break;
		n += sizeof(msg.msg_from);		//	5.	msg size =  (size of 2nd member as 1st is assumed) + (# o bytes in msg)
		if(msgsnd(status, &msg, n, 0) == -1){
			//			printf("[%d] ", getpid());
			perror("4_Client: msgsnd");
			return 4;
		}
		
		if((n=msgrcv(status, &msg, BUFFSIZE, client_pid, 0)) != -1)
			write(fileno(stdout), msg.buffer, n);	//6.	server will pause, waiting for msgs to be added to queue. Once retrieved it is written to standard output 
	}
	msgsnd(status, &msg, 0, 0);

	return 0;
}
