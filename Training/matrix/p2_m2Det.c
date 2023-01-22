#include <stdio.h>
float determinant(int m[][2], int order){
    if (order == 2) return m[0][0]*m[1][1]-m[0][1]*m[1][0];
}
void main(){
    int i, j, matrix[2][2] = {0 ,0}, order = 2; //square matrix only
    float det;
    printf("Enter 2 x 2 matrix:\n");

    //input matrix
    for(i=0; i< order; i++){
        for(j=0; j< order; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    //print matrix
    for(i=0; i< order; i++){
        for(j=0; j< order; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    det = determinant(matrix, order);
    printf("Determinant of matrix is %.2f\n", det);
}