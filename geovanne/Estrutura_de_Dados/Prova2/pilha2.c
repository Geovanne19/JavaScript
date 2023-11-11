#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct Pilha{
    int nums[N];
    int topo;
} Pilha;

void Inicializapilha(Pilha *pilha){
    pilha->topo = -1;
}

int Cheia(Pilha *pilha){return pilha->topo == N-1;}

int Vazia(Pilha *pilha){return pilha->topo == -1;};

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