#include <stdio.h>
#include <stdlib.h>
/* GLOBAL DECLARATIONS */
typedef char string[100];

typedef enum category {north = 1, south, chinese } group;

typedef struct Food{
    int id;
    string name;
    float cost;
    int group;
    int qty;    //food item order counter
}item;

static int empty = 1;   //flag to indicate status of menu (whether empty or not)
item order[100];    //globally declaring order list
int menu = 0;   //Number of menu items

FILE *database;

/* USER-DEFINED FUNCTIONS */
// order_food(){}

void create_menu(){
    if(empty){
        empty = 0;
        printf("added\n");
        fprintf(database, "hello\n");
        empty = 0;
    }
    else{
        order[menu].id = menu + 1;
        order[menu].qty = 0;
        printf(">> Enter dish:\n<dish>  <cost>  <group>\n");
        scanf("%s %f %d", order[menu].name, &order[menu].cost, &order[menu].group);
        printf("{%d, %s, ₹%.2f, %d} x %d\n", order[menu].id, order[menu].name, order[menu].cost, order[menu].group, order[menu].qty);    
        menu++;
        fprintf(database, "%d %s ₹%.2f %d %d", order[menu].id, order[menu].name, order[menu].cost, order[menu].group, order[menu].qty);
    }
}
// display_menu(){}
// display_report(){}

/* MAIN FUNCTION */
void main(){
    database = fopen("database.txt", "w+"); 
    int choice;
    int empty = 1;   //flag to indicate status of menu (whether empty or not)
    do{
        printf("0. Exit 1. Add dish 2. Remove dish\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:{
            create_menu();
            break;
        }
        case 2:{
            printf("dummy case 2: exit"); 
            break;
        }
        default:
            break;
        }

    }while(choice != 0);
    fclose(database);
}