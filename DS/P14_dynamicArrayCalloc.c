// ARRAY - DYNAMIC MEMORY ALLOCATION USING CALLOC
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;
    int n = 5;
    arr = (int*)calloc(n, sizeof(int));
    for(int i=1; i<=n; i++)
        arr[i] = i;
    for(int i=1; i<=n; i++)
        printf("%d ", arr[i]);

    return 0;
}