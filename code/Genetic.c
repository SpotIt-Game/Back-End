#include "Image.h"



#define maxArea (radio*radio*PI)
int id_image, n = 0;
card input;










void print(){

    for(int i = 0; i<n; ++i){
        printf("id: %d\n", input.imgs[i].id_image);
        for(int j = 0; j<4; ++j) printf("%lf %lf\n", input.imgs[i].P[j].x, input.imgs[i].P[j].y);
        puts("");
    }

}









int main(){

    while(scanf("%d", &id_image) == 1){

        input.imgs[n].id_image = id_image;
        input.imgs[n].rotate = 0;

        for(int i = 0; i<4; ++i) scanf("%lf %lf", &input.imgs[n].P[i].x, &input.imgs[n].P[i].y);
        input.imgs[n].scale = radio/max(input.imgs[n].P[3].x, input.imgs[n].P[3].y);

        for(int i = 0; i<4; ++i){
            input.imgs[n].P[i].x *= input.imgs[n].scale;
            input.imgs[n].P[i].y *= input.imgs[n].scale;

        }++n;  

    }print();
    return 0;
    

}