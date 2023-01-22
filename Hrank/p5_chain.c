#include <stdio.h>

void shift(int *ptr_arr, int m, int n, int size){
    // MAIN LOGIC BEGINS
    for(int i=m; i<=n; i++){
        ptr_arr[i-1] = 0;
    }
    // MAIN LOGIC ENDS
    printf("Array after shifting is:\n");
    for(int i=0;i< size; i++)
        printf("%d ",ptr_arr[i]);
}
void main(){
    int i, j=0, a, b, k, m, n, *ptr_arr, size;
    printf("Enter array size (a:b):\n");
    scanf("%d%d",&a,&b);
    //n = b-a+1;  //total num of elements
    //printf("%d\n",n);
    size = b-a+1;
    int arr[size];
    for(i=a;i<=b;i++)
        arr[j++] = i;
    ptr_arr = arr;
    printf("Enter num of breakages:\n");
    scanf("%d", &k);
    printf("List is:\n");
    for(i=0;i< size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    /************** END OF ARRAY INPUT ********************/
    while(k>0){
        k--;
        printf("Enter range(m:n):\n");
        scanf("%d%d",&m,&n);
        shift(ptr_arr, m, n, size);
    }
}