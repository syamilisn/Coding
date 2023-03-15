/*
* Author     : Syamili S N
* Program    : p11_procsync
* Description: demo synchronization concept
*/


#include "run/headers.h"

#define THREAD_NUM 4

sem_t semaphore;

void *routine(void *args){
        sem_wait(&semaphore);           //s--;                         
        sleep(1);
        printf("[thread_%d] Hello from thread!\n", *(int*)args );
        sem_post(&semaphore);           //s++;                          
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

