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
node* insert_start(node* head){
	node* new = create_node();
	printf("Enter the integer value: ");
	scanf("%d", &new->data);
	printf("Enter the string value: ");
	scanf("%s", new->string);
	
	printf("\n");
	new->next = head;
	return new;
}

node* insert_middle(node* head, node* prev_node){
	if(prev_node != NULL){
		node* new = create_node();
		node* temp = head;
		printf("Enter the integer value: ");
		scanf("%d", &new->data);
		printf("Enter the string value: ");
		scanf("%s", new->string);
		
		printf("\n");
		// insert middle logic:
		while(temp->next != NULL){
			if(temp == prev_node){
				new->next = prev_node->next;
				prev_node->next = new;
			}
			temp = temp->next;
		}
		return head;
	}
}

void print_list(node* n){
	while(n != NULL){
		if(n->data != 0)
		printf("{Data: %d, String: %s}\n", n->data, n->string);
		n = n->next;
	} 
	printf("Reached end of list.\n");
}
void main(){
	int n, i;
	node* head = create_node();
	node* temp = head;
	node* prev_node = NULL;
	printf("Enter the number of list elements:\n");
	scanf("%d", &n);
	while(n !=0 ){
		head = insert_start(head); n--;
	}

	printf("The list elements before inserting are:\n");
	print_list(head);
	
	prev_node = head->next;
	head = insert_middle(head, prev_node); 
	printf("The list elements after inserting are:\n");
	print_list(head);
}

