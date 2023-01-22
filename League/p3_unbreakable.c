#include <stdio.h>

void shift(int ptr_arr[], int m, int n, int size){
    char c_tes = '*';

    // MAIN LOGIC BEGINS
    int *temp = ptr_arr;
    for(int i=m; i<=n; i++){
        ptr_arr[i-1] = 0;
    }
    // MAIN LOGIC ENDS
    for(int i=0;i<size;i++){
        if(temp[i+1] == 0 && temp[i]!= 0){
            printf("%d ",temp[i]);
            break;
        }
        else{
            if(temp[0]==0){
                printf("%c ",c_tes);
                break;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(temp[i-1] == 0 && temp[i]!= 0){
            printf("%d\n",temp[i]);
            break;
        }
        else{
            if(temp[size-1]==0){
                printf("%c\n",c_tes);
                break;
            }
        }
    }
}
void main(){
    int i, j=0, a, b, k, m, n, *ptr_arr, size;
    //printf("Enter array size (a:b):\n");
    scanf("%d%d",&a,&b);
    size = b-a+1;
    int arr[size];
    for(i=a;i<=b;i++)
        arr[j++] = i;
    //ptr_arr = arr;
    //printf("Enter num of breakages:\n");
    scanf("%d", &k);
    int arr_m[k], arr_n[k];
    //printf("\n");
    for(i=0; i<k; i++)
        scanf("%d%d", &arr_m[i], &arr_n[i]);
    // }
    // while(k>0){
    //     k--;
    //     //printf("Enter range(m:n):\n");
    //     scanf("%d%d",&m,&n);
    //     //shift(ptr_arr, m, n, size);
    // }
    for(i=0; i<k; i++)
        shift(arr, arr_m[i], arr_n[i], size);
    
}