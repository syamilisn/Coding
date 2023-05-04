#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
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

    // Create a table
    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS users (id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255), email VARCHAR(255))")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Insert data into the table
    if (mysql_query(conn, "INSERT INTO users (name, email) VALUES ('John Doe', 'johndoe@example.com')")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Retrieve the data from the table
    if (mysql_query(conn, "SELECT * FROM users")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    // Print the results
    printf("ID\tName\tEmail\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
    }

    // Free resources
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
