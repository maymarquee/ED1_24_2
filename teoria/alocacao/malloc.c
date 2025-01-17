#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p = malloc(sizeof(int));
    char *name = malloc(sizeof(char)*50); //string com 50 posições
    float *f = malloc(sizeof(float)*10); // vetor float com 10 posições

    struct endereco {
        char rua[100];
        int numero;
    };

    struct endereco *end;
    end = malloc(sizeof(struct endereco));

    if (end){
        end -> numero = 324;
    }

    return 0;
}