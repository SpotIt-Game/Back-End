#include "libs.h"

//solución 1 (primera forma de hacerlo)

int f(int n){
    return n*n+n+1;
}

void print(int** matrix, int rows, int cols){
    for(int i=0;i<rows;i++){
        printf("Carta %d: ",i+1);
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        } printf("\n");
    }
}

int main(){
    int order,i,j,k;          //resuelve solamente planos proyectivos finitos de orden de un número primo
    scanf("%d",&order);      //pasé el code de java script a C, así que si falla me avisan (Joshua)
    int rows=f(order);
    int cantSymbols=order+1;
    int** cards;
    cards=(int*)malloc(rows*sizeof(int));
    for(i=0;i<rows;i++) cards[i]=(int*)malloc((order+1)*sizeof(int));
    for(i=0;i<cantSymbols;i++) cards[0][i]=i+1;
    for(i=1;i<=order;i++){
        cards[i][0]=1;
        for(j=1;j<=order;j++){
            cards[i][j]=order*i+(j+1);
        }
    } int temp=order+1;
    for(i=1;i<=order;i++){
        for(j=1;j<=order;j++){
            cards[temp][0]=i+1;
            for(k=1;k<=order;k++){
                cards[temp][k]=order+2+order*(k-1)+(((i-1)*(k-1)+j-1)%order);
            } temp++;
        }
    } print(cards,rows,order+1);
    for(i=0;i<rows;i++) free(cards[i]);
    free(cards);
    return 0;
}
