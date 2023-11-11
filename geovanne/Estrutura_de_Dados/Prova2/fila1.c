#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  N 100

typedef struct Fila{
    int nums[N];
    int primeiro;
    int ultimo;
} Fila;

void InicializaFila(Fila *fila){
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int Vazia(Fila *fila){return fila->ultimo == -1;}

int Cheia(Fila *fila){return(fila->ultimo == N-1);}

void Enfileirar(int num, Fila *fila){
    if(Cheia(fila)){
        printf("A fila está cheia\n");
    } else{
        fila->ultimo++;
        [fila->ultimo] = num;
    }
}

void Desenfileirar(Fila *fila){
    if(Vazia(fila)){
        printf("Fila vazia\n");
    } else{
        int i=0;
        do{
            [i] = [i+1];
            i++;
        } while(i <=fila->ultimo);
        fila->ultimo--;
    }
}

void ImprimirFila(Fila *fila){
    if(Vazia(fila)){
        printf("A Fila está vazia\n");
    } else{
        for(int i = 0; i <= fila->ultimo; i++){
            printf("%d ", [i]);
        }
        printf("\n");
    }
}
void SelectionSort(Fila *fila){
    for(int i=0; i <= fila->ultimo; i++){
        for(int j = i+1; j <= fila->ultimo; j++){
            if([i] > [j]){
                int aux = [i];
                [i] = [j];
                [j] = aux;
            }
        }
    }
}

void InsertionSort(Fila *fila){
    for(int i=0; i < fila->ultimo; i++){
        if([i] > [i+1]){
            int aux = [i+1];
            [i+1] = [i]; 
            [i] = aux;
            int j=i-1;
            while(j>=0){
                if(aux<[j]){
                    [j+1] = [j];
                    [j] = aux;
                } else{
                    break;
                }
                j--;
            }
        }
    }
}



void ShellSort(Fila *fila) {
    int intervalo, i, j, aux;
    for (intervalo = (fila->ultimo+1)/2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < fila->ultimo+1; i++) {
            aux = [i];
            for (j = i; j >= intervalo && [j - intervalo] > aux; j -= intervalo) {
                [j] = [j - intervalo];
            }
            [j] = aux;
        }
    }
}

void BubbleSort(Fila *fila){
    for(int i=1; i <= fila->ultimo; i++){
        for(int j=0; j < fila->ultimo; j++){
            if([j] > [j+1]){
                int aux = [j];
                [j] = [j+1];
                [j+1] = aux;
            }
        }
    }
}

void QuickSort(Fila *fila, int primeiro, int ultimo) {
    int meio = (primeiro+ultimo)/2;
    int pivot = [meio];
    int i = primeiro, j = ultimo;

    while (i <= j) {
        while ([i] < pivot) {
            i++;
        }
        while ([j] > pivot) {
            j--;
        }
        if (i <= j) {
            int aux = [i];
            [i] = [j];
            [j] = aux;
            i++;
            j--;
        }
    }
    if (primeiro < j) {
        QuickSort(fila, primeiro, j);
    }
    if (i < ultimo) {
        QuickSort(fila, i, ultimo);
    }
}

void MergeSort(Fila *fila){
    
}

int main(){
    
    Fila fila;

    InicializaFila(&fila);

    // Enfileirar(5, &fila);
    // Enfileirar(6, &fila);
    // Enfileirar(7, &fila);
    // Enfileirar(75, &fila);
    // Enfileirar(24, &fila);
    // Enfileirar(15, &fila);
    // Enfileirar(88, &fila);
    // Enfileirar(21, &fila);
    // Enfileirar(8, &fila);
    // Enfileirar(34, &fila);
    // Enfileirar(53, &fila);
    // Enfileirar(41, &fila);
    // Enfileirar(66, &fila);

    for(int i=N; i > 0; i--){
        Enfileirar(i, &fila);
    }

    ImprimirFila(&fila);

    ShellSort(&fila);

    ImprimirFila(&fila);

    // for(int i=1; i < 6; i++){
    //     Desenfileirar(&fila);
    // }

    // ImprimirFila(&fila);
    // printf("%d\n", fila.ultimo);

    return 0; 
}