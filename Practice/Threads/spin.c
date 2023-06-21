#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_spinlock_t spin;    //shows error but works
int value = 0;
void func(char * prompt){
    for(int i=0; i<5; i++){
        pthread_spin_lock(&spin);
        printf("[%s] Hi i am thread! %d \n", prompt, value++);  //with lock each thread prints sequentially
        pthread_spin_unlock(&spin);
        // printf("[%s] Hi i am thread! %d \n", prompt, value++);   //without lock, each thread prints alternate numbers
    }
}
int main(){
    pthread_t t1, t2;
    pthread_spin_init(&spin, PTHREAD_PROCESS_PRIVATE);
    // pthread_spin_init(&spin, NULL);

    pthread_create(&t1, NULL, (void *)func, "t1~");
    pthread_create(&t2, NULL, (void *)func, "t2~");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_spin_destroy(&spin);
    return 0;
}
