#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

celula *enfileira (celula *f, int x){
    celula *novo = (celula *)malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = NULL;
    if (f==NULL){
        return novo;
    } else{
        celula *atual = f;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return f;
}
