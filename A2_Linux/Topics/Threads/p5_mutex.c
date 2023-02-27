/*
* Date       : 27-02-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : p5_mutex
* Description: mutex lock to encounter race condition
*/


#include "run/headers.h"

int mails = 0;
pthread_mutex_t mutex;

void* routine(){
      printf("[begin~Routine]\n");
        for(int i=0; i<1000000; i++){    //accurate upto 100, 1000, 100000 
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

