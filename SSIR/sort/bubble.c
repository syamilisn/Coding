// bubble sort
#include <stdio.h>

int main() {
    int n = 4;
    int a[4] = {4,1,2,3};
    for( int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
        
    printf("\n");
    return 0;
}
