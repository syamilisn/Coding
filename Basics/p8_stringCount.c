// Online C compiler to run C program online
#include <stdio.h>
void main() {
    int count = 0;
    char s[10] = "computer";
    char *ptr_s = s;
    printf("Enter string:\n");
    //for(count = 0; *ptr_s != '\0'; count++)     ptr_s++;  METHOD 1
    //for(count = 0; s[count] != '\0'; count++){}           METHOD 2
    while(s[count]!= '\0')      count++;                  //METHOD 3

    printf("The length of string \"%s\" is %d\n", s, count);
}