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
};

struct mesg_buffer msg = {
    .mesg_type = 1,
    .success = 0,
    .emp = {
        .id = 1,
        .name = "shyam",
        .domain = "kdd",
        .lang = "c",
        .expc = 1
    }
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

int emp_exists(int send_id){
    return 1;
}

void fetch_emp(int send_id){
    
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

    // Enter emp_id
    int send_id;
    printf("Enter employee id to be sent: \n");
    scanf("%d", &send_id);
    if(emp_exists(send_id)){
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

        msgctl(msgid, IPC_RMID, NULL);
    }
    else{
        printf("Employee with id = %d doesn't exist in employee database. \n", send_id);
    }

    mysql_close(conn);
    return 0;
}