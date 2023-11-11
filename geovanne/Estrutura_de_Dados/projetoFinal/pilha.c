#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

void InicializaPilha(Pilha * pilha){
    pilha->tarefa = NULL;
    pilha->nTarefas = 0;
} 

int PilhaVazia(Pilha * pilha){
    return(pilha->tarefa == NULL && pilha->nTarefas == 0);
} 

int TemUmPilha(Pilha * pilha){
    return(pilha->nTarefas == 1);
} 

void InserirTarefaPilha(Pilha * pilha, Tarefa tarefa){
    pilha->nTarefas++;
    pilha->tarefa = (Tarefa *) realloc(pilha->tarefa, pilha->nTarefas*sizeof(Tarefa));
    pilha->tarefa[pilha->nTarefas - 1] = tarefa;
} 

void PrintarPilha(Pilha * pilha){
    int contador;
    if(PilhaVazia(pilha)) printf("Pilha sem tarefas\n");
    else{
        for (contador = 0; contador < pilha->nTarefas; contador++){
            printf("Tarefa %d\n", contador+1);
            printf("------------------------------------------------\n");
            PrintarTarefa(pilha->tarefa[contador]);
        }
    }
} 

void printarPilhaReduzido(Pilha * pilha){
    int contador;
    if(PilhaVazia(pilha)) printf("Pilha sem tarefas\n");
    else{
        for (contador = 0; contador < pilha->nTarefas; contador++){
            printf("%d ", contador+1);
            PrintarTarefaReduzido(pilha->tarefa[contador]);
        }
    }
}

void RemoverPilha(Pilha * pilha, int index){
    if(TemUmPilha(pilha)) DestruirPilha(pilha);
    else{
        if(!PilhaVazia(pilha)){
            if (!(index == pilha->nTarefas-1)){
                CopiaTarefa(pilha->tarefa[pilha->nTarefas-1], &pilha->tarefa[index]);
            }
            pilha->tarefa = (Tarefa *) realloc(pilha->tarefa, pilha->nTarefas-1);
            pilha->nTarefas--;
        }
    }
}

void DestruirPilha(Pilha * pilha){
    if(!PilhaVazia(pilha)){
        free(pilha->tarefa);
        InicializaPilha(pilha);
    }
} 

void TarefasDoDiaPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    Data hoje = DataAtual();
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(DataSaoIguais(hoje, copia->data)){
                InserirTarefaPilha(pilha, (*copia));
            }
        }
    }
} 

void TarefasDoMesPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    Data hoje = DataAtual();
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if((hoje.Mes == copia->data.Mes) && (hoje.Ano == copia->data.Ano)){
                InserirTarefaPilha(pilha, (*copia));
            }
        }
    }
} 

void TarefasDoDiaEspecificoPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    Data data;
    printf("Informe o dia deseja ver\n");
    LeData(&data);
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(DataSaoIguais(data, copia->data)){
                InserirTarefaPilha(pilha, (*copia));
            }
        }
    }
} 

void TarefasAteDiaEspecificoPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    Data data;
    printf("Informe ate que dia deseja ver\n");
    LeData(&data);
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(DataEhMenor(copia->data, data)){
                InserirTarefaPilha(pilha, (*copia));
            }
        }
    }
} 

void TarefasIntervaloEspecificoPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    Data dataInicio, dataFim;
    printf("De: \n");
    LeData(&dataInicio);
    printf("Ate: \n");
    LeData(&dataFim);
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(DataEhMenor(copia->data, dataFim) && !DataEhMenor(copia->data, dataInicio) ){
                InserirTarefaPilha(pilha, (*copia));
            }
        }
    }
} 

void TarefasNomeEspecificoPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    char nome[TAMTAREFA];
    printf("Digite o nome que deseja ver: ");
    scanf("%s", nome);
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if( strcmp(nome, copia->Nome) == 0 ) InserirTarefaPilha(pilha, (*copia));
        }
    }
} 

void TarefasTAGEspecificaPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    char tag[TAMTAG];
    printf("Digite o nome que deseja ver: ");
    scanf("%s", tag);
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if( strcmp(tag, copia->Tag) == 0 ) InserirTarefaPilha(pilha, (*copia));
        }
    }
} 

void TarefasPendentesPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(copia->Status == PENDENTE ) InserirTarefaPilha(pilha, (*copia));
        }
    }
}

void TodasAsTarefasPilha(Pilha * pilha, Lista * lista){
    Tarefa * copia;
    if (!Vazia(lista)){
        if(!PilhaVazia(pilha)) DestruirPilha(pilha);
        for (copia  = lista->Primeira; copia != NULL; copia = copia->Proximo){
            InserirTarefaPilha(pilha, (*copia));
        }
    }
} 

int particionarData(Pilha * pilha, int inicio, int ultimo) {
    Data pivot;
    int contador;
    int i = inicio - 1;
    CopiaData(pilha->tarefa[ultimo].data, &pivot);

    for (int contador = inicio; contador < ultimo; contador++) {
        if ( DataEhMenor(pilha->tarefa[contador].data, pivot) ) {
            i++;
            SwapTarefas(&pilha->tarefa[i], &pilha->tarefa[contador]);
        }
    }
    SwapTarefas(&pilha->tarefa[i+1] , &pilha->tarefa[ultimo]);
    return i + 1;
}

int particionarNome(Pilha * pilha, int inicio, int ultimo) {
    char pivot[TAMTAREFA];
    int contador;
    int i = inicio - 1;
    strcpy(pivot, pilha->tarefa[ultimo].Nome);

    for (int contador = inicio; contador < ultimo; contador++) {
        if ( strcmp(pilha->tarefa[contador].Nome, pivot) < 0 ) {
            i++;
            SwapTarefas(&pilha->tarefa[i], &pilha->tarefa[contador]);
        }
    }
    SwapTarefas(&pilha->tarefa[i+1] , &pilha->tarefa[ultimo]);
    return i + 1;
}

int particionarPrioridade(Pilha * pilha, int inicio, int ultimo) {
    int pivot = pilha->tarefa[ultimo].Prioridade;
    int i = inicio - 1;
    int contador;

    for (int contador = inicio; contador < ultimo; contador++) {
        if ( pilha->tarefa[contador].Prioridade < pivot )  {
            
            i++;
            SwapTarefas(&pilha->tarefa[i], &pilha->tarefa[contador]);
        }
    }
    SwapTarefas(&pilha->tarefa[i+1] , &pilha->tarefa[ultimo]);
    return i + 1;
}

int particionarStatus(Pilha * pilha, int inicio, int ultimo) {
    int pivot = pilha->tarefa[ultimo].Status;
    int i = inicio - 1;
    int contador;

    for (int contador = inicio; contador < ultimo; contador++) {
        if ( pilha->tarefa[contador].Status < pivot )  {
            
            i++;
            SwapTarefas(&pilha->tarefa[i], &pilha->tarefa[contador]);
        }
    }
    SwapTarefas(&pilha->tarefa[i+1] , &pilha->tarefa[ultimo]);
    return i + 1;
}

void quickSortPilha(Pilha * pilha, int inicio, int ultimo, int tipo ) {
    int pivot;
    if (inicio < ultimo) {
        if(tipo == DATA) pivot = particionarData(pilha, inicio, ultimo);
        else if (tipo == NOME) pivot = particionarNome(pilha, inicio, ultimo);
        else if (tipo == PRIORIDADE) pivot = particionarPrioridade(pilha, inicio, ultimo);
        else if (tipo == STATUS) pivot = particionarStatus(pilha, inicio, ultimo);
        quickSortPilha(pilha, inicio, pivot - 1, tipo);
        quickSortPilha(pilha, pivot + 1, ultimo, tipo);
    }
}

void insertionData(Pilha * pilha){
    int contador, contador2;
    for (contador = 1; contador < pilha->nTarefas; contador++){
        for (contador2 = contador; contador2 > 0 &&
        DataEhMenor(pilha->tarefa[contador2].data, pilha->tarefa[contador2-1].data); contador2--){ 
            SwapTarefas(&pilha->tarefa[contador2], &pilha->tarefa[contador2-1]);                
        }
    }
} 

void insertionNome(Pilha * pilha){
    int contador, contador2;
    for (contador = 1; contador < pilha->nTarefas; contador++){
        for (contador2 = contador; (contador2 > 0) && (strcmp(pilha->tarefa[contador2].Nome, pilha->tarefa[contador2-1].Nome) < 0); contador2--){
            SwapTarefas(&pilha->tarefa[contador2], &pilha->tarefa[contador2-1]);                
        }
    }
} 

void insertionPrioridade(Pilha * pilha){
    int contador, contador2;
    for (contador = 1; contador < pilha->nTarefas; contador++){
        for (contador2 = contador; (contador2 > 0) && (pilha->tarefa[contador2].Prioridade < pilha->tarefa[contador2-1].Prioridade) ; contador2--){
            SwapTarefas(&pilha->tarefa[contador2], &pilha->tarefa[contador2-1]);                
        }
    }
} 

void insertionStatus(Pilha * pilha){
    int contador, contador2;
    for (contador = 1; contador < pilha->nTarefas; contador++){
        for (contador2 = contador; (contador2 > 0) && (pilha->tarefa[contador2].Status < pilha->tarefa[contador2-1].Status) ; contador2--){
            SwapTarefas(&pilha->tarefa[contador2], &pilha->tarefa[contador2-1]);                
        }
    }    
} 

void insertionSortPilha(Pilha * pilha, int tipo){
    switch (tipo){
        case DATA:
            insertionData(pilha);
            break; 
        case NOME:
            insertionNome(pilha); 
            break;
        case PRIORIDADE:
            insertionPrioridade(pilha); 
        case STATUS:    
            insertionStatus(pilha); 
        default:
            break;
    }
} 

void OrdenarPilha(Pilha * pilha, int tipo){
    if(!PilhaVazia(pilha)){
        if (pilha->nTarefas <= 500) insertionSortPilha(pilha, tipo);
        else quickSortPilha(pilha, 0, pilha->nTarefas-1, tipo);
    }
}

void buscarTarefaPilha(Pilha * pilha){
    int index, flag = 0;
    Tarefa tarefa;
    LeTarefa(&tarefa);
    for ( index = 0; index < pilha->nTarefas; index++){
        if (TarefasSaoIguais(pilha->tarefa[index], tarefa)){
            printf("\n\nTarefa %d\n", index+1);
            PrintarTarefa(tarefa);
            flag=1;
        }
    }
    if(flag == 0) printf("\nTarefa nao encontrada\n");
} 

void buscarDataPilha(Pilha * pilha){
    int index, flag = 0;
    Data data;
    LeData(&data);
    for ( index = 0; index < pilha->nTarefas; index++){
        if (DataSaoIguais(pilha->tarefa[index].data, data)){
            printf("\n\nTarefa %d\n", index+1);
            PrintarTarefa(pilha->tarefa[index]);
            flag=1;
        }
    }
    if(flag == 0) printf("\nTarefa nao encontrada\n");
} 

void buscarNomePilha(Pilha * pilha){
    int index, flag = 0;
    char nome[TAMTAREFA];
    limparBuffer();
    printf("Digite o nome que deseja procurar: ");
    fgets(nome, TAMTAREFA, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    for ( index = 0; index < pilha->nTarefas; index++){
        if (strcmp(nome, pilha->tarefa[index].Nome) == 0){
            printf("\n\nTarefa %d\n", index+1);
            PrintarTarefa(pilha->tarefa[index]);
            flag=1;
        }
    }
    if(flag == 0) printf("\nTarefa com o nome %s nao esta na pilha\n", nome);
} 

void buscarTAGPilha(Pilha * pilha){
    int index, flag = 0;
    char tag[TAMTAG];
    printf("Digite a TAG que deseja procurar: ");
    limparBuffer();
    fgets(tag, TAMTAG, stdin);
    tag[strcspn(tag, "\n")] = '\0';
    for ( index = 0; index < pilha->nTarefas; index++){
        if (strcmp(tag, pilha->tarefa[index].Tag) == 0){
            printf("\n\nTarefa %d\n", index+1);
            PrintarTarefa(pilha->tarefa[index]);
            flag=1;
        }
    }
    if(flag == 0) printf("\nTarefa com a tag %s nao esta na pilha\n", tag);
} 

void buscarPilha(Pilha * pilha, int tipo){
    switch (tipo){
        case TAG:
            buscarTAGPilha(pilha);
            break;

        case DATA: 
            buscarDataPilha(pilha);
            break;

        case NOME:
            buscarNomePilha(pilha);
            break;

        case TAREFA:
            buscarTarefaPilha(pilha);
            break;
    }
} 
