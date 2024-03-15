#include "SAT.h"




#define maxArea (radio*radio*PI)
int id_image, w, h, n = 0;
card input;











double fitness(card * curr){

    double fitness = 1; 
    for(int i = 0; i<n; ++i) fitness += curr->imgs[i].width * curr->imgs[i].height;
    int collisions = 1;
    for(int i = 0; i<n; ++i){
        collisions += !inside(curr->imgs[i]);
        for(int j = i+1; j<n; ++j)
            collisions += (polygonIntersect(curr->imgs[i], curr->imgs[j]));

    }return fitness/collisions;

        
}












void print(){

    for(int i = 0; i<n; ++i){
        printf("id: %d\n", input.imgs[i].id_image);
        for(int j = 0; j<4; ++j) printf("%lf %lf\n", input.imgs[i].P[j].x, input.imgs[i].P[j].y);
        puts("");
    }

}









int main(){

    while(scanf("%d %d %d", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        ++n; 

    }print();
    printf("%lf\n", fitness(&input));   
    return 0;
    

}