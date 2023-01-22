#include <stdio.h>
#include <stdlib.h>
#define N 7
void main(){
	int a = 1;
	int arr[10] = {-3,-2,-1,0,1,2,3};
	unsigned int b = 1;
	float b1;
	double b2;
	char c;
	char str[30];
	
	int p = 10;
	int *ptr = &p;
	// POINTERS
	printf("The value of var. p = %d\n",p);	
	printf("The value of var. ptr = %p\n",ptr);  //Returns pointer address
	printf("The value of var. *ptr = %d\n",*ptr); //Returns pointer value
	printf("The value of var. &p = %p\n",&p);
	
	// UNSIGNED INT
	printf("The value of 'int' var. a = %d\n",a);
	printf("The value of 'unsigned int' var. b = %u\n",b);
	
	for(int i=0; i<N;++i){
		printf("a[%d] is %d \n",i,arr[i]);
		printf("%d\n",arr[i]);	//prints array
		printf("%p\n",arr+i);	//prints array addresses
	}
	
}
