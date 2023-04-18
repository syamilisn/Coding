#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("mydatabase.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    const char *sql = "INSERT INTO mytable (id, name, age) VALUES (1, 'John Smith', 30)";
    char *errmsg;
    rc = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }

    sqlite3_close(db);
    return 0;
}

