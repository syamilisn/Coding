// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

// void* thread(void* arg)
void thread(char * prompt)
{
	//wait
	sem_wait(&mutex);
	printf("\n[%s] Entered..\n", prompt);

	//critical section
	sleep(4);
	
	//signal
	printf("\n[%s] Just Exiting...\n", prompt);
	sem_post(&mutex);
}


int main()
{
	sem_init(&mutex, 0, 1);     //2nd arg: If pshared is 0, the semaphore is shared among all threads of a process
	pthread_t t1,t2;
	pthread_create(&t1,NULL,(void *)thread,"t1~");
	sleep(2);
	pthread_create(&t2,NULL,(void *)thread,"t2~");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}
