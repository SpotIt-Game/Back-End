#include "libs.h"




const int radio = 140; // radio - 10

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




double random(double min, double max){
    return min + (double)rand() / RAND_MAX * (max - min);
}







void scale(polygon *a, double factor){

    a->height *= factor;
    a->width *= factor;
    for(int i = 0; i<4; ++i){
        a->P[i].x *= factor;
        a->P[i].y *= factor;
    }a->scale *= factor;

}

void move(polygon *a){

    int moveX = (rand()%radio) - (radio>>1), moveY = (rand()%radio) - (radio>>1);
    for(int w = 0; w<4; ++w){
        a->P[w].x += moveX; //check this
        a->P[w].y += moveY;
    }  
    
}


void rotate(polygon * a){

    // double radian = random(0.0, 2*PI);
    // a->rotate += radian;

    // double cX = a->P[0].x, cY = a->P[0].y;
    // double cosTheta = cos(radian), sinTheta = sin(radian);
    // for(int i = 0; i<4; ++i){

    //     double x = a->P[i].x - cX, y = a->P[i].y - cY;
    //     a->P[i].x *= (x*cosTheta - y*sinTheta) + cX;
    //     a->P[i].y *= (x*sinTheta + y*cosTheta) + cY;

    // }


}







double distance(vector a, vector b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


bool inside(polygon a){
    for (int i = 0; i < 4; ++i)
        if (sqrt(a.P[i].x * a.P[i].x + a.P[i].y * a.P[i].y) >= radio) return 0;
    return 1;
}






vector normal(vector a, vector b) {
    vector norm = {a.y - b.y, b.x - a.x};
    double len = sqrt(norm.x * norm.x + norm.y * norm.y);
    norm.x /= len;
    norm.y /= len;
    return norm;
}



double dotProduct(vector a, vector b) {
    return a.x * b.x + a.y * b.y;
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
