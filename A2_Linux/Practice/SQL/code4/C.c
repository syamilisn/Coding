#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef char string[30];

typedef struct emp_details{
	int id;
	string name;
	string domain;
	string lang;
	int expc;
}employee;

// structure for message queue
typedef struct mesg_buffer {
	long mesg_type;
	int success;
	employee emp;
} msg;

msg message;

int main(int argc, char *argv[]){
    //declarations
    sqlite3 *db;
    char *error_msg = NULL;
    key_t key;
    int choice = 0, msgid, empid;

    do{
        printf("**********************************************************\n");
        printf("choice: 1. Insert records 2. View records 3. Send/Receive records 4. Retrieve record 5. Check record exists\n\t> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: //insert into database
            {
                int rc = sqlite3_open("mydatabase.db", &db);    //db connection
                if (rc != SQLITE_OK){
                    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
                    sqlite3_close(db);
                    return 1;
                }
                //create_table();
                char *create_table = "CREATE TABLE IF NOT EXISTS employees (id INTEGER PRIMARY KEY, name TEXT NOT NULL, domain VARCHAR(30), lang VARCHAR(30), exp INTEGER)";
                rc = sqlite3_exec(db, create_table, NULL, 0, &error_msg);
                if(rc != SQLITE_OK){
                        fprintf(stderr, "SQL error: %s\n", error_msg);
                        sqlite3_free(error_msg);
                        sqlite3_close(db);
                        return 1;
                }
                printf("Enter row:\nNAME DOMAIN, LANG, EXPERIENCE\n");
                scanf("%s %s %s %d", message.emp.name, message.emp.domain, message.emp.lang, &message.emp.expc);
                char buffer[500];
                snprintf(buffer, sizeof(buffer), "INSERT INTO employees (name, domain, lang, exp) VALUES ('%s', '%s', '%s', %d)", message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);
                char* insert_sql = buffer;
                rc= sqlite3_exec(db, insert_sql, NULL, 0, &error_msg);

                if(rc != SQLITE_OK){
                        fprintf(stderr, "SQL error: %s\n", error_msg);
                        sqlite3_free(error_msg);
                        sqlite3_close(db);
                        return 1;
                }
                printf("Record added: \n");
                printf("Emp_id: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", message.emp.id,  message.emp.name,  message.emp.domain,  message.emp.lang,  message.emp.expc);
                sqlite3_close(db);
            }
            break;
        case 2: //view database
        {
                int rc = sqlite3_open("mydatabase.db", &db);    //db connection
                if (rc != SQLITE_OK){
                    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
                    sqlite3_close(db);
                    return 1;
                }
                //create_table();
                char *create_table = "CREATE TABLE IF NOT EXISTS employees (id INTEGER PRIMARY KEY, name TEXT NOT NULL, domain VARCHAR(30), lang VARCHAR(30), exp INTEGER)";
                rc = sqlite3_exec(db, create_table, NULL, 0, &error_msg);
                if(rc != SQLITE_OK){
                        fprintf(stderr, "SQL error: %s\n", error_msg);
                        sqlite3_free(error_msg);
                        sqlite3_close(db);
                        return 1;
                }
                printf("**********************DATABASE****************************\n");
                sqlite3_stmt* select_stmt;
                const char* select_sql = "SELECT * FROM employees";
                rc = sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, NULL);

                if (rc != SQLITE_OK) {
                        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
                        sqlite3_close(db);
                        return 1;
                }

                while (sqlite3_step(select_stmt) == SQLITE_ROW) {
                        int id = sqlite3_column_int(select_stmt, 0);
                        const unsigned char* name = sqlite3_column_text(select_stmt, 1);
                        const unsigned char* domain = sqlite3_column_text(select_stmt, 2);
                        const unsigned char* lang = sqlite3_column_text(select_stmt, 3);
                        int expc = sqlite3_column_int(select_stmt, 4);
                        printf("Emp_id: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", id, name, domain, lang, expc);
                }

                sqlite3_finalize(select_stmt);
                sqlite3_close(db);
        }
            break;
        case 3: //send employee details
        {
            key = ftok("progfile", 65);
        	msgid = msgget(key, 0666 | IPC_CREAT);
            while(1){
                msgrcv(msgid, &message, sizeof(message), 1, 0);
                printf("Data Received is : %d %s %s %s %d \n", message.emp.id, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);
                message.mesg_type = 2;  //fetch data
		        message.success =1;
		        printf("Write Data :\nID NAME DOMAIN LANG EXP\n");
		        scanf("%d %s %s %s %d", &message.emp.id, message.emp.name, message.emp.domain, message.emp.lang, &message.emp.expc);
		        //else if not found success = 0
		        msgsnd(msgid,&message,sizeof(message),0);
            }
        	msgctl(msgid, IPC_RMID, NULL); 
            break;
        }
        
        case 4: //retrieve record from queue
        {
            printf("Enter employee-id: ");
            scanf("%d", &empid);
            //search through the db
                int rc = sqlite3_open("mydatabase.db", &db);    //db connection
                if (rc != SQLITE_OK){
                    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
                    sqlite3_close(db);
                    return 1;
                }
                //create_table();
                char *create_table = "CREATE TABLE IF NOT EXISTS employees (id INTEGER PRIMARY KEY, name TEXT NOT NULL, domain VARCHAR(30), lang VARCHAR(30), exp INTEGER)";
                rc = sqlite3_exec(db, create_table, NULL, 0, &error_msg);
                if(rc != SQLITE_OK){
                        fprintf(stderr, "SQL error: %s\n", error_msg);
                        sqlite3_free(error_msg);
                        sqlite3_close(db);
                        return 1;
                }
                printf("**********************DATABASE****************************\n");
                sqlite3_stmt* select_stmt;
                const char* select_sql = "SELECT * FROM employees";
                rc = sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, NULL);

                if (rc != SQLITE_OK) {
                        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
                        sqlite3_close(db);
                        return 1;
                }

                while (sqlite3_step(select_stmt) == SQLITE_ROW) {
                        int id = sqlite3_column_int(select_stmt, 0);
                        const unsigned char* name = sqlite3_column_text(select_stmt, 1);
                        const unsigned char* domain = sqlite3_column_text(select_stmt, 2);
                        const unsigned char* lang = sqlite3_column_text(select_stmt, 3);
                        int expc = sqlite3_column_int(select_stmt, 4);
                        if (empid == id){
                            message.emp.id = id;
                            strcpy(message.emp.name, name);
                            strcpy(message.emp.domain, domain);
                            strcpy(message.emp.lang, lang);
                            message.emp.expc = expc;
                            break;
                        }
                }
                if(empid == message.emp.id){
                    printf("Employee exists!...Record placed in Message Queue:\nEmp_id: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", message.emp.id, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);
                }
                else{
                    printf("Employee does not exist!!...Try again\n");
                }
                
                sqlite3_finalize(select_stmt);
                sqlite3_close(db);
            //end of search
            break;
        }

        case 5: //Check record exists
        {

            break;
        }
        default:
            printf("default choice \n");
            exit(0);
        }
    }while(choice);
}