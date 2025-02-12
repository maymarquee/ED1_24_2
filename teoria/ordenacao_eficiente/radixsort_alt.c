#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

#define key(A) A
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)


#define maxstring 101
#define bitsbyte 8
#define bytesword 4
#define R (1 << bitsbyte) //00000001 << 8 = 00000001 00000000 = 2^8 = 256
#define digit(N,D) (((N) >> ((D)*bitsbyte)) & (R-1))


void show(Item v[][maxstring], int l, int r){
    for(int i=l; i<=r; i++){
        printf("%s ", v[i]);
    }
    printf("\n");
}


//Ordena para o d-éimo caractere
void radixMSD(char a[][maxstring],  int l, int r, int d)
{ 
    
    if(r<=l) return;
    
    char aux[r-l+1][maxstring];
    int count[R+1];
    //for(int i=0; i<=R; i++)
      //  count[i] = 0;
    memset(count, 0, sizeof(int)*(R+1));
    
    for (int i = l; i <= r; i++)
        count[a[i][d] + 1]++; //frequencia do d-ésimo caractere
    
    for (int i = 1; i<R; i++)
        count[i] += count[i-1]; //acha as posições
    
    for (int i = l; i <= r; i++) 
        strcpy(aux[count[a[i][d]]++], a[i]); //ordena em aux

    for (int i = l; i <= r; i++)
        strcpy(a[i], aux[i - l]); //copia para o original
    
    for (int i = 1; i < R; i++){
        radixMSD(a, l + count[i-1], l + count[i]-1, d+1);
    }

}


//strings de tamanho w
void radixLSD(char a[][maxstring],  int l, int r, int w)
{ 
    char aux[r-l+1][maxstring];
    int count[R+1];
    
    //d -> posição do caractere
    for(int d=w-1; d>=0; d--){
        for(int i=0; i<=R; i++)
            count[i] = 0;
    
        for (int i=l; i<=r; i++)
            count[a[i][d] + 1]++;
    
        for (int i=1; i<R; i++)
            count[i] += count[i-1];

        for (int i=l; i<=r; i++){
            strcpy(aux[count[a[i][d]]++], a[i]);
        }

        for (int i = l; i <= r; i++){
            strcpy(a[i], aux[i - l]); 

        }

    }
}

void radixLSDI(int *v,  int l, int r)
{
    
    int *aux = malloc((r-l+1)*sizeof(int));
    
    int i, w;
    int count[R+1];
    
    for(w=0; w<bytesword; w++){
        memset(count, 0, sizeof(int)*(R+1));

        for(i=l; i<=r; i++){
            count[digit(v[i], w)+1]++;
        }
        
        for(i=1; i<=R; i++)
            count[i] += count[i-1];
        
        for(i=l; i<=r; i++){
            aux[count[digit(v[i], w)]] = v[i];
            count[digit(v[i], w)]++;
        }

        for(i=l; i<=r; i++)
            v[i] = aux[i-l]; 
    }

}

int main() {
    char a[5][maxstring] = {"cavalo", "bexiga", "nabo", "praca", "cafe"};
    char b[5][maxstring] = {"caro", "beta", "nabo", "pera", "cafe"};

    show(b, 0, 4);
    radixLSD(b, 0, 4, 4);
    show(b, 0, 4);

    show(a, 0, 4);
    radixMSD(a, 0, 4, 0); 
    show(a, 0, 4);


    int v[16] = {3,2,3,5,1,6,8,2,4,7,1,3,8,6,8,9};
    for(int i=0; i<16; i++) printf("%d ", v[i]);
    printf("\n");
    radixLSDI(v, 0, 15);
    for(int i=0; i<16; i++) printf("%d ", v[i]);
    printf("\n");
}