// Crie um programa que dado uma string, coloque as letras dela em ordem crescente
// pelo algoritmo quick-sort.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void QuickSort(char string[], int primeiro, int ultimo) {
    if (primeiro < ultimo) {
        int i = primeiro, j = ultimo;
        char pivot = string[(primeiro + ultimo) / 2];

        while (i <= j) {
            while (string[i] < pivot) {
                i++;
            }
            while (string[j] > pivot) {
                j--;
            }
            if (i <= j) {
                char aux = string[i];
                string[i] = string[j];
                string[j] = aux;
                i++;
                j--;
            }
        }

        QuickSort(string, primeiro, j);
        QuickSort(string, i, ultimo);
    }
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    int len = strlen(string);
    if(len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    QuickSort(string, 0, strlen(string) - 1);

    printf("String ordenada: %s\n", string);

    return 0;
}
