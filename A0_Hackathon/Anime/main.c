#include <stdio.h>
typedef struct student{
    int id;
    char name[20];
}list;
void main(){
    list s1 = {1, "Syamili"};
    printf("%d %s", s1.id, s1.name);
}