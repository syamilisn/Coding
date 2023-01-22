// Online C compiler to run C program online
#include <stdio.h>
#define row 2
#define col 5
int main() {
    int ip[row][col] = {
        {10,1,137,127,0},
        {10,1,139,255,1}
    };
    
    int *ptr_ip = ip;
    int **ptr = ptr_ip;
    for(int i=0; i< row*col; i++){
        printf("%d ", *(ptr_ip+i));
        if((i+1)%5 == 0 ){ 
            printf("\n");
        }
    }
    int k = 0;
    for(int i=0; i< row*col; i++){
        printf("%d ", *(ptr_ip+i));
        for(int j=i+1; j%5 == 0; j--){
            ptr[k++] = ptr_ip+i;
            printf("\n");
        }
    }
    return 0;
}