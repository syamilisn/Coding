#include <stdio.h>

void print_arr(int n, int *arr){
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
	

int recur_binary_search(int *arr, int x, int low, int high){
 	int mid = (low + high)/2;
 	if(arr[mid] == x) return mid;
	else if(x < arr[mid]) return recur_binary_search(arr, x, low, mid-1);
 	else return recur_binary_search(arr, x, mid+1, high);	
}

void bubble_sort(int n, int *arr){
 	int temp;
 	for(int i=0; i<n; i++)
 		for(int j=0; j<n-i-1; j++)
 			if(arr[j] > arr[j+1])
 				temp = arr[j], arr[j] = arr[j+1], arr[j+1] = temp;
 	print_arr(n, arr);
}

int linear_search(int n, int *arr, int x){
	for(int i=0; i<6; i++)
		if(arr[i] == x)	return i;
}

int binary_search(int n, int *arr, int x){
	int low = 0, high = n-1, mid;
	bubble_sort(n, arr);
	do{
		mid = (low + high) / 2;
		if(x == arr[mid])	return mid;
		else if(x > arr[mid])	low = mid+1;
		else	high = mid - 1;
	}while(high != low);
}

void selection_sort(){
	int n = 6;
	int arr[6] = {6,5,4,36,24,12};
	int temp;
	printf("Before Selection sort:\n");
	print_arr(n, arr);
	// variable i represents the smaller element index. No need for extra variable
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
	printf("Linear search: %d\n", linear_search(n, arr, x));
	printf("Binary search: %d\n", binary_search(n, arr, x));
	printf("Recursive Binary search: %d\n", recur_binary_search(arr, x, 0, n-1));
	selection_sort();
}

