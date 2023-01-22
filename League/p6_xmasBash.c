#include <stdio.h>

int solved(int n, int k){
    int arr[n];
    int rem_min = 240 - k + 1;  //  added additional one
    int count = 0;  // problems solved
    int sum_min = 0;    // adding time for solved problems
    for(int i=0; i<n; i++){
        arr[i] = (i+1)*5;   //  multiples of 5
        // printf("%d ", arr[i]);
    }
    
    for(int i=0; i<n; i++){
        if(sum_min + arr[i] < rem_min){
            sum_min += arr[i];
            count++;
        }
    }
    return count;
}
void main(){
    // int n = 3;  // no. of problems
    // int k = 222;    //  no. of minutes in traffic
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d \n", solved(n, k));
}