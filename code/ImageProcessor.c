#include "SAT.h"





int n = 0;
card input;








void moveToInitialPoints(){

    vector * initPoints = generatePoints(n);
    for(int i = 0; i<n; ++i) move(&input.imgs[i], &initPoints[i]);

}













int main(){

    srand(time(NULL));
    while(scanf("%d %lf %lf", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = 1;
        input.imgs[n].rotate = 0;
        scale(&input.imgs[n], initSize/max(input.imgs[n].width, input.imgs[n].height));
        ++n; 

    }moveToInitialPoints();
    for(int i = 0; i<n; ++i) print(input.imgs[i]);
    return 0;
    

}