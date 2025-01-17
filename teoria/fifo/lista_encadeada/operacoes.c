//LISTA ENCADEADA -> cada elemento da lista é armazenado em um nó que contem um valor e um ponteiro para o próximo nó.
// o primeiro nó é chamado de cabeça, e o último aponta para NULL
// lista simplesmente encadeada com cauda -> lista simplesmente encadeada possui um ponteiro adicional que aponta para o último nó da lista -> a cauda

// o acesso ao primeiro elemento é constante
// acesso ao ÚLTIMO elemento -> em simplesmente/duplamente encadeada com cabeça -> metadados -> lista -> ultimo
//                           -> em duplamente encadeada circular ->  no *ultimo = lista->prox->ant (anterior do primeiro)
//                           -> simplesmente encadeada circular modificada -> último elemento aponta para cabeça, inserir na cabeça, criar uma nova cabeça que aponta para a velha cabeça aponta, velha cabeça/novo elemento aponta para o que?
//                           -> simplesmente encadeada com cauda -> utiliza um apontador direto para a cauda

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct No{
    Item dado;
    struct No *prox;
} No;

typedef struct Cabeca{
    No *prox; // ponteiro pro 1º nó
    No *ultimo; //ponteiro para último nó
    int tam; //tamanho da lista
} Cabeca;

No* criar_no(Item x){
    No *novo = (No *)malloc(sizeof(No));
    if (novo){
        novo->dado = x;
        novo->prox = NULL;
    }
    return novo;
}

int vazia(Cabeca *lista){
    return lista->prox == NULL;
}


void enfileira(Cabeca *lista, Item x){
    No *novo = criar_no(x);
    if (novo){
        if (vazia(lista)) lista->prox = novo;
        else lista->ultimo->prox = novo;

        lista->ultimo = novo;
        novo->prox = NULL;

        lista->tam++;
    }
}

int main(){

    return 0;
}