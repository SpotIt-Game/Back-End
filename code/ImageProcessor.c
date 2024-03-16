#include "SAT.h"


int n = 0;
card input;





void print(card curr){

    for(int i = 0; i<n; ++i){
        printf("id: %d\nwidth: %lf\nheight: %lf\n", curr.imgs[i].id_image, curr.imgs[i].width, curr.imgs[i].height);
        printf("Scale: %lf\nRotate: %lf\n", curr.imgs[i].scale, curr.imgs[i].rotate);
        printf("Area: %lf\n", curr.imgs[i].width * curr.imgs[i].height);
        for(int j = 0; j<4; ++j) printf("%lf %lf\n", curr.imgs[i].P[j].x, curr.imgs[i].P[j].y);
        puts("");
    }

}









int main(){

    srand(time(NULL));
    while(scanf("%d %lf %lf", &input.imgs[n].id_image, &input.imgs[n].width, &input.imgs[n].height) == 3){

        for(int i = 0; i<4; ++i) scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = 1;
        input.imgs[n].rotate = 0;
        scale(&input.imgs[n], initSize/input.imgs[n].width);
        move(&input.imgs[n]);
        rotate(&input.imgs[n]);
        ++n; 

    }print(input);
    return 0;

}