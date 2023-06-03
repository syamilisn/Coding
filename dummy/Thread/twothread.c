/*
* Author     : Syamili S N
* Program    : p9_thread
* Description: pthread() functionality
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void* display(){
        printf("[thread~%d] Displaying with thread.\n", gettid());
        sleep(3);
        printf("[thread~%d] Ending thread.\n", gettid());
}

int main(){
        pthread_t t1, t2;
        int status1, status2;
        status1 = pthread_create(&t1, NULL, &display, NULL);
        status2 = pthread_create(&t2, NULL, &display, NULL);
        if(status1 != 0){
                printf("Thread 1 creation unsuccessful.\n");
                return 1;
        }
        else
                printf("Thread 1 creation successful.\n");

        if(status2 != 0){
                printf("Thread 2 creation unsuccessful.\n");
                return 1;
        }
        else
                printf("Thread 2 creation successful.\n");

        if(pthread_join(t1, NULL) != 0)
                printf("Thread 1 joining unsuccessful.\n");

        if(pthread_join(t2, NULL) != 0)
                printf("Thread 2 joining unsuccessful.\n");
        return 0;
}

