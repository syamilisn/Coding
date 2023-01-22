#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int data;
    struct node* next;
}node;
node* create_node(){
    node* n = (node *)malloc(sizeof(node));
    return n;
}
void main(){
    node* head = NULL;
    node* temp = NULL;
    head = create_node();
}