#include <stdio.h>
#define ARRSIZE 5

int n = 5, i, j, temp;
int arr[5] = {4,1,2,3,5};

void printArray(char prompt[10], int arr[ARRSIZE]);
void bubbleSort(int arr[ARRSIZE]);

void main(){
	printArray("Original",arr);	//original
	bubbleSort(arr);

	
}

void printArray(char prompt[10], int arr[ARRSIZE]){
	printf("%s: ",prompt);
	for(i=0; i<n; i++)	printf("%d ",arr[i]);
	printf("\n");
}
void bubbleSort(int arr[ARRSIZE]){
	for(i=1; i<=n; i++){
		for(j=1; j<=(n-i); j++){
			if(arr[j-1] > arr[j]){
				temp = arr[j-1], arr[j-1] = arr[j], arr[j] = temp;
			}
		}
	}	
	printArray("Bubble sort",arr);	//sorted - bubble sort
}
