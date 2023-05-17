#include <stdio.h>
#include <pthread.h>
void *display(void *args){
	printf("string: %s\n", (char *)args);
}
void main(){
	pthread_t t1;
	char string[100] = "hello world";
	pthread_create(&t1, NULL, &display, string);
	pthread_join(t1, NULL);
}
