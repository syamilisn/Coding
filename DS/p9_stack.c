#include <stdio.h>
int maxsize = 8;
int stack[8];
int top = -1;
void push(int ele){
    if(top == maxsize-1)  
        printf("Stack is full.\n");
    else{
        stack[++top] = ele;
    }
}
void pop(){
   if(top == -1)
        printf("Stack is empty.\n");
    else
        printf("Deleted element: %d\n", stack[top--]);
}

void display(){
    printf("Stack elements: ");
    if(top > -1){
        for(int i=0; i <= top; i++)
            printf("%d ", stack[i]);
    }
    else    
        printf("Empty stack, nothing to display!");
    printf("\n");
}
void main(){
    int choice = 0;
    int ele;
    do{
        printf("Enter choice: 1. Push item, 2. Pop item, 3. Display stack:\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Insert element: ");
                    scanf("%d", &ele);
                    push(ele);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            default: printf("End of stack operations. Thank you!!!"); 
                    choice = 0;
        }
    }while(choice);
}