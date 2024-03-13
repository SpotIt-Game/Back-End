#include "libs.h"


typedef struct{
    double x, y;
} vector;






vector normal(vector a, vector b){

    vector norm = {a.y - b.y, b.x - a.x};
    double len = sqrt(norm.x * norm.x + norm.y * norm.y);
    norm.x /= len;
    norm.y /= len;
    return norm;

}



double dotProduct(vector a, vector b){
    return a.x*b.x + a.y*b.y;
}





void projectPolygon(vector axis, vector *verts, int count, double *min, double *max){

    *min = dotProduct(axis, verts[0]);
    *max = *min;

    for(int i = 1; i<count; ++i){

        double project = dotProduct(axis, verts[i]);
        *min = min(*min, project);
        *max = max(*max, project);

    }

}




bool intervalIntersect(double minA, double maxA, double minB, double maxB) {
    return maxA >= minB && maxB >= minA;
}






bool polygonIntersect(vector *vertsA, vector *vertsB, int countA, int countB){

    for(int i = 0; i<countA; ++i){

        vector norm = normal(vertsA[i], vertsA[(i+1)%countA]);
        double minA, minB, maxA, maxB;
        projectPolygon(norm, vertsA, countA, &minA, &maxA);
        projectPolygon(norm, vertsB, countB, &minB, &maxB);
        if (!intervalIntersect(minA, maxA, minB, maxB)) return 0;

    }

    for(int i = 0; i<countB; ++i){

        vector norm = normal(vertsB[i], vertsB[(i+1)%countB]);
        double minA, minB, maxA, maxB;
        projectPolygon(norm, vertsA, countA, &minA, &maxA);
        projectPolygon(norm, vertsB, countB, &minB, &maxB);
        if (!intervalIntersect(minA, maxA, minB, maxB)) return 0;

    }return 1;

}













int main(){

    vector polygonA[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    vector polygonB[] = {{-1, -1}, {-1, -2}, {-2, -2}, {0, -2}};
    int collision = polygonIntersect(polygonA, polygonB, 4, 4);
    printf("Collision: %s\n", collision ? "Yes" : "No");
    return 0;

}




