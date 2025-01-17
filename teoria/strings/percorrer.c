#include <stdio.h>

// a função compara duas strings (s1 e s2) caracter por caracter 
int string ( char s1[] , char s2[]) {

    int i=0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    // condição do while: nenhuma das strings alcançou o fim dela e nenhum dos caracteres das palavras são diferentes
    i ++; //incrementa o indice para continuar a comparar

    return s1[i] - s2[i];
    // função retorna um valor inteiro
    // quando para de comparar, a função retorna a diferença de valor na tabela ASCII dos caracteres atuais

}

int main(){

    return 0;
}