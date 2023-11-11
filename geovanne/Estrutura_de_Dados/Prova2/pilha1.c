#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct Pilha{
    int nums[N];
    int topo;
} Pilha;

void InicializaPilha(Pilha *pilha){
    pilha->topo = -1;
}
int Cheia(Pilha *pilha){return pilha->topo == N-1;}

int Vazia(Pilha *pilha){return pilha->topo == -1;}

void Empilhar(int num, Pilha *pilha){
    if(Cheia(pilha)){
        printf("A pilha está cheia\n");
    } else{
        int i = pilha->topo;
        do{
            pilha->nums[i+1] = pilha->nums[i];
            i--;
        } while(i>=0);
        pilha->topo++;
        pilha->nums[0] = num;
        
    }
}

void Desempilhar(Pilha *pilha){
    if(Vazia(pilha)){
        printf("Pilha vazia\n");
    } else{
        int i=0;
        do{
            pilha->nums[i] = pilha->nums[i+1];
            i++;
        }while(i<=pilha->topo);
        pilha->topo--;
    }
}

void ImprimirPilha(Pilha *pilha){
    if(Vazia(pilha)){
        printf("A pilha está vazia\n");
    } else{
        for(int i = 0; i <= pilha->topo; i++){
            printf("%d ", pilha->nums[i]);
        }
        printf("\n");
    }
}

int main(){
    
    Pilha pilha;

    InicializaPilha(&pilha);

    for(int i = 1; i < 51; i++){
        Empilhar(i, &pilha);
    }

    ImprimirPilha(&pilha);

    for(int i=1; i < 11; i++){
        Desempilhar(&pilha);
    }

    ImprimirPilha(&pilha);

    return 0; 
}