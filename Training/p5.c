/*
	PROGRAM TO SORT ARRAY AND FIND IF THE SUM OF 3RD ELEMENT AND LAST SECOND ELEMENT IS GREATER THAT 50
*/

#include <stdio.h>
int n, i, j, temp, sum=0, arr[30];
void bubbleSort(int *arr, int n);
void main(){
	//input array
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	
	printf("Enter array:\n");
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	
	int arr[5] = {4,1,2,3,5}, *ptr = arr;
	printf("Array before sorting is\n");
	for(i=0; i<n; i++)
			printf("%d ",arr[i]);
			
	printf("\n");

	bubbleSort(arr,n);	//sort array elements
	
	printf("Array after sorting is\n");
	for(i=0; i<n; i++)
			printf("%d ",arr[i]);
			
	printf("\n");
	
	for(i=1;i<=n;i++){
		if(i == 2 || i == n-2){
			sum+= arr[i];
		}
	}
	if(sum > 50)	printf("Sum %d is greater than 50\n",sum);
	else	printf("Sum %d is not greater than 50\n",sum);
	
}

void bubbleSort(int *arr,int n){
		/* BUBBLE SORT */
	for(i=1; i<=n; i++){
		for(j=1; j<=(n-i); j++){
			if(arr[j-1] > arr[j]){
				temp = arr[j-1], arr[j-1] = arr[j], arr[j] = temp;
			}
		}
	}
}
