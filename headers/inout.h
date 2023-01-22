#include <stdio.h>

int scan(char variable){
    printf("%c >> ", variable);
    int x;
    scanf("%d", &x);
    return x;
}
void print(char prompt[100], int x){
    printf("%s%d\n", prompt, x);
}


char scanc(int x){
    scanf("%d", &x);
    return x;
}
void printc(int x){
    printf("%c", x);
}

char* scans(char *str){
    scanf("%s", str);
    return str;
}
void prints(char *str){
    printf("%s", str);
}