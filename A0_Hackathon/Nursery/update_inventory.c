#include <stdio.h>

typedef char string[150];
void main(){

    int id;
    int cat_id;   //  category id
    string cat_name;    //  category name
    int subcat_id;  //  sub-category id
    string subcat_name;
    string item_name;   // item name
    int qty;  //  available quantity
    float price;

    
    int choice = 0;
    do{    
        printf("Enter 1/0: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            FILE *fp = fopen("save.txt", "a");
            printf("Enter item:\n[id, cat_id, cat_name, subcat_id, subcat_name, item_name, qty, price]\n");
            scanf("%d %d %s %d %s %s %d %f", &id, &cat_id, cat_name, &subcat_id, subcat_name, item_name, &qty, &price);
            fprintf(fp, "%d %d %s %d %s %s %d %.2f\n", id, cat_id, cat_name, subcat_id, subcat_name, item_name, qty, price);
            printf("Database updated successfully!");
            fclose(fp);
        }
            break;
        
        default:
            printf("Database saved.");
            exit(0);
        }

    }while(choice);
    
}