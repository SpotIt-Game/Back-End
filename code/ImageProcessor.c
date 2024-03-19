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
    return !inside(*a) || (max(a->height, a->width)  > radio);

}








//expands an Image as much as possible, using binary search
void expand(polygon *a, int pol){

    double i = 1.0, j = 100;
    polygon aux = *a;
    while(fabsl(i-j) > 1e-15){

        double m = (i+j)/2;
        aux = *a;
        scale(&aux, m);
        if(collision(&aux, pol)) j = m;
        else i = m;
    
    }*a = aux;

}









void tryRotatingCenter(polygon * a, int index){

    polygon aux = *a;
    for(double i = 0.0174; i<2*PI; i += 0.0174){

        rotate(a, i);
        if(!collision(a, index)) return;

    }*a = aux;

}


void tryRotatingCorners(polygon * a, int index){

    for(int i = 0; i<4; ++i){
        polygon aux = copyPolygon(a);
        vector corner = {aux.P[i].x, aux.P[i].y};
        for(double j = 0.0174; j<2*PI; j += 0.0174){
            rotateCorner(&aux, j, &corner);
            if(!collision(&aux, index)){
                a = &aux;
                return;
            }
        }
    }
    

}











void expandImages(){

    for(int i = 0; i<1000; ++i){
        int index = rand()%n;
        expand(&input.imgs[index], index);
        tryRotatingCenter(&input.imgs[index], index);
        tryRotatingCorners(&input.imgs[index], index);
        expand(&input.imgs[index], index);
    }

}













double usedArea(){

    double area = 0;
    for(int i = 0; i<n; ++i) area += (input.imgs[i].width * input.imgs[i].height);
    return area;

}











int main(){

    srand(time(NULL));
    while(scanf("%d %Lf %Lf", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) scanf("%Lf %Lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = 1;
        input.imgs[n].rotate = 0;
        scale(&input.imgs[n], (initSize)/max(input.imgs[n].width, input.imgs[n].height));
        rotate(&input.imgs[n], random(0.0, 2*PI));
        ++n; 

    }shuffle(input.imgs, n);
    moveToInitialPoints();
    expandImages();
    for(int i = 0; i<n; ++i) print(input.imgs[i]);
    // printf("Used area: %Lf\n", usedArea());
    return 0;
    

}