#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef char string[30];
typedef char query[300];

struct employee{
    int id;
    string name;
    string domain;
    string lang;
    int expc;
}myemp;

struct mesg_buffer{
    long mesg_type;
    int success;
    struct employee emp;
}msg;

// struct mesg_buffer msg = {
//     .mesg_type = 1,
//     .success = -1,
//     .emp = {
//         .id = 1,
//         .name = "shyam",
//         .domain = "kdd",
//         .lang = "c",
//         .expc = 1
//     }
// };

key_t key;
int msgid;

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;
char *server = "localhost";
char *user = "root";
char *password = "Cuppie@123";
char *database = "employeedb";

int emp_exists(int send_id){
    string table_name = "employee";
    query fetch;
    sprintf(fetch, "SELECT * FROM %s WHERE id = %d", table_name, send_id);
    int exists;
    if(mysql_query(conn, fetch)){
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_use_result(conn);   // line required for fetching connection results even if not result are not required
    row = mysql_fetch_row(res);
    
    if(row == NULL)
        exists = 0;
    else
        exists = 1;
    mysql_free_result(res);
    return exists;
}

void fetch_emp(int send_id){
    string table_name = "employee";
    query fetch;
    sprintf(fetch, "SELECT * FROM %s WHERE id = %d", table_name, send_id);
    if(mysql_query(conn, fetch)){
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_use_result(conn);
    row = mysql_fetch_row(res);
    msg.emp.id = send_id;
    strcpy(msg.emp.name, row[1]);
    strcpy(msg.emp.domain, row[2]);
    strcpy(msg.emp.lang, row[3]);
    msg.emp.expc = atoi(row[4]);
    mysql_free_result(res);
}

int main(int argc, char* argv[]){
    int flag = 1;
    string choice;
    // Initialize connection object
    conn = mysql_init(NULL);

    // Connect to the database
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    do{
        key = ftok("progfile", 65);
        msgid = msgget(key, 0666 | IPC_CREAT);

        // Enter emp_id
        int send_id;
        printf("Enter employee id to be sent: \n");
        scanf("%d", &send_id);
        if(emp_exists(send_id) == 1){
            printf("Employee exists... \n");
            //  send mechanism
            msg.mesg_type = 1;
                //fetch data from DB here >>
            fetch_emp(send_id);
            msgsnd(msgid, &msg, sizeof(msg), 0);
            printf("Message sent: id-%d name-%s domain-%s lang-%s expc-%d \n", msg.emp.id, msg.emp.name, msg.emp.domain, msg.emp.lang, msg.emp.expc);
            msgrcv(msgid, &msg, sizeof(msg), 2, 0);
            printf("Message received: id-%d name-%s domain-%s lang-%s expc-%d \n", msg.emp.id, msg.emp.name, msg.emp.domain, msg.emp.lang, msg.emp.expc);
            if(msg.success == 0)
                //  if message is received and read successfully by client B
                printf("ACK = %d ...success \n", msg.success);
            else{
                //  if message NOT received and read successfully by client B
                printf("NACK = %d ...failure \n", msg.success);
                exit(0);
                // break;
            }
            
        }  
        
        else{
            printf("Employee with id = %d doesn't exist in employee database. \n", send_id);
            exit(0);
        }
        msgctl(msgid, IPC_RMID, NULL);   
        printf("Continue? y/n: ");
        scanf("%s", choice);
        printf(" \n");
        if(strcmp(choice, "n")==0 || strcmp(choice, "N")==0)
            break;
    }while(flag);
    mysql_close(conn);
    return 0;
}