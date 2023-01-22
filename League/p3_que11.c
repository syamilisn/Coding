// Online C compiler to run C program online
#include <stdio.h>
int doesnt_exist(int member, int row, int col, int arr[][col]){
    for(int i=1; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == member)
                return 0;
        }
    }
    return 1;
}
int find_group(int x, int row, int col, int arr[][col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == x)
                return i;
        }
    }
}
int member_of_group_exists(int grp_x, int que[], int n){
    
    return;
}
int main() {
    int g = 2;
    int n = 0;  //to count queue elements
    int row = g + 1;    //grouping start from 1
    int col = 1000 + 1;
    // int arr[row][col];
    int arr[3][1001] = {
        {0},
        {3,101,102,103},
        {3,201,202,203}
    };
    int count = 0;  //number of elements that do not belong to any group (added to group 0 in 2D arr)
    // for(int i=1; i<row; i++){
    //     int temp = 1;
    //     for(int j=0; j<=temp; j++){
    //         scanf("%d", &arr[i][j]);
    //         if(j == 0)
    //             temp = arr[i][j];
    //     }
    // }
    
    ///////
    /*
    int n = 6, t;
    int arr[6] = {101,201,102,202,103,203};
    int grp[6] = {1,2,1,2,1,2};
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)  
            if(grp[j] > grp[j+1]){
                t = grp[j], grp[j] = grp[j+1], grp[j+1] = t;
                t = arr[j], arr[j] = arr[j+1], arr[j+1] = t;
            }
            
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
        
        */
    int que[1000000]={-1};
    char str[10];
    int choice;
    int x, index, index2; //Enter member
    
    do{
        printf("Enter choice:\n");
        scanf("%s", str);
        if(strcmp(str, "s") == 0) choice = 0;
        else if(strcmp(str, "e") == 0) choice = 1;
        else if(strcmp(str, "d") == 0) choice = 2;
        
        switch(choice){
            case 0: {
                printf("***STOP***\n");
                //STOP
                break;
            }
            case 1: {
                //  ENQUEUE BEGINS
                scanf("%d", &x);    //input member to be added to Queue
                if( doesnt_exist(x, row, col, arr) ){
                    arr[0][count++] = x;
                }
                
                    if( que[0] == -1 ){
                        que[0] = x; //initialize first element
                        n = 1;
                    }
                    else{
                        n += 1;
                        int grp_x = find_group(x, row, col, arr);
                        int last_mem_index = member_of_group_exists(grp_x, que, n);
                        if( last_mem_index == 0){ 
                            que[n] = x;
                            //ADD AT END OF QUE
                        }
                        else{
                            for(int i=n-1; i>= last_mem_index; i--){
                                que[i+1] = que[i];
                            }
                            que[ last_mem_index ] = x;
                        }
                    }
                
                
                //  ENQUEUE ENDS
                break;
            }
            case 2: {
                if(n>0)
                    n-=1;
                //  DEQUEUE BEGINS
                //  DEQUEUE ENDS
                break;
            }
            default: {
                printf("Wrong choice.\n");
                break;
            }
        }
    }while(choice);
    return 0;
}