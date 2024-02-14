#include "libs.h"

//El código verifica que cada carta solo tenga una figura en común, sino imprime un par que da problemas. 
//(es ineficiente pero es para probar que las cartas estén bien y ya)

void test(int** cards, int rows, int col){ //rows = cantidad de cartas y col = figuras por carta
    for(int i=0;i<rows-1;i++){
        for(int j=i+1;j<rows;j++){
            int matches=0;
            for(int k=0;k<col;k++){
                for(int z=0;z<col;z++){
                    if(cards[i][k]==cards[j][z]) matches++;
                }
            } if(matches>1 || matches==0){ //en caso de que haya errores
                printf("Hay mas de una figura en comun en la carta %d con la carta %d\n",i,j); //imprima esas cartas para comprobar
                return;
            }
        }
    } printf("sirve\n");
}

int main(){

    return 0;
}
