/*
 *	client B - Reader process
 */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 100

typedef char string[100];

// structure for employee
struct emp_details{
        int empid;
        string name;
        string domain;
        string lang;
        int expc;
};

// structure for message queue
struct mesg_buffer {
	int mesg_type;
//	char mesg_text[100];
	int success;
	struct emp_details emp;
} message;

int main()
{
	key_t key;
	int msgid;
	int status;

	// ftok to generate unique key
	key = ftok("progfile", 65);

	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	//message.mesg_type = 2;	//	receive
	printf("Message id = %d\n",msgid);
	// msgrcv to receive message
	status = msgrcv(msgid, &message, sizeof(message), 1, 0);

	if(status == 0){
		// display the message
		printf("Data received is :\n %d %s %s %s %d\n", message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);
		message.success = 1;
	}
	else{
		printf("rcv_status = %d\n", status);
		perror("received failed");
	}
	// to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}

