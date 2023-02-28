/*
* Date       : 28-02-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : p6_semaphore
* Description: semaphore: synchronization mechanism
*
* 	#include <semaphore.h>
*
* 	sem_init(address, proc_shared?:(0 or 1), initial_val);
*/


#include "run/headers.h"
#define THREAD_NUM 4

sem_t semaphore;

void *routine(void *args){
	//simulates mutex behavior					//[initially] s=1
	sem_wait(&semaphore);		//s--;				//[decrease ] s=0
									/*Critical section begins*/
	sleep(1);
	printf("[thread_%d] Hello from thread!\n", *(int*)args );
									/*Critical section ends*/
	sem_post(&semaphore);		//s++;				//[increase ] s=1
	free(args);
}

int main(int argc, char *argv[]){
	pthread_t th[THREAD_NUM];
	sem_init(&semaphore, 0, 2);
	
	for(int i=0; i < THREAD_NUM; i++){
		int *a = malloc(sizeof(int));
		*a = i;
		if(pthread_create(&th[i], NULL, &routine, a) != 0){
			perror("Failed to create thread.\n");
		}
	}
	for(int i=0; i < THREAD_NUM; i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed to join thread.\n");
		}
	}
	sem_destroy(&semaphore);
	return 0;
}
