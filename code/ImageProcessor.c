#include "SAT.h"





int n = 0;
card input;








void moveToInitialPoints(){

    vector * initPoints = generatePoints(n);
    for(int i = 0; i<n; ++i) move(&input.imgs[i], &initPoints[i]);

}












void expand(polygon *a, int pol){

    double i = 1.0, j = 7;
    polygon aux = *a;
    while(fabs(i-j) > 1e-10){

        double m = (i+j)/2;
        aux = *a;
        scale(&aux, m);
        for(int k = 0; k<n; ++k)
            if((k != pol) && (polygonIntersect(aux, input.imgs[k]) || (!inside(aux)) || (max(aux.width, aux.height) >= radio>>1))){    
                j = m; k = n;
            }

        if(j != m) i = m;

    }*a = aux;

}





void expandImages(){

    for(int i = 0; i<10000; ++i){
        int index = rand()%n;
        expand(&input.imgs[index], index);
    }for(int i = 0; i<10000; ++i) expand(&input.imgs[i%n], i%n);
    


}













int main(){

    srand(time(NULL));
    while(scanf("%d %lf %lf", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = 1;
        input.imgs[n].rotate = 0;
        scale(&input.imgs[n], initSize/max(input.imgs[n].width, input.imgs[n].height));
        rotate(&input.imgs[n], random(0.0, 2*PI));
        ++n; 

    }shuffle(input.imgs, n);
    moveToInitialPoints();
    expandImages();
    for(int i = 0; i<n; ++i) print(input.imgs[i]);
    return 0;
    

}