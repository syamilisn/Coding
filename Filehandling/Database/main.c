#include <stdio.h>

// typedef union Header{
//     int a;
//     char b[20];
// }field;
struct Table{
    const unsigned int id;
    char anime[100];
    char name[50];
};

scan_file(FILE *database, struct Table tuple){
    // tuple.id

    // scanf("%d", )
    if(database == NULL)
        fprintf(database, "ID\tANIME\t\tNAME\n");

    else{
        
        // scanf()
    }
}

print_file(FILE *database){
    //TO PRINT FILE CONTENTS
    char ch;
    while(1){
        ch = fgetc(database);
        if(ch == EOF)
            break;
        printf("%c", ch);
    }
}
main(){
    FILE *database = fopen("database.txt", "w+");
    struct Table tuple; 
    int id = 0;
    print_file(database);
    scan_file(database, tuple);

    fclose(database);
    // return 0;
}