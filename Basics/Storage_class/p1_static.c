#include <stdio.h>
int static_var;
int normal_var;

int func(int args){
	static int b = args;
	//int b = b + args;
	return b;
}
void main(){
	int a = 10;
	int b;
        b = func(10);
	printf("a = %d b = %d\n", a, b);
	b = func(10);
	printf("a = %d b = %d\n", a, b);
}
