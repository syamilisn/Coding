#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	char string[50];
}node;

node* create_node(int d, char s[5]){
	node* new = (node*)malloc(sizeof(node));
	new->data = d;
	new->string = s;
	return new;
}

void main(){
	node* head = create_node(1,"head");
	

}

