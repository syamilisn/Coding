/*
    INSERT/ DELETE ELEMENTS AT BEGINNING OF LINKED LIST
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;
node* create_node(node* head){
    if(head == NULL){
        head = (node*)malloc(sizeof(node));
        printf("Enter head node data: ");
        scanf("%d", &head->data);
        head->next = NULL;
        return head;
    }
    else{
        node* new = (node*)malloc(sizeof(node));
        printf("Enter node data: ");
        scanf("%d", &new->data); 
        new->next = head;   //INSERT AT BEGINNING
        head = new;
        return head;
    }
}
node* delete_node(node* head){
    if(head == NULL){
        printf("List is empty.\n");
    }    
    else{
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }   
}
void print_list(node* n){
    printf("LIST: ");
    while(n != NULL){
        printf("%d->", n->data);
        n = n->next;
    }
    printf("\n");
}
void main(){
    int n, i, choice;
    node* head = NULL;

    do{
        printf("Press 1: insert, 2: delete, 0: exit\nCHOICE: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                        printf("Insert element at start:\n");
                        head = create_node(head);
                        //printf("List after insertion:\n");
                        print_list(head);
                        break;
            }
            case 2: {
                        printf("Delete element at start:\n");
                        head = delete_node(head);
                        //printf("List after deletion:\n");
                        print_list(head);
                        break;
            }
            default:{
                        printf("Exit choice.\n");
                        printf("Final list:\n");
                        print_list(head);
            }
        }
    }while(choice);
}