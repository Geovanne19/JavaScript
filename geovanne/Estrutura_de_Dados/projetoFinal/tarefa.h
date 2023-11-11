#include <stdio.h>
#include "tempo.h"
#define TAMDESCRICAO 128
#define TAMTAREFA 64
#define TAMTAG 32
#define ALTA 1
#define MEDIA 2
#define BAIXA 3
#define NENHUMA 4
#define FEITA 1
#define PENDENTE 0
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define ORANGE "\x1b[38;5;214m"

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

typedef struct Tarefa{
    char Nome[TAMTAREFA];
    char Descricao[TAMDESCRICAO];
    char Tag[TAMTAG];
    int Status;
    int Prioridade;
    Data data;
    struct Tarefa * Anterior, * Proximo;
}Tarefa;

void limparBuffer();
void LeTarefa(Tarefa * tarefa); 
void CopiaTarefa(Tarefa tarefaOrigem, Tarefa * tarefaDestino); 
void printarPrioridade(Tarefa tarefa); 
void printarStatus(Tarefa tarefa); 
void PrintarTarefa(Tarefa tarefa); 
void PrintarTarefaReduzido(Tarefa tarefa);
int TarefasSaoIguais(Tarefa tarefa1, Tarefa tarefa2); 
void SwapTarefas(Tarefa * referencia1, Tarefa * referencia2); 