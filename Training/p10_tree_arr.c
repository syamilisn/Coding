#include <stdio.h>
void main(){
    int n = 7;
    int k = 2;
    int arr[7] = {2,7};
    ///////////
    int ans[100] = {1, 2, 3, 4, 5, 6, 7};
    int i, j=0, index;
    //////////////
    for(i=0; i<n; i++){
        if(arr[j] == 1){
            printf("%d", 0);
            exit(0);
        }
        if(ans[i] == arr[j]){
            ans[i] = 0;
            j++;
            if(ans[i] == 0){
                int index = 2*i;
                ans[index+1] = 0;   //left child index
                ans[index+2] = 0;   //right child index
            }
        }
    }
    
    for(i=0; i<n; i++)
        if(ans[i] != 0)
            printf("%d ", ans[i]);
}