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
sqlite3 *db;
char *error_msg = NULL;
key_t key;
int choice = 0, msgid, empid;
employee database;
//*****************************************************

void emp_details(int id, char *name, char *domain, char *lang, int expc){
    message.emp.id = id;
    strcpy(message.emp.name, name);
    strcpy(message.emp.domain, domain);
    strcpy(message.emp.lang, lang);
    message.emp.expc = expc;
}
int emp_exists(int empid){      //  WORKING
    int rc = sqlite3_open("mydatabase.db", &db);    //db connection
    if (rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
    sqlite3_stmt* select_stmt;
    const char* select_sql = "SELECT * FROM employees";
    rc = sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, NULL);

    if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
    }

    while (sqlite3_step(select_stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(select_stmt, 0);
            const unsigned char* name = sqlite3_column_text(select_stmt, 1);
            const unsigned char* domain = sqlite3_column_text(select_stmt, 2);
            const unsigned char* lang = sqlite3_column_text(select_stmt, 3);
            int expc = sqlite3_column_int(select_stmt, 4);
            //printf("Emp_id: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", id, name, domain, lang, expc);
            if(empid == id){
                emp_details(id, name, domain, lang, expc);
                return 1;
            }
    }

    sqlite3_finalize(select_stmt);
    sqlite3_close(db);
    return 0;
}

//*****************************************************

int main(){
    do{
        printf("**********************************************************\n");
        printf("choice: 1. Insert records 2. View records 3. Send/Receive records\n\t> ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 3: //  send or receive
            {

                key = ftok("progfile", 65);
        	    msgid = msgget(key, 0666 | IPC_CREAT);

                printf("Enter employee ID \n");
                scanf("%d", &empid);
                if(emp_exists(empid))
                {
                    printf("employee record loaded to queue successfully\n"); 
		            message.success = 0;
                    message.mesg_type = 1;
                    msgsnd(msgid,&message,sizeof(message),0);
                    msgrcv(msgid,&message,sizeof(message),2,0);
                    if(message.success == 1)
                        printf("ACK...success \n");
                    else
                        printf("NACK...failure \n");

                }
                else
                    printf("employee record unavailable in DB_E.\n");
            	msgctl(msgid, IPC_RMID, NULL); 
                break;
            }
            default:
                printf("default choice \n");
                exit(0);
        }
    }while(choice);

}