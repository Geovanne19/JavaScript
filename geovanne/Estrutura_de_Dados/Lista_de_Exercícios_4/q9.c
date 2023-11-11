 #include <stdio.h>
#include <stdlib.h>

typedef struct _pessoa_ {
    int Matricula;
    float Nota;
} Aluno;

void TrocarAlunos(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

int ParticaoPorNota(Aluno alunos[], int esquerda, int direita) {
    float pivo = alunos[direita].Nota;
    int i = esquerda - 1;

    for (int j = esquerda; j <= direita - 1; j++) {
        if (alunos[j].Nota >= pivo) {
            i++;
            TrocarAlunos(&alunos[i], &alunos[j]);
        }
    }

    TrocarAlunos(&alunos[i + 1], &alunos[direita]);
    return i + 1;
}

void QuickSortPorNota(Aluno alunos[], int esquerda, int direita) {
    if (esquerda < direita) {
        int indiceParticao = ParticaoPorNota(alunos, esquerda, direita);
        QuickSortPorNota(alunos, esquerda, indiceParticao - 1);
        QuickSortPorNota(alunos, indiceParticao + 1, direita);
    }
}

void Merge(Aluno alunos[], int esquerda, int meio, int direita) {
    int tamanhoEsquerda = meio - esquerda + 1;
    int tamanhoDireita = direita - meio;

    Aluno *esq = malloc(tamanhoEsquerda * sizeof(Aluno));
    Aluno *dir = malloc(tamanhoDireita * sizeof(Aluno));

    for (int i = 0; i < tamanhoEsquerda; i++) {
        esq[i] = alunos[esquerda + i];
    }
    for (int j = 0; j < tamanhoDireita; j++) {
        dir[j] = alunos[meio + 1 + j];
    }

    int i = 0, j = 0, k = esquerda;
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esq[i].Matricula <= dir[j].Matricula) {
            alunos[k] = esq[i];
            i++;
        } else {
            alunos[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        alunos[k] = esq[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        alunos[k] = dir[j];
        j++;
        k++;
    }

    free(esq);
    free(dir);
}

void MergeSortPorMatricula(Aluno alunos[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        MergeSortPorMatricula(alunos, esquerda, meio);
        MergeSortPorMatricula(alunos, meio + 1, direita);

        Merge(alunos, esquerda, meio, direita);
    }
}

int main() {
    int N;
    printf("Digite o numero de alunos: ");
    scanf("%d", &N);

    Aluno *alunos = malloc(N * sizeof(Aluno));

    for (int i = 0; i < N; i++) {
        printf("Digite a matricula e a nota do aluno %d: ", i + 1);
        scanf("%d%f", &alunos[i].Matricula, &alunos[i].Nota);
    }

    QuickSortPorNota(alunos, 0, N - 1);
    printf("\nAlunos ordenados por nota:\n");
    for (int i = 0; i < N; i++) {
        printf("Matricula: %d, Nota: %.2f\n", alunos[i].Matricula, alunos[i].Nota);
    }

    MergeSortPorMatricula(alunos, 0, N - 1);
    printf("\nAlunos ordenados por matricula:\n");
    for (int i = 0; i < N; i++) {
        printf("Matricula: %d, Nota: %.2f\n", alunos[i].Matricula, alunos[i].Nota);
    }

    free(alunos);
    return 0;
}

// 5
// 123 8.5
// 456 7.2
// 789 9.0
// 234 6.8
// 567 8.0

