#include <stdio.h>
int i, x, y;
void func(int arr[40], int i1, int i2){
    int a = i1 - 1, b = i1 + 1, diff = i2 - i1;
    for(i= i1-1; i<= 40; i++){
        if(i<= i2+diff)  arr[i] = arr[i+diff];
        else arr[i-1] = 0;
    }
    printf("Array printed by func:\n");
    for(i=0; i<40; i++) printf("%d ", arr[i]);  //prints array

}
void main(){
    int n = 8;
    int arr[40] = {0};
    for(i=0; i<40; i++) arr[i] = i+1;   //assigns array (1-40)
    for(i=0; i<40; i++) printf("%d ", arr[i]);  //prints array
    //func(arr, 28, 32);
    //func(arr, 6, 11);
    for(i=0; i<n; i++){
        printf("Enter x and y:\n");
        scanf("%d %d", &x ,&y);
        func(arr, x, y);
    }
}