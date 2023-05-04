#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char string[30];
typedef char query[300];
struct employee{
    int id;
    string name;
    string domain;
    string lang;
    int expc;
}emp;

int main(int argc, char* argv[]) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *password = "Cuppie@123";
    char *database = "employeedb";
    
    // Initialize connection object
    conn = mysql_init(NULL);

    // Connect to the database
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    //  selection starts:
    int choice;
    do{
        printf("Enter choice: 1-List tables, 2-Create table, 3-Insert data, 4-Delete data, 5-View data\n\t> ");
        scanf("%d", &choice);
        // choice = 1;
        switch (choice)
        {
        case 1:
            {
                printf("Tables in employeedb: \n");
                if (mysql_query(conn, "SHOW TABLES")) {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                    exit(1);
                }
                // Store the result of the query
                res = mysql_use_result(conn);

                // Print each table name
                while ((row = mysql_fetch_row(res)) != NULL) {
                    printf("%s\n", row[0]);
                }

                // Free the result set
                mysql_free_result(res);
            }
            break;

        case 2:
            {
                printf("Enter table name:\n\t> ");
                string table_name;
                scanf("%s", table_name);
                printf("TABLE: %s \n", table_name);
                printf("Enter field names: \n");
                string field_name;
                string data_type;
                string constraints;
                string primary;
                string conti;
                query all_fields;
                while (1)
                {
                    printf("Enter-(field_name, data_type, constraints) \n");
                    printf("constraints: NOT NULL, AUTO_INCREMENT... \n");
                    printf("data_type: INT, VARCHAR(30)... \n");
                    scanf("%s %s %[^\n]s", field_name, data_type, constraints);
                    query field;
                    sprintf(field, " %s %s %s,", field_name, data_type, constraints);
                    printf("FIELD: %s \n", field);
                    strcat(all_fields, field);
                    printf("ALL_FIELDS: %s \n", all_fields);
                    printf("Continue? y/n:\t");
                    scanf("%s", conti);
                    printf(" \n");
                    if((strcmp(conti, "n") == 0) || (strcmp(conti, "N") == 0)){
                        printf("Enter primary key: \n");
                        scanf("%s", primary);
                        query field2;
                        sprintf(field2, "PRIMARY KEY(%s)", primary);
                        strcat(all_fields, field2);
                        printf("ALL_FIELDS: %s \n", all_fields);
                        break;
                    }
                }
                
                query create;
                sprintf(create, "CREATE TABLE IF NOT EXISTS %s(%s)", table_name, all_fields);
                printf("CREATE CMD: %s \n", create);
                printf("Creating new table... \n");
                if (mysql_query(conn, create)) {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                    exit(1);
                }
            }
            break;

        case 3:
            {
                query insert;
                string conti;
                do{
                    printf("Enter employee record: \n");
                    printf("NAME DOMAIN LANG EXPC \n");
                    scanf("%s %s %s %d", emp.name, emp.domain, emp.lang, &emp.expc);
                    printf("Inserting new employee... \n");
                    sprintf(insert, "INSERT INTO employee3 (name, domain, lang, expc) VALUES ('%s', '%s', '%s', %d )", emp.name, emp.domain, emp.lang, emp.expc);
                    if (mysql_query(conn, insert)) {
                        fprintf(stderr, "%s\n", mysql_error(conn));
                        exit(1);
                    }
                    printf("Continue? y/n \t");
                    scanf("%s", conti);
                    printf(" \n");
                    if((strcmp(conti, "n") == 0) || (strcmp(conti, "N") == 0)){
                        break;
                    }

                }while(1);
            }
            break;

        case 4:
            {
                int emp_id;
                query delete;
                string table_name;
                printf("Enter table name: \n");
                scanf("%s", table_name);
                printf("Enter id of employee to be deleted: \n");
                scanf("%d", &emp_id);
                sprintf(delete, "DELETE FROM %s WHERE id = %d", table_name, emp_id);
                if (mysql_query(conn, delete)) {
                        fprintf(stderr, "%s\n", mysql_error(conn));
                        exit(1);
                }
                printf("Deleting old employee... \n");
            }
            break;

        case 5:
            {
                string table_name;
                printf("Enter tablename: ");
                scanf("%s", table_name);
                // Retrieve the data from the table
                query view;
                sprintf(view, "SELECT * FROM %s", table_name);
                printf("VIEW: %s \n", view);
                if (mysql_query(conn, view)) {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                    exit(1);
                }
                res = mysql_use_result(conn);

                // Print the results
                printf("ID\tName\tDomain\tLang\tExpc\n");
                while ((row = mysql_fetch_row(res)) != NULL) {
                    printf("%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3], row[4]);
                }

                mysql_free_result(res);
            }
            break;        
        default:
            break;
        }
    }while(choice);     

    mysql_close(conn);

    return 0;
}
