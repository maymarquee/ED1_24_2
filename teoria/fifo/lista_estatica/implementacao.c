#include <stdio.h>
#include <stdlib.h>

typedef int Item; //define um item genérico do tipo inteiro
typedef struct {
    Item *item; // item é ponteiro para a array que armazena os elementos da lista
    int primeiro, ultimo; // indices dos primeiros e ultimos elementods da fila
}Fila;

int i, N, p, u;
int *fila;

Fila *criar (int maxN){ 
    Fila *p = malloc(sizeof(Fila)); //aloca memória para uma nova fila
    p->item = malloc(maxN*sizeof(Item)); // aloca memória para uma array item com tamanho maxN
    p->primeiro = p->ultimo = 0; //inicia indices primeiro e último
    return p; //retorna ponteiro para a nova fila
}

int vazia(Fila *f){
    return f->primeiro == f->ultimo;
}

int desenfileira(Fila *f){
    return f->item[f->primeiro++];
}

void enfileira(Fila *f, int y){ //está recebendo um ponteiro que aponta para uma região da memória onde Fila foi alocada
    f->item[f->ultimo++] = y;
}

void imprime(Fila *f){
    printf("\nFILA p=%d e u=%d\n", f->primeiro, f->ultimo);
    for( i=f->primeiro; i<f->ultimo; i++)
        printf(" F[%d] |", i);
    printf("\n");

    for(int i=f->primeiro; i<f->ultimo; i++)
        printf(" %3d  |", f -> item[i]);
    printf("\n");
}

void redimensiona(void){
    N *= 2; //evita novos redimensionamentos
    fila = realloc(fila, N * sizeof(int));
}

//reajusta variaveis p e u
void _redimensiona(){
    N *= 2;
    int *novo = malloc(N * sizeof(int));

    int j=0;
    for (int i = p; i < u; i++, j++)
        novo[j] = fila[i];

    p = 0;
    u = j;

    free(fila);
    fila = novo;
}

int main(){

    printf("\n\nCriando a fila e enfileirando 10 elementos\n");
    Fila *fila1 = criar(100);
    for (int i=0; i<10; i++) 
        enfileira(fila1, i);
    imprime(fila1);

    printf("\n\nDesenfileirando os 3 primeiros elementos\n");
    for(int i =fila1->primeiro; i<3; i++) 
        desenfileira(fila1);
    imprime(fila1);

    return 0;
}