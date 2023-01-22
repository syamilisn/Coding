#include <stdio.h>
#include <string.h>
#include "declare.h"

struct Info info;

void file(string data, string mode, string operation){
    FILE *fp = fopen(data, mode);
    if(!strcmp(operation, "rinfo")){
        fscanf(fp, "%d %d %d %d", &info.n, &info.m, &info.x, &info.y);  
    }
    else if(!strcmp(operation, "winfo")){
        fprintf(fp, "%d %d %d %d", info.n, info.m, info.x, info.y);  
    }
    fclose(fp);
}

void load_data(){
    // file("stats.txt", "r", "rstats");
    file("info.txt", "r", "rinfo");
}
void save_data(){
    // file("stats.txt", "w", "wstats");   
    file("info.txt", "w", "winfo");
}
void main(){
    load_data();

    {
        printf("info: %d %d %d %d \n", info.n, info.m, info.x, info.y);
        info.n += 1;
    }
    save_data();
}