#include <stdio.h>
#include <string.h>
typedef struct{
    int member;
    int group;
}queue;
int findGroup(int x, int g, int arr[][1001]){
    int index = -1;
    for(int i=0; i<g; i++){
        for(int j=0; j<arr[i][0]; j++){
            if(x == arr[i][j])
                index = i; //store index of group
        }
    }
    printf("Ret index = %d\n", index);
    return index;
}
void main(){
    int g = 2;
    int arr[2][1001] = {
        {3, 101, 102, 103},
        {3, 201, 202, 203}
    };
    char str[10];
    int choice;
    int x, index, index2; //Enter member
    // int que[1000000];
    // int que[g*1000];
    queue que[g*1000];
    int front = -1, rear = -1;
    
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
                printf("***ENQUEUE*** member = %d; Front = %d, Rear = %d\n", x, front, rear);
                //  MAIN LOGIC BEGINS
                if(rear == -1){
                    ++rear;
                    ++front;
                    que[rear].member = x;
                    que[rear].group = findGroup(x, g, arr);
                }
                else{
                    //++rear;
                    int temp_grp = findGroup(x, g, arr);
                    int temp_index;
                    for(int i = front; i < rear; i++){
                        if(que[i].group == temp_grp){
                            int j = i;
                            // while(que[i].group == temp_grp){
                            //     i+=1;
                            // }
                            while(j < rear){
                                if(que[j].group == i){
                                    temp_index = j;
                                }
                                j++;
                            }
                            temp_index = j; // j or j-1
                        }
                    }
                    for(int i = rear; i >= temp_index; i--){
                        que[i+1].member = que[i].member;
                    }
                    que[temp_index].member = x;
                    que[temp_index].group = temp_grp;
                    ++rear;
                }

                //  MAIN LOGIC ENDS
                
               
                //print Que
                for(int i=front; i<=rear; i++)
                    printf("%d-%d ", que[i].member, que[i].group);
                printf("\n");
                //  ENQUEUE ENDS
                break;
            }
            case 2: {
                //  DEQUEUE BEGINS
                printf("***DEQUEUE*** deleted = %d\n", que[front++].member);
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