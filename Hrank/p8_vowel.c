#include <stdio.h>
#include <string.h>
int isVowel(char c){
    switch(c){
        case 'a': return 1;
        case 'e': return 1;
        case 'i': return 1;
        case 'o': return 1;
        case 'u': return 1;
        default: return 0;
    }
}
void sort_string(char *ptr_str, int n){
    int i=0, j=0;
    char temp;
    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(ptr_str[j] > ptr_str[j+1]){
                temp = ptr_str[j], 
                ptr_str[j] = ptr_str[j+1], 
                ptr_str[j+1] = temp;
            }
        }
    }
    //printf("%s\n", ptr_str);
}
void main(){
    int i=0, j=0, k=0, tmp;
    char s1[10] = "apio";
    char s2[10] = "ipau";
    char str1[10]="", str2[10]="";
    sort_string(s1,strlen(s1));
    sort_string(s2,strlen(s2));
    while(s1[i] != '\0'){
        if(isVowel(s1[i])){
            str1[j] = s1[i];
            j++;    //count of vowels of s1
        }
        if(isVowel(s2[i])){
            str2[k] = s2[i];
            k++;    //count of vowels of s2
        }
        i++;
    }
        
    if(strcmp(str1, str2) == 0)
        printf("common no. of vowels, count = %d", j);
    else
        printf("uncommon no. of vowels.");
}