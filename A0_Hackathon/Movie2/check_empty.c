#include <stdio.h>
void main(){
    FILE *fp = fopen("screen_info.txt", "r+");
    {
        if(fgetc(fp) == EOF)  printf("yes \n"); //check empty file
        else    printf("no \n");
    }
    fclose(fp);
}