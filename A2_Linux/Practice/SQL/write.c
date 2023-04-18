/*
 *	client A - Writer process
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
	printf("MEssage id =%d\n",msgid);
	message.mesg_type = 1;	//	send

	printf("Write Data :\nID NAME DOMAIN LANG EXP\n");
//	fgets(message.mesg_text,MAX,stdin);
	scanf("%d %s %s %s %d", &message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, &message.emp.expc);

	message.success = 0;	//default acknowledgment
	// msgsnd to send messag
	printf("name =%s\n",message.emp.name);
	status = msgsnd(msgid, &message, sizeof(message), 0);
	if(status == 0){
		// display the message
		//printf("Data send is : %s \n", message.mesg_text);
		printf("Data send is :\n %d %s %s %s %d\n", message.emp.empid, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);
		if(message.success == 0)	//	TESTING
		{
			printf("success = 0, NACK\n");
			printf("Message failed to be sent...!\n");
		}
		else
		{
			printf("success = 1, ACK\n");
			printf("Message sent successfully...!\n");
		}
	}
	else{
		perror("send failed");
	}
	return 0;
}

