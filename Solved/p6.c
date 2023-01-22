#include <stdio.h>
#define N 3
int i, j;
int arr[N] = {1,2,3,4,5,6,7,8,9};
void main(){
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}