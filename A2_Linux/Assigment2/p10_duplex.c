/*
* Author     : Syamili S N
* Program    : p10_duplex
* Description: full-duplex communication using threads 
*/


#include "run/headers.h"

int token = 1;
int play = 1;
pthread_mutex_t lock;

void *routine_generate(void *args){
	char *prompt = args;
	for(int i=0; i<10; i++){
		if(play){
			printf("[%s~thread] Token: %d\n", prompt, token);
			sleep(1);
			token++;
		}
		else
			i -= 1;
	}
}
void *routine_write(void *args){
	char *prompt = args;
	sleep(5);
	pthread_mutex_lock(&lock);
	play = 0;
	printf("[%s~thread] Enter random token: \n>> ", prompt);
	scanf("%d", &token);
	play = 1;
	pthread_mutex_unlock(&lock);
}

int main(){
	printf("Program generates integer token every second:\n");
	pthread_t write, generate;
	pthread_mutex_init(&lock, NULL);
	if( pthread_create(&write, NULL , &routine_write, "write") ){
		perror("write thread creation failed\n");
	}
	if( pthread_create(&generate, NULL , &routine_generate, "generate") ){
		perror("generate thread creation failed\n");
	}
	if( pthread_join(write, NULL) ){
		perror("write thread join failed\n");
	}
	if( pthread_join(generate, NULL) ){
		perror("genereate thread join failed\n");
	}
	pthread_mutex_destroy(&lock);
	return 0;
}
