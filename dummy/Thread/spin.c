#include <stdio.h>
#include <pthread.h>
pthread_mutex_t lock;
void *print(void * num){
	pthread_spin_lock(&lock);
	int value = 100;
	int num2 = *(int *) num;
	value = value + num2;
	printf("value = %d", value);
	pthread_spin_unlock(&lock);

}

void main(){
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
        pthread_create(&t1, NULL, &routine, NULL);
        pthread_create(&t2, NULL, &routine, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        pthread_mutex_destroy(&mutex);
}
