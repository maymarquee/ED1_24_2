#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x){
    
    if ((f->u + 1) % f->N == f->p){ //verifica se fila está cheia
        int novoTam = f->N*2; //aumenta para o dobro
        int *novoDados = realloc(f->dados, novoTam*sizeof(int)); //realoca
        if (!novoDados) return 0; //realloc não foi possível

        // copia elementos antigos para o novo vetor
        int j=0;
        for (int i = f->p; i != f->u; i = (i + 1) % f->N){
            novoDados[j++] = f->dados[i];
        }

        free(f->dados); //libera o passado
        f->dados = novoDados;
        f->p = 0;
        f->u = j;
        f->N = novoTam;
    }

    f->dados[f->u++] = x;
    if (f->u == f->N) f->u = 0;
    return 1;
}

// int main(){
//     return 0;
// }
