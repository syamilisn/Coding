#include <stdio.h>
/*
    main logic
*/
void string_reversal(char *str, int a, int b){
    //a and b are intervals 
    b = b-1;
    char temp;
    while( a!=b){
        temp = str[a], str[a] = str[b], str[b] = temp;
        ++a,--b;
    }
}
void main(){
    char string[50] = "Little Lamb, I'll tell thee;";
    printf("The original String is: %s\n",string);
    string_reversal(string, 2, 11);
    printf("\nAfter reversing it becomes :%s\n",string);
    string_reversal(string, 21, 26);
    printf("\nAfter reversing it becomes :%s\n",string);
}