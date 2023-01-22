#include <stdio.h>
#define ROWS 3
#define COLS 3

typedef int matrix[ROWS][COLS];
void determinant(int *arr);
void inputMatrix(int arr[ROWS][COLS], int order){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d ", &m[i][j]);
        }
        printf("\n");
    }
}
void printMatrix(int arr[ROWS][COLS], int n);

void main(){
    matrix m2 = {1,2,3,4};
    matrix m3 = {1,2,3,4,5,6,7,8,9};
    matrix m1;
    inputMatrix(m1,2);
    printMatrix(m1,2);
    //determinant(matrix2,2);
}

void printMatrix(matrix m, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void determinant(int *arr){

}