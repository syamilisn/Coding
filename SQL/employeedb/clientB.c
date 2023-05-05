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

struct employee myemp= {
        .id = 1,
        .name = "shyamil",
        .domain = "kdd",
        .lang = "c",
        .expc = 1
};

key_t key;
int msgid;

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;
char *server = "localhost";
char *user = "root";
char *password = "Cuppie@123";
char *database = "employeedb";

int emp_exists(int receive_id){
    return 1;
}

void fetch_emp(int receive_id){

}

int main(int argc, char* argv[]){
    
    // Initialize connection object
    conn = mysql_init(NULL);

    // Connect to the database
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    int receive_id = 1;     // obtained from mesg_buf
    if(emp_exists(receive_id)){
        //  receive mechanism
        msgrcv(msgid, &msg, sizeof(msg), 1, 0);
        printf("Message received: id-%d name-%s domain-%s lang-%s expc-%d \n", msg.emp.id, msg.emp.name, msg.emp.domain, msg.emp.lang, msg.emp.expc);
        //  fetch from database
        fetch_emp(receive_id);
        printf("Database details: id-%d name-%s domain-%s lang-%s expc-%d \n", myemp.id, myemp.name, myemp.domain, myemp.lang, myemp.expc);
        msg.mesg_type = 2;
        msg.success = 0;        //  message received success

        if(strcmp(msg.emp.name, myemp.name) != 0){
            printf("name mismatched! \n");
            msg.success = -1;    //  message name not matched with DB
        }
        if(strcmp(msg.emp.domain, myemp.domain) != 0){
            printf("domain mismatched! \n");
            msg.success = -1;    //  message domain not matched with DB
        }
        if(strcmp(msg.emp.lang, myemp.lang) != 0){
            printf("language mismatched! \n");
            msg.success = -1;    //  message lang not matched with DB
        }
        if(msg.emp.expc != myemp.expc){
            printf("experience mismatched! \n");
            msg.success = -1;    //  message experience not matched with DB
        }
            //fetch data from DB here >>
        msgsnd(msgid, &msg, sizeof(msg), 0);
        printf("Message sent: id-%d name-%s domain-%s lang-%s expc-%d \n", msg.emp.id, msg.emp.name, msg.emp.domain, msg.emp.lang, msg.emp.expc);
        if(msg.success == 0)
            //  if message is received and read successfully by client B
            printf("ACK = %d ...success \n", msg.success);
        else{
            //  if message NOT received and read successfully by client B
            printf("NACK = %d ...failure \n", msg.success);
            exit(0);
            // break;
        }
        msgctl(msgid, IPC_RMID, NULL);
    }
    else{
        printf("Employee with id = %d doesn't exist in employee2 database. \n", receive_id);
    }

    mysql_close(conn);
    return 0;
}