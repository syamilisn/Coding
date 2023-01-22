#include <stdio.h>
enum prompt{ STOP, ENQUEUE, DEQUEUE};
void main(){
    int g = 1;
    int arr[1][1000] = {1,38024};
    enum prompt choice;
    choice = ENQUEUE;
    int x; //Enter member
    int que[1000000];
    do{
        scanf("%d", &choice);
        switch(choice){
            case 0: {
                //  ENQUEUE BEGINS
                printf("enq");
                //  ENQUEUE ENDS
                break;
            }
            case 1: {
                //  DEQUEUE BEGINS
                printf("deq");
                //  DEQUEUE ENDS
                break;
            }
            case 2: {
                printf("stop");
                //STOP
                break;
            }
            default: {
                printf("Wrong choice.\n");
                break;
            }
        }
    }while(choice);
}