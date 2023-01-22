#include <stdio.h>  // score 55
#include <string.h>
void game(char *s){
    int flag = 1;
    /*
        flag = 0; player1: lost (string has no repeating consecutive letters in 1st Try.)
        flag = 1; player1: won
        flag = 2; player1: lost; player2: won
    */
    int len = strlen(s);
    if(len < 2){
        printf("No");
        return;
    }
    else if(len == 2){
        if(s[0] == s[1]){
            printf("Yes");
        }
        else{
            printf("No");
        }
        return;
    }

    for(int i=0; i<len-1; i++){
        if(s[i] != '*' && s[i+1] != '*')
        {    if(s[i] != s[i+1])
                flag = 0;
            else{
                s[i] = '*', s[i+1] = '*';
                if(flag == 1)
                    flag = 2;
                else  if(flag == 2)
                    flag = 1;
            }
        }    
        else{
            int next_index;
            {
                char *s2 = s;
                next_index = i+1;
                while(s2[next_index] != '\0'){  //scan till next star is reached
                    if(s2[next_index] == '*')
                        next_index++;
                    else
                        break;
                }
            }
            if(s[i] != s[next_index])
                flag = 0;
            else{
                s[i] = '*', s[next_index] = '*';
                if(flag == 1)
                    flag = 2;
                else if(flag == 2)
                    flag = 1;
            }
        }
    }

    if(flag == 1)   printf("Yes \n");
    else printf("No \n");
}
void main(){
    char string[100000];
    scanf("%s", string);
    game(string);
}