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
#define FLIP(mks, i) ((msk)^(1<<(i)))







int factorial(int n){
    if(!n) return 1;
    return n * factorial(n-1);
}



int binomialCoefficient(int n, int k){
    return factorial(n)/(factorial(n-k)*factorial(k));
}




int Pow(int b, int e){
    if(!e) return 1;
    if(e&1) return b*pow(b*b, e>>1);
    return pow(b*b, e>>1);
}







#endif 

