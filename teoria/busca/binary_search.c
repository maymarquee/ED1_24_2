#include <stdio.h>

typedef int Key;

int binary_search(Key *keys, int l, int r, Key k){
    if (l>r) return -1; //condição de parada
    
    int media = (l+r)/2; 

    if (k == keys[media]) return media;

    if (l == r) return -1;

    if (k < keys[media]){
        return binary_search(keys, l, media-1, k); //diminui o intevalo superior
    }
    
    return binary_search(keys, media+1, r, k); //aumenta o intervalo inferior
}


int main(){
    Key keys[] = {2, 3, 4, 10, 16, 18, 40, 54};
    int n = sizeof(keys)/sizeof(keys[0]);
    Key k = 10;

    int indice = binary_search(keys, 0, n-1, k);
    if (indice != -1){
        printf("Indice: %d", indice);
    }else{
        printf("Número não encontrado na lista.\n");
    }

    return 0;
}