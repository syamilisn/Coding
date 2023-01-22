#include<stdio.h>
typedef struct student{
	char name[30];
	int roll, height;
} stud;

void main(){
	int i,j;
	stud arr[4], temp;
	/*
	arr[0] = {name ="abhi",100,150};
	arr[1] = {"bittu",101,160};
	arr[2] = {"cara",105,170};
	arr[3] = {"dilan",103,145};
	arr[3] = {"mitu",102,130};
	*/
	
	/*
	for(i = 0; i< 5; i++){
		scanf("\n%s %d %d",arr[i].name,&arr[i].roll,&arr[i].height);
	}
	*/
	for(i = 0; i< 5; i++){
		printf("\n%s %d %d",arr[i].name,arr[i].roll,arr[i].height);	//print array BEFORE sort
	}
	/*
	for(i = 1; i<= 5; i++){
		for(j = 1; j<= 5; i++){
			if (arr[j-1].roll > arr[j].roll){
				//temp = arr[j-1].roll, arr[j-1].roll = arr[j].roll, arr[j].roll = temp;
				temp = arr[j-1]; arr[j-1] = arr[j]; arr[j] = temp;
			}
		}
		
	}
	*/
	for(i = 0; i< 5; i++){
		printf("\n%s %d %d",arr[i].name,arr[i].roll,arr[i].height); ////print array AFTER sort
	}
	printf("\n");
}
