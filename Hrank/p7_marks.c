#include <stdio.h>
int if_num_exists(int n, int *ptr_arr, int num){
    for(int i=0; i<n; i++){
        if(num == ptr_arr[i])
            return 1;
    }
    return 0;
}
int max_marks_func(int n, int *ptr_marks){
    int max_marks = ptr_marks[0];
    for(int i=0 ;i<n; i++){
        if(ptr_marks[i] > max_marks)
            max_marks = ptr_marks[i];
    }
    return max_marks;
}
void main(){
    int n = 5;
    int arr[5] = {1,4,5,4,5};
    int marks[5] = {0};
    int exists = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        exists = if_num_exists(i, arr, arr[i]);
        if(exists == 1){
            marks[i] = max_marks_func(n, marks) + 1;
            sum += marks[i];
            //marks[i] = sum;
        }
        else{
            marks[i] = arr[i];
            sum += marks[i];
        }
    }
    for(int i=0; i<n; i++){
        printf("marks of %d is %d \n", arr[i], marks[i]);
    }
    printf("Final sum is %d", sum);
}