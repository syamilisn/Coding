#include <stdio.h>
#include <string.h>
#include "declare.h"

static struct Stats stats;
static struct Info info;
// int info[4] = {0}; //maximum values (#oScreens, #oCounters, #oRows, #oColumns)

// void read_info(FILE *fp){
//     fscanf(fp, "%d %d %d %d", &info.n, &info.m, &info.x, &info.y);
//     printf("#oScreens: %d, #oCounters: %d, #oRows: %d, #oColums: %d \n", info.n, info.m, info.x, info.y);
// }
void file(string data, string mode, string operation){
    // main operations: read(data from file), write(data to file), print(print data to console), scan(scan data from console)
    FILE *fp = fopen(data, mode);

    if(fgetc(fp) == EOF && stats.flag == 0){
        printf("Load error: '%s' file empty!\nEnter n, m, x, y values: \n", data);
        scanf("%d %d %d %d", &info.n, &info.m, &info.x, &info.y);
        fprintf(fp, "%d %d %d %d", info.n, info.m, info.x, info.y);
        stats.flag = 1;
    }
    else if(!strcmp(operation, "read_info")){
        fscanf(fp, "%d %d %d %d", &info.n, &info.m, &info.x, &info.y);
    }
    else if(!strcmp(operation, "print_info")){
        printf("#oScreens: %d, #oCounters: %d, #oRows: %d, #oColumns: %d \n", info.n, info.m, info.x, info.y);
    }
    else if(!strcmp(operation, "write_info")){
        fprintf(fp, "%d %d %d %d", info.n, info.m, info.x, info.y);
    }
    else if(!strcmp(operation, "read_stats")){
        fscanf(fp, "%d", stats.flag);
    }
    else if(!strcmp(operation, "write_stats")){
        fprintf(fp, "%d", stats.flag);
    }
    else{
        "Operation failed!";
    }
    fclose(fp);
}

void load_data(){
    file("stats.txt", "r+", "read_stats");
    file("screen_info.txt", "r+", "read_info");  //loads screen info
}

void save_data(){
    file("stats.txt", "w", "write_stats");
    file("screen_info.txt", "w", "write_info");
    exit(0);
}
void main(){
    load_data();
        int choice;
    do{
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: //display screen info - admin
            {
                file("screen_info.txt", "r+", "print_info");
            }
            break;
        
        case 2: //display movie info
            {
                
            }
            break;
        default:
        printf("Come again! \n");
            break;
        }
    }while(choice);
    // flag = 1;
    save_data();
    
}