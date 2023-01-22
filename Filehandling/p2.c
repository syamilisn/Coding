#include <stdio.h>
#include "h1_print.h"

void main(){
    int g;
    scanf("%d", &g);
    int row = g;
    int col = 1000;
    int arr[row][col];
    int i=0, j=0;
    for(int i=0; i<row; i++){
        int size;
        printf("%d", &size);
        for(int j=0; j<size;j++)
            scanf("%d", &arr[i][j]);
    }


}