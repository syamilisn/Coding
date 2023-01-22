#include <stdio.h>
void main(){
    
    int n;
    scanf("%d",&n);
    int arr[10]={0};
    for(int i=0; i<n; i++) printf("value %d is %d \n", i+1, arr[i]);
}