//	server process
#include "headers.h"

void process_msg(char *b, int len){
	// function to convert lowercase alphabets to uppercase
	for(int i=0; i<len; ++i)
		if(isalpha(*(b+i)))*(b+i) = toupper(*(b+i));
}
int main(int argc, char *argv[]){
        printf("**************************************************\n");
	int status, n;
	message msg;
	//	1. check #o cmd-line args
//	void process;
	if(argc !=3){
	//	printf("1_Server Usage: %s msq_id &\n", argv[0]);
		perror("Usage: insufficent cmd-line args...");
		return 1;
	}
	status = atoi(argv[1]);		// 	converts string(initial part) to int
	while(1){
	//	2. retrieve msg from que; wait if no message present
		memset(msg.buffer, 0x0, BUFFSIZE);
		if((n=msgrcv(status, &msg, BUFFSIZE, SERVER, 0)) == -1){
			perror("2_Server: msgrcv");
			return 2;
		}
	//	3. if zero-length msg, exit loop
		else if(n==0) break;
		process_msg(msg.buffer, strlen(msg.buffer));
		msg.msg_to = msg.msg_from;
		msg.msg_from = SERVER;
		n += sizeof(msg.msg_from);
	//	4. reassign to and from fields for message. Process msg and put back in que
		if(msgsnd(status, &msg, n, 0) == -1 ){
			perror("3_Server: msgsnd");
			return 3;
		}
	}
	//	5. remove the message queue
	msgctl(status, IPC_RMID, (struct msqid_ds *) 0);
	return 0;
}
