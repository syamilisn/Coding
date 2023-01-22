/*
    PRINT AND INITIALIZE ARRAY
*/

#include <stdio.h>

void print1D(int n, int arr[], int reverse){
    //PRINTS ONE DIM. ARRAY
    for(int i=0; i<n; i++){
        if(reverse)
            printf("%d ", arr[n-i-1]);
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

// void init1D(int n, int arr[], int initialize){
//     for(int i=0; i<n; i++)
//         arr[i] = initialize;
// // }

// void print2D(int row, int col,  int *arr_2D){
//     //PRINTS TWO DIM. ARRAY
//     for(int i=0; i< row*col; i++){
//         printf("%d ", arr_2D[i]);
//         if(((i+1) % col) == 0)
//             printf("\n");
//     }
    
//     printf("\n");
// }