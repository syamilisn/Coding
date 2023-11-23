// bubble sort
#include <stdio.h>

int main() {
    int n = 4;
    int a[4] = {4,1,2,3};
    for( int min_index=0; min_index<n; min_index++)
    {
        int min_val = a[min_index+1];
        for(int j = min_index+1; j<n; j++)
        {
            if(min_val > a[j+1])
                min_val = a[j+1];
        }
        //swap (min_val & value in min_index)
        int temp = min_val;
        min_val = a[min_index];
        a[min_index] = temp;
    }
            
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
        
    printf("\n");
    return 0;
}
