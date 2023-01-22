#include <stdio.h>
#define row 3
#define col 4

enum game { R=1, P, S};

void main(){
    enum game move;
    enum game arr[row][col]={R,S,P,R,S,P,R,S,P,R,S,P};
    //print array
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    
    
}