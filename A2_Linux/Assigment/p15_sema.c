/*
* Author     : Syamili S N
* Program    : p15_sema
* Description: demo semaphores
command to run gcc -pthread p15_sema.c -o p15_sema
*/


#include "run/headers.h"

#include<pthread.h>
#include<semaphore.h>

sem_t sem1,sem2;
void *worker1(void *arg)
{
	while(1)
	{
		sem_wait(&sem1);
		printf("Worker1 acquired semaphore\n");
		sleep(1);
		sem_post(&sem2);
	}
}

void *worker2(void *arg)
{
	while(1)
	{
		sem_wait(&sem2);
		printf("Worker2 acquired semaphore\n");
		sleep(1);
		sem_post(&sem1);
	}
}

int main()
{
	pthread_t threads[2];
	
	
	sem_init(&sem1,0,1);
	sem_init(&sem2,0,1);
	pthread_create(&threads[0],NULL,worker1,NULL);
	pthread_create(&threads[1],NULL,worker2,NULL);
	
	for(int i=0;i<2;i++)
	{
		pthread_join(threads[i],NULL);
	}
	
	sem_destroy(&sem1);
	sem_destroy(&sem2);
	
	return 0;
}

