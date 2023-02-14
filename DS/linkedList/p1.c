#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node* link;
}node;

void create(node *head){
	node newnode = (node)malloc(sizeof(node));
	printf("Enter node data: \n");
	scanf("%d", &newnode->data);
	if(head == NULL){
		newnode->link = NULL;
		head = newnode;
	}
	else{
		//Insert at beginning
		newnode->link = head;
		head = newnode;
	}
	
}

void main(){
	node *head = NULL;
	node *n1 = (node*)malloc(sizeof(node));
	n1->data=10;
	node *n2 = (node*)malloc(sizeof(node));
	n2->data=20;
	node *n3 = (node*)malloc(sizeof(node));
	n3->data=30;
	n1->link = n2;
	n2->link = n3;
	n3->link = NULL;
	
	node* temp = n1;
	while(temp->link != NULL){
		printf("%d->",temp->data);
		temp = temp->link;
	}
	printf("%d->",temp->data);

	printf("Enter number of nodes:\n");
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++)
		create(head);

	temp = head;
	while(temp->link != NULL){
		printf("%d->",temp->data);
		temp = temp->link;
	}
	printf("%d->",temp->data);


	
}
