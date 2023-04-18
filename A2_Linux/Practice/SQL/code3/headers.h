//	common headers between client and server processes
//	message_type = 1; server
//	message_type = pid; client process id
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef char string[30];

typedef struct employee{
	int id;
	string name;
}emp;

typedef struct message_buffer{
	int msg_to;	//	receiver message_type
	int msg_from;	//	sender message_type
	emp details;	//	employee details to be sent to msg queue
}message;
