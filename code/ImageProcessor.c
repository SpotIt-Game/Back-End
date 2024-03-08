#include "libs.h"




int rows, cols, cX, cY;
double S, R;
typedef struct image Image;






struct image{

    int points[4][2];         // -> (0, 0), (x, 0), (0, y), (x, y)
    int rotate, scale;

};



Image newImage(){

    Image img = {
        .points = {{0, 0}, {cols, 0}, {0, rows}, {cols, rows}}, 
        .rotate = R,
        .scale = S,
    };return img;

}






void readPNG(char *file){

    FILE *fp = fopen(file, "rb");
    if (!fp) abort();
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();
    png_infop info = png_create_info_struct(png);
    if (!info) abort();
    if (setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);
    png_read_info(png, info);
    cols = png_get_image_width(png, info);
    rows = png_get_image_height(png, info);
    fclose(fp);

}






void scaleAndRotate(Image * img){

    double cosTheta = cos(R), sinTheta = sin(R);
    cX = cols>>1; cY = rows>>1;

    for(int i = 0; i<4; ++i){

        int x = img->points[i][0] - cX, y = img->points[i][1] - cY;
        img->points[i][0] = (int)(x*cosTheta - y*sinTheta) + cX;
        img->points[i][1] = (int)(x*sinTheta + y*cosTheta) + cY;

    }

    for(int i = 0; i<4; i++){
        img->points[i][0] *= S;
        img->points[i][1] *= S;
    }

}















int main(){

    readPNG("/home/danilo/SpotIT-Game/SpotIT/code/Images/ComputerScience/gitlab.png"); //path to images
    srand((unsigned)time(NULL));
    
    S = sqrt(((double)rand() / RAND_MAX) * 2.0);
    R = ((double)rand() / RAND_MAX) * 2.0 * PI;

    Image img = newImage();
    
    scaleAndRotate(&img);
    for(int i = 0; i<4; ++i) printf("%d %d\n", img.points[i][0], img.points[i][1]);
    return 0;

}
