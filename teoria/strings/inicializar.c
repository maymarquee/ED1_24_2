#include <stdio.h>

int main() {

    char nome1[6] = "maria";
    char nome2[6] = {'m', 'a', 'r', 'i', 'a', '\0'};

    printf("%s %s", nome1, nome2);


    char nome[100];
    char c;

    // ler palavra em um vetor de caracteres
    scanf(" %c", &c); 
    /*
    Espaço antes do %c -> faz o scanf ignorar espaços em branco, quebra de linha e tabluação antes do próximo caractere
    Feito para evitar capturar resíduos de entrada, como o enter
    */
    for(int = 0, i < 100 && c!=' ' && c!='\n' && c!='\t'; i++ ) {
        // condição: enquanto o vetor não foi percorrido por inteiro, enquanto c não enconmtrar espaços, uma tabulação ou uma nova linha 
        nome[i] = c;
        scanf("%c", &c); //sem espaço -> o loop já controla a leitura 
    }
    return 0;
}
