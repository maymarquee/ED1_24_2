#include <stdio.h>

int main(){

    char nome1[100];
    char nome2[100];
    char nome3[100];

    scanf("%s", nome1); //armazena a entrada do usuário em nome1

    scanf("%99s", nome2);
    // lê no máximo 99 caracteres (sem encontrar espaços)

    // esse scanf espera uma entrada formatada por "Estrutura de " ANTES de ler a próxima entrada
    // se, no nome 2, o usuário não inserir "Estrutura de ", o scanf vai falhar
    scanf("Estrutura de %s", nome3);

    printf("%s %s %s\n", nome1, nome2, nome3); 

    return 0;
}