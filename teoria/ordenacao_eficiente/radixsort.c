#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;
#define maxstring 101
#define bytesword 4
#define bitsbyte 8 
#define R (1 << bitsbyte)
#define N 1000 
#define digit(N,D) (((N) >> ((D)*bitsbyte)) & (R-1))
// char a[N][maxstring]; 
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)


void radix_sortLSD(int *v, int l, int r){
    int i, w, k;
    int aux[r - l + 1];  
    int count[R+1]; //257!!

    //byte w
    for(w=0; w<bytesword; w++){
        //for(i = 0; i<=R; i++) count[i] = 0;
        memset(count, 0, sizeof(int)*(R+1));

        //frequências
        for(i=l; i<=r; i++) count[digit(v[i], w)+1]++;

        //posição de k
        for(k=1; k<R; k++) count[k] += count[k-1];

        //distribuição
        for(i=l; i<=r; i++) aux[count[digit(v[i], w)]++] = v[i];

        for(i=l;i<=r; i++) v[i] = aux[i-l];
    }

}

//ordenação de Strings
void radixMSD(char a[][maxstring], int l,int r, int d){

    if(r<=l) return;

    char aux[r-l+1][maxstring];
    int count[R+1];
    memset(count, 0, sizeof(int)*(R+1));

    //frequências
    for(int i=l; i<=r; i++) count[a[i][d] +1]++;

    //posições
    for(int i=1; i<R; i++) count[i] += count[i-1];

    //distribuição e cópia
    for(int i=l; i<=r; i++) strcpy(aux[count[a[i][d]]++], a[i]);
    for(int i=l; i<=r; i++) strcpy(a[i], aux[i-l]);

    //subconjuntos
    for(int i = 1; i < R; i++){
        radixMSD(a, l + count[i=1], l + count[i]-1, d+1);
    }
}

int main(){
    return 0;
}