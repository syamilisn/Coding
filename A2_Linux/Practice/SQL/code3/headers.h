//	common headers between client and server processes
//	message_type = 1; server
//	message_type = pid; client process id
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>

#define BUFFSIZE 100
const char     SEED  ='M';        // Common seed for ftok
const long int SERVER = 1L;         // Message type for server

typedef char string[30];

typedef struct employee{
	int id;
	string name;
}emp;

typedef struct message_buffer{
	long int msg_to;	//	receiver message_type
	long int msg_from;	//	sender message_type
	//emp details;	//	employee details to be sent to msg queue
	char buffer[BUFFSIZE];
}message;
