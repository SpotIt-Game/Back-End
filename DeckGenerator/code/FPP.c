#include "libs.h"


#define card bitset
#define deck bitset*





int n, order, id_deck, id_card;
deck mat;







void print(){

    printf("%d\n" ,id_deck);
    printf("%d\n", order);
    for(int i = 0; i<n; i++){
        printf("%d\n", id_card++);
        for(int j = 0; j<n; j++) if(test(&mat[i], j)) printf("%d ", (id_deck > 5)*73 + j+1);
        printf("\n");
    }

}




// Creates a finite projective plane using cyclic difference sets
void createFPP(){

    int * pts = copy(CDS[order-4], order);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<order; j++)
            for(int k = 0; k<order; k++)
                if(pts[j] != CDS[order-4][k]) 
                    set(&mat[pts[j]], i);

        for(int j = 0; j<order; j++) pts[j] = (pts[j]+1)%n;
    }

}





int main(){

    printf("Insert the order of the plane: ");
    scanf("%d", &order);
    printf("Insert the id of the deck: ");
    scanf("%d", &id_deck);
    printf("Insert the id of the first card: ");
    scanf("%d", &id_card);

    n = order*(order-1) + 1;
    mat = (deck)malloc(n*sizeof(card));
    for(int i = 0; i<n; i++) mat[i] = init(n);
    createFPP();

    print();
    return 0;

}
