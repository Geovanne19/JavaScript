#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct Fila{
    int nums[N];
    int primeiro;
    int ultimo;
} Fila;

void InicializaFila(Fila *fila){
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int Cheia(Fila *fila){return fila->ultimo == N-1;}

int Vazia(Fila *fila){return fila->ultimo == -1;};

void Enfileirar(int num, Fila *fila){
    if(Cheia(fila)){
        printf("A fila está vazia\n");
    } else{
        fila->ultimo++;
        fila->nums[fila->ultimo] = num;
    }
}

void Desenfileirar(Fila *fila){
    if(Vazia(fila)){
        printf("A fila está vazia\n");
    } else{
        for(int i=0; i < fila->ultimo; i++){
            fila->nums[i] = fila->nums[i+1];
        }
        fila->ultimo--;
    }
}

void ImprimeFila(Fila *fila){
    if(Vazia(fila)){
        printf("A fila está vazia\n");
    } else{
        for(int i=0; i <= fila->ultimo; i++){
            printf("%d ", fila->nums[i]);
        }
        printf("\n");
    }
}

int main(){
    
    Fila fila;

    InicializaFila(&fila);

    for(int i=1; i < 51; i++){
        Enfileirar(i, &fila);
    }

    ImprimeFila(&fila);

    for(int i=1; i<50; i++){
        Desenfileirar(&fila);
    }

    ImprimeFila(&fila);
    printf("%d\n", fila.ultimo);

    return 0; 
}