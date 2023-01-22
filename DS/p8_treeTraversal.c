#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}node;

node* create_node(int d){
	node* new = (node*)malloc(sizeof(node));
	new->data = d;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void print_inorder(node* node){
	if(node == NULL)	return;
	print_inorder(node->left);
	printf("%d ", node->data);
	print_inorder(node->right);
	
}

void print_preorder(node* node){
	if(node == NULL)	return;
	printf("%d ", node->data);
	print_preorder(node->left);
	print_preorder(node->right);
	
}

void print_postorder(node* node){
	if(node == NULL)	return;
	print_postorder(node->left);
	print_postorder(node->right);
	printf("%d ", node->data);
}
void main(){
	node* root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	
	printf("Inorder Traversal:\n");
	print_inorder(root);	
	printf("\n");
	
	printf("Preorder Traversal:\n");
	print_preorder(root);	
	printf("\n");
	
	printf("Postorder Traversal:\n");
	print_postorder(root);	
	printf("\n");
}
