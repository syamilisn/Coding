//OPENING FILE
#include <stdio.h>

void main(){
    FILE *anime;
    char ch;
    anime = fopen("anime.txt","r");
    while ( 1 ){
    ch = fgetc ( anime ) ;  
    if ( ch == EOF )  
        break ;  
        printf("%c",ch) ;  
    }  
    fclose (anime) ; 
}