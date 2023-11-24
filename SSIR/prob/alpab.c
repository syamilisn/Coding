// Online C compiler to run C program online
#include <stdio.h>

arrange_asc(int a, int b, char * str){
    for(int i = a; i <b; i++){
        for(int j = a; j <b-i-1; j++){
            if(str[j] > str[j+1])
            {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1]  = temp;
        
            }
        }
    }
}
int main() {
    int n = 6;
    char str[6] = "tocmat";
    int k = 2;
    printf("before: %s\n", str);
    
    // arrange(0,k,str);
    // arrange(k+k,str);
    int a = 0;
    int b = k;
    while(b<n){
        arrange_asc(a,b,str);
        a += 2;
        b += 2;
    }
    
    printf("after: %s\n", str);
    return 0;
}
