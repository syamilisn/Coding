#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 3
void display(int **arr){

    int **arr2 = (int**)calloc(row, sizeof(int));

    for(int i=0; i<row; i++){
        arr2[i] = (int*)calloc(col, sizeof(int));
    }
    
    arr2 = arr;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", *(*(arr2+i) + j));
        }
        printf("\n");
    }
}
void main(){
    int k=1;
    int **arr = (int**)malloc(sizeof(int) * row);

    for(int i=0; i<row; i++){
        arr[i] = (int*)malloc(sizeof(int) * col);
    }

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            arr[i][j] = k++;

    display(arr);
}