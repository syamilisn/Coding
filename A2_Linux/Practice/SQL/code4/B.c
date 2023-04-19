// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10
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

	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1)
	{

	message.mesg_type = 1;
		printf("Write Data : ");
		printf("Write Data :\nID NAME DOMAIN LANG EXP\n");
		scanf("%d %s %s %s %d", &message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, &message.emp.expc);

		// msgsnd to send message
		msgsnd(msgid, &message, sizeof(message), 0);

		// display the message
		printf("Data send is : %d %s %s %s %d \n", message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);

		msgrcv(msgid,&message,sizeof(message),2,0);

		printf("Message recieved : %d %s %s %s %d \n", message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);
	}

	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}

