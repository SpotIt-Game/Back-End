#include "SAT.h"




#define maxArea (radio*radio*PI)
#define sizeGen 200
int id_image, w, h, n = 0;

card input;
card gen[sizeGen], newGen[sizeGen];










//fitness function of a card
double fitness(card * curr){

    double fitness = 1; 
    for(int i = 0; i<n; ++i) fitness += curr->imgs[i].width * curr->imgs[i].height;
    int collisions = 1;
    for(int i = 0; i<n; ++i){
        collisions += !inside(curr->imgs[i]);
        for(int j = i+1; j<n; ++j)
            collisions += (polygonIntersect(curr->imgs[i], curr->imgs[j]));

    }return fitness/(collisions*collisions);

}




//Mutates a card's genes
void mutation(card * kid){

    for(int i = 0; i<n; ++i)
        if(rand()%4 < 2){
            kid->imgs[i].rotate += rand()%3;
            double newScale = sqrt(random(0.7, 1.5));
            kid->imgs[i].scale *= newScale;
            for(int j = 0; j<4; ++j){
                kid->imgs[i].P[j].x  *= newScale;
                kid->imgs[i].P[j].y *= newScale;
            }
        }

}


//combines two parents cards
card crossOver(card * p1, card * p2){

    card new;
    for(int i = 0; i<(n>>1); ++i) new.imgs[i] = p1->imgs[i];
    for(int i = n>>1; i<n; ++i) new.imgs[i] = p2->imgs[i];
    if((rand()%100) < 5) mutation(&new);
    return new;

}







//generates the first generation of cards
void generateSeed(){

    for(int i = 0; i<n; ++i) scale(&input.imgs[i], 20.0/max(input.imgs[i].width, input.imgs[i].height)); //scales all cards to approximately 20*20

    for(int i = 0; i<sizeGen; ++i){
        gen[i] = input;
        for(int j = 0; j<n; ++j)
            for(int w = 0; w<4; ++w){
                gen[i].imgs[j].P[w].x += (rand()%radio) - (radio>>1);
                gen[i].imgs[j].P[w].y += (rand()%radio) - (radio>>1);
            }        
    }

}




















void print(card curr){

    for(int i = 0; i<n; ++i){
        printf("id: %d\nwidth: %lf\nheight: %lf\n", curr.imgs[i].id_image, curr.imgs[i].width, curr.imgs[i].height);
        for(int j = 0; j<4; ++j) printf("%lf %lf\n", curr.imgs[i].P[j].x, curr.imgs[i].P[j].y);
        puts("");
    }

}









int main(){

    srand(time(NULL));
    while(scanf("%d %lf %lf", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) 
            scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = 1;
        input.imgs[n].rotate = 0;
        ++n; 

    }
    
    generateSeed();
    for(int i = 0; i<10; ++i){
        printf("Entity %d:\n", i);
        printf("fitness: %lf\n", fitness(&gen[i]));
        print(gen[i]);
        puts("");

    }return 0;
    

}