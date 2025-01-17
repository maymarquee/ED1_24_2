#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

///////////////////////////////
//ARVORE
///////////////////////////////
typedef struct registro node;
struct registro {
    int dado, nivel, altura; 
    node *esq;
    node *dir;
    node *pai;
};

node *criar_arvore(int x, node *e, node *d, node *p)
{
    node *no = malloc(sizeof(node));
    no->dado = x;
    no->esq = e;
    no->dir = d;
    no->pai = p;
    return no;
}


///////////////////////////////
//FILA E PILHA
///////////////////////////////
typedef node *Item;

typedef struct elemento elem;
struct elemento {
    Item info; 
    elem *prox;
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    elem *prox;
    elem *ultimo;
};

head *criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

elem *criar_no(Item x)
{
    elem *no = malloc(sizeof(elem));
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{ 
    return (p->prox==NULL); 
}

///////////////////////////////
//FILA
///////////////////////////////
void enfileira(head *lista, Item x)  //inserir_fim
{
    elem *novo = criar_no(x);
    if(novo){
        
        novo->prox = NULL;
        
        //cabeca != node
        if(!vazia(lista)) lista->ultimo->prox = novo;
        else lista->prox = novo;

        lista->ultimo = novo;
        lista->num_itens++;
    }
}

Item desenfileira(head *lista) //remover_inicio
{
    elem *lixo = lista->prox;
    lista->prox = lista->prox->prox;

    //cabeca != node
    if(lixo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = lixo->info;
    free(lixo);
    return x;
}

///////////////////////////////
//PILHA
///////////////////////////////
void empilha(head *lista, Item x)  //inserir_inicio
{
    elem *novo = criar_no(x);
    if(novo){
        if(vazia(lista)) lista->ultimo = novo;
        
        novo->prox = lista->prox;
        lista->prox = novo;
        
        lista->num_itens++;
    }
}

Item desempilha(head *lista) //remover_inicio
{
    elem *topo = lista->prox;
    lista->prox = topo->prox;

    if(topo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = topo->info;
    free(topo);
    return x;
}

void imprime_pilha(head *lista){
    
    elem *a = lista->prox;
    printf("\n\npilha: ");
    while(a!=NULL) {
        if(a->info) printf("%3d", a->info->dado);
        a = a->prox;
    }
    printf("\n");
}

///////////////////////////////
//EXEMPLO ARVORE
///////////////////////////////
//cria a árvore a partir de um vetor do exemplo do torneio (visto em aula)
node *torneio(int *v, int l, int r) {
    node *esq , *dir, *pai;
    int valor;
    int m = (l + r) / 2;
    if (l == r) return criar_arvore(v[l], NULL , NULL, NULL);

    esq = torneio(v, l, m);
    dir = torneio(v, m+1, r);
    valor = esq->dado > dir->dado ? esq->dado : dir->dado;
    
    pai = criar_arvore(valor, esq , dir, NULL);
    esq->pai = dir->pai = pai;
    return pai;
}

//a partir do vetor v, que representa uma árvore binária completa cujas as folhas estão sempre mais a esquerda possível
//criar a mesma árvore, porém com sua representação encadeada 
node *arvore_completa(int *v, int k, int n) {
    if(k>=n) return NULL;
    node *esq , *dir;
    esq = arvore_completa(v, 2*k+1, n);
    dir = arvore_completa(v, 2*k+2, n);
    
    node *pai = criar_arvore(v[k] , esq , dir, NULL);    
    if(esq) esq->pai = pai;
    if(dir) dir->pai = pai;
    
    return pai;
}

///////////////////////////////
//PERCORRER ARVORE EM LARGURA
///////////////////////////////
void percurso_em_largura (node *raiz) {
    head *f;

    f = criar_lista();
    enfileira(f, raiz);
    int nivel=0;
    while (!vazia(f)) {
        
        raiz = desenfileira(f);

        if (raiz != NULL) {
            printf("%d ", raiz->dado); /* visita raiz */
            enfileira(f, raiz->esq);
            enfileira(f, raiz->dir);
           
        }
    }
}


////////////////////////////////////
//PERCORRER ARVORE EM PROFUNDIDADE
////////////////////////////////////
void preordem(node *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado); /* visita raiz */
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
    
}

void pre_ordem(node *raiz) {

    head *p;
    p = criar_lista();

    empilha(p, raiz);

    while (!vazia(p)) {
        raiz = desempilha(p);

        if (raiz != NULL) {
            empilha(p, raiz->dir);
            empilha(p, raiz->esq);
            printf("%d ", raiz->dado); /* visita raiz */

            //imprime_pilha(p);
        }
    }
}

void inordem(node *raiz) {
    if (raiz != NULL) {
        inordem(raiz->esq);
        printf("%d ", raiz->dado); /* visita raiz */
        inordem(raiz->dir);
    }
}

void visita_esquerda(head *p, node *raiz) {
    while (raiz!=NULL) {
        empilha(p, raiz);
        raiz = raiz->esq;
    }
}

void in_ordem(node *raiz) {

    head *p;
    p = criar_lista();

    //empilha todos os nós a esquerda
    while (raiz!=NULL) {
        empilha(p, raiz);
        raiz = raiz->esq;
    }
    while (!vazia(p)) {
        raiz = desempilha(p); //processa o nó mais a esquerda

        if (raiz != NULL) {
            printf("%d ", raiz->dado); //processa o nó mais a esquerda
            raiz = raiz->dir;          //vai para direita do nó mais a esquerda
            visita_esquerda(p, raiz);  //empilha todos os nós a esquerda do nó direita
                                       //o próximo nó será esquerda da direita se existir        
          }
    }
}

void posordem(node *raiz) {
    if (raiz != NULL) {
        posordem(raiz->esq);
        posordem(raiz->dir);
        printf("%d ", raiz->dado); /* visita raiz */
    }
}

void pos_ordem(node *raiz) {

    head *p, *raizes;
    p = criar_lista();      //pilha para percurso
    raizes = criar_lista(); //pilha para raízes
                            //por que não filas? 
                            //  para vistar e processar os nós mais profundos primeiro

    empilha(p, raiz);       
    while (!vazia(p)) {
        raiz = desempilha(p);
        if (raiz != NULL) {
            if(raiz->esq) empilha(p, raiz->esq);    //por que empilhar primeiro a sub-arvore esquerda?
            if(raiz->dir) empilha(p, raiz->dir);    //  para empilhar da esquerda para direita (direita no topo)
                                                    //  e visitar da direita para esquerda 

            empilha(raizes, raiz);                  //raizes visitadas e empilhadas da direita - esquerda
                                                    //  raízes processadas na ordem inversa da que foram inseridas
          } 
    }
    
    while (!vazia(raizes)) {
        raiz = desempilha(raizes);
        printf("%d ", raiz->dado);
    }
}

//calcular, recursivamente, o nível de cada nó armazenando no campo "nivel"
//dica: utilize o nó pai
int nivel(node *raiz){
    if(raiz->pai == NULL) return 0;
    
    return 1 + nivel(raiz -> pai);
}

int numero_folhas(node *raiz){
    if(raiz == NULL) return 0; 
    if((raiz -> esq == NULL) && (raiz -> dir == NULL)) return 1;

    return numero_folhas(raiz->esq) + numero_folhas(raiz->dir);
}

int numero_nos(node *raiz){
    if(raiz== NULL) return 0; 
    int a = numero_nos(raiz ->esq);
    int b = numero_nos(raiz ->dir);
    return 1 + a + b;
}

int altura(node *raiz){
    if ( raiz == NULL ) return 0;

    int h_esq = altura ( raiz -> esq );
    int h_dir = altura ( raiz -> dir );

    return 1 + ( h_esq > h_dir ? h_esq : h_dir );
}



int minimo(node *raiz){

    if(raiz == NULL) return INT_MAX;

    int a = raiz->dado;
    int b = minimo(raiz->esq);
    int c = minimo(raiz->dir);
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int maximo(node *raiz){

    if(raiz==NULL) return INT_MIN;
    int a = raiz->dado;
    int b = maximo(raiz->esq);
    int c = maximo(raiz->dir);
    return (a > b ? (a > c ? a : c) : (b > c ? b : c));
    
}

node *avo(node *raiz){
    if((raiz != NULL) && (raiz->pai != NULL ) )
        return raiz -> pai -> pai;

    return NULL;
}

node *tio(node *raiz){
    node *vo = avo(raiz); 
    if(vo==NULL) return NULL;

    if(raiz->pai == vo->esq) 
        return vo->dir; 
    return vo->esq; 

}

node *irmao(node *raiz){
    if((raiz-> pai == NULL) && (raiz == NULL)) return NULL; 


    if(raiz->pai->esq == raiz) 
        return raiz->pai->dir;

    return raiz->pai->esq;

    
}

//buscar nó com valor x
node * busca_linear(node *raiz, int x){
    if( raiz == NULL || raiz -> dado == x)
        return raiz;

    node *e = busca_linear (raiz->esq, x);

    if(e != NULL ) return e;

    return busca_linear (raiz->dir, x);

}

//buscar nó com valor x menos profundo
//dica: usar uma tad apropriada
node * mais_proximo(node *raiz, int x) {
    //??
}

//prof. Siang Wun Song 
//slide 44
//calcular as alturas das subarvores de cada nó, guardando no campo alt
//Exemplo: no(alt)
//          a(4)
//      /          \
//   b(3)           c(3)
//  / \            /
//d(1) e(1)      f(1)
int subaltura(node *raiz){
    //??
}

int main () {
    
    //criando uma árvore
    //node *no1, *no2, *no3;
    //no1 = criar_arvore(3, NULL , NULL);
    //no2 = criar_arvore(4, NULL , NULL);
    //no2 = criar_arvore(8, no2, NULL);
    //no3 = criar_arvore(5, no1, no2);
    //no1 = criar_arvore(9, NULL , NULL);
    //no1 = criar_arvore(1, NULL, no1);
    //no2 = criar_arvore(6, NULL , NULL);
    //node *arvore = criar_arvore(2, no3, criar_arvore(7, no1, no2));


    //criando uma árvore
    int v[8] = {5, 1, 7, 4, 3, 2, 6, 8};
    node *arvore = torneio(v, 0, 7);
    
    preordem(arvore);
    printf("\n");

    percurso_em_largura(arvore);
    printf("\n");
    
    //     5
    //  1     7
    // 4 3   2 6
    //8
    node *arvore2 = arvore_completa(v, 0, 8);
    preordem(arvore2);
    printf("\n");
    
    return 0;
}
