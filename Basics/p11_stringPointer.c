#include <stdio.h>
typedef char string[100];
void main(){
    string s1 = "comp", s2 = "uter";
    string *str = s1;
    *str[0] = 'C';
    printf("%s", str);
}