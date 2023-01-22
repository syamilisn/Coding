// Online C compiler to run C program online
#include <stdio.h>
#include <ctype.h>
char* function(int n, char str[100]){
    char s[100];
    int i = 0;
    int length = 0;
    while(str[i] != NULL){
        if(isdigit(str[i])){
            length+= (str[i] - '0') * 1;
        }
        i++;
    }
    printf("length = %d", length);
    if(length)
}
int main() {
    // int n = 5;
    // char str = "abccc";
    char ans = function(5, "a1b1c3");
    return 0;
}