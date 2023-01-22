#include <stdio.h>
int i, j;
float determinant(int m[][3], int order, int i1, int i2){
    if (order == 2) return m[1][i1]*m[2][i2]-m[1][i2]*m[2][i1];
    else{
        return m[0][0]*determinant(m, 2, 1, 2) -m[0][1]*determinant(m, 2, 0, 2) + m[0][2]*determinant(m, 2, 0, 1);
    }
}

void cofactor(int m[][3], int order, int cfm[][3]){
    for(i=0;i<order;i++){
        for(j=0;j<order;j++){
            cfm[i][j] = determinant(m,2)
        }
    }
}
void main(){
    int matrix[3][3] = {0, 0},cfMatrix[3][3] = {0, 0} ,order = 3; //square matrix only
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
    cofactor(matrix, 3,cfMatrix); 
}