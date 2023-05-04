#include <mysql/mysql.h>
// #include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
typedef char string[30];
struct employee{
    int id;
    string name;
    string domain;
    string lang;
    int expc;
};
// struct employee e1 = {
//     .name = "dummy",
//     .domain = "dummy",
//     .lang = "dummy",
//     .expc = 1
// };

int main(int argc, char* argv[]) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *password = "Cuppie@123";
    char *database = "employeedb";

    if(argc < 4){
        perror("Usage-(name, domain, lang, expc)");
        exit(1);
    }

    // Initialize connection object
    conn = mysql_init(NULL);

    // Connect to the database
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Create a table
    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS employee3(id int NOT NULL AUTO_INCREMENT,name varchar(50) NOT NULL,domain varchar(50) NOT NULL,lang varchar(50) NOT NULL,expc int NOT NULL,PRIMARY KEY (id))")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Insert data into the table
        //  Data entry point begins:
        // printf("Enter employee details: \n");
        
        //  Data entry point ends!
    char query[250];
    sprintf(query, "INSERT INTO employee3 (name, domain, lang, expc) VALUES ('%s', '%s', '%s', %d )", argv[1], argv[2], argv[3], atoi(argv[4]));
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Retrieve the data from the table
    if (mysql_query(conn, "SELECT * FROM employee3")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    // Print the results
    printf("ID\tName\tDomain\tLang\tExpc\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3], row[4]);
    }

    // Free resources
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
