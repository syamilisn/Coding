#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 3
void display(int **arr){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", arr[i][j]);
        }
    }
}
void main(){
    int k = 1;
    int **arr = (int**)malloc( row * sizeof(int));
    for(int i=0; i<row; i++)
        arr[i] = (int*)malloc( col * sizeof(int));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j] = k++;
        }
    }
    display(arr);
}