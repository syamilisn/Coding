#include <stdio.h>
int factorial(int n){
    if(n <= 1) return 1;
    return n * factorial(n-1);
}
int combinations(int n, int r){
    return factorial(n)/(factorial(n-r)*factorial(r));
}
void main(){
    int n = 4;
    int arr[4] = {1,2,3,4};
    int r = 2; //Pairs of 2 numbers
    int row = combinations(n, r);
    int col = 2;
    int k = 0;
    int temp;
    printf("number of combinations = %d\n", row);
    int pair[row][col];
    // for(int i=0; i<row; i++){
    //     // for(int j=0; j<col; j++){
    //         pair[i][0] = arr[k];
    //         // pair[i][1] = arr[k];
    //         int temp = k+1;
    //         while(temp < n){
    //             if(i < row)
    //             pair[i++][1] = arr[temp];
    //             temp += 1;
    //         }
    //         k++;
    //     // }
    // }
    
    
    
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         if(j == 0){
    //             pair[i][j] = arr[k];
    //             temp = ++k;
    //         }
    //         if(j == 1)
    //             pair[i][j] = arr[temp++];
    //     }
    // }
    
    int p = 1;
    for(int i=0; i<row; i++){
        // if(k+p < n){
        if(p < n){
            pair[i][0] = arr[k];
        
            temp = k + p++;
            pair[i][1] = arr[temp];
        }
        else
            k++;
    }
    
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", pair[i][j]);
        }
        printf("\n");
    }
}