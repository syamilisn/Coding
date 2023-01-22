#include <stdio.h>
#include <string.h>
void main(){
    char str[30] = "malaytalam";
    int len = strlen(str);
    int i = 0;
    while(i <= len/2){
        if(str[i] != str[len-i-1]){
            printf("Not palindrome");
            exit(0);
        }
        i++;
    }
    printf("Is Palindrome");
}