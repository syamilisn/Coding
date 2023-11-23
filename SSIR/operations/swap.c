// swap numbers
#include <stdio.h>
swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    // Write C code here
    int a = 10, b = 20;
    printf("a = %d, b = %d \n", a, b);

    swap(&a, &b);
    printf("a = %d, b = %d \n", a, b);
    return 0;
}
