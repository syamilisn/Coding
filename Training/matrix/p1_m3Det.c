#include <stdio.h>
float determinant(int m[][3], int order, int i1, int i2){
    if (order == 2) return m[1][i1]*m[2][i2]-m[1][i2]*m[2][i1];
    else{
        return m[0][0]*determinant(m, 2, 1, 2) -m[0][1]*determinant(m, 2, 0, 2) + m[0][2]*determinant(m, 2, 0, 1);
    }
}
void main(){
    int i, j, matrix[3][3] = {0 ,0}, order = 3; //square matrix only
    float det;
    printf("Enter 3 x 3 matrix:\n");

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
    det = determinant(matrix, order, 0, 1);
    printf("Determinant of matrix is %.2f\n", det);
}