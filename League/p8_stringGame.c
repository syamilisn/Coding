#include <stdio.h>  // score = 43
#include <string.h>
void game(char *s){
    int flag = 1;
    /*
        flag = 0; player1: lost (string has no repeating consecutive letters in 1st Try.)
        flag = 1; player1: won
        flag = 2; player1: lost; player2: won
    */
    int len = strlen(s);
    for(int i=0; i<len-1; i++){
        if(s[i] != '*' && s[i+1] != '*')
        {    if(s[i] != s[i+1])
                flag = 0;
            else{
                s[i] = '*', s[i+1] = '*';
                if(flag == 1)
                    flag = 2;
                else
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