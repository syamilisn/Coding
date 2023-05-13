/*
* Author     : Syamili S N
* Program    : p12_mutex
* Description: demo mutex in pthread()
*/


#include "run/headers.h"

int mails = 0;
pthread_mutex_t mutex;

void* routine(){
      printf("[begin~Routine]\n");
        for(int i=0; i<100000; i++){    //accurate upto 100, 1000, 100000 without mutex lock
                pthread_mutex_lock(&mutex);
                mails++;
                pthread_mutex_unlock(&mutex);
        }
      printf("[  end~Routine]\n");
}

int main(){
        pthread_t t1, t2;
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&t1, NULL, &routine, NULL);
        pthread_create(&t2, NULL, &routine, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        pthread_mutex_destroy(&mutex);
        printf("No. of mails: %d\n", mails);
        return 0;
}

