// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
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
	long mesg_type;
	int success;
	struct emp_details emp;
} message;

int main()
{
	key_t key;
	int msgid;

	// ftok to generate unique key
	key = ftok("progfile", 65);

		msgid = msgget(key, 0666 | IPC_CREAT);
	// msgget creates a message queue
	// and returns identifier
	while(1)
	{

	// msgrcv to receive message
		msgrcv(msgid, &message, sizeof(message), 1, 0);

	// display the message
		printf("Data Received is : %d %s %s %s %d \n", message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);


		//fetch the data
		message.mesg_type = 2;
		message.success =1;
		printf("Write Data :\nID NAME DOMAIN LANG EXP\n");
		scanf("%d %s %s %s %d", &message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, &message.emp.expc);
		//else if not found success = 0
		msgsnd(msgid,&message,sizeof(message),0);
	}
	// to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}

