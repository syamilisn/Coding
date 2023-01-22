#include <stdio.h>
int func(int n){    //davids
    if( n < 4 )
        return n;
    return func(n-1) + func(n-2) + func(n-3);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
    return 0;
}