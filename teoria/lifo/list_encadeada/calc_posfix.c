// exemplo de entrada: 5 9 8 + 4 6 * * 7 + *
// saida: 2075

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *prox;
} node;

typedef struct head{
    node *topo;
} head;

head *criar_lista(){
    head *pilha = malloc(sizeof(head));
    pilha->topo = NULL;
    return pilha;
}

void empilha(head *pilha, int x){
    node *novo = malloc(sizeof(node));
    novo->item = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilha(head *pilha){
    node *topo = pilha->topo;
    int valor = topo->item;
    pilha->topo = topo->prox;
    free(topo);
    return valor;
}

int main(int arg, char *argv[]){
    char *a = argv[1];

    head *pilha = criar_lista();

    for(int i=0; a[i]!='\0'; i++){
        if (a[i] == '+')
            empilha(pilha, desempilha(pilha)+desempilha(pilha));
        if (a[i] == '*')
            empilha(pilha, desempilha(pilha)*desempilha(pilha));

       if ((a[i] >= 0) && (a[i] <= '9'))  empilha(pilha, 0);

       while((a[i] >= '0') && (a[i] <= '9'))
       empilha(pilha, 10*desempilha(pilha) + (a[i++]-'0'));
    }
    printf("%d \n", desempilha(pilha));
}