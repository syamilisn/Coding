#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
    sqlite3* db;
    char* error_msg = NULL;
    int rc;

    rc = sqlite3_open("mydatabase.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char* create_table_sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT NOT NULL, age INTEGER)";

    rc = sqlite3_exec(db, create_table_sql, NULL, 0, &error_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    char* insert_sql = "INSERT INTO users (name, age) VALUES ('John Doe', 25), ('Jane Doe', 23)";

    rc = sqlite3_exec(db, insert_sql, NULL, 0, &error_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_stmt* select_stmt;
    const char* select_sql = "SELECT * FROM users";
    rc = sqlite3_prepare_v2(db, select_sql, -1, &select_stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    while (sqlite3_step(select_stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(select_stmt, 0);
        const unsigned char* name = sqlite3_column_text(select_stmt, 1);
        int age = sqlite3_column_int(select_stmt, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }

    sqlite3_finalize(select_stmt);
    sqlite3_close(db);

    return 0;
}

