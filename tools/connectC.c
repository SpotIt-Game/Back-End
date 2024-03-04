#include <stdio.h>
#include <stdlib.h>
#include "mysql_libs/mysql.h"


int main() {

    MYSQL *conn;
    char *server = "sql5.freesqldatabase.com";
    char *user = "sql5688705";
    char *password = "uACuvPiU8u";
    char *database = "sql5688705";
    int port = 3306;

    conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "mysql_init failed\n");
        return 1;
    }

    if (!mysql_real_connect(conn, server, user, password, database, port, NULL, 0)) {
        fprintf(stderr, "Error connecting to the database: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    printf("Connected to the database successfully\n");
    mysql_close(conn);
    return 0;

}
