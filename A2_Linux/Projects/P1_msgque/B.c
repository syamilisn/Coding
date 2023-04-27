#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

//  custom datatype for string
typedef char string[30];

// structure for employee details
typedef struct emp_details{
	int id;
	string name;
	string domain;
	string lang;
	int expc;
}employee;

// structure for message queue
typedef struct mesg_buffer {
	long mesg_type;     // messagetype: 1 - clientB, 2 - clientA
	int success;    //  whether acknowledgment is successful or not
	employee emp;   //  structure of type employee
} msg;

msg message;        //  structure of type message
sqlite3 *db;        //  pointer to database
char *error_msg = NULL;
key_t key;          //  message queue key
int choice = 0, msgid, empid;
employee database;
//*****************************************************
void view_record(int eid){
    int rc = sqlite3_open("mydatabase2.db", &db);    //db connection
    if (rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    printf("**********************DATABASE****************************\n");
    printf("Found: \n");
    sqlite3_stmt* select_stmt;
    string cmd;
    // sprintf(cmd, "SELECT * FROM employees WHERE id = %d\n", id);
    // const char* select_sql = cmd;
    const char* select_sql = "SELECT * FROM employees";
    rc = sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, NULL);

    if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return 1;
    }

    while (sqlite3_step(select_stmt) == SQLITE_ROW) {
            //  fetch data row by row from database
            int id = sqlite3_column_int(select_stmt, 0);
            const unsigned char* name = sqlite3_column_text(select_stmt, 1);
            const unsigned char* domain = sqlite3_column_text(select_stmt, 2);
            const unsigned char* lang = sqlite3_column_text(select_stmt, 3);
            int expc = sqlite3_column_int(select_stmt, 4);
            if(eid == id)
                printf("Emp_id: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", id, name, domain, lang, expc);
    }

    sqlite3_finalize(select_stmt);
    sqlite3_close(db);
}
void emp_details(int id, char *name, char *domain, char *lang, int expc){
    //  assign employee details to message queue
    message.emp.id = id;
    strcpy(message.emp.name, name);
    strcpy(message.emp.domain, domain);
    strcpy(message.emp.lang, lang);
    message.emp.expc = expc;
}
int emp_exists(int empid){
    //  function that checks whether an employee exists in the database or not
    int rc = sqlite3_open("mydatabase2.db", &db);    //db connection
    if (rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
    sqlite3_stmt* select_stmt;
    const char* select_sql = "SELECT * FROM employees";
    //  sqlite2_prepare_v2: for compiling SQL statement (database, sql_statement, max_bytes_of_SQL_statement)
    rc = sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, NULL);
    //  Passing -1 causes the SQL string to be read up to the first zero terminator (which is the )end of the string)

    if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
    }

    while (sqlite3_step(select_stmt) == SQLITE_ROW) {
            //sqlite3_column_int: 32-bit INTEGER result
            int id = sqlite3_column_int(select_stmt, 0);
            //sqlite3_column_text: UTF-8 TEXT result
            const unsigned char* name = sqlite3_column_text(select_stmt, 1);
            const unsigned char* domain = sqlite3_column_text(select_stmt, 2);
            const unsigned char* lang = sqlite3_column_text(select_stmt, 3);
            int expc = sqlite3_column_int(select_stmt, 4);
            //printf("Emp_id: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", id, name, domain, lang, expc);
            if(empid == id){
                if(message.emp.expc != expc){
                    printf("\tExperience mismatched! \n");
                }

                if(strcmp(message.emp.name, name) != 0){
                    printf("\tName mismatched! \n");
                }

                if(strcmp(message.emp.domain, domain) != 0){
                    printf("\tDomain mismatched! \n");
                }

                if(strcmp(message.emp.lang, lang) != 0){
                    printf("\tLanguage mismatched! \n");
                }

                if(message.emp.expc != expc || (strcmp(message.emp.name, name) != 0) || (strcmp(message.emp.domain, domain) != 0) || (strcmp(message.emp.lang, lang) != 0))
                {
                    return 0;
                }
                    emp_details(id, name, domain, lang, expc);
                    //  sqlite3_finalize(): called to delete a prepared statement
                    sqlite3_finalize(select_stmt);
                    sqlite3_close(db);
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
        printf("choice: 1. Insert records 2. View records 3. Receive records\n\t> ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: //insert into database
            {
                int rc = sqlite3_open("mydatabase2.db", &db);    //db connection
                if (rc != SQLITE_OK){
                    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
                    sqlite3_close(db);
                    return 1;
                }
                //create_table(): for creating table "employees" in database
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
                //  store SQL statement in string buffer
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
                int rc = sqlite3_open("mydatabase2.db", &db);    //db connection
                if (rc != SQLITE_OK){
                    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
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
                        //  fetch data row by row from database
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
            case 3: //  receive message
            while(1){
                key = ftok("progfile", 65);             //  generate key for msg queue
                msgid = msgget(key, 0666 | IPC_CREAT);  //  acquire msg queue id

                msgrcv(msgid, &message, sizeof(message), 1, 0); //  four_argument: message_type
                printf("Received:\nEmp_id: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", message.emp.id, message.emp.name, message.emp.domain, message.emp.lang, message.emp.expc);
                if(emp_exists(message.emp.id))          //  check if employee exists or not
                {
                    printf("employee record exists in DB_B.\n");
                    view_record(message.emp.id);
                    message.success = 1;                //  message successfully received from clientA
                    message.mesg_type = 2;              //  message_type: set to client A
                    msgsnd(msgid,&message,sizeof(message),0);   //  last_argument: message flag (0 - wait, IPC_NOWAIT - not wait)
                }
                else
                {
                    printf("employee record unmatched in DB_B.\n");   //  employee not present in mydatabase2
                    view_record(message.emp.id);
                }
                if(message.success == 1)
                    //  if message is received and read successfully by client B
                    printf("ACK = %d\n", message.success-1);
                else{
                    //  if message NOT received and read successfully by client B
                    printf("NACK = %d\n", message.success-1);
                }
                //  removes msgid and destroys message on queue
                msgctl(msgid, IPC_RMID, NULL); 
                //break;
                printf("**********************************************************\n");
                printf("**********************************************************\n");
            }
            default:
                printf("default choice \n");
                exit(0);
        }
    }while(choice);

}