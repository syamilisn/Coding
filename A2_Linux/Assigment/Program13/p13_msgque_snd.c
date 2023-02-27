/*
* Author     : Syamili S N
* Program    : p13_msgque
* Description: demo message queue

send msg via message queue
*/


#include "../run/headers.h"

#include<sys/msg.h>
#include<sys/ipc.h>


struct msg_buffer
{
	long m_type;
	char m_data[100];
}message;
int main()
{
	key_t key;
	int m_id;
	
	key = ftok("testfile1",65);
	m_id = msgget(key,0666|IPC_CREAT);
	message.m_type = 1;
	
	while(1)
	{
		printf("Enter data to send \n");
		fgets(message.m_data,30,stdin);
		
		msgsnd(m_id,&message,sizeof(message),0);
	}
	return 0;
}
