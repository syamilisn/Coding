#include <stdio.h>
#include <stdlib.h>
#include <../headers/inout.h>
void main(){
    // int n;
    // scanf("%d", &n);
    int n = scan('n');
    int *arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i <n; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i <n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    for(int i=0; i <n; i++)
        printf("%d ", *(arr+i));

    int row, col;
    scanf("%d%d", &row, &col);
    int *list = (int*)calloc(col, sizeof(int));   //arr_col[row]
    for(int i=0; i<row; i++){
        printf("%d", *(list + i));
    }


}