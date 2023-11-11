#include <stdio.h>
#define REMOVER 1
#define FILTRAR 1
#define ADICIONAR 2
#define BUSCAR 3
#define POMODORO 4
#define TAREFAS_GERAL 5
#define TAREFAS_ATUAIS 6
#define TAREFASDIA 1
#define TAREFASMES 2
#define TAREFASPENDENTES 4
#define VERPERSONALIZADO 5
#define DATA_ESPECIFICA 1
#define INTERVALO_PERSONALIZADO 2
#define DIA_ESPECIFICO 3
#define NOME_ESPECIFICO 4
#define TAG_ESPECIFICA 5
#define TODAS_AS_TAREFAS 3
#define ORDENAR 4
#define MARCARFEITA 5
#define SAIR 0
#define VOLTAR 0

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

int MenuPrincipal(Pilha * pilha, Lista * lista);
int menuVer(); 
void menuVerPersonalizar(Pilha * pilha, Lista * lista);
void menuOpcoesTarefas(Pilha * pilha, Lista * lista); 
void menuOrdenacao(Pilha * pilha); 
void printauxiliaMenuBuscar(); 
void menuBuscar(Pilha * pilha); 
void menuBuscaGeral(Lista * lista); 
void voltar(); 