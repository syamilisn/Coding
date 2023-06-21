#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void func(char * prompt){
    printf("[%s] Hi i am thread! \n", prompt);
}
int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, (void *)func, "t1~");
    pthread_create(&t2, NULL, (void *)func, "t2~");
    pthread_join(t2, NULL);
    pthread_join(t1, NULL);
    return 0;
}
