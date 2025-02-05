#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct {
    Item *pq;
    int N;
}PQueue;

#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t=A; A=B, B=t;}
#define MAX 100

static Item *pq;
static int N;
int v[MAX];

void PQinit(int maxN){
    pq = malloc(sizeof(Item)*(maxN + 1));
    N = 0;
}

int PQempty(){
    return N == 0;
}

// COMPLEXIDADE: 1 + logN comparações -> O(logN)
void fixUp(int k){
    // se não for raiz e maior que pai
    //vai reduzindo metade por iteração
    while(k>1 && less(pq[k/2], pq[k])){
        //troque
        exch(pq[k], pq[k/2]);
        //subir: atualizar k
        k = k/2;
    }
}

// é fila, logo, insere no fim!!!
void PQinsert(Item v){
    pq[++N] = v;

    //consertar elemento na posição N
    fixUp(N);

}


// COMPLEXIDADE: 2logN comparações -> O(LogN) -> no pior caso, é a altura da heap
void fixDown(int k, int N){ //afunda k, k é indice do nó que quer aplicar fixDown
    //enquanto tiver filho (logo, só opera fixDown até chegar no nó folha)
    // dobra a cada iteração
    while (2*k <= N){
        int j = 2*k; //filho da esquerda, pq direita é filho 2*K + 1

        // se tiver filho da direita e for maior? se o j for menor que N, quer dizer que existe filho a direita
        if(j<N && less(pq[j], pq[j+1])) j++; //  CONSTANTE -> 0(1)
        // agora j aponta para o filho da direita, logo pq[k] sempre é o maior filho

        //pq[k] maior que o maior filho?
        if(!less(pq[k], pq[j])) break; // CONSTANTE -> O(1)
        //se pq[k] for maior que pq[j], a propriedade do heap já está garantida

        //se não, afunde -> trocar com o filho
        exch(pq[k], pq[j]); //troca pq[k] com seu maior filho

        //atualiza k para o maior filho
        k = j; //atualiza k para continuar descendo

    }
}

Item PQdelmax(){
    //troca o topo pelo último
    exch(pq[1], pq[N]);
    //reposicionar
    fixDown(1, N-1); //começa o fixDown a partir do anterior ao que será removido
    //retorne removido
    return pq[N--]; //retorna o elemento e decrementa o tamanho da fila
}

void PQchange(int k, int valor){
    if (v[k] < valor){ //verifica se o novo valor é maior que o atual
        v[k] = valor; //se sim, pode subir na árvore, atualiza v[k] com o novo valor
        fixUp(k); //chama para reposicionar
    } else{ //se ele for menor ou igual, ele pode descer 
        v[k] = valor;
        fixDown(k, N);
    }
}

// para várias filas
// PQueue *PQinit(int);
// int PQempty(PQueue*);
// void PQinsert(PQueue*, Item);
// Item PQdelmax(PQueue*);

// void fixUp(PQueue*, int);
// void fixDown(PQueue*, int);

// int main(){
//     return 0;
// }