#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No *proximo;
} No;

typedef struct Pilha{
    No *topo;
    int tam;
} Pilha;

void InicializaPilha(Pilha *pilha){
    pilha->topo = NULL;
    pilha->tam = 0;
}

int Vazia(Pilha *pilha){return pilha->topo == NULL;}

void Empilhar(int num, Pilha *pilha){
    No *NovoNo = malloc(sizeof(No));
    if(NovoNo){
        NovoNo->num = num;
        NovoNo->proximo = pilha->topo;
        pilha->topo = NovoNo;
        pilha->tam++;
    }
}

No *Desempilhar(Pilha *pilha){
    No *aux = pilha->topo;
    if(Vazia(pilha)){
        printf("A pilha está vazia\n");
    } else{
        pilha->topo = pilha->topo->proximo;
        pilha->tam--;
    }
    return aux;
}

void ImprimePilha(Pilha *pilha){
    No *aux = pilha->topo;
    if(Vazia(pilha)){
        printf("A Pilha está vazia\n");
    } else{
        while(aux != NULL){
            printf("%d ", aux->num);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

int main(){
    
    Pilha pilha;

    InicializaPilha(&pilha);

    for(int i=1; i < 51; i++){
        Empilhar(i, &pilha);
    }

    ImprimePilha(&pilha);

    for(int i=1; i<11; i++){
        Desempilhar(&pilha);
    }

    ImprimePilha(&pilha);
    printf("%d\n", pilha.topo->num);

    return 0;
}