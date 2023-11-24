// Online C compiler to run C program online
#include <stdio.h>

int count(int val, int n, int a, int b, int *arr){
    //n is count value
    int sum = 0;
    for(int i=a; i<=b; i++){
        sum += arr[i];
    }
    if(sum == 0)
        return count(val+1, n, a, b+1, arr);
    else
    {
        if(b < n)
            return count(val, n, a, b+1, arr);
        else
            return val;
    }
}

int main() {
    int n = 5;
    int arr[5] = {2,0,-1,1,0};
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    
    int x = -1 * sum;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            arr[i] = x;
            break;
        }
    }
    
    int count_val = count(0,n, 0, 1, arr);
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
        
    printf("count = %d\n", count_val);

    
    
    
    return 0;
}
