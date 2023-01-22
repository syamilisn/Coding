#include <stdio.h>
#include <string.h>
typedef char string[50];
int i , j;
void main(){
    string s1;
    int n,i=0;
    //string *ptr_s1[20];
    printf("Enter the sentence: ");
    scanf("%[^\n]s",s1);    //to input a line
    n = strlen(s1);
    puts(s1);
    //LOGIC STARTS
    while(s1[i] != '\0'){
        if(s1[i] != ' ')
            printf("%c",s1[i]);
        else
            printf("\n");
        i++;
    }
}