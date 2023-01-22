/* 
    CURRENTLY CORRECT- WITHOUT SCAN STATS.
    SCORE : 33.33
*/
#include <stdio.h>
#include <string.h>
typedef struct{
    int member;
    int group;
}queue;
int findGroup(int x, int g, int arr[][1001]){
    int index = -1;
    for(int i=0; i<g; i++){
        for(int j=0; j<=arr[i][0]; j++){
            if(x == arr[i][j])
                index = i; //store index of group
        }
    }
    // printf("Ret index = %d\n", index);
    return index;
}

void sort(queue *que, int n){ //n is value of rear
    int t;
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)
            if(que[j].group > que[j+1].group)
                t = que[j].group, que[j].group = que[j+1].group, que[j+1].group = t;
    // return que;
}
void main(){
    // printf("Enter g:\n");
    int g;
    scanf("%d", &g);
    // printf("Enter arr:\n");
    int arr[g][1001];
    for(int i=0; i<g; i++){
        int temp = 1;
        for(int j=0; j<=temp; j++){
            scanf("%d", &arr[i][j]);
            if(j == 0)
                temp = arr[i][j];
        }
    }
    char str[10];
    int choice;
    int x, index, index2; //Enter member
    // int que[1000000];
    // int que[g*1000];
    queue que[g*1000];
    int front = -1, rear = -1;
    int ans[g*1000], count = 0;

    do{
        // printf("Enter choice:\n");
        scanf("%s", str);
        if(strcmp(str, "STOP") == 0) choice = 0;
        else if(strcmp(str, "ENQUEUE") == 0) choice = 1;
        else if(strcmp(str, "DEQUEUE") == 0) choice = 2;
        switch(choice){
            case 0: {
                // printf("***STOP***\n");
                //STOP
                for(int i=0; i<count; i++)
                    printf("%d ", ans[i]);
                break;
            }
            case 1: {
                //  ENQUEUE BEGINS
                scanf("%d", &x);    //input member to be added to Queue
                // printf("***ENQUEUE*** member = %d; Front = %d, Rear = %d\n", x, front, rear);
                //  MAIN LOGIC BEGINS
                if(rear == -1)  front = ++rear;
                else    ++rear;
                
                que[rear].member = x;
                que[rear].group = findGroup(x, g, arr);
                //  MAIN LOGIC ENDS
                
               
                // //print Que
                // for(int i=front; i<=rear; i++)
                //     printf("%d-%d ", que[i].member, que[i].group);
                // printf("\nSORTED ARRAY:\n");
                
                //sort and print que
                    // que = sort(que, rear);
                
                int temp, n = rear+1;
                for(int i=0; i<n; i++)
                    for(int j=0; j<n-i-1; j++)
                        if(que[j].group > que[j+1].group){
                            temp = que[j].group, que[j].group = que[j+1].group, que[j+1].group = temp;  //swap
                            temp = que[j].member, que[j].member = que[j+1].member, que[j+1].member = temp;  //swap
                        }
                // for(int i=front; i<=rear; i++)
                //     printf("%d-%d ", que[i].member, que[i].group);
                // printf("\n");
                //  ENQUEUE ENDS
                break;
            }
            case 2: {
                //  DEQUEUE BEGINS
                if(front <= rear)
                    // printf("%d\n", que[front++].member);
                    ans[count++] = que[front++].member;
                else
                    break;
                //  DEQUEUE ENDS
                break;
            }
            default: {
                // printf("Wrong choice.\n");
                break;
            }
        }
    }while(choice);
}