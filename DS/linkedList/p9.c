#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
typedef struct Node{
	int data;
	char string[SIZE];
	struct Node* next;
}node;

node* create_node(){
	node* new = (node*)malloc(sizeof(node));
	printf("Enter integer value: ");
	scanf("%d", &new->data);
	printf("Enter string value: ");
	scanf("%s", new->string);
	return new;
}

node* insert(node* n){
	node* new = create_node();
	new->next = n;
	printf("\n");
	return new;
}

void print_list(node* n){
	while(n != NULL){
		printf("{Integer: %d, String: %s}\n",n->data, n->string); 
		n = n->next;
	}
}

void delete(node* n){
	node* temp = n;
	n = n->next;
	
}

void main(){
	int n, i;
	printf("Head Node:\n");
	node* head = create_node();
	printf("Enter the number of list elements:\n");
	scanf("%d",&n);
	printf("Enter list elements:\n");
	for(i=0; i<n-1; i++)	head = insert(head);

	print_list(head);
}
