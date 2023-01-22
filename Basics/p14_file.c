#include <stdio.h>

void write_file(){
    FILE *database = fopen("","");
}

void read_file(){

}
void main(){
    int choice;
    
    do{
        printf("Enter choice: 0-exit, 1-write, 2-read\n>> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:{
            printf("Writing to file:\n");
            write_file();
            break;
        }
        
        case 2:{
            printf("Reading from file:\n");
            read_file();
            break;
        }
        default:
            printf("Exit program!\n");
            break;
        }
        
    }while (choice);
    
}