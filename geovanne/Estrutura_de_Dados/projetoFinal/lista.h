#include <stdio.h>
#include "tarefa.h"
#define PRIORIDADE 5
#define STATUS 4
#define TAREFA 4
#define NOME 3
#define DATA 2
#define TAG 1

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

typedef struct Lista{
    Tarefa * Primeira, * Ultima;
    int Tam;
}Lista;

void InicializaLista(Lista * lista); 
int Vazia(Lista * lista); 
int UmaTarefa(Lista * lista); 
void InserirInicioLista(Tarefa tarefa, Lista * lista); 
void RemoverFinal(Lista *lista); 
void RemoverInicio(Lista *lista); 
void Remover(Lista *lista, Tarefa tarefa); 
void Destruir(Lista * lista); 
void Printar(Lista * lista); 
void PrintarReduzido(Lista * lista);
void buscarTarefaLista(Lista * lista); 
void buscarDataLista(Lista * lista); 
void buscarNomeLista(Lista * lista); 
void buscarTAGLista(Lista * lista); 
void buscarLista(Lista * lista, int tipo); 
void marcarComoFeitaLista(Lista * lista, Tarefa tarefa);
