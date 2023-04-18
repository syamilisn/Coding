#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

	int empid, expc;
	char name[100], domain[100], lang[100];
int insert_row(sqlite3* db, char *error_msg){
	printf("Enter row:\nEMPID NAME DOMAIN, LANG, EXPERIENCE\n");
	scanf("%d %s %s %s %d", &empid, name, domain, lang, &expc);
	char buffer[500];
	snprintf(buffer, sizeof(buffer), "INSERT INTO employees (name, domain, lang, exp) VALUES ('%s', '%s', '%s', %d)", name, domain, lang, expc);
	char* insert_sql = buffer;
	int rc = sqlite3_exec(db, insert_sql, NULL, 0, &error_msg);
	return rc;
}
int main(int argc, char* argv[]){
	sqlite3* db;
	char* error_msg = NULL;
	int rc = sqlite3_open("mydatabase.db", &db);	//db connection
	if (rc != SQLITE_OK){
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	//create_table();
	char *create_table = "CREATE TABLE IF NOT EXISTS employees (empid INTEGER PRIMARY KEY, name TEXT NOT NULL, domain VARCHAR(30), lang VARCHAR(30), exp INTEGER)";
	rc = sqlite3_exec(db, create_table, NULL, 0, &error_msg);
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", error_msg);
		sqlite3_free(error_msg);
		sqlite3_close(db);
		return 1;
	}
	
	rc = insert_row(db, error_msg);
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", error_msg);
		sqlite3_free(error_msg);
		sqlite3_close(db);
		return 1;
	}

	sqlite3_stmt* select_stmt;
	const char* select_sql = "SELECT * FROM employees";
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
       		 printf("EMPID: %d, Name: %s, Domain: %s, Lang: %s, Exp: %d\n", empid, name, domain, lang, expc);
   	 }

   	 sqlite3_finalize(select_stmt);
   	 sqlite3_close(db);

   	 return 0;
}
