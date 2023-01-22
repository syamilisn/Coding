#include <stdio.h>
void print(int row, int col, char arr[][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

char compare(char a, char b){
    if(a == b)
        return a; 
    if(a == 'R' && b == 'P' || a == 'P' && b == 'R')
        return 'P';
    if(a == 'R' && b == 'S' || a == 'S' && b == 'R')
        return 'R';
    if(a == 'P' && b == 'S' || a == 'S' && b == 'P')
        return 'S';
}

void game(int row, int col, char arr[][col], int n){
    char ans[row][col];
    char temp;
    while(n>0){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                temp = arr[i][j];
                if(temp == arr[i][j])
                    if(j+1 < col)   //RIGHT
                        temp = compare(temp, arr[i][j+1]);
                    
                if(temp == arr[i][j])
                    if(i+1 < row)  //DOWN
                        temp = compare(temp, arr[i+1][j]);
                        
                if(temp == arr[i][j])
                    if(j-1 >= 0)   //LEFT
                        temp = compare(temp, arr[i][j-1]);
                        
                if(temp == arr[i][j])
                    if(i-1 >= 0)   //TOP
                        temp = compare(temp, arr[i-1][j]);

                ans[i][j] = temp;
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                arr[i][j] = ans[i][j];
            }
        }
        n--;
    }
    print(row, col, ans);//print array
}
void main(){
    int row, col, n;
    scanf("%d%d%d", &row, &col, &n);
    char arr[row][col];
    for(int i=0; i<row; i++)
        scanf("%s", arr[i]);
    game(row, col, arr, n);
}