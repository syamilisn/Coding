#include<stdio.h>
#define SIZE 6
void main(){
	int a[SIZE]={4,6,5,3,3,1}, b[SIZE];
	int i,j,k=1;
	//print array
	for(i=0; i<SIZE; i++){
		printf("%d",a[i]);
	}
	b[0]=a[0];
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(b[i] != a[j]) 
				b[i]=a[j];
		}
		printf("%d",b[i]);
	}
	
	printf("\n");
}
