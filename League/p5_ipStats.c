#include <stdio.h>
void print(int row, int col, char arr[][col]){
    printf("Display array:\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}
void game(int row, int col, char arr[][col]){
    
}
void main(){
    int row, col, n;
    scanf("%d%d%d", &row, &col, &n);
    char arr[row][col];
    // char ans[row][col];
    for(int i=0; i<row; i++)
        scanf("%s", arr[i]);
    
    print(row, col, arr);   //print array
    game(row, col, arr);
}