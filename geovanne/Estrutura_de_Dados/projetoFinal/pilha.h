#include <stdio.h>
#include "lista.h"

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

typedef struct {
    Tarefa * tarefa;
    int nTarefas;
}Pilha;

void InicializaPilha(Pilha * pilha); 
int PilhaVazia(Pilha * pilha); 
int TemUmPilha(Pilha * pilha); 
void InserirTarefaPilha(Pilha * pilha, Tarefa tarefa); 
void PrintarPilha(Pilha * pilha); 
void printarPilhaReduzido(Pilha * pilha);
void RemoverPilha(Pilha * pilha, int index);
void DestruirPilha(Pilha * pilha); 
void TarefasDoDiaPilha(Pilha * pilha, Lista * lista); 
void TarefasDoMesPilha(Pilha * pilha, Lista * lista); 
void TarefasDoDiaEspecificoPilha(Pilha * pilha, Lista * lista);
void TarefasAteDiaEspecificoPilha(Pilha * pilha, Lista * lista);
void TarefasIntervaloEspecificoPilha(Pilha * pilha, Lista * lista);
void TarefasNomeEspecificoPilha(Pilha * pilha, Lista * lista);
void TarefasTAGEspecificaPilha(Pilha * pilha, Lista * lista);
void TarefasPendentesPilha(Pilha * pilha, Lista * lista);
void TodasAsTarefasPilha(Pilha * pilha, Lista * lista);
void insertionData(Pilha * pilha); 
void insertionNome(Pilha * pilha); 
void insertionPrioridade(Pilha * pilha); 
void insertionStatus(Pilha * pilha); 
void insertionSortPilha(Pilha * pilha, int tipo); 
int particionarData(Pilha * pilha, int inicio, int ultimo);
int particionarNome(Pilha * pilha, int inicio, int ultimo);
int particionarPrioridade(Pilha * pilha, int inicio, int ultimo);
int particionarStatus(Pilha * pilha, int inicio, int ultimo);
void quickSortPilha(Pilha * pilha, int inicio, int ultimo, int tipo );
void OrdenarPilha(Pilha * pilha, int tipo);
void buscarTarefaPilha(Pilha * pilha); 
void buscarDataPilha(Pilha * pilha); 
void buscarNomePilha(Pilha * pilha); 
void buscarTAGPilha(Pilha * pilha); 
void buscarPilha(Pilha * pilha, int tipo); 