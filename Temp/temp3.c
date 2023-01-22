// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n = 5;
    int arr[5] = {1,4,4,5,5};
    int sum = 0, i;
    //////////
    for(i=0; i<n-1; i++){
        if(arr[i] == arr[i+1])
            arr[i+1]++;
        
        else if(arr[i] > arr[i+1])
            arr[i+1] = arr[i] + 1;
            
        sum+= arr[i];
    }

    sum += arr[i];
    printf("%d", sum);
}