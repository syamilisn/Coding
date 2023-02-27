/*
* Author     : Syamili S N
* Program    : p6_setjmp
* Description: demo setjmp() & longjmp() calls
*/


#include "run/headers.h"
#include <setjmp.h>

void jmpfunction(jmp_buf);
int main(){
	int state;
	jmp_buf envbuf;
	state = setjmp(envbuf); //nonlocal goto
	if(state != 0 ){
		printf("Returned from longjmp() with value = %d\n", state);
		exit(0);
	}
	printf("Jump function call\n");
	jmpfunction(envbuf);
	return 0;	
}

void jmpfunction(jmp_buf envbuf){
	printf("Inside the function\n");
	longjmp(envbuf, 1);
}
