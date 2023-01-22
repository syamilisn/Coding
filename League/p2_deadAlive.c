#include <stdio.h>
#define N 5
#define PT 4
void print(int arr[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void main(){
    int arr[N][N] = {0};
    int x[PT] = {0,4,4,1};
    int y[PT] = {1,2,3,2};
    int i=0, j=0, k=0, flag=1; //alive, flag = 0 is dead;
    printf("Initial array (2D-world):\n");
    print(arr);
    for(k=0; k<PT-1; k++){
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(i == x[k]){
                    arr[i][j] = 1;
                }
                if(j == y[k]){
                    arr[i][j] = 1;
                }
            }
        }
    }
    printf("Modified array (Line-of-fire):\n");
    print(arr);
    
    // LOGIC STARTS
    int sasX = x[PT-1];
    int sasY = y[PT-1];
    if(arr[sasX][sasY] == 0)
        flag = 1;
        
    else if(0<=sasX && sasX<N && 0<=sasY && sasY<N){
        // if(arr[sasX-1][sasY] == 1 && arr[sasX+1][sasY] == 1 && arr[sasX][sasY-1] == 1 && arr[sasX][sasY+1] == 1) //all surround is fire
        //     flag = 0;
            
        if(arr[sasX-1][sasY] == 0)  //shift TOP
            flag = 1;
        else if(arr[sasX+1][sasY] == 0) //shift DOWN
            flag = 1;
        else if(arr[sasX][sasY-1] == 0) //shift LEFT
            flag = 1;
        else if(arr[sasX][sasY+1] == 0) //shift RIGHT
            flag = 1;
        else
            flag = 0;
    }
    // LOGIC ENDS
    if(flag)
        printf("ALIVE!");
    else
        printf("DEAD!");

}