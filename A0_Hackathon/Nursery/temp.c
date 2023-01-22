#include <stdio.h>
#include <string.h>

typedef char string[150];

//  Global Declarations:
float amount;
float profit;

//  User Functions:
void file(string data, string mode, string operation){
    //Function to perform file operations. (created to avoid repeated file open and close commands for multiple databases.)

    FILE *fp = fopen(data, mode);
    if(!strcmp(operation, "load_money")){
        fscanf(fp, "%f %f", &amount, &profit);
    }
    else if(!strcmp(operation, "save_money")){
        fprintf(fp, "%.2f %.2f", amount, profit);
    }
    fclose(fp);
}

void load_file(){
    // Function to load and initialize previous data

    // Passing: file(file_name, file_mode, file_operation)
    file("moneydb.txt", "r", "load_money");
}

void save_file(){
    //  Function to save previous data

    // Passing: file(file_name, file_mode, file_operation)
    file("moneydb.txt", "w", "save_money");
}

//  Main Function:
void main(){
    load_file();

    int choice = 0;
    string prompt = "0. Save and Exit,\n1. Buy Plants, 2. Buy Accessories, 3. Buy Fertilizers,\n4. Update Inventory, 5. Print Transactions, 6. Print Profit";
    string prompt2 = "\t0. Save and Exit\n\t1. Flowering Plants\n\t2. Succulents\n\t3. Medicinal Plants\n\t4. Indoor Plants\n";
    printf("\t\t***** NURSERY BILLING SYSTEM ***** \n");
    do{
        printf("Enter choice:\n%s\n>> \n", prompt);
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                {
                    int choice2 = 0;
                    do{
                        printf("1. Buy Plants:\n%s", prompt2);
                        scanf("%d", &choice2);
                        switch (choice2)
                        {
                            case 1:
                                /* code */
                                break;
                            case 2:
                                /* code */
                                break;
                            default:
                                break;
                        }
                    }while(choice2);
                    
                    
                    printf("\tYour Plants purchase has completed successfully! \n");
                }
                break;
            
            case 2:
                {
                    printf("2. Buy Accessories:\n");

                    printf("\tYour Accessories purchase has completed successfully! \n");
                }
                break;
            case 3:
                {
                    printf("3. Buy Fertilizers:\n");

                    printf("\tYour Fertilizers purchase has completed successfully! \n");
                }
                break;
            case 4:
                {
                    printf("4. Update Inventory:\n");
                    
                    // profit += 200;
                    // amount -= profit;
                    printf("\tInventory updated successfully! \n");
                }
                break;
            case 5:
                {
                    printf("5. Print Transactions:\n");
                    printf("\tTransactions printed successfully! \n");
                }
                break;
            case 6:
                {
                    printf("6. Print Profit:\n");
                    printf("\tGrand total: ₹ %.2f\tProfit: ₹ %.2f \n", amount, profit);
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

    save_file();
}