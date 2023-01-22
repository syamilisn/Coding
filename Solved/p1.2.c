#include<stdio.h>
typedef struct student{
	char name[30];
	int roll;
	int height;
} arr[5];

//stud temp, arr[5];
//void swap(stud a, stud b);

void main(){
	int i;
	arr[0].name = "abhi"; arr[0].roll = 101, arr[0].height = 170;
	arr[1].name = "bitu"; arr[1].roll = 100, arr[1].height = 160;
	for(i = 0; i< 2; i++){
		printf("\n%s %d %d",arr[i].name,arr[i].roll,arr[i].height);	//print array BEFORE sort
	}
}
/*
void swap(stud a, stud b){
	temp = a, a = b, b = temp;
}
*/
