#include <stdio.h>
#include "pilha.h"
#include "menu.h"

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

int main(){
    Tarefa tarefa1, tarefa2, tarefa3;
    Lista lista;
    Pilha pilha;
    int i, Escolha = -1;

    InicializaLista(&lista);
    InicializaPilha(&pilha);

    while (Escolha != SAIR){        
        system("clear");
        Escolha = MenuPrincipal(&pilha, &lista);
        system("clear");
        switch (Escolha){
            case FILTRAR: ;
                int escolhaVer = menuVer();
                system("clear");
                switch (escolhaVer){
                    case TAREFASDIA:
                        TarefasDoDiaPilha(&pilha, &lista);
                        break;
                    
                    case TAREFASMES:    
                        TarefasDoMesPilha(&pilha, &lista);
                        break;
                        
                    case TODAS_AS_TAREFAS:
                        DestruirPilha(&pilha);
                        TodasAsTarefasPilha(&pilha, &lista);
                        break;

                    case TAREFASPENDENTES:
                        TarefasPendentesPilha(&pilha, &lista);
                        break;

                    case VERPERSONALIZADO:
                        menuVerPersonalizar(&pilha, &lista);                        
                        break;
                    
                    case VOLTAR:
                        break;
                }
                break;

            case ADICIONAR: ; 
                Tarefa tarefa;
                LeTarefa(&tarefa);
                if (!PilhaVazia(&pilha)) InserirTarefaPilha(&pilha, tarefa);
                InserirInicioLista(tarefa, &lista);
                break;

            case BUSCAR: 
                if(!PilhaVazia(&pilha)) menuBuscar(&pilha);
                else menuBuscaGeral(&lista);
                voltar();
                break;

            case POMODORO: 
                Pomodoro();
                break;

            case TAREFAS_GERAL: 
                Printar(&lista);
                voltar();
                break;

            case TAREFAS_ATUAIS:
                if (!PilhaVazia(&pilha)) {
                    menuOpcoesTarefas(&pilha, &lista);
                }
                break;

            case SAIR: 
                Destruir(&lista);
                DestruirPilha(&pilha);
                printf("Programa encerrado\n");
                break;
        }
    }
    return 0;
}