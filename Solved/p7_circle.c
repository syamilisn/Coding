#include <stdio.h>
#include <stdlib.h>
int *res = (int*)malloc(sizeof(int)*n);
res = {0};
// int* circle_func(int *a, int n, int k){
//     int *res = (int*)malloc(sizeof(int)*n);//dynamic array res
//     for(int i = 0; i < n;i++){
//         res[i] = a[((k-1-i)%n)];
//     }
//     return res;
// }

int* recur_func(int *res, int n, int k, int i){ //i:index
    res[i];
}
void main(){
    int n, k, *ptr_res;
    printf("Enter n, key values:\n");
    scanf("%d%d",&n,&k);
    int arr[n];
    printf("Enter array:\n");
    for(int i = 0; i<n;i++){
        scanf("%d",&arr[i]);
    }
    ptr_res = circle_func(arr,n,k);
    printf("Result array is:\n");
    for(int i = 0; i<n;i++){
        printf("%d ",ptr_res[i]);
    }
    printf("\n");
}