#include "libs.h"


//return all the bitmasks with size "n" and "k" ones



void getSubSets(int set, int at, int n, int k, int *rslt, int *rsltSize) {

    if(!k){

        rslt[*rsltSize] = set;
        (*rsltSize)++;
        return;

    }for (int i = at; i < n; i++) getSubSets(SET(set, i), i + 1, n, k - 1, rslt, rsltSize);
    
}



int * combinations(int n, int k, int *rsltSize){

    *rsltSize = 0;
    int *rslt = (int *)malloc(sizeof(int) * (1 << n));
    getSubSets(0, 0, n, k, rslt, rsltSize);
    return rslt;

}



int main() {

    int rsltSize;
    int * result = combinations(21, 19, &rsltSize);
    for (int i = 0; i < rsltSize; i++) printf("%b\n", result[i]);
    return 0;

}
