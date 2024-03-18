#include "libs.h"




const int radio = 150;
const int initSize = 20;



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
    double fit;
} card;






vector newVector(double x, double y){
    vector n;
    n.x = x;
    n.y = y;
    return n;
}







vector * generatePoints(int n){

    vector * points = (vector*)malloc(n * sizeof(vector));
    points[0] = newVector(0, 0);
    n--;
    for(int i = 0; i<n; ++i) points[i+1] = newVector((radio>>2) * cos((2*PI*i)/n), (radio>>2) * sin((2*PI*i)/n));
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

//random inside an interval
double random(double min, double max){
    return min + (double)rand() / RAND_MAX * (max - min);
}

//distance between two points
double distance(vector a, vector b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}



//verifies if a polygon is inside a circle
bool inside(polygon a){
    for (int i = 0; i<4; ++i)
        if(sqrt((a.P[i].x * a.P[i].x) + (a.P[i].y * a.P[i].y)) >= radio-initSize) return 0;
    return 1;
}

double dotProduct(vector a, vector b) {
    return a.x * b.x + a.y * b.y;
}














//scales a polygon by factor
void scale(polygon *a, double factor){

    a->height *= factor;
    a->width *= factor;
    for(int i = 0; i<4; ++i){
        a->P[i].x *= factor;
        a->P[i].y *= factor;
    }a->scale *= factor;

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













//rotates a polygon by a given angle
void rotate(polygon *a, double radian) {

    vector center = getCenter(a);
    a->rotate += radian;
    double cosTheta = cos(radian), sinTheta = sin(radian);

    for (int i = 0; i < 4; ++i) {
        double x = a->P[i].x - center.x, y = a->P[i].y - center.y;
        a->P[i].x = center.x + (x * cosTheta - y * sinTheta);
        a->P[i].y = center.y + (x * sinTheta + y * cosTheta);
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
    return maxA >= minB && maxB >= minA;
}




bool polygonIntersect(polygon a, polygon b){

    for (int i = 0; i < 4; ++i) {
        vector norm = normal(a.P[i], a.P[(i + 1) % 4]);
        double minA, minB, maxA, maxB;
        projectPolygon(norm, a, 4, &minA, &maxA);
        projectPolygon(norm, b, 4, &minB, &maxB);
        if (!intervalIntersect(minA, maxA, minB, maxB)) return false;
    }

    for (int i = 0; i < 4; ++i){

        vector norm = normal(b.P[i], b.P[(i + 1) % 4]);
        double minA, minB, maxA, maxB;
        projectPolygon(norm, a, 4, &minA, &maxA);
        projectPolygon(norm, b, 4, &minB, &maxB);
        if (!intervalIntersect(minA, maxA, minB, maxB)) return false;

    }return true;

}










void print(polygon curr){

    printf("id: %d\n", curr.id_image);
    //printf("width: %lf\nheight: %lf\nScale: %lf\nRotate: %lf\n", curr.width, curr.height, curr.scale, curr.rotate);
    //printf("Area: %lf\n", curr.width * curr.height);
    for(int j = 0; j<4; ++j) printf("%lf %lf\n", curr.P[j].x, curr.P[j].y);
    puts("");

}


void shuffle(polygon * arr, int n) {
   
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); 
        polygon temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
}