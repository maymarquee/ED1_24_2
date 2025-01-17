// FILA
// p = inicio da fila
// u = fim da FILA
// N = tamanho definido para o vetor

// fila[p...u-1]   7 posições
// o fim da fila sempre é vazio -> é aonde será inseridos elementos (posição precisa estar vazia)

//       p                    u
//   0    1   2    3     4    5    6    7    8      9
// ---------------------------------------------------
// |   |  11 | 22 | 55 | 99 |    |    |  1  |  5  |     |
// ---------------------------------------------------
//                                       p     u

// fila vazia = p == u
// cheia se u == N

#include <stdio.h>

#define N 7
int fila[N]; // pode armazenar até N elementos
int p, u;

void criar_fila(){
    p = u = 0; //define o incício e o fim da fila no índice 0
}

int vazia(){ //verifica se a fila está vazia
    return p == u; // retorna 1 se a fila está vazia e 0 se não estiver
}

//remoção no incício -> desenfileirar
//início da fila p é deslocado para mais próximo do fim -> "removendo" elemento da fila
int _desenfileira(){
    return fila[p++]; //uso do p++ -> primeiro retorna o valor atual de p para depois incrementá-lo
}

//inserção no fim da fila -> enfileirar
//elemento é colocado na posição indicada por u
//fim da fila é deslocado
void _enfileira(int y){ // y = elemento a ser enfileirado
    fila[u++] = y; // primeiro, o valor de u é usado para depois ser incrementado 
    // o elemento y será armazenado na posição atual de u para depois u ser incrementado para a próxima posição
} // se inserir elemento em uma lista cheia -> ocorre transbordamento (overflow)
// fila[u] = 4;
// fila[7] = 4; // como 7 > N-1, ocorre transbordamento

//fila cheia 
// u == N

// se a fila estiver cheia, mas com espaços livres -> chegou ao fim, volta para o primeiro (circular)
// lista estática circular
void enfileira (int y){
    fila[u++] = y;
    if (u == N) u = 0; // se u atingir o final da fila, volta para o início
}

int desenfileira(){
    int x = fila[p++]; //remove e incrementa
    if (p == N) p = 0; // se p atingir o limite da array, volta para o início
    // se p for igual a N, significa que a lista foi percorrida completamente
    return x; //retorna elemento removido
}

// decisão: posição anterior a p fica vazio
// fila cheia: u+1 == p ou (u+1==N e p==0)
// ou seja, se (u+1) % N == p 
// (0 + 1) % 7 = 1


int main(){
   

    return 0;
}