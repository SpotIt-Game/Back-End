#include "libs.h"
#include "SAT.h"



const int radio = 140; //radio - 10




typedef struct{

    int id_image;
    vector P[4];
    double scale, rotate;

} polygon;



typedef struct{
    polygon imgs[73];
} card;




double distance(vector a, vector b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}






bool inside(polygon a){

    for(int i = 0; i<4; ++i) 
        if(sqrt(a.P[i].x*a.P[i].x + a.P[i].y*a.P[i].y) >= radio) return 1;
    return 0;
    
}







vector getCenter(polygon a){

    vector c;
    double minY = oo, minX = oo, maxY = -oo, maxX = -oo;
    for(int i = 0; i<4; ++i){

        minY = min(minY, a.P[i].y);
        minX = min(minX, a.P[i].x);
        maxY = max(maxY, a.P[i].y);
        maxX = max(maxX, a.P[i].x);

    }c.x = (maxX+minX)/2;
    c.y = (maxY+minY)/2;
    return c;

}






double borderDistance(polygon a){

    vector center = a.P[3];
    vector origin = {0, 0};
    printf("%lf\n", distance(center, origin));
    return radio - distance(center, origin) + 10;

}





double distanceBetweenPolygons(polygon a, polygon b){
    return distance(getCenter(a), getCenter(b));
}



