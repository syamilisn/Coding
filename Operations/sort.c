#include <stdio.h>

void print_arr(int n, int *arr){
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


void insertion_sort(int n, int arr[]){
	int key = 0;
	int temp;
 	for(int i=0; i<n; i++)
 		for(int j=0; j<n; j++)
 			if(arr[key] > arr[j])
 				temp = arr[j], arr[j] = arr[key], arr[key] = temp;
	printf("Insertion sort:\n");
 	print_arr(n, arr);
}

void bubble_sort(int n, int arr[]){
	int temp;
 	for(int i=0; i<n; i++)
 		for(int j=0; j<n-i-1; j++)
 			if(arr[j] > arr[j+1])
 				temp = arr[j], arr[j] = arr[j+1], arr[j+1] = temp;
	printf("bubble sort:\n");
 	print_arr(n, arr);
}

void selection_sort(int n, int arr[]){
	int temp;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > arr[j])
				temp = arr[i], arr[i] = arr[j], arr[j] = temp;
		}
	}	
	printf("Selection sort:\n");
	print_arr(n, arr);
}
void main(){
	int n = 6;
	int arr[6] = {6, 5, 4, 36, 24, 12};
	int x = 36;	//element whose index is to be found
	printf("Before sort:\n");
	print_arr(n, arr);
	selection_sort(n, arr);
	bubble_sort(n, arr);
	insertion_sort(n, arr);
}


