#include <stdio.h>
#include <string.h>
void main(){
    int g = 2;
    int arr[2][1001] = {
        {3, 101, 102, 103},
        {3, 201, 202, 203}
    };
    char str[10];
    int choice;
    int x; //Enter member
    // int que[1000000];
    int que[g*1000];
    int front = 0, rear = 0;
    do{
        scanf("%s", str);
        if(strcmp(str, "STOP") == 0) choice = 0;
        else if(strcmp(str, "ENQUEUE") == 0) choice = 1;
        else if(strcmp(str, "DEQUEUE") == 0) choice = 2;
        switch(choice){
            case 0: {
                printf("***STOP***\n");
                //STOP
                break;
            }
            case 1: {
                //  ENQUEUE BEGINS
                scanf("%d", &x);    //input member to be added to Queue
                printf("***ENQUEUE*** member = %d\n", x);
                que[rear++] = x;
                //  ENQUEUE ENDS
                break;
            }
            case 2: {
                //  DEQUEUE BEGINS
                printf("***DEQUEUE*** deleted = %d\n", que[front++]);
                //  DEQUEUE ENDS
                break;
            }
            default: {
                printf("Wrong choice.\n");
                break;
            }
        }
    }while(choice);
}