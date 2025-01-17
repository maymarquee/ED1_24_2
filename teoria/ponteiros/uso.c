#include <stdio.h>

int main(){

    int i = 1234;
    int *p;
    p = &i; //p aponta para i OU p referencia a variável i

    printf("%d\n", i); //printa o conteúdo de i (1234)
    printf("%p\n", p); //printa o endereço de i
    printf("%d\n", *p); //printa o conteúdo de i

    // se escrever *p no printf, irá printar o CONTEUDO da variável apontada por p
    // isso é chamado de desreferenciar a variavel

    printf("%ld\n", sizeof(p)); //printa tamanho de p na memória (4 bytes)
    //a função sizeof retorna o tamanho em bytes da variável ou do tipo de dado

    int v[2] = {3, 7};
    printf("%d %d\n", *(v+0), *(v+1)); // printa o primeiro elemento do vetor e o segundo (3 e 7)

    int **r;
    r = &p;
    printf("%d\n", **r); //printa o conteúdo de i

    //a troca de valores só pode ser feita com PONTEIROS
    void troca(int *p_, int *q) { // ponteiros recebem endereços
    int t;
    t = *p_; //conteudo do apontado por p
    *p_ = *q; //conteudo do apontado por q
    *q = t; //conteudo de t
    }

    int a = 3 , b = 9;

    troca(&a , &b); // passando os endereços

    printf("%d %d\n",a , b);

    return 0;
}