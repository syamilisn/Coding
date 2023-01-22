#include <stdio.h>

void main(){
    FILE *ptr_file = fopen("anime.txt", "r+");
    // char ch;
    // while(1){
    //     ch = fgetc(ptr_file);
    //     if(ch == EOF)
    //         break;
    //     printf("%c", ch);
    // }
    fprintf(ptr_file,"\nMy name is actually not Yam!");
    fclose(ptr_file);
}