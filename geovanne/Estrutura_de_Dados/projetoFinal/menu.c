#include <stdio.h>
#include "pilha.h"
#include "menu.h"

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

int MenuPrincipal(Pilha * pilha, Lista * lista){
    int Escolha;
    printf("------------------------------------------------\n");
    printf(BLUE"✅TASKS ORGANIZER\n"RESET);
    printf("------------------------------------------------\n");

    if ( PilhaVazia(pilha) ){
        PrintarReduzido(lista);
        printf(YELLOW"\n1 - Filtrar Tarefas\n");
        printf("2 - Adicionar Tarefa\n");
        printf("3 - Buscar Tarefa\n");
        printf("4 - Pomodoro\n"RESET);

    }
    else {
        printarPilhaReduzido(pilha);
        printf(YELLOW"\n1 - Mudar filtro de Tarefas\n");
        printf("2 - Adicionar Tarefa\n");
        printf("3 - Buscar Tarefa\n");
        printf("4 - Pomodoro\n");
        printf("5 - Todas as tarefas\n");
        printf("6 - Operacoes com tarefas atuais\n"RESET);
    }
    printf(YELLOW"0 - Sair\n"RESET);
    printf("\nSua escolha: ");
    scanf("%d", &Escolha);
    return Escolha;
} 

int menuVer(){
    int Escolha;
    printf("Escolha o que deseja ver\n\n");
    printf(YELLOW"1 - Tarefas do dia\n");
    printf("2 - Tarefas do mes\n");
    printf("3 - Todas as tarefas\n");
    printf("4 - Tarefas pendentes\n");
    printf("5 - Personalizar\n");
    printf("0 - Voltar\n"RESET);
    printf("\nSua escolha: ");
    scanf("%d", &Escolha);
    return Escolha;
} 

void menuVerPersonalizar(Pilha * pilha, Lista * lista){
    int Escolha;
    printf("Escolha como deseja personalizar\n\n");
    printf(YELLOW"1 - Ver tarefas ate uma data especifica\n");
    printf("2 - Ver tarefas dentro de um intervalo especifico\n");
    printf("3 - Ver tarefas de um dia especifico\n");
    printf("4 - Ver tarefas com um nome especifico\n");
    printf("5 - Ver tarefas com uma TAG especifica\n");
    printf("0 - Voltar\n"RESET);
    printf("\nSua escolha: ");
    scanf("%d", &Escolha);
    switch (Escolha){
        case DATA_ESPECIFICA:
            TarefasAteDiaEspecificoPilha(pilha, lista);
            break;

        case INTERVALO_PERSONALIZADO:
            TarefasIntervaloEspecificoPilha(pilha, lista);
            break;

        case DIA_ESPECIFICO:
            TarefasDoDiaEspecificoPilha(pilha, lista);
            break;
        
        case NOME_ESPECIFICO:
            TarefasNomeEspecificoPilha(pilha, lista);
            break;

        case TAG_ESPECIFICA:
            TarefasTAGEspecificaPilha(pilha, lista);
            break;
    }
}

void printAuxiliarMenuOpcoesTarefas(){
    system("clear");
    printf(YELLOW"1 - Remover tarefa\n");
    printf("2 - Adicionar tarefa\n");
    printf("3 - Buscar tarefa\n");
    printf("4 - Ordenar\n");
    printf("5 - Marcar tarefa como feita\n");
    printf("0 - Voltar"RESET);

} 

void menuOpcoesTarefas(Pilha * pilha, Lista * lista){
    int Escolha;
    printarPilhaReduzido(pilha);
    printf("\nDeseja realizar alguma operacao nessa pilha de tarefas?\n");
    printf("1 - Sim\n2 - Nao\nSua escolha: ");
    scanf("%d", &Escolha);
    if(Escolha == 1){
        int EscolhaFinal = -1;
        while (EscolhaFinal != VOLTAR){
            printAuxiliarMenuOpcoesTarefas();
            printf("\nSua escolha: ");
            scanf("%d", &EscolhaFinal);
            switch (EscolhaFinal){
                case REMOVER: ; 
                    int index;
                    system("clear");
                    printarPilhaReduzido(pilha);
                    printf("\nDigite o numero da tarefa que deseja remover: ");
                    scanf("%d", &index);
                    index--;
                    if(index >= 0 && index < pilha->nTarefas){
                        Remover(lista, pilha->tarefa[index]);
                        RemoverPilha(pilha, index);
                    }
                    break;

                case ADICIONAR: ; 
                    Tarefa novaTarefa;
                    LeTarefa(&novaTarefa);
                    InserirInicioLista(novaTarefa, lista);
                    InserirTarefaPilha(pilha, novaTarefa);
                    break;

                case BUSCAR: 
                    menuBuscar(pilha);
                    voltar();
                    break;

                case ORDENAR: 
                    menuOrdenacao(pilha);
                    break;

                case MARCARFEITA: ;
                    system("clear");
                    printarPilhaReduzido(pilha);
                    printf("Digite o numero da tarefa que deseja marcar como feita: ");
                    scanf("%d", &index);
                    index--;
                    if( (index >= 0) && (index < pilha->nTarefas) ){
                        marcarComoFeitaLista(lista, pilha->tarefa[index]);
                        pilha->tarefa[index].Status = FEITA; 
                        printf("%d\n", pilha->tarefa[index].Status == FEITA);
                    }    
                    break;
            }
        }
    }
} 

void menuOrdenacao(Pilha * pilha){
    int Escolha = -1;
    while (Escolha < 1 || Escolha > 4){
        printf("Escolha a forma que deseja ordenar\n\n");
        printf(YELLOW"1 - Ordenar por data\n");
        printf("2 - Ordenar por nome\n");
        printf("3 - Ordenar por status\n");
        printf("4 - Ordenar por prioridade\n");
        printf("0 - Voltar\n"RESET);
        printf("\nSua escolha: ");
        scanf("%d", &Escolha);
    }
    if(Escolha != 0) OrdenarPilha(pilha, Escolha+1);
} 

void printauxiliaMenuBuscar(){
    system("clear");
    printf("Escolha a forma que deseja buscar\n\n");
    printf(YELLOW"1 - Buscar por tag\n");
    printf("2 - Buscar por data\n");
    printf("3 - Buscar por nome\n");
    printf("4 - Buscar por tarefa\n");
    printf("0 - Voltar\n"RESET);
    printf("\nSua escolha: ");
} 

void menuBuscar(Pilha * pilha){
    int Escolha = -1;
    while (Escolha < 0 || Escolha > 4){
        printauxiliaMenuBuscar();
        scanf("%d", &Escolha);
    }
    if(Escolha != 0) buscarPilha(pilha, Escolha);    
} 

void menuBuscaGeral(Lista * lista){
    int Escolha = -1;
    while (Escolha < 0 || Escolha > 4){
        printauxiliaMenuBuscar();
        scanf("%d", &Escolha);
    }
    if(Escolha != 0) buscarLista(lista, Escolha);
} 

void voltar(){
    char voltar;
    printf("\nAperte enter para voltar ");
    scanf("%*c%c", &voltar);                           
} 