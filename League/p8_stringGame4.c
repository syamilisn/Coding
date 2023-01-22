#include <stdio.h>  //linked list
#include <stdlib.h>
typedef struct Node
{   char ch;
    struct Node *next;
}node;

void print_list(node *head){
    node *temp = head;
    while(temp->next != NULL){
        printf("%c", temp->ch);
        temp = temp->next;
    }
    printf("%c", temp->ch);
}
void create_node(node *head, char letter){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->ch = letter;
    if(head == NULL){
        newnode->next = NULL;
    }
    else{
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void main(){

    char string[100000] = "noon";
    // scanf("%s", string);
    // game(string);
    ///
    node *head = NULL;
    int i = 0;  //str len
    while(string[i] != '\0'){
        create_node(head, string[i]);
        i++;
    }

    print_list(head);
    
}