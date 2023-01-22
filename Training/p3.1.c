/* 2 DIMENSIONAL ARRAY */
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

enum Result {SUCCESS, FAILURE};

Result matrixInput(int matrix[ROW][COL], int *row, int *col){
	printf("Enter the no. of rows and cols in matrix:\n");
	scanf("%d %d", row, col);
	if(((*row > ROW) || (*col > COL))){
		printf("Too big a matrix\n");
		return FAILURE;
	}
	printf("Enter the matrix elements:\n"):
	for(unsigned int i = 0 ; i < *row; ++i)
		for(unsigned int j = 0 ; i < *col; ++j)
			scanf("%d", &(matrix[i][j]));
	return SUCCESS;
}
void matrixOutput(int matrix[ROW][COL], int *row, int *col){
	for(unsigned int i = 0 ; i < *row; ++i){
		for(unsigned int j = 0 ; i < *col; ++j)
			printf("%d", matrix[i][j]);
		printf("\n");S		
	}
}

int main(){
	int i, row, col;
	int matrixA[ROW][COL];
	if(ret == FAILURE){
		printf("Bailing out \n");
		return 1;
	}
	enum Result ret =  matrixInput(matrixA, &rowm &col);
	matrixOutput(matrixA, &rowm &col);
	return 0;

}
