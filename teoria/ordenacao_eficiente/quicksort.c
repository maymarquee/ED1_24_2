#include <stdio.h>

int partition(int *v, int l, int r){
    //pivô
    int pivot = v[r]; //pivô a direita
    // procura a direita e à esquerda, atualiza e verifica um aposição válida no fim da iteração, pois i e j não podem ultrapassar os limites, pq vão ser usadas nos swaps
    int i = l-1;
    int j = r;

    //enquanto caminhos não se cruzam
    while(i<j){
        //procura elementos maiores
        while(v[++i] < pivot);

        //procura elementos menores
        while(v[--j] > pivot && j>l); // para quando chega em um elemento da esquerda

        //se o maior estiver atrás do menor
        if(i<j) exch(v[i], v[j]); //faz swap
    }

    exch(v[i], v[r]); //nova posição do pivô

    return i; //nova posição do pivô
}

void quick_sort(int *v, int l, int r){ // recebe vetor a ser odenada e os índices direito e esquerdo
    //condição de parada
    if(r<=l) return; // se a subarray a ser ordenado tem 0 ou um elemento

    //posicionando o pivô
    int p = partition(v, l, r);

    //ordena subvetores
    quick_sort(v, l, p-1); //menores
    quick_sort(v, p+1, r); //maiores

}

// int main(){
//     return 0;
// }