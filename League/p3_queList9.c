#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    int group;
    struct Node* next;
}node;

node* create_node(int member, int grp){
    node* new = (node*)malloc(sizeof(node));
    new->data = member;
    new->group = grp;
    new->next = NULL;
    return new;
}
int find_group(int *que, int n, int mem, int g){
    int grp[g];
    // grp[0] = 0; //assign index of group 0 to grp[0]
    int j = 0;
    for(int i=0; i<g; i++){
        grp[i] = j;
        printf("%d ", grp[i]);
        j = j + que[j] + 1;
    }

    j = 0;

    for(int i=0; i<n; i++){
        if( mem == que[i]){
            while(i > grp[j]){
                j++;
            }
        }
    }
    printf("Group number of %d is %d.\n", mem, j);
    return j;   //either j or j-1 (returns group number of member)
    // j: if group numbers start from 1,2,3... 
    // j-1: if group numbers start from 0,1,2...
}
void main(){
    node* head = NULL;
    int choice, member, temp_group;
    int g = 2;
    int que[2002] = {3,101,102,103,3,201,202,203};  //size = g * 1001
    int count=8;    //track number of elements
    int count2 = 0; //to get count of que
    char str[10];
    do{
        printf("Enter choice:\n");
        scanf("%s", str);
        if(strcmp(str, "s") == 0) choice = 0;
        else if(strcmp(str, "e") == 0) choice = 1;
        else if(strcmp(str, "d") == 0) choice = 2;
        
        switch(choice){
            case 0: {
                printf("***STOP***\n");
                //STOP  AND PRINT
                break;
            }
            case 1: {
                //  ENQUEUE BEGINS
                scanf("%d", &member);    //input member to be added to Queue
                if(head == NULL){
                    temp_group = find_group(que, count, member, g);
                    head = create_node(member, temp_group);
                    count2 = 1;
                }
                else{
                    node* temp = head;
                    temp_group = find_group(que, count, member, g);
                    node* new = create_node(member, temp_group);
                    while(temp->next != NULL){
                        temp = temp->next;
                    }
                    temp->next = new;
                    count2 += 1;
                }

                //PRINT LIST
                node* temp = head;
                while (temp->next != NULL)
                {
                    printf("(group %d = %d)->", temp->group, temp->data);
                    temp = temp->next;
                }
                printf("(group %d = %d)\n", temp->group, temp->data);

                //LOGIC TO ARRANGE IN ORDER
                printf("\nQue count = %d\n", count2);
                int ans[count2];
                // node* ptr = head;

                node* prev = head;
                node* current = prev->next;
                node* next1 = current->next;
                node* t;

                while(next1->next != NULL){
                    if(current->group > next1->group){
                        prev->next = next1;
                        t = current;
                        current->next = next1->next;
                        next1->next = t;
                    }
                }
                //END OF ARRANGE LOGIC
                //PRINT LIST 2
                node* temp1 = head;
                while (temp1->next != NULL)
                {
                    printf("(group %d = %d)->", temp1->group, temp1->data);
                    temp1 = temp1->next;
                }
                printf("(group %d = %d)\n", temp1->group, temp1->data);

                break;
            }
            case 2: {
                //  DEQUEUE
                break;
            }
            default: {
                printf("Wrong choice.\n");
                break;
            }
        }
    }while(choice);
}