// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n = 6, t;
    int arr[6] = {101,201,102,202,103,203};
    int grp[6] = {1,2,1,2,1,2};
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)  
            if(grp[j] > grp[j+1]){
                t = grp[j], grp[j] = grp[j+1], grp[j+1] = t;
                t = arr[j], arr[j] = arr[j+1], arr[j+1] = t;
            }
            
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}