#include <stdio.h>
#include <string.h>
void main(){
    int i,n, count=0;
    char str[200], *p_str;
    //printf("Enter String:\n");
    scanf("%[^\n]s",str);
    p_str = str; //pointer points to string
    n = strlen(str);
    for(i=0; i<n; i++){
        if (*p_str == 's' || *p_str == 'S'){
            if(*(p_str+1 )== 'a' || *(p_str+1 )== 'A'){
                if(*(p_str+2) == 's' || *(p_str+2) == 'S'){
                    if(*(p_str+3) == 'k' || *(p_str+3) == 'K'){
                        if(*(p_str+4) == 'e' || *(p_str+4) == 'E'){
                            if(*(p_str+5) == 'n' || *(p_str+5) == 'N'){
                                count++;
                            }
                        }
                    }
                }
            }
        }
        p_str++;
    }
    if(count == 0)
        printf("Hello, World!");
    else{
        printf("Hello, Sasken");
        while(count>0){
            count-=1;
            printf("%c",'!');
        }
    }
    
}