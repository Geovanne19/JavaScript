#include <stdio.h>

void MergeSort(int vetor1[], int tamanho1, int vetor2[], int tamanho2, int vetor3[], int tamanho3, int vetor_resultante[]) {
    int i = 0, j = 0, k = 0;

    while (i < tamanho1 && j < tamanho2 && k < tamanho3) {
        if (vetor1[i] <= vetor2[j] && vetor1[i] <= vetor3[k]) {
            vetor_resultante[i + j + k] = vetor1[i];
            i++;
        } else if (vetor2[j] <= vetor1[i] && vetor2[j] <= vetor3[k]) {
            vetor_resultante[i + j + k] = vetor2[j];
            j++;
        } else {
            vetor_resultante[i + j + k] = vetor3[k];
            k++;
        }
    }

    while (i < tamanho1) {
        vetor_resultante[i + j + k] = vetor1[i];
        i++;
    }

    while (j < tamanho2) {
        vetor_resultante[i + j + k] = vetor2[j];
        j++;
    }

    while (k < tamanho3) {
        vetor_resultante[i + j + k] = vetor3[k];
        k++;
    }
}

int main() {
    int vetor1[] = {1, 4, 7, 10};
    int tamanho1 = sizeof(vetor1) / sizeof(vetor1[0]);

    int vetor2[] = {2, 5, 8};
    int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);

    int vetor3[] = {3, 6, 9, 11};
    int tamanho3 = sizeof(vetor3) / sizeof(vetor3[0]);

    int vetor_resultante[tamanho1 + tamanho2 + tamanho3];

    MergeSort(vetor1, tamanho1, vetor2, tamanho2, vetor3, tamanho3, vetor_resultante);

    printf("Vetor resultante ordenado: ");
    for (int i = 0; i < tamanho1 + tamanho2 + tamanho3; i++) {
        printf("%d ", vetor_resultante[i]);
    }
    printf("\n");

    return 0;
}
