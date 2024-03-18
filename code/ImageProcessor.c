#include "SAT.h"





int n = 0;
card input;








void moveToInitialPoints(){

    vector * initPoints = generatePoints(n);
    for(int i = 0; i<n; ++i) move(&input.imgs[i], &initPoints[i]);

}






//verifies if a polygon is in a valid position
bool collision(polygon *a, int index){

    for(int k = 0; k<n; ++k)
        if(k != index && polygonIntersect(*a, input.imgs[k])) return true;
    return !inside(*a) || (max(a->height, a->width)  > 3*radio/4);

}








//expands an Image as much as possible, using binary search
bool expand(polygon *a, int pol){

    double i = 1.0, j = 100;
    polygon aux = *a;
    while(fabs(i-j) > 1e-15){

        double m = (i+j)/2;
        aux = *a;
        scale(&aux, m);
        if(collision(&aux, pol)) j = m;
        else i = m;
    
    }*a = aux;
    return (i-1 > 10e-15);

}







bool tryRotating(polygon * a, int index){

    polygon aux = *a;
    for(double i = 0.0174; i<2*PI; i += 0.0174){

        rotate(a, i);
        if(!collision(a, index)) return true;

    }*a = aux;
    return false;
    

}









void expandImages(){

    for(int i = 0; i<10000; ++i){
        int index = rand()%n;
        //if(!expand(&input.imgs[index], index)) tryRotating(&input.imgs[index], index);
        expand(&input.imgs[index], index);
        
    }
    


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