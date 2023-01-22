#include <stdio.h>
#define ROWS 3
#define COLS 3
int i, j;
typedef int matrix[ROWS][COLS];
void inputMatrix(int matrix[][COLS]);
void printMatrix(int matrix[][COLS]);
void main(){
//	int i, j;
	matrix m1 = {1,2,3,4,5,6,7,8,9};
	matrix m2 = {9,8,7,6,5,4,3,2,1};
	matrix m3;
	/* Prints matrix1 using array index */
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}
	/* Prints matrix2 using array pointer */
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			printf("%d ", *(*(m2+i)+j));
		}
		printf("\n");
	}
	/* Prints matrix1 using user-def function */
	printMatrix(m1);
	inputMatrix(m3);
	printMatrix(m3);
}

void printMatrix(int matrix[][COLS]){
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			printf("%d ", *(*(matrix+i)+j));
		}
		printf("\n");
	}
}

void inputMatrix(int matrix[][COLS]){
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			scanf("%d ", (*(matrix+i)+j));
		}
	}
}
