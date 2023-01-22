#include <stdio.h>
int n, i, j, temp;
int * bubbleSort(int *arr, int n);
void main(){
	int arr[20] = {4,1,2,3,5}, *mod_arr;
	//input array
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	
	printf("Enter array:\n");
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	
	
	printf("Array before sorting is\n");
	for(i=0; i<n; i++)
			printf("%d ",arr[i]);
			
	printf("\n");

	mod_arr = bubbleSort(arr,n);	//sort array elements
	
	printf("Array after sorting is\n");
	for(i=0; i<n; i++)
			printf("%d ",mod_arr[i]);
			
	printf("\n");
	
}

int * bubbleSort(int *arr,int n){
		/* BUBBLE SORT */
	for(i=1; i<=n; i++){
		for(j=1; j<=(n-i); j++){
			if(arr[j-1] > arr[j]){
				temp = arr[j-1], arr[j-1] = arr[j], arr[j] = temp;
			}
		}
	}
	return arr;
}
