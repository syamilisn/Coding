#include <stdio.h>
#include <string.h>
typedef char string[20];
int i, j, count;
int stringCount(string s){
    /* RETURN STRING LENGTH */
    //int count = 0;
    for(count = 0; *s != '\0'; count++)     s++; //works only for pointers to string. Not direct string itself.
    return count;
}
void stringReverse(string s, int n){
    /* RETURN STRING REVERSE */

 char *ptr_s;
 ptr_s = s;
 printf("%s\n", s);
 //for(i=n; i>0; i++) {}
}
void main(){
    int strlen1, strlen2;
    string s1 = "Sasken";
    string s2 = "Technologies";
    printf("String is \"%s\"\n",s1);
    printf("String is \"%s\"\n",s2);
    printf("Reverse of \"%s\" is \"%s\"\n", s1, s1);
    strlen1 = stringCount(s1);
    strlen2 = stringCount(s2);
    printf("The length of string \"%s\" is %d\n", s1, strlen1);
    printf("The length of string \"%s\" is %d\n", s2, strlen2);

    //stringReverse(s1, strlen);

}