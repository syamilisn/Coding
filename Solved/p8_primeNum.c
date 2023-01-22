// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n = 8;
    for(int i=2; i<n; i++)
        if(n%i != 0){
            printf("prime"); 
            break;
        }
        else {
            printf("not prime");
            break;
        }
            
    return 0;
}