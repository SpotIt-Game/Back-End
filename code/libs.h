#ifndef LIBS_H
#define LIBS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>





#define SET(msk, i) ((msk)|(1<<(i)))
#define TEST(msk, i) ((msk)&(1<<(i)))
#define CLEAR(msk, i) ((msk)&~(1<<(i)))
#define FLIP(msk, i) ((msk)^(1<<(i)))
#define size(arr) (int)(sizeof((arr))/sizeof((arr[0])))
#define bitset struct bitset





int CDS[][9] = {
    {0, 1, 3, 9},                    //order -> 3
    {0, 1, 6, 8, 18},                //order -> 4
    {0, 1, 3, 10, 14, 26},           //order -> 5
    {},                              //order -> 6 (no solution)
    {0, 1, 3, 13, 32, 36, 43, 52},   //order -> 7
    {0, 1, 3, 7, 15, 31, 36, 54, 63} //order -> 8
};








    













//bitset a = init(64);   creates init bitset of size 64(bits)
bitset{
    int * arr, size;
};


bitset init(int size){
    bitset c = {0, size};
    c.arr = (int*)calloc((size/32)+1, sizeof(int));
    return c;
}  



//set(&a, 12);   sets the 12'th bit of "a" to 1
void set(bitset *msk, int i){
    msk->arr[i/32] = SET(msk->arr[i/32], i%32);
}



void clear(bitset *msk, int i){
    msk->arr[i/32] = CLEAR(msk->arr[i/32], i%32);
}




// test(&a, 13);    returns 0, if the 13'th bit of "a" is 0
bool test(bitset *msk, int i){
    return TEST(msk->arr[i/32], i%32);
}



// count(&a);   returns the number of 1s in a
int count(bitset *msk){

    int c = 0;
    for(int i = 0; i<=msk->size; i++){
        int k = msk->arr[i];
        while(k){
            c++;
            k -= k&-k;
        }

    }return c;

}




//bitset uni = Union(&a, &b);   creates bitset "uni", which is the union between "a" and "b"
bitset Union(bitset *a, bitset *b){

    int size = a->size;
    bitset uni = init(size);
    for(int i = 0; i<=size; i++)
        uni.arr[i] = a->arr[i]|b->arr[i];
    return uni;

}



// bitset inter = Intersection(&a, &b)  creates bitset "inter" which is the intersection between "a" and "b"
bitset Intersection(bitset *a, bitset *b){

    int size = a->size;
    bitset inter = init(size);
    for(int i = 0; i<=size; i++)
        inter.arr[i] = a->arr[i]&b->arr[i];
    return inter;

}

















int * copy(int arr[], int size){

    int * c = (int*)malloc(size*sizeof(int));
    for(int i = 0; i<size; i++) c[i] = arr[i];
    return c;

}

















#endif 

