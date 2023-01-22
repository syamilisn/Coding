#include <stdio.h>
#include <stdlib.h>
int* init1D(int n){
    printf("A[%d] >> ", n);
    int *array = (int*)calloc(n, sizeof(n));
    int i=0;
    while(i<n){
        scanf("%d", &array[i++]);
    }
    return array;
}

void display1D(int n, int *arr){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}