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
    int x, index; //Enter member
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
                    //  logic begins
                    for(int i=0; i<g; i++){
                        for(int j=0; j<arr[i][0]; j++){
                            if(x == arr[i][j])  index = i; //store index of group
                        }
                    }
                    
                    // for(int i=1; i<arr[index][0]; i++){
                        
                    // }
                    // for(int i=0; i<rear; i++){
                    //     int k = 0;
                    //     for(int j=0; j<arr[j][0]; j++){
                    //         if(que[i] == arr[j][k++]){
                                
                    //         }
                    //     }
                    // }
                    //  logic ends  
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