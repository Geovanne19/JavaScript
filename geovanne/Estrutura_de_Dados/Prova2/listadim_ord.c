#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *prox;
    struct No *anterior;
} No;

typedef struct Lista{
    No *primeiro;
    No *anterior;
    No *ultimo;
    int tam;
} Lista;

void InicializaLista(Lista *lista){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->anterior = NULL;
    lista->tam = 0;
}

int Vazia(Lista *lista){
    return(lista->primeiro == NULL && lista->ultimo == NULL);
}

void Inserir_Final(int dado, Lista *lista){
    No *NovoNo = malloc(sizeof(No));
    if(NovoNo){
        NovoNo->dado = dado;
        NovoNo->prox = NULL;
        if(Vazia(lista)){
            NovoNo->anterior = NULL;
            lista->primeiro = NovoNo;
            lista->ultimo = NovoNo;
        } else{
            lista->ultimo->prox = NovoNo;
            lista->ultimo = NovoNo;
            lista->ultimo->anterior = NovoNo;
        }
        lista->tam++;
    } else{
        printf("Erro ao alocar memória.\n");
    }
}

void Inserir_Inicio(int dado, Lista *lista){
    No *NovoNo = malloc(sizeof(No));
    if(NovoNo){
        NovoNo->dado = dado;
        NovoNo->prox = lista->primeiro;
        NovoNo->anterior = NULL;
        if(Vazia(lista)){
            lista->primeiro->anterior = NovoNo;
        }
        lista->primeiro = NovoNo;
        lista->tam++;
    } else{
        printf("Erro ao alocar memória.\n");
    }
}

void ImprimeLista(Lista *lista){
    No *aux = lista->primeiro;
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void BubbleSort(Lista *lista) {
    No *atual;
    No *proximo;
    int flag, aux;
    
    if(Vazia(lista)){
        printf("A lista está vazia\n");
    } else{
        do{
            flag = 0;
            atual = lista->primeiro;
            while (atual->prox != NULL) {
                proximo = atual->prox;
                if (atual->dado > proximo->dado) {
                    aux = atual->dado;
                    atual->dado = proximo->dado;
                    proximo->dado = aux;
                    flag = 1;
                }
                atual = atual->prox;
            }
        } while(flag);
    }
    
}

void SelectionSort(Lista *lista){
    
}

int main(){
    
    Lista lista;

    ImprimeLista(&lista);

    BubbleSort(&lista);

    ImprimeLista(&lista);

    FILE *arquivo = fopen("arquivo.txt", "w");

    return 0; 
}