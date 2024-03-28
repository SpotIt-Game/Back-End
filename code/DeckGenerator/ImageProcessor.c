#include "SAT.h"



int n, id_deck, id_card;
card input;









void moveToInitialPoints(){

    vector * initPoints = generatePoints(n);
    for(int i = 0; i<n; ++i) move(&input.imgs[i], &initPoints[i]);

}






//verifies if a polygon is in a valid position
bool collision(polygon *a, int index){

    for(int k = 0; k<n; ++k)
        if(k != index && polygonIntersect(*a, input.imgs[k])) return true;
    return !inside(*a) || (max(a->height, a->width) >= 5*radio/4);

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
    for(double i = 0.0174; i<PI; i += 0.0174){

        rotate(a, i, getCenter(a));
        if(!collision(a, index)) return;

    }*a = aux;

}


void tryRotatingCorners(polygon * a, int index){

    for(int i = 0; i<4; ++i){
        polygon aux = *a;
        for(double j = 0.0174; j<PI; j += 0.0174){
            rotate(&aux, j, (vector){aux.P[i].x, aux.P[i].y});
            if(!collision(&aux, index)){
                *a = aux;
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





























int main(){

    // MYSQL * conn = connectDB();
    srand(time(NULL));
    scanf("%d %d", &id_deck, &n);

    for(int i = 0; i<n * (n-1) + 1; ++i){

        scanf("%d", &id_card);
        for(int j = 0; j<n; ++j){

            scanf("%d %Lf %Lf", &input.imgs[j].id_image, &input.imgs[j].width, &input.imgs[j].height);
            for(int w = 0; w<4; ++w) scanf("%Lf %Lf", &input.imgs[j].P[w].x, &input.imgs[j].P[w].y);
            input.imgs[j].scale = 1; 
            input.imgs[j].rotate = 0;
            scale(&input.imgs[j], (initSize)/max(input.imgs[j].width, input.imgs[j].height));
            rotate(&input.imgs[j], random(0.0, 2*PI), getCenter(&input.imgs[j]));
            
        }shuffle(input.imgs, n);
        moveToInitialPoints();
        expandImages();
        printf("id_card: %d\n", id_card);
        for(int j = 0; j<n; ++j) print(input.imgs[j]);

    }return 0;
    

}