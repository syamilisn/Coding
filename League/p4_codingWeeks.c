// Online C compiler to run C program online
#include <stdio.h>
int max(int *arr, int n){
    int big = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > big)
            big = arr[i];
    return big;
}
int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    int arr[n];
    // = {4, 3, 3, 2, 3, 4, 2, 1, 3, 2, 2, 1, 4, 3, 2, 2, 1, 3, 4, 2, 3, 3, 1};
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int max_ele = max(arr, n);
    int sum = 0;
    while(max_ele > 0){
        sum += max_ele--;
    }
    printf("Comparison sum = %d\n", sum);
    int temp_sum = 0;
    for(int i=0; i<n; i++){
        // if(arr[i] != arr[i+1] && arr[i+1] != arr[i+2] && arr[i+2] != arr[i+3] && arr[i+3] != arr[i])
        if(i+3 < n)
            temp_sum = arr[i] + arr[i+1] + arr[i+2] + arr[i+3];
        else
            temp_sum = 0;
        if(sum == temp_sum){
            count++;
            i++;
        }
    }
    printf("Count = %d\n", count);
    return 0;
}