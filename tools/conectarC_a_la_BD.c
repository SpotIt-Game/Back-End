//Para poder conectar el programa C se debe descargar la carpeta con mysql.h y agregarlo al path para poder incluirlo correctamente
#include<stdio.h>
#include<mysql.h>

int main(){
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "127.0.0.1";
    char *user = "joshua"; 
    char *password = "Besamestazona11!";
    char *database = "P1";
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "Error al conectar a la base de datos: %s\n", mysql_error(conn));
        return 1;
    } printf("Conectado!\n");
    mysql_close(conn);
    return 0;
}

// Ejecutar una consulta SQL
    // if (mysql_query(conn, "SELECT * FROM nombre_tabla")) { // Reemplaza "nombre_tabla" con el nombre de tu tabla
    //     fprintf(stderr, "Error al ejecutar la consulta: %s\n", mysql_error(conn));
    //     return 1;
    // }

    // res = mysql_use_result(conn);

    // // Imprimir resultados
    // while ((row = mysql_fetch_row(res)) != NULL) {
    //     printf("%s %s\n", row[0], row[1]); // Ajusta según las columnas de tu tabla
    // }

    // mysql_free_result(res);
