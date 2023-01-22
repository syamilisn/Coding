#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void main(){
	int arr[SIZE] = {0};
	
	for(unsigned int i = 0 ; i < SIZE; ++i){
		arr[i] = rand();
	}
	
	for(unsigned int i = 0 ; i < SIZE; ++i){
		printf("arr[%d] is %d\n", i, arr[i]);
	}

}
