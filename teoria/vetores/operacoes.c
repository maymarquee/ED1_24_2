#include <stdio.h>

/* 
Estrutura for em C:
    for(valor_inicial; condição_final; valor_incremento)
    {
            intruções
    }
*/

int remove_v(int aux, int vetor[], int tam) //função que recebe uma variavel auxiliar, um vetor e uma variavel com o tamanho do vetor
    { //a variavel auxiliar é igual a 0, para começar percorrendo as posições no vetor

        int x = vetor[aux], aux_1; //define duas variaveis, uma que é a posição do elemento a ser removido do vetor e outra auxiliar_1

        for (aux_1 = aux+1; aux_1 < tam; ++aux_1) //aux_1 vai incrementando, tem que ser menor que o tamanho do vetor e aumenta a cada rodada de loop
            vetor[aux_1-1] = vetor[aux_1]; //move cada elemento para uma posição antes

        
        printf("%d", x);
        return x; //retorna o valor do elemento antes de ser removido
        //não altera o tamanho da lista
    }


int insere_v(int x, int k, int v[], int n) // essa função insere x na posição k do vetor v, de tamanho n
{ // condição: vetor não pode estar cheio

    for (int j = n - 1; j > k; --j) //vai puxando
        v[j] = v[j - 1];

    v[k] = x;
}

int main() {
    //busca

    // int achou = 0, k = 0; //variaveis auxiliares
    // while (k < n && achou == 0) { //continua o loop ate o k for menor que n e não tiver achado o valor
    //     if (v[k] == x) achou = 1;  //acessa o valor do elemento que está naquela posição, se for igual a x, muda o valor de achou pra 1
    //     else k++; //continua a procurar pelo vetor até o tamanho inteiro dele
    // }

    // int x = 30; //valor que quer achar no vetor
    int n = 3; //tamanho do vetor
    int v[n]; //v é o vetor

    int k = 0; //variavel auxiliar
    // while (k < n && v[k] != x) k++; //  verifica se a variável auxiliar percorreu o vetor inteiro e também se achou o item que está procurando na array, se é diferente, continua o loop

    //um sentinela é um elemento sinalizador, usado para mostrar o fim de um vetor
    //ex: /

    int v_[6] = {1, 3, 2, 5, 6}; //o vetor foi inicializado com um elemento a menos
    int k_ = 0, x_ = 2;

    v_[5] = x_; //foi adcionado na última posição do vetor um sentinela de valor 2
    while (v_[k_] != x_) k_++;

    int remove = remove_v(2, v, n);

    return 0;
}