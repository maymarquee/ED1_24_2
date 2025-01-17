// inserções e remoções no topo da pilha
// complexidade CONSTANTE
// TOPO é o primeiro elemento da pilha -> quando possui um ponteiro para o início da lista
// não é possivel ter complexidade constante em qualquer lista encadeada, ex: topo ser o último elemento da lista(inserção e remoção precisam percorrer a lista toda)
// complexidade constante é viável para lista simplesmente encadeada com ponteiro para a cauda

#include <stdio.h>
#include <stdlib.h>

typedef int Item; //dados interos armazenados na pilha
typedef struct node{
    Item info;
    struct node *prox;
} node;

typedef struct{
    node *prox; //aponta para 1 elemento
    node *ultimo; //aponta para ultimo elemento
    int num_item; //conta elementos na pilha
} head;

node *criar_no(Item x){
    node *novo = (node*)malloc(sizeof(node));
    if (novo){
        novo->info = x;
        novo->prox = NULL;
    }
    return novo;
}

int vazia(head *lista){
    return lista->prox == NULL;
}


void empilha(head *lista, Item x){
    node *novo = criar_no(x);
    if (novo){
        if (vazia(lista)) lista->ultimo = novo;

        novo->prox = lista->prox; //inserindo na cabeça, adciona um novo nó
        lista->prox = novo; //adciona elemento à lista

        lista->num_item++;
    }
}

Item desempilha(head *lista){
    node *topo = lista->prox; //primeiro elemento será desempilhado
    lista->prox = topo->prox;

    if (topo == lista->ultimo) lista->ultimo = NULL;
    lista->num_item--;

    Item x = topo->info; //atualiza o proximo
    free(topo); //libera o espaço
    return x; //devolve valor desempilhado
}

Item espia(head *p){
    return (p->prox->info);
}

int main(){

    return 0;
}