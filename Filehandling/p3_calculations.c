#include <stdio.h>
#include "../headers/inout.h"
#include "../headers/calculator.h"
#include "../headers/print.h"
void main(){
    int a = scan('a');
    int b = scan('b');
    print("Addition:", add(a,b));
    print("Subtraction:", sub(a,b));
    print("Multiplication:", mul(a,b));
    print("Division:", divide(a,b));

    int n = scanf('n');
    int *arr = init1D(n);
    display1D(n, arr);
}