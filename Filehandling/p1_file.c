#include <stdio.h>
#include "h1_print.h"
void main(){
    int n = 5;
    int arr[n];
    // int arr[5] = {1,2,3,4,5};
    init1D(n, arr, 1);
    print1D(n, arr, 0);
    // print1D(n, arr, 1);

    // int row = 3;
    // int col = 3;
    // int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    // print2D(row, col, matrix);
}