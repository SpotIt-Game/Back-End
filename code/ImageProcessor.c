#include "SAT.h"


int n = 0;
card input;
vector * initPoints;






void print(polygon curr){

    printf("id: %d\nwidth: %lf\nheight: %lf\n", curr.id_image, curr.width, curr.height);
    printf("Scale: %lf\nRotate: %lf\n", curr.scale, curr.rotate);
    printf("Area: %lf\n", curr.width * curr.height);
    for(int j = 0; j<4; ++j) printf("%lf %lf\n", curr.P[j].x, curr.P[j].y);
    puts("");

}










int main(){

    srand(time(NULL));
    while(scanf("%d %lf %lf", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = 1;
        input.imgs[n].rotate = 0;
        ++n; 

    }initPoints = generatePoints(n);
    for(int i = 0; i<n; ++i) printf("%lf %lf\n", initPoints[i].x, initPoints[i].y);
    return 0;
    

}