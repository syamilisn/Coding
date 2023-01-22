#include <stdio.h>
#include <string.h>
typedef struct{
    int member;
    int group;
}queue;
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
                
                //  logic 1 begins (storing group of new member)
                    for(int i=0; i<g; i++){
                        for(int j=0; j<arr[i][0]; j++){
                            if(x == arr[i][j])  {
                                index = i; //store index of group
                                break;
                            }
                            else index = -1;    //member doesn't belong to any group
                        }
                    }
                    printf("Index = %d\n", index);
                //  logic 1 ends  

                //  logic 2 begins (add que members with individual groups)
                    
                    for(int k = front; k < rear; k++){
                        for(int i = 0; i < g; i++){
                            for(int j = 0; j < arr[i][0]; j++){
                                if(que[k].member == arr[i][j])
                                    que[k].group = i;
                            }
                        }
                    }
                //  logic 2 ends

                //  logic 3 starts  (adding at the end of list; comparing index/ groups)
                    if(index == -1){
                        que[rear++].member = x;
                        // que.group = -1;
                    }
                    else{
                        for(int i = front; i < rear; i++){
                            if(que[i].group == index){
                                while (que[i].group == index)
                                {
                                    i++;
                                }
                                index2 = i;
                                break;
                            }
                        }

                        for(int i = index2; i < rear+1; i++){
                            que[i+1].member = que[i].member;
                        }
                        que[index2].member = x;
                    }
                //  logic 3 ends
                //print Que
                for(int i=front; i<rear; i++)
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