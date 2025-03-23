#include <stdio.h>

void insertion_sort(int v[], int l, int r){
    int elem, i, j;
    //percorre array a partir do segundo elemento
    for(i=l+1; i<=r; i++){
        elem = v[i]; //elemento que será (re)inserido

        //para cada elemento maior
        for(j=i; j>l && elem < v[j-1]; j--){
            v[j] = v[j-1]; //puxa o maior
        }
        //insere no elemento a posição
        v[j] = elem;
    }
}

// int main(){
//     return 0;
// }