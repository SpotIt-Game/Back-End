#include "SAT.h"


int n = 0;
card input;





void print(polygon curr){

    printf("id: %d\nwidth: %lf\nheight: %lf\n", curr.id_image, curr.width, curr.height);
    printf("Scale: %lf\nRotate: %lf\n", curr.scale, curr.rotate);
    printf("Area: %lf\n", curr.width * curr.height);
    for(int j = 0; j<4; ++j) printf("%lf %lf\n", curr.P[j].x, curr.P[j].y);
    puts("");

}








bool rotateImage(polygon *a, int index){

    polygon aux = *a;
    for(double i = 0.0174; i<2*PI; i += 0.0174){
        
        rotate(&aux, i);
        for(int j = 0; j<n; ++j)
            if(j != index && !polygonIntersect(aux, input.imgs[j])){
                a = &aux;
                return 1;
            }

    }return 0;
    
}



bool resizeImage(polygon * a, int index){

    double i = 1, j = 2;
    polygon aux;
    while((j-i) > 1e-5){

        aux = *a;
        double m = (i+j)/2;
        scale(&aux, m);
        for(int w = 0; w<n; ++w)
            if(w != index && (polygonIntersect(aux, input.imgs[w]) || !inside(aux))){
                j = m; break;
            }

        if(j != m) i = m;

    }a = &aux;
    return (i-1 > 1e-2);

}






void extendImages(){

    bool couldExtend;
    do{

        for(int i = 0; i<n; ++i) 
            couldExtend = (resizeImage(&input.imgs[i], i));

    }while(couldExtend);

}










int main(){

    srand(time(NULL));
    while(scanf("%d %lf %lf", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = 1;
        input.imgs[n].rotate = 0;
        scale(&input.imgs[n], initSize/input.imgs[n].width);
        move(&input.imgs[n]);
        //rotate(&input.imgs[n], random(0.0, 2*PI));
        ++n; 

    }extendImages();
    for(int i = 0; i<n; ++i) print(input.imgs[i]);
    for(int i = 0; i<n; ++i)
        for(int j = i+1; j<n; ++j)
            if(polygonIntersect(input.imgs[i], input.imgs[j]))
                printf("collision between %d and %d\n", i, j);
    return 0;
    

}