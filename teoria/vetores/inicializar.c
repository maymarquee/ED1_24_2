#include <stdio.h>

int main() {

    //na declaração
    float dinheiros[3] = {23.4, 123.0, 55.0}; //já declarou o vetor e atribuiu valor a ele
    char letras_[4] = {'a', 'b', 'c', 'd'};

    // int a=5; 
    // int y[a] = {1, 4, 6, 99, 2}; ERRO =  em c, arrays de tamanho variável (y) não podem ser inicializadas no momento de sua declaração
    int y[5] = {1, 4, 6, 99, 2};

    // int erro[5];
    // erro = { 2, 4, 6, 8, 10}; ERRO = só pode usar as chaves para atribuir valor no momento da declaração de uma variável
    int erro[5] = {2, 4, 6, 8, 10};

    int peso[] = { 153, 135, 170};
    // int b[]; ERRO = todas as arrays devem ter seu tamanho especificado na declaração, somente não se ela já for inicializada em sua declaração; seu tamanho tem que ser definido 


    //pela entrada
    float dinheiro[100]; // possui de 0 a 99 elementos
    char letras[4]; //aramzena de 0 a 3 elementos
    int i=0;

    while (i<100) {
        scanf ("%f", &dinheiro[i]); //pede ao usuário um valor para "dinheiro" para ir alocando no índice 0 de uma array que armazena dados float
        printf ("%f", dinheiro[0]); //teste meu para observar se realmente os valores estão sendo armazenados
        i++; //vai aumentando o índice e alocando novos valores a cada entrada do usuário
    }

    for (i=0; i<4; i++) {
         scanf (" %c", &letras[i]);
        // o espaço é sugerido para leitura de caracteres para que o enter que o usuário dá no teclado apoós informar um valor não ser interpretado e armazenado na variável
    }

    dinheiro[2] = 1; //atribui 1 como valor para a terceira posição de dinheiro
    int x = dinheiro[3]; //atribui o valor que está na quarta possição da array pra variável x, se ela não foi inicliazada, o valor será lixo de memória
    
    dinheiro[2]++; //incrementa o valor que está na terceira posição da array -> será 2 agora


    //por cópia
    int vetorA[10], vetorB[10];

    for (int i_=0; i_<10; i_++) {
        scanf ("%d", &vetorA[i_]); //pede todos os 10 valores que vão ser armazenados em vetor A, quando o usuário passa o 10º valor, o loop para de rolar
    }

    for (int i_=0; i_<10; i_++) {
        vetorB[i_] = vetorA[i_]; //passa os valores que o usuário passou pra vetor A para o vetor B
    }

    printf("%d\n", vetorA[0]); //so verifica que o primeiro elemento de vetor A é igual ao de vetor B
    printf("%d\n", vetorB[0]);

    return 0;

}
