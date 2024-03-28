#include "libs.h"



#define double long double
const double radio = 200.0;
const double initSize = 26.0;



typedef struct{
    double x, y;
}vector;


typedef struct{
    int id_image;
    vector P[4];
    double scale, rotate, width, height;
} polygon;



typedef struct {
    polygon imgs[73];
} card;






vector newVector(double x, double y){
    vector n;
    n.x = x;
    n.y = y;
    return n;
}








//random inside an interval
double random(double min, double max){
    return min + ((double)rand()) / RAND_MAX * (max - min);
}


















//This may change
vector * generatePoints(int n){

    vector * points = (vector*)malloc(n*sizeof(vector));
    points[0] = newVector(0, 0);
    n--;
    for(int i = 0; i<n; ++i) points[i+1] = newVector((radio/4) * cos((2*PI*i)/n), (radio/4) * sin((2*PI*i)/n));
    return points;

}









//returns the center point of a circle
vector getCenter(polygon * a){

    vector c = {0, 0};
    for (int i = 0; i < 4; ++i) {
        c.x += a->P[i].x;
        c.y += a->P[i].y;

    }c.x /= 4.0;
    c.y /= 4.0;
    return c;

}







//verifies if a polygon is inside a circle
bool inside(polygon a){
    for (int i = 0; i<4; ++i)
        if(sqrt((a.P[i].x * a.P[i].x) + (a.P[i].y * a.P[i].y)) > radio-initSize) return 0;
    return 1;
}


double dotProduct(vector a, vector b) {
    return a.x * b.x + a.y * b.y;
}














//scales a polygon by factor
void scale(polygon * a, double factor){

    a->height *= factor;
    a->width *= factor;
    for(int i = 0; i<4; ++i){
        a->P[i].x *= factor;
        a->P[i].y *= factor;
    }a->scale *= factor*factor; //this could change


}








//moves a polygon to a given point
void move(polygon *a, vector * center){

    vector currCenter = getCenter(a);
    double x = center->x - currCenter.x;
    double y = center->y - currCenter.y;

    for(int w = 0; w<4; ++w){
        a->P[w].x += x;
        a->P[w].y += y;
    } 

    
}










void rotate(polygon *a, double radian, vector corner) {

    a->rotate = fmod(radian + a->rotate, 2*PI);
    double cosTheta = cos(radian), sinTheta = sin(radian);

    for (int i = 0; i < 4; ++i) {
        double x = a->P[i].x - corner.x, y = a->P[i].y - corner.y;
        a->P[i].x = corner.x + (x * cosTheta - y * sinTheta);
        a->P[i].y = corner.y + (x * sinTheta + y * cosTheta);
    }

}
















vector normal(vector a, vector b) {
    vector norm = {a.y - b.y, b.x - a.x};
    double len = sqrt(norm.x * norm.x + norm.y * norm.y);
    norm.x /= len;
    norm.y /= len;
    return norm;
}




void projectPolygon(vector axis, polygon p, int count, double *min, double *max){

    *min = dotProduct(axis, p.P[0]);
    *max = *min;

    for (int i = 1; i < count; ++i) {
        double project = dotProduct(axis, p.P[i]);
        *min = fmin(*min, project);
        *max = fmax(*max, project);
    }

}



bool intervalIntersect(double minA, double maxA, double minB, double maxB) {
    return maxA+initSize >= minB && maxB+initSize >= minA;
}




bool polygonIntersect(polygon a, polygon b){

    double minA, minB, maxA, maxB;
    for (int i = 0; i < 4; ++i) {

        vector norm = normal(a.P[i], a.P[(i + 1) % 4]);
        projectPolygon(norm, a, 4, &minA, &maxA);
        projectPolygon(norm, b, 4, &minB, &maxB);
        if (!intervalIntersect(minA, maxA, minB, maxB)) return false;
    }

    for (int i = 0; i < 4; ++i){

        vector norm = normal(b.P[i], b.P[(i + 1) % 4]);
        projectPolygon(norm, a, 4, &minA, &maxA);
        projectPolygon(norm, b, 4, &minB, &maxB);
        if (!intervalIntersect(minA, maxA, minB, maxB)) return false;

    }return true;

}























void print(polygon curr){
    
    printf("id: %d\n", curr.id_image);
    // printf("Scale: %Lf\nRotate: %Lf\n", curr.scale, curr.rotate);
    printf("%Lf %Lf\n", curr.P[0].x, curr.P[0].y);
    printf("%Lf %Lf\n", curr.P[1].x, curr.P[1].y);
    printf("%Lf %Lf\n", curr.P[2].x, curr.P[2].y);
    printf("%Lf %Lf\n", curr.P[3].x, curr.P[3].y);
    puts("");

}



void shuffle(polygon *arr, int n) {
   
    for (int i = n-1; i > 0; i--) {
        int j = rand()%(i+1); 
        polygon temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
}

















void insertImageIntoDB(int id_card, polygon * img, MYSQL * conn){

    MYSQL_STMT *stmt;
    MYSQL_BIND bind[6];
    const char *query = "INSERT INTO image_card (id_card, id_image, x, y, scale, rotate) VALUES (?, ?, ?, ?, ?, ?);";
    stmt = mysql_stmt_init(conn);
    if(!stmt || mysql_stmt_prepare(stmt, query, strlen(query))){
        puts("Error preparing the statement\n");
        return;
    }


    memset(bind, 0, sizeof(bind));
    bind[0].buffer_type = MYSQL_TYPE_LONG;
    bind[0].buffer = &id_card;

    bind[1].buffer_type = MYSQL_TYPE_LONG;
    bind[1].buffer = &img->id_image;

    char str_x[50], str_y[50], str_scale[50], str_rotate[50];
    snprintf(str_x, sizeof(str_x), "%Lf", img->P[0].x);
    snprintf(str_y, sizeof(str_y), "%Lf", img->P[0].y);
    snprintf(str_scale, sizeof(str_scale), "%Lf", img->scale);
    snprintf(str_rotate, sizeof(str_rotate), "%Lf", img->rotate);

    bind[2].buffer_type = MYSQL_TYPE_STRING;
    bind[2].buffer = str_x;
    bind[2].buffer_length = strlen(str_x);

    bind[3].buffer_type = MYSQL_TYPE_STRING;
    bind[3].buffer = str_y;
    bind[3].buffer_length = strlen(str_y);

    bind[4].buffer_type = MYSQL_TYPE_STRING;
    bind[4].buffer = str_scale;
    bind[4].buffer_length = strlen(str_scale);

    bind[5].buffer_type = MYSQL_TYPE_STRING;
    bind[5].buffer = str_rotate;
    bind[5].buffer_length = strlen(str_rotate);

    if (mysql_stmt_bind_param(stmt, bind)) {
        printf("Error binding parameters\n"); 
        mysql_stmt_close(stmt);
        return;
    }

    if (mysql_stmt_execute(stmt)) {
        printf("Error executing the statement\n");
        mysql_stmt_close(stmt);
        return;
    }

    mysql_stmt_close(stmt);
    printf("Image with id: %d in card %d, inserted successfully!\n", img->id_image, id_card);

}

