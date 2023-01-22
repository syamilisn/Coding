#include <stdio.h>
void main(){
    // int arr[5][5]={0};
    int status = 1;
    int no=3;
    int x[3] = {0,4,4};
    int y[3] = {1,2,3};
    int m = 1, n = 2;
    for(int i=0; i<no; i++){
        if (x[i] == m){
            if (m+1 < no)   ++m;
            else if(m-1 >0) --m;

            if(x[i+1] == m || x[i-1] == m) status = 0;
        }
        if (y[i] == n){
            if (n+1 < no)   ++n;
            else if(n-1 >0) --n;

            if(y[i+1] == n || y[i-1] == n) status = 0;
        }
    }
    if(status)  printf("ALIVE!");
    else printf("DEAD!");
}