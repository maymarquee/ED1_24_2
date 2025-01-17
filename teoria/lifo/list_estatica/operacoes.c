#include <stdio.h>
#include <stdlib.h>


int *pilha; //ponteiro para um vetor de inteiros (a pilha)
int t; // inteiro para o índice do topo da pilha

// CRIAÇÃO DA PILHA
void criar(int N){ // N é numero maximo de elementos que a pilha pode ter
    pilha = malloc( N * sizeof(int));
    t = 0; // pilha está vazia
}

// EMPILHAMENTO -> elemento é colocado na posição indicada por t (está vazia)
//                 topo da pilha é deslocado
// pilha[0..t-1] 
void empilha(int y){ // recebe elemento a ser empilhado
    pilha[t++] = y;
}

// DESEMPILHAR -> topo da pilha é deslocado para mais próximo do início
//                não apaga da memória
// item indicado pela nova posição do topo é ignorado

int desempilha(){
    return pilha[--t]; // elemento que quer retirar está 1 posição atrás do topo (espaço vazio)
}

int espia(){
    return pilha[t-1]; //elemento válido está 1 posição atrás do topo
}

int vazia(){
    return t == 0; // retorna 1 se verdadeiro e 0 para falso (t!=0)
}

typedef char Item;
typedef struct{
    Item *item; //vetor de itens
    int topo; //variavel auxiliar
}Pilha;

Pilha *_criar(int maxN){
    Pilha *p = malloc(sizeof(Pilha)); //aloca espaço para armazenar Pilha; o ponteiro aponta para a memória alocada
    p->item = malloc(maxN*sizeof(Item)); // o p->item armazena um ponteiro para os itens da pilha; aloca espaço para um vetor, em que cada item tem tamanho do tipo Item
    p->topo = 0; //início do topo
    return p; //retorna um ponteiro para Pilha
}

int _vazia(Pilha *p){ //recebe a pilha para manipulação
    return p->topo == 0;
}

void empilhar(Pilha *p, Item item){
    p->item[p->topo++] = item;
}

Item desempilhar(Pilha *p){
    return p->item[--p->topo];
}

Item espiar(Pilha *p){
    return p->item[p->topo-1];
}

int main(){

    return 0;
}