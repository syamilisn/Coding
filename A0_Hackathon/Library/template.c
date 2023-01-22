#include <stdio.h>
#include <string.h>
#define getName(var)  #var  //to get variable name as string
typedef char string[100];

void file_write(FILE *fp){
    // return 0;
    string data;
    fscanf(fp, "%[^\n]s", data);
    printf("Data >> %s", data);
}
void file_read(FILE *fp){
    // return 0;
    fprintf(fp, "My name is NOT yam!");
}
void file(string data, string mode, string operation){
    FILE *fp = fopen(data, mode);
    if(strcmp(operation, "read")) {
        file_read(fp);
    }
    else if(strcmp(operation, "write")){
        file_write(fp);
    }
    fclose(fp);
}
void main(){
    int choice = 2;
    // string func1 = getName(choice);
    string file_read = "read";
    // printf("%s \n", func1);
    switch (choice)
    {
    case 1:
        {
        printf("write file \n");    
        file("dum.txt", "w", "write");
        }
        break;
    
    case 2:
        {
        printf("read file \n");    
        file("dum.txt", "r", "read");
        }
        break;
    default:
        break;
    }
}