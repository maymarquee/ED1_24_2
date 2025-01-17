#include <stdio.h>

/* 
struct nome_da_estrutura {

    tipo_do_campo campo1;
    tipo_do_campo campo2;

};
*/ 

struct nomes {

    char nome1;
    char nome2;

}; 

// renomeia o tipo de "struct data" para "Data"
typedef struct data Data; 

//definindo tipo Data
struct data {
    int dia, mes, ano;
};

//definir o tipo Pessoa
typedef struct {
    int cpf;
    Data nascimento;
    char nome[100];
}Pessoa;

int main() {

    Pessoa diretor; //variavel diretor
    Pessoa alunos[100]; //vetor alunos
    Pessoa vazia = {0, {0, 0, 0}, "nada"};

    scanf("%d", &diretor.cpf);
    scanf("%[^\n]", diretor.nome);
    //não está chegando no terceiro scanf!!!
    scanf("%d%d%d", &diretor.nascimento.dia, &diretor.nascimento.mes, &diretor.nascimento.ano);


    return 0;
}