#include <stdio.h>
#include <math.h>
#include "heapsort.c"
#include "quicksort.c"
#include "../elementar/insertionsort.c"

#define compexch(A,B) if ((A) > (B)) {Item t=A; A=B, B=t;}

void heap_sort(Item *v, int l, int r);

void intro(int *v, int l, int r, int maxdepth){
    if( r - l <= 15){
        // insertion_sort(v, l, r)
        return;
    } else if(maxdepth == 0){
        //merge_sort(v, l, r);
        heap_sort( v, l, r);
    } else{
        compexch(v[l], v[(l + r)/2]);
        compexch(v[l], v[r]);
        compexch(v[r], v[(l + r)/2]);

        int p = partition(v, l, r);
        intro(v, l, p-1, maxdepth-1);
        intro(v, p+1, r, maxdepth-1);
    }
}

void intro_sort(int *v, int l, int r){
    // maxdepth proprorcional à altura de uma árvore balanceada
    int maxdepth = 2*((int)log2((double)(r - l +1)));

    intro(v, l, r, maxdepth);
    insertion_sort(v, l, r);
}

int main(){
    return 0;
}