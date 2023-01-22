#include <stdio.h>
void print(int n1, int n2, int arr[][5], char prompt[30]){
    printf("%s\n", prompt);
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void main(){
    int n1, n2, n3; //n1: x-dimension; n2: y-dimension; n3: enemy ops
    scanf("%d%d%d", &n1, &n2, &n3);
    int x[n1], y[n2], arr[n1][n2];
    int i=0, j=0, k=0, flag=1;  //Default is ALIVE!
    for(i=0; i<n3+1; i++)
        scanf("%d%d", &x[i], &y[i]);
    int sasX = x[n3];
    int sasY = y[n3];
    printf("sasX = %d, sasY = %d\n", sasX, sasY);
    //  INITIALIZE ARR WITH 0
    for(i=0; i<n1; i++)
        for(j=0; j<n2; j++)
            arr[i][j] = 0;
    print(n1, n2, arr, "Initial array (2D-world):");
    //  END INITIALIZATION
    
    //  MODIFY ARRAY WITH LINE OF FIRE
    for(k=0; k<n3; k++){
        for(i=0; i<n1; i++){
            for(j=0; j<n2; j++){
                if(i == x[k]){
                    arr[i][j] = 1;
                }
                if(j == y[k]){
                    arr[i][j] = 1;
                }
            }
        }
    }
    print(n1, n2, arr, "Modified array (Line-of-fire):");
    //  END MODIFICATION
    
    //  LOGIC BEGINS
    if(arr[sasX][sasY] == 0)
        flag = 1;
        
    else if(0<=sasX && sasX<n3 && 0<=sasY && sasY<n3){
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
        else if(arr[sasX-1][sasY] == 1 && arr[sasX+1][sasY] == 1 && (arr[sasX][sasY-1] == 1) && (arr[sasX][sasY+1] == 1))
            flag = 0;
    }
    
    //  LOGIC ENDS
    if(flag == 1)
        printf("ALIVE!");
    else
        printf("DEAD!");
}