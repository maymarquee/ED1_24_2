#include <stdio.h>
#include "../heap_binaria/operacoes.c"

//HEAP MÁXIMO
//COMPLEXIDADE NlogN -> cada inserção custa logn, e cada remoção, logn, logo custo total é nlogn
void PQsort(Item *v, int l, int r){
    PQinit(r - l + 1); //inicializa a fila de prioridade somando 1, pq ela começa em 1!!
    for(int k=l; k<=r; k++){
        PQinsert(v[k]); //insere todos os elementos  da array v[] na fila de prioridades (HEAP)
    }
    for(int k=r; k>=l; k--){
        v[k] = PQdelmax(); //remove o maior elemento da heap e armazena no vetor
    } //ordenado de forma crescente
}

//versão in-place
// v é o vetor que vamos ordenar, l é o indice inial, r é o indice final
void heap_sort(Item *v, int l, int r){
    pq = v + l - 1; // heap contruida em v; uma posição anterior a v[l], se l=0, pq[1] = v[0]

    N = r - l + 1; // numero total de elementos na heap

    for(int k=N/2; k>=1; k--){ //começa do meio do vetor e vai até o início
        fixDown(k, N); //garante que a propriedade da heap seja mantida
    }

    while(N>1){ //move o maior elemento da fila para a última posição e reduz o tamanho da heap
        exch(pq[1],pq[N]);
        fixDown(1, --N); // chama a função fixDown para manter propriedade da heap
    }
}

// int main(){
//     return 0;
// }