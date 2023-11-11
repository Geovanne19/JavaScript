#include <stdio.h>
#include <string.h>
#include "tarefa.h"

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

void limparBuffer(){
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF);
}

void LeTarefa(Tarefa * tarefa){
    limparBuffer();
    printf("\nAdicione a nova tarefa\n");
    printf("------------------------------------------------\n");
    printf("Nome: ");
    fgets(tarefa->Nome, TAMTAREFA, stdin);
    tarefa->Nome[strcspn(tarefa->Nome, "\n")] = '\0';

    printf("\nDescricao: ");
    fgets(tarefa->Descricao, TAMDESCRICAO, stdin);
    tarefa->Descricao[strcspn(tarefa->Descricao, "\n")] = '\0';

    printf("\nTAG: ");
    fgets(tarefa->Tag, TAMTAG, stdin);
    tarefa->Tag[strcspn(tarefa->Tag, "\n")] = '\0';

    printf("\nPrioridade\n([1] - Alta [2] - Media [3] - Baixa [4] - Nenhuma)\n");
    printf("Sua escolha: ");
    scanf("%d", &(tarefa->Prioridade));
    printf("\nData\n");
    LeData(&(tarefa->data));
    tarefa->Status = PENDENTE;

} 

void CopiaTarefa(Tarefa tarefaOrigem, Tarefa * tarefaDestino){
    strcpy( tarefaDestino->Nome, tarefaOrigem.Nome);
    strcpy( tarefaDestino->Descricao, tarefaOrigem.Descricao);
    strcpy( tarefaDestino->Tag, tarefaOrigem.Tag);
    tarefaDestino->Prioridade = tarefaOrigem.Prioridade;
    tarefaDestino->Status = tarefaOrigem.Status;
    CopiaData(tarefaOrigem.data, &(tarefaDestino->data));
} 

void printarPrioridade(Tarefa tarefa){
    if (tarefa.Prioridade == ALTA) printf(RED"!!!"RESET); 
    else if (tarefa.Prioridade == MEDIA) printf(YELLOW"!! "RESET); 
    else if (tarefa.Prioridade == BAIXA) printf(BLUE"!  "RESET); 
    else printf(" - ");
} 

void printarStatus(Tarefa tarefa){
    if (tarefa.Status == FEITA) printf(GREEN"\u25A0 "RESET);
    else printf(ORANGE"\u25A1 "RESET);
} 

void PrintarTarefa(Tarefa tarefa){
    printf("%s\t#%s\t", tarefa.Nome, tarefa.Tag);
    printaData(tarefa.data);
    printarStatus(tarefa);
    printarPrioridade(tarefa);
    printf("---------------------------------------------------\n");

    printf("%s\n\n\n\n", tarefa.Descricao);
}

void PrintarTarefaReduzido(Tarefa tarefa){
    printarStatus(tarefa);
    printf("|");
    printarPrioridade(tarefa);
    printf("| %s\t", tarefa.Nome);
    printaData(tarefa.data);
    printf("------------------------------------------------\n");
    

}

int TarefasSaoIguais(Tarefa tarefa1, Tarefa tarefa2){
    return(
        (strcmp(tarefa1.Nome, tarefa2.Nome) == 0) &&
        (strcmp(tarefa1.Tag, tarefa2.Tag) == 0) &&
        (strcmp(tarefa1.Descricao, tarefa2.Descricao) == 0) &&
        tarefa1.Prioridade == tarefa2.Prioridade &&
        tarefa1.Status == tarefa2.Status &&
        DataSaoIguais(tarefa1.data, tarefa2.data)
    );
}

void SwapTarefas(Tarefa * referencia1, Tarefa * referencia2){
    Tarefa copia;
    CopiaTarefa((*referencia1), &copia);
    CopiaTarefa((*referencia2), referencia1);
    CopiaTarefa( copia, referencia2);
} 
