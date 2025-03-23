#include <stdio.h>

#define MAX 10000
#define R 5

typedef struct{ int chave; char nome[20]; }Item;
Item aux[MAX];


void countingsort(Item *v, int l, int r){
    int i, count[R+1];
    
    for(i = 0; i <= R; i++) count[i] = 0;
    for(i = l; i<=r; i++) count[v[i].chave + 1]++;
    for(i = 1; i <= R; i++) count[i] += count[i-1];

    //distribuição dos itens
    for(i = l; i <- r; i++){
        aux[count[v[i].chave]++] = v[i];
    }

    for(i = l; i <= r; i++) v[i] = aux[i-l];
}

// int aux[MAX];
// void countingsort(int *v, int l, int r){
//     int i, count[R+1];

//     //zerando
//     for(i = 0; i <= R; i++) count[i] = 0;

//     //calcular frequencias
//     for(i = l; i < = r; i++) count[v[i] + 1]++;

//     //posições
//     for(i = 1; i <= R; i++) count[i] += count[i-1];

//     //distribuições
//     for(i = l; i <= r; i++) aux[count[v[i]]++] = v[i];

//     //cópia a partir de aux[0] 
//     for(i = l; i <= r; i++) v[i] = aux[i-l];
// }

int main(){
    return 0;
}