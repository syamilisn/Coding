#include <stdio.h>
#include <string.h>
#define SIZE 44 //Number of items that can be bought from STORE to INVENTORY

//  USER DATATYPES:

typedef char string[200];

struct Item{
    int id;
    int cat_id;   //  category id
    string cat_name;    //  category name
    int subcat_id;  //  sub-category id
    string subcat_name;
    string item_name;   // item name
    int qty;  //  available quantity
    float price;
}item[SIZE];

typedef struct Transaction{
    int id;
    // int category; //1- owner buys(reduces amount), 2- owner sell to customer(increases amount)

    int item_id;
    int cat_id;   //  category id
    string cat_name;    //  category name
    int subcat_id;  //  sub-category id
    string subcat_name;
    string item_name;   // item name
    int qty;  //  available quantity
    float price;
    float total_price;
    
}transaction;

//  GLOBAL DECLARATIONS:

int choice = 0, quantity = 0;
int category_choice = 0, subcategory_choice = 0;
/******************************************************************/
//items that are store in moneydb.txt
float amount;   //  INITIAL = RS. 100000
float profit;   //  INITIAL = RS. 0
int inventory_count;    //count of items in inventory   INITIAL = 0
int transaction_count;  //count of transactions    INITIAL = 0
int trans_id;   //transaction id

/******************************************************************/

string prompt0 = "0. Save and Exit,\n1. Update Plants, 2. Update Accessories, 3. Update Fertilizers,\n4. Update Inventory, 5. Print Transactions, 6. Print Profit, 7. Buy Plants, 8. Buy Accessories, 9. Buy Fertilizers";

string prompt1 = "\n\t0. Save\n\t1. Flowering Plants\n\t2. Succulents\n\t3. Medicinal Plants\n\t4. Indoor Plants\n";
string prompt_flowering = "\n\t0. Save\n\t1. Jasmine\n\t2. Rose\n\t3. Chrysanthemum\n\t4. Hibiscus\n\t5.tuberose\n";
string prompt_succulent = "\n\t0. Save\n\t1. Lucky Jade\n\t2. Aloe Vera\n\t3. Cactus\n";
string prompt_medicinal = "\n\t0. Save\n\t1. Tulsi\n\t2. Turmeric\n\t3. Ginger\n\t4. Big Thyme\n";
string prompt_indoor = "\n\t0. Save\n\t1. Rubber plant\n\t2. Spider plant\n\t3. Syngonium\n";

string prompt2 = "\n\t0. Save\n\t1. Water Pots\n\t2. Plates\n\t3. Secateur\n\t4. Pickaxe\n\t5. Shovel\n\t6. Gloves\n";
string prompt_pots = "\n\t0. Save\n\t1. Porcelain\n\t2. Terracotta\n\t3. Plastic\n\t4. Cement\n";
string prompt_pots_sub = "\n\t0. Save\n\t1. Small\n\t2. Medium\n\t3. Big\n\t4. Very big\n";
string prompt_plates = "\n\t0. Save\n\t1. Small\n\t2. Medium\n\t3. Big\n\t4. Very big\n";
string prompt_secateur = "\n\t0. Save\n\t1. Red\n\t2. Blue\n";
string prompt_pickaxe = "\n\t0. Save\n\t1. Steel\n";
string prompt_shovel = "\n\t0. Save\n\t1. Steel\n";
string prompt_gloves = "\n\t0. Save\n\t1. Rubber\n";

string prompt3 = "\n\t0. Save\n\t1. Potting Mix\n\t2. Coco  Peat\n";
string prompt_pottmix = "\n\t0. Save\n\t1. Small (500 grams)\n\t2. Big (1 kilo)\n";
string prompt_cocopeat = "\n\t0. Save\n\t1. Small (500 grams)\n\t2. Big (1 kilo)\n";

//  USER FUNCTIONS:
void file(string data, string mode, string operation){
    //Function to perform file operations. (created to avoid repeated file open and close commands for multiple databases.)

    FILE *fp = fopen(data, mode);
    if(!strcmp(operation, "load_money")){
        fscanf(fp, "%f %f %d", &amount, &profit, &inventory_count, &transaction_count);
    }
    else if(!strcmp(operation, "save_money")){
        fprintf(fp, "%.2f %.2f %d", amount, profit, inventory_count, transaction_count);
    }
    else if(!strcmp(operation, "load_inventory")){
        for(int i=0; i< SIZE; i++)
            fscanf(fp, "%d %d %s %d %s %s %d %f", &item[i].id, &item[i].cat_id, item[i].cat_name, &item[i].subcat_id, item[i].subcat_name, item[i].item_name, &item[i].qty, &item[i].price);
    }

    else if(!strcmp(operation, "save_inventory")){
        for(int i=0; i< SIZE; i++)
            fprintf(fp, "%d %d %s %d %s %s %d %.2f\n", item[i].id, item[i].cat_id, item[i].cat_name, item[i].subcat_id, item[i].subcat_name, item[i].item_name, item[i].qty, item[i].price);
    }
    fclose(fp);
}

void load_file(){
    // Function to load and initialize previous data

    // Passing: file(file_name, file_mode, file_operation)
    file("moneydb.txt", "r", "load_money");
    file("inventorydb.txt", "r", "load_inventory");
}

void save_file(){
    //  Function to save previous data

    // Passing: file(file_name, file_mode, file_operation)
    file("moneydb.txt", "w", "save_money");
    file("inventorydb.txt", "w", "save_inventory");
}

void print_balance(){
    printf("\tGrand total: ₹ %.2f\tProfit: ₹ %.2f\tInventory count: %d \tTransaction count: %d \n", amount, profit, inventory_count, transaction_count);

}

void create_transaction(int id, int index, int bill){
    transaction temp = {
        .id = id,
        .item_id = item[index].id,
        .cat_id = item[index].cat_id,
        .cat_name = item[index].cat_name,
        .subcat_id = item[index].subcat_id,
        .subcat_name = item[index].subcat_name,
        .item_name = item[index].item_name,
        .qty = item[index].qty,
        .price = item[index].price,
        .total_price = bill
    };
    FILE *fp = fopen("transactions.txt", "a");
    fprintf(fp, "%d %d %d %s %d %s %s %d %.2f %.2f\n", temp.id, temp.item_id, temp.cat_id, temp.cat_name, temp.subcat_id, temp.subcat_name, temp.item_name, temp.qty, temp.price, temp.total_price);
    fclose(fp);
}

void buy_item(string name_of_item){
    printf("\tEnter Quantity:\n>> ");
    scanf("%d", &quantity);
    for(int i=0; i<SIZE; i++){
        if(!strcmp(item[i].item_name, name_of_item)){
            if((quantity * item[i].qty) <= amount){
                item[i].qty += quantity;
                amount -= (quantity * item[i].price);
                inventory_count += quantity;
                // transaction_count += 1;
                create_transaction(trans_id, i, (quantity * item[i].price));
                print_balance();
            }
            else
                printf("Account Balance Insufficient.\n");

            break;
        }
    }
}

void sell_item(string name_of_item, string categ){
    printf("\tEnter Quantity:\n>> ");
    scanf("%d", &quantity);
    for(int i=0; i<SIZE; i++){
        if(!strcmp(item[i].item_name, name_of_item)){

            if(item[i].qty <= quantity){
                printf("Requested quantity is available.\n");
                item[i].qty -= quantity;
                amount += (quantity * item[i].price);
                if(!strcmp(categ, "plant"))
                    profit += (quantity * 20);
                else
                    profit += (quantity * 50);
                inventory_count -= quantity;
                // transaction_count += 1;
                print_balance();

            }
            else
                printf("Requested quantity not available.\n");

            break;
        }
    }
}

void print_transactions(){
    transaction temp;
    FILE *fp = fopen("transactions.txt", "r");
    // if (fp == NULL)
    // {
    //     printf("Cannot open file \n");
    //     exit(0);
    // }
  
    // // Read contents from file
    // char c = fgetc(fp);
    // while (c != EOF)
    // {
    //     printf ("%c", c);
    //     c = fgetc(fp);
    // }
    printf("id, item_id, cat_id, cat_name, subcat_id, subcat_name, item_name, qty, price, total_price\n");
    for(int i=0; i<transaction_count; i++){
        fscanf(fp, "%d %d %d %s %d %s %s %d %.2f %.2f\n", &temp.id, &temp.item_id, &temp.cat_id, temp.cat_name, &temp.subcat_id, temp.subcat_name, temp.item_name, &temp.qty, &temp.price, &temp.total_price);
        printf(fp, "%d %d %d %s %d %s %s %d %.2f %.2f\n", temp.id, temp.item_id, temp.cat_id, temp.cat_name, temp.subcat_id, temp.subcat_name, temp.item_name, temp.qty, temp.price, temp.total_price);

    }
    fclose(fp);
}

//  MAIN FUNCTION:
void main(){
    load_file();
    trans_id = transaction_count;
    printf("\t\t***** GREENFIELD NURSERY INVENTORY & BILLING SYSTEM ***** \n");
    do{
        printf("Enter choice:\n%s\n>> \n", prompt0);
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                {
                    do{
                        printf("1. Update Plants:\n%s\n>> ", prompt1);
                        scanf("%d", &category_choice);
                        switch (category_choice)
                        {
                            case 1:
                                {    
                                    printf("\t\t%s\n>> ", prompt_flowering);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("jasmine");
                                        break;
                                    case 2:
                                        buy_item("rose");
                                        break;
                                    case 3:
                                        buy_item("chrysanthemum");
                                        break;
                                    case 4:
                                        buy_item("hibiscus");
                                        break;
                                    case 5:
                                        buy_item("tuberose");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }  
                                break;
                            case 2:
                                {    
                                    printf("\t\t%s\n>> ", prompt_succulent);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("lucky_jade");
                                        break;
                                    case 2:
                                        buy_item("aloe_vera");
                                        break;
                                    case 3:
                                        buy_item("cactus");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            case 3:
                                {    
                                    printf("\t\t%s\n>> ", prompt_medicinal);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("tulsi");
                                        break;
                                    case 2:
                                        buy_item("turmeric");
                                        break;
                                    case 3:
                                        buy_item("ginger");
                                        break;
                                    case 4:
                                        buy_item("big_thyme");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 4:
                                {    
                                    printf("\t\t%s\n>> ", prompt_indoor);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("rubber_plant");
                                        break;
                                    case 2:
                                        buy_item("spider_plant");
                                        break;
                                    case 3:
                                        buy_item("syngonium");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            default:
                                break;
                        }
                    }while(category_choice);
                    
                    
                    printf("\tYour Plants update has completed successfully! \n");
                }
                break;
            
            case 2:
                {
                    do{
                        printf("1. Update Accessories:\n%s\n>> ", prompt2);
                        scanf("%d", &category_choice);
                        switch (category_choice)
                        {
                            case 1:
                                {    
                                    printf("\t\t%s\n>> ", prompt_pots);
                                    scanf("%d", &subcategory_choice);
                                    int temp_choice;
                                    printf("\t\t%s\n>> ", prompt_pots_sub);
                                    scanf("%d", &temp_choice);
                                    int actual_choice;
                                    if(subcategory_choice == 1){
                                        // small size pots
                                        if(temp_choice == 1)    actual_choice = 1;  
                                        else if(temp_choice == 2)    actual_choice = 2;  
                                        else if(temp_choice == 3)    actual_choice = 3;  
                                        else if(temp_choice == 4)    actual_choice = 4;  
                                    }
                                    else if(subcategory_choice == 2){
                                        // medium size pots
                                        if(temp_choice == 1)    actual_choice = 5;
                                        else if(temp_choice == 2)    actual_choice = 6;
                                        else if(temp_choice == 3)    actual_choice = 7;
                                        else if(temp_choice == 4)    actual_choice = 8;
                                    }
                                    else if(subcategory_choice == 3){
                                        // big size pots
                                        if(temp_choice == 1)    actual_choice = 9;
                                        else if(temp_choice == 2)    actual_choice = 10;
                                        else if(temp_choice == 3)    actual_choice = 11;
                                        else if(temp_choice == 4)    actual_choice = 12;
                                    }
                                    else if(subcategory_choice == 4){
                                        // very big size pots
                                        if(temp_choice == 1)    actual_choice = 13;
                                        else if(temp_choice == 2)    actual_choice = 14;
                                        else if(temp_choice == 3)    actual_choice = 15;
                                        else if(temp_choice == 4)    actual_choice = 16;
                                    }
                                    switch (actual_choice)
                                    {
                                    case 1:
                                        buy_item("porcelain_small");
                                        break;
                                    case 2:
                                        buy_item("terracotta_small");
                                        break;
                                    case 3:
                                        buy_item("plastic_small");
                                        break;
                                    case 4:
                                        buy_item("cement_small");
                                        break;
                                    case 5:
                                        buy_item("porcelain_medium");
                                        break;
                                    case 6:
                                        buy_item("terracotta_medium");
                                        break;
                                    case 7:
                                        buy_item("plastic_medium");
                                        break;
                                    case 8:
                                        buy_item("cement_medium");
                                        break;
                                    case 9:
                                        buy_item("porcelain_big");
                                        break;
                                    case 10:
                                        buy_item("terracotta_big");
                                        break;
                                    case 11:
                                        buy_item("plastic_big");
                                        break;
                                    case 12:
                                        buy_item("cement_big");
                                        break;
                                    case 13:
                                        buy_item("porcelain_verybig");
                                        break;
                                    case 14:
                                        buy_item("terracotta_verybig");
                                        break;
                                    case 15:
                                        buy_item("plastic_verybig");
                                        break;
                                    case 16:
                                        buy_item("cement_verybig");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }  
                                break;
                            case 2:
                                {    
                                    printf("\t\t%s\n>> ", prompt_plates);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("small");
                                        break;
                                    case 2:
                                        buy_item("medium");
                                        break;
                                    case 3:
                                        buy_item("big");
                                        break;
                                    case 4:
                                        buy_item("verybig");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            case 3:
                                {    
                                    printf("\t\t%s\n>> ", prompt_secateur);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("red");
                                        break;
                                    case 2:
                                        buy_item("blue");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 4:
                                {    
                                    printf("\t\t%s\n>> ", prompt_pickaxe);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("steel");
                                        break;
                                    // case 2:
                                    //     buy_item("spider_plant");
                                    //     break;
                                    // case 3:
                                    //     buy_item("syngonium");
                                    //     break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 5:
                                {    
                                    printf("\t\t%s\n>> ", prompt_shovel);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("steel");
                                        break;
                                    // case 2:
                                    //     buy_item("spider_plant");
                                    //     break;
                                    // case 3:
                                    //     buy_item("syngonium");
                                    //     break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 6:
                                {    
                                    printf("\t\t%s\n>> ", prompt_gloves);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("rubber");
                                        break;
                                    // case 2:
                                    //     buy_item("spider_plant");
                                    //     break;
                                    // case 3:
                                    //     buy_item("syngonium");
                                    //     break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            default:
                                break;
                        }
                    }while(category_choice);

                    printf("\tYour Accessories update has completed successfully! \n");
                }
                break;
            case 3:
                {
                    do{
                        printf("1. Update Fertilizers:\n%s\n>> ", prompt3);
                        scanf("%d", &category_choice);
                        switch (category_choice)
                        {
                            case 1:
                                {    
                                    printf("\t\t%s\n>> ", prompt_pottmix);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("pottmix_small");
                                        break;
                                    case 2:
                                        buy_item("pottmix_big");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }  
                                break;
                            case 2:
                                {    
                                    printf("\t\t%s\n>> ", prompt_cocopeat);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        buy_item("cocopeat_small");
                                        break;
                                    case 2:
                                        buy_item("cocopeat_big");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            default:
                                break;
                        }
                    }while(category_choice);
                    printf("\tYour Fertilizers update has completed successfully! \n");
                }
                break;
            case 4:
                {
                    printf("4. Updated Inventory:\n");
                    print_balance();
                    if(inventory_count != 0){
                        printf("\nid, cat_id, cat_name, subcat_id, subcat_name, item_name, qty, price\n");
                        for(int i=0; i< SIZE; i++){
                            if(item[i].qty != 0)
                                printf("%d\t%d\t%s\t%d\t%s\t%s\t%d\t%.2f\n", item[i].id, item[i].cat_id, item[i].cat_name, item[i].subcat_id, item[i].subcat_name, item[i].item_name, item[i].qty, item[i].price);

                        }
                    printf("\tInventory updated successfully! \n");
                    }
                    else{
                        printf("\tInventory is empty! \n");
                    }
                }
                break;
            case 5:
                {
                    printf("5. Print Transactions:\n");
                    print_transactions();
                    printf("\tTransactions printed successfully! \n");
                }
                break;
            case 6:
                {
                    printf("6. Print Profit:\n");
                    print_balance();
                }
                break;
            
            case 7:
                {
                    do{
                        printf("7. Buy Plants:\n%s\n>> ", prompt1);
                        scanf("%d", &category_choice);
                        switch (category_choice)
                        {
                            case 1:
                                {    
                                    printf("\t\t%s\n>> ", prompt_flowering);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("jasmine", "plant");
                                        break;
                                    case 2:
                                        sell_item("rose", "plant");
                                        break;
                                    case 3:
                                        sell_item("chrysanthemum", "plant");
                                        break;
                                    case 4:
                                        sell_item("hibiscus", "plant");
                                        break;
                                    case 5:
                                        sell_item("tuberose", "plant");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }  
                                break;
                            case 2:
                                {    
                                    printf("\t\t%s\n>> ", prompt_succulent);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("lucky_jade", "plant");
                                        break;
                                    case 2:
                                        sell_item("aloe_vera", "plant");
                                        break;
                                    case 3:
                                        sell_item("cactus", "plant");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            case 3:
                                {    
                                    printf("\t\t%s\n>> ", prompt_medicinal);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("tulsi", "plant");
                                        break;
                                    case 2:
                                        sell_item("turmeric", "plant");
                                        break;
                                    case 3:
                                        sell_item("ginger", "plant");
                                        break;
                                    case 4:
                                        sell_item("big_thyme", "plant");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 4:
                                {    
                                    printf("\t\t%s\n>> ", prompt_indoor);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("rubber_plant", "plant");
                                        break;
                                    case 2:
                                        sell_item("spider_plant", "plant");
                                        break;
                                    case 3:
                                        sell_item("syngonium", "plant");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            default:
                                break;
                        }
                    }while(category_choice);
                    
                 
                    
                    printf("\tYour Plants purchase has completed successfully! \n");
                    
                }
                break;
            case 8:
                {
                    do{
                        printf("8. Buy Accessories:\n%s\n>> ", prompt2);
                        scanf("%d", &category_choice);
                        switch (category_choice)
                        {
                            case 1:
                                {    
                                    printf("\t\t%s\n>> ", prompt_pots);
                                    scanf("%d", &subcategory_choice);
                                    int temp_choice;
                                    printf("\t\t%s\n>> ", prompt_pots_sub);
                                    scanf("%d", &temp_choice);
                                    int actual_choice;
                                    if(subcategory_choice == 1){
                                        // small size pots
                                        if(temp_choice == 1)    actual_choice = 1;  
                                        else if(temp_choice == 2)    actual_choice = 2;  
                                        else if(temp_choice == 3)    actual_choice = 3;  
                                        else if(temp_choice == 4)    actual_choice = 4;  
                                    }
                                    else if(subcategory_choice == 2){
                                        // medium size pots
                                        if(temp_choice == 1)    actual_choice = 5;
                                        else if(temp_choice == 2)    actual_choice = 6;
                                        else if(temp_choice == 3)    actual_choice = 7;
                                        else if(temp_choice == 4)    actual_choice = 8;
                                    }
                                    else if(subcategory_choice == 3){
                                        // big size pots
                                        if(temp_choice == 1)    actual_choice = 9;
                                        else if(temp_choice == 2)    actual_choice = 10;
                                        else if(temp_choice == 3)    actual_choice = 11;
                                        else if(temp_choice == 4)    actual_choice = 12;
                                    }
                                    else if(subcategory_choice == 4){
                                        // very big size pots
                                        if(temp_choice == 1)    actual_choice = 13;
                                        else if(temp_choice == 2)    actual_choice = 14;
                                        else if(temp_choice == 3)    actual_choice = 15;
                                        else if(temp_choice == 4)    actual_choice = 16;
                                    }
                                    switch (actual_choice)
                                    {
                                    case 1:
                                        sell_item("porcelain_small", "access");
                                        break;
                                    case 2:
                                        sell_item("terracotta_small", "access");
                                        break;
                                    case 3:
                                        sell_item("plastic_small", "access");
                                        break;
                                    case 4:
                                        sell_item("cement_small", "access");
                                        break;
                                    case 5:
                                        sell_item("porcelain_medium", "access");
                                        break;
                                    case 6:
                                        sell_item("terracotta_medium", "access");
                                        break;
                                    case 7:
                                        sell_item("plastic_medium", "access");
                                        break;
                                    case 8:
                                        sell_item("cement_medium", "access");
                                        break;
                                    case 9:
                                        sell_item("porcelain_big", "access");
                                        break;
                                    case 10:
                                        sell_item("terracotta_big", "access");
                                        break;
                                    case 11:
                                        sell_item("plastic_big", "access");
                                        break;
                                    case 12:
                                        sell_item("cement_big", "access");
                                        break;
                                    case 13:
                                        sell_item("porcelain_verybig", "access");
                                        break;
                                    case 14:
                                        sell_item("terracotta_verybig", "access");
                                        break;
                                    case 15:
                                        sell_item("plastic_verybig", "access");
                                        break;
                                    case 16:
                                        sell_item("cement_verybig", "access");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }  
                                break;
                            case 2:
                                {    
                                    printf("\t\t%s\n>> ", prompt_plates);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("small", "access");
                                        break;
                                    case 2:
                                        sell_item("medium", "access");
                                        break;
                                    case 3:
                                        sell_item("big", "access");
                                        break;
                                    case 4:
                                        sell_item("verybig", "access");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            case 3:
                                {    
                                    printf("\t\t%s\n>> ", prompt_secateur);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("red", "access");
                                        break;
                                    case 2:
                                        sell_item("blue", "access");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 4:
                                {    
                                    printf("\t\t%s\n>> ", prompt_pickaxe);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("steel", "access");
                                        break;
                                    // case 2:
                                    //     sell_item("spider_plant");
                                    //     break;
                                    // case 3:
                                    //     sell_item("syngonium");
                                    //     break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 5:
                                {    
                                    printf("\t\t%s\n>> ", prompt_shovel);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("steel", "access");
                                        break;
                                    // case 2:
                                    //     sell_item("spider_plant");
                                    //     break;
                                    // case 3:
                                    //     sell_item("syngonium");
                                    //     break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                                case 6:
                                {    
                                    printf("\t\t%s\n>> ", prompt_gloves);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("rubber", "access");
                                        break;
                                    // case 2:
                                    //     sell_item("spider_plant");
                                    //     break;
                                    // case 3:
                                    //     sell_item("syngonium");
                                    //     break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            default:
                                break;
                        }
                    }while(category_choice);
                    printf("\tYour Accessories purchase has completed successfully! \n");
                    
                }
                break;
            case 9:
                {do{
                        printf("9. Buy Fertilizers:\n%s\n>> ", prompt3);
                        scanf("%d", &category_choice);
                        switch (category_choice)
                        {
                            case 1:
                                {    
                                    printf("\t\t%s\n>> ", prompt_pottmix);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("pottmix_small", "fert");
                                        break;
                                    case 2:
                                        sell_item("pottmix_big", "fert");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }  
                                break;
                            case 2:
                                {    
                                    printf("\t\t%s\n>> ", prompt_cocopeat);
                                    scanf("%d", &subcategory_choice);
                                    switch (subcategory_choice)
                                    {
                                    case 1:
                                        sell_item("cocopeat_small", "fert");
                                        break;
                                    case 2:
                                        sell_item("cocopeat_big", "fert");
                                        break;
                                    
                                    default:
                                        printf("Item unavailable!\n");
                                        break;
                                    }
                                }                                
                                break;
                            default:
                                break;
                        }
                    }while(category_choice);
                    printf("\tYour Fertilizers purchase has completed successfully! \n");
                    
                }
                break;
            default:    //when user enters 0 or anyother number as choice, he is exited from the app.
                {
                    printf("Progress saved successfully!\n");
                    choice = 0;   
                }
                break;
        }
    }while(choice);

    transaction_count = trans_id;
    save_file();
}