// Faça um programa que leia n nomes e ordene-os pelo tamanho utilizando o
// algoritmo de inserção e de seleção. No final, o algoritmo deve mostrar todos os
// nomes ordenados.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define N 7
#define TAM_PALAVRA 10

typedef struct Fila {
    char palavras[N][TAM_PALAVRA]; 
    int primeiro;
    int ultimo;
} Fila;

void InicializaFila(Fila *fila) {
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int Vazia(Fila *fila) {
    return fila->ultimo == -1;
}

int Cheia(Fila *fila) {
    return (fila->ultimo == N - 1);
}

void Enfileirar(char palavra[], Fila *fila) {
    if (Cheia(fila)) {
        printf("A fila está cheia\n");
    } else {
        fila->ultimo++;
        strcpy(fila->palavras[fila->ultimo], palavra);
    }
}

void Desenfileirar(Fila *fila) {
    if (Vazia(fila)) {
        printf("Fila vazia\n");
    } else {
        for (int i = 0; i < fila->ultimo; i++) {
            strcpy(fila->palavras[i], fila->palavras[i + 1]);
        }
        fila->ultimo--;
    }
}

void ImprimirFila(Fila *fila) {
    if (Vazia(fila)) {
        printf("A Fila está vazia\n");
    } else {
        for (int i = 0; i <= fila->ultimo; i++) {
            printf("%s", fila->palavras[i]);
            if(i<fila->ultimo) printf(", ");
            if(i==fila->ultimo) printf(".");
        }
        printf("\n");
    }
}

void SelectionSort(Fila *fila) {
    for (int i = 0; i <= fila->ultimo; i++) {
        for (int j = i + 1; j <= fila->ultimo; j++) {
            if (strcmp(fila->palavras[i], fila->palavras[j]) > 0) {
                char aux[TAM_PALAVRA];
                strcpy(aux, fila->palavras[i]);
                strcpy(fila->palavras[i], fila->palavras[j]);
                strcpy(fila->palavras[j], aux);
            }
        }
    }
}

void InsertionSort(Fila *fila) {
    for (int i = 1; i <= fila->ultimo; i++) {
        char chave[TAM_PALAVRA];
        strcpy(chave, fila->palavras[i]); 
        int j = i - 1;
        
        while (j >= 0 && strcmp(chave, fila->palavras[j]) < 0) {
            strcpy(fila->palavras[j + 1], fila->palavras[j]); 
            j--;
        }
        
        strcpy(fila->palavras[j + 1], chave); 
    }
}

int main(){

    Fila fila1, fila2;

    InicializaFila(&fila1);
    InicializaFila(&fila2);

    Enfileirar("Bernardo", &fila1);
    Enfileirar("Bernardo", &fila2);
    Enfileirar("Ana", &fila1);
    Enfileirar("Ana", &fila2);
    Enfileirar("Pássaro", &fila1);
    Enfileirar("Pássaro", &fila2);
    Enfileirar("Navio", &fila1);
    Enfileirar("Navio", &fila2);
    Enfileirar("Dado", &fila1);
    Enfileirar("Dado", &fila2);
    Enfileirar("Herick", &fila1);
    Enfileirar("Herick", &fila2);

    printf("Ord. por InsertionSort: ");
    InsertionSort(&fila1);
    ImprimirFila(&fila1);

    printf("Ord. por SelectionSort: ");
    SelectionSort(&fila2);
    ImprimirFila(&fila2);

    return 0;
}


