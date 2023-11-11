#include <stdio.h>

int buscaSequencial(int vet[], int n, int chave, int posicoes[]) {
    int ocorrencias = 0;
    
    for (int i = 0; i < n; i++) {
        if (vet[i] == chave) {
            posicoes[ocorrencias] = i;
            ocorrencias++;
        }
    }
    
    return ocorrencias;
}

int buscaBinaria(int vet[], int n, int chave, int posicoes[]) {
    int ocorrencias = 0;
    int inicio = 0;
    int fim = n - 1;
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        
        if (vet[meio] == chave) {
            posicoes[ocorrencias] = meio;
            ocorrencias++;
            
            int esq = meio - 1;
            while(esq >= 0 && vet[esq] == chave) {
                posicoes[ocorrencias] = esq;
                ocorrencias++;
                esq--;
            }
            
            int dir = meio + 1;
            while(dir < n && vet[dir] == chave) {
                posicoes[ocorrencias] = dir;
                ocorrencias++;
                dir++;
            }
            
            return ocorrencias;
        }
        else if(vet[meio] < chave) {
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    
    return ocorrencias;
}

int main() {
    int vet[] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8};
    int n = sizeof(vet)/sizeof(vet[0]);
    int chave = 5;
    int posicoes[10]; 
    
    int ocorrencias = buscaSequencial(vet, n, chave, posicoes);
    printf("Busca Sequencial:\n");
    for (int i = 0; i < ocorrencias; i++) {
        printf("Chave encontrada na posição: %d\n", posicoes[i]);
    }

    ocorrencias = buscaBinaria(vet, n, chave, posicoes);
    printf("\nBusca Binária:\n");
    for (int i = 0; i < ocorrencias; i++) {
        printf("Chave encontrada na posição: %d\n", posicoes[i]);
    }
    
    return 0;
}
