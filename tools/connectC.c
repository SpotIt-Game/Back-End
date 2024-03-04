#include<stdio.h>
#include "mysql_libs/mysql.h"


int main() {

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "127.0.0.1";
    char *user = "joshua"; 
    char *password = "Besamestazona11!";
    char *database = "P1";
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to the database: %s\n", mysql_error(conn));
        return 1;
    } printf("Connected!\n");
    mysql_close(conn);
    return 0;

}

// Execute an SQL query
    // if (mysql_query(conn, "SELECT * FROM table_name")) { // Replace "table_name" with the name of your table
    //     fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
    //     return 1;
    // }

    // res = mysql_use_result(conn);

    // // Print results
    // while ((row = mysql_fetch_row(res)) != NULL) {
    //     printf("%s %s\n", row[0], row[1]); // Adjust according to your table's columns
    // }

    // mysql_free_result(res);
