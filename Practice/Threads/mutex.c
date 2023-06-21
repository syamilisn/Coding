#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t mutex;
int value = 0;
void func(char * prompt){
    for(int i=0; i<5; i++){
        pthread_mutex_lock(&mutex);
        printf("[%s] Hi i am thread! %d \n", prompt, value++);  //with lock each thread prints sequentially
        pthread_mutex_unlock(&mutex);
        // printf("[%s] Hi i am thread! %d \n", prompt, value++);   //without lock, each thread prints alternate numbers
    }
}
int main(){
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, (void *)func, "t1~");
    pthread_create(&t2, NULL, (void *)func, "t2~");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}
