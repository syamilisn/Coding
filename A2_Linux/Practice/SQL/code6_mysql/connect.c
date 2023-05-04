/* mysql_
 * 	 init()		:initialize connection
 * 	 real_connect()	:connect to DB
 * 	 query()	:write query
 * 	 close()	:close connection
 *	 error()	:connection error
 *	 get_client_info(): get client version
 */
#include <stdio.h>
#include <mysql.h>

int main() {
    MYSQL *conn;
    conn = mysql_init(NULL);

    if (mysql_real_connect(conn, "localhost", "root", "Cuppie@123", "employeedb", 0, NULL, 0) == NULL) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    mysql_query(conn, "CREATE TABLE mytable (id INT, name VARCHAR(50))");
    mysql_query(conn, "INSERT INTO mytable VALUES (1, 'John Smith')");

    mysql_close(conn);

    return 0;
}

