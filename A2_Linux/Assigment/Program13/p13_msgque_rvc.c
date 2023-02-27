/*
* Author     : Syamili S N
* Program    : p13_msgque
* Description: demo message queue

rcv msg via message queue
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
	
	
	while(1)
	{	
		msgrcv(m_id,&message,sizeof(message),1,0);
		printf("Data recived = %s\n",message.m_data);
	}
	return 0;
}
