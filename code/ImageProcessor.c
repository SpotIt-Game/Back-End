#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <png.h>
#include<string.h>
#include<dirent.h>
#define pi 3.141592653589793
#define FOLDER_PATH "/home/joshua/Desktop/C/imagenes"

FILE* archivo;

int rows, cols;

struct image{
    int points[4][2];         // -> (0, 0), (x, 0), (0, y), (x, y)
    double rotate, scale;
};

typedef struct image Image;

Image newImage(double R, double S){
    Image img = {
            .points = {{0, 0}, {cols, 0}, {0, rows}, {cols, rows}},
            .rotate = R,
            .scale = S,
    };return img;
}

void readPNG(char *file){
    char filepath[256];
    snprintf(filepath,sizeof(filepath),"%s/%s",FOLDER_PATH,file);
    FILE *fp = fopen(filepath, "rb");
    if (!fp) abort();
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png){
        fclose(fp);
        abort();
    } png_infop info = png_create_info_struct(png);
    if (!info){
        fclose(fp);
        png_destroy_read_struct(&png,NULL,NULL);
        abort();
    } if (setjmp(png_jmpbuf(png))){
        fclose(fp);
        png_destroy_read_struct(&png,&info,NULL);
        abort();
    } png_init_io(png, fp);
    png_read_info(png, info);
    cols = (int)png_get_image_width(png, info);
    rows = (int)png_get_image_height(png, info);
    fclose(fp);
    png_destroy_read_struct(&png,&info,NULL);
}

void scaleAndRotate(Image * img){
    double cosTheta = cos(img->rotate), sinTheta = sin(img->rotate);
    int cX = cols>>1;
    int cY = rows>>1;
    for(int i = 0; i<4; ++i){
        int x = img->points[i][0] - cX, y = img->points[i][1] - cY;
        img->points[i][0] = (int)(x*cosTheta - y*sinTheta) + cX;
        img->points[i][1] = (int)(x*sinTheta + y*cosTheta) + cY;
    }
    for(int i = 0; i<4; i++){
        img->points[i][0] *= img->scale;
        img->points[i][1] *= img->scale;
    }
}

void print_num(int num){
    char chain[20];
    sprintf(chain,"%d",num);
    fprintf(archivo,"%s\n",chain);
}

void print_float(double num){
    char chain[20];
    sprintf(chain,"%.5f",num);
    fprintf(archivo,"%s\n",chain);
}

void print_in_txt(Image* img){
    print_num(rows);
    print_num(cols);
    for(int i=0;i<8;i++){
        print_num(img->points[(int)(i/2)][i%2]);
    } print_float(img->rotate);
    print_float(img->scale);
    fprintf(archivo,"%s","\n");
}

void process_images_in_folder() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(FOLDER_PATH)) != NULL) {
        srand((unsigned)time(NULL));
        double R,S;
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".png") != NULL) {
                readPNG(ent->d_name);
                R = ((double)rand() / RAND_MAX) * 2.0 * pi;  //[0,2pi]
                S = sqrt(((double)rand() / RAND_MAX) * 2.0); //[0,sqrt(2)]
                Image img = newImage(R,S);
                scaleAndRotate(&img);
                print_in_txt(&img);
            }
        } closedir(dir);
    } else abort();
}

int main(){
    archivo=fopen("puntos.txt","w");
    if(archivo==NULL) abort();
    process_images_in_folder();
    fclose(archivo);
    return 0;
}
