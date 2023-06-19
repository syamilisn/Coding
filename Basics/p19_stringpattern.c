// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
int main() {
    // Write C code here
    char str[100] = "aaabbcccaa";
    int n = strlen(str);
    int start_index = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j = start_index; j<n+1; j++){
            if(str[start_index] == str[j])
                count++;
            else{
                printf("%c%d", str[start_index], count);
                start_index = j;
                count = 0;
                break;
            }
        }
    }
	printf("\n");
    return 0;
}
