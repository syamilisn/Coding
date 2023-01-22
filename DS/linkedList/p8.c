#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
	int data;
	char string[50];
	struct Node* next;
}node;

node* create_node(){
	node* n = (node*)malloc(sizeof(node));
	return n;
}

void print_list(node* n){
	while(n != NULL){
		if(n->data != 0)
		printf("{Data: %d, String: %s}\n", n->data, n->string);
		n = n->next;
	} 
	printf("Reached end of list.\n");
}

node* insert_end(node* head){
	node* new = create_node();
	node* temp = head;
	printf("Enter the integer value: ");
	scanf("%d", &new->data);
	printf("Enter the string value: ");
	scanf("%s", new->string);
	
	printf("\n");
	// insert end logic:
	/*
		if 'temp' is used instead of 'temp->next' then segmentation fault (core dumped) error occurs at while loop.
	*/
	while(temp->next != NULL)	temp = temp->next;
	temp->next = new;
	new->next = NULL;
	return head;
}
node* delete_start(node* head){
	if(head == NULL){
		printf("No list elements\n");
		return head;
	}
	node* temp = head;
	head = head->next;
	temp = NULL;
	free(temp);
	//printf("The list elements after deleting start node (Delete Function):\n");
	print_list(head);
	return head;
}

void main(){
	int n, i;
	node* head = create_node();
	node* temp = head;
	printf("Enter the number of list elements:\n");
	scanf("%d", &n);
	while(n !=0 ){
		head = insert_end(head); n--;
	}

	printf("The list elements are:\n");
	print_list(head);
	
	head = delete_start(head);
	printf("The list elements after deleting start node:\n");
	print_list(head);
}

