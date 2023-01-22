/*
    INSERT/ DELETE ELEMENTS AT END OF LINKED LIST
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
        node* temp;
        printf("Enter node data: ");
        scanf("%d", &new->data); 
        //INSERT AT END
        temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = new;
        new->next = NULL;   //without this, infinite pointers will be creates
        return head;
    }
}
node* delete_node(node* head){
    if(head == NULL){
        printf("List is empty.\n");
    }    
    else{
        node* temp = head;
        while(temp->next->next != NULL)   temp = temp->next;
        free(temp->next);
        temp->next = NULL;
        return head;
    }   
}
void print_list(node* n){
    printf("LIST:");
    while(n != NULL){
        printf(" %d->", n->data);
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
                        exit(0);    //to avoid infinite execution in case of wrong console input
            }
        }
    }while(choice);
}