#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No *proximo;
} No;

typedef struct Fila{
    No *primeiro;
    No *ultimo;
    int tam;
} Fila;

void InicializaFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tam = 0;
}

int Vazia(Fila *fila){return fila->primeiro == NULL;}

void Enfileirar(int num, Fila *fila){
    No *NovoNo = malloc(sizeof(No));
    if(NovoNo){
        NovoNo->num = num;
        NovoNo->proximo = NULL;
        if(Vazia(fila)){
            fila->primeiro = NovoNo;
            fila->ultimo = NovoNo;
        } else{
            fila->ultimo->proximo = NovoNo;
            fila->ultimo = NovoNo;
        }
        fila->tam++;
    }
}

No *Desenfileirar(Fila *fila){
    No *aux = fila->primeiro;
    if(Vazia(fila)){
        printf("A fila está vazia\n");
    } else{
        fila->primeiro = fila->primeiro->proximo;
        fila->tam--;
    }
    return aux;
}

void ImprimeFila(Fila *fila){
    No *aux = fila->primeiro;
    if(Vazia(fila)){
        printf("A fila está vazia\n");
    } else{
        while(aux != NULL){
            printf("%d ", aux->num);
            aux = aux->proximo;
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

    for(int i=1; i<11; i++){
        Desenfileirar(&fila);
    }

    ImprimeFila(&fila);
    printf("%d\n", fila.ultimo->num);

    return 0; 
}