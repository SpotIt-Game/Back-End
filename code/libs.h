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
#define size(arr) (sizeof((arr))/sizeof((arr[0])))
#define new(msk, i) {0, init}; msk.init(&msk, i);
#define bitset struct bitset


















//bitset a = new(a, 64);   creates new bitset of size 64(bits)
bitset{

    int * arr;
    void(*init)(bitset*, int);
    
};

void init(bitset *msk, int size){
    msk->arr = (int*)calloc((size/32)+1, sizeof(int));
}  



//set(&a, 12);   sets the 12'th bit of "a" to 1
void set(bitset *msk, int i){
    msk->arr[i/32] = SET(msk->arr[i/32], i%32);
}




// test(&a, 13);    returns 0, if the 13'th bit of "a" is 0
int test(bitset *msk, int i){
    return TEST(msk->arr[i/32], i%32);
}


// count(&a);     returns the number of 1s in a
int count(bitset *msk){

    int c = 0;
    for(int i = 0; i<=size(msk->arr); i++){
        int k = msk->arr[i];
        while(k){
            c++;
            k -= k&-k;
        }

    }return c;

}




//bitset uni = Union(&a, &b);   creates bitset "uni", which is the union between "a" and "b"
bitset Union(bitset *a, bitset *b){

    int size = size(a->arr);
    bitset uni = new(uni, size);
    for(int i = 0; i<=size; i++)
        uni.arr[i] = a->arr[i]|b->arr[i];
    return uni;

}



// bitset inter = Intersection(&a, &b)  creates bitset "inter" which is the intersection between "a" and "b"
bitset Intersection(bitset *a, bitset *b){

    int size = size(a->arr);
    bitset inter = new(inter, size);
    for(int i = 0; i<=size; i++)
        inter.arr[i] = a->arr[i]&b->arr[i];
    return inter;

}









#endif 

