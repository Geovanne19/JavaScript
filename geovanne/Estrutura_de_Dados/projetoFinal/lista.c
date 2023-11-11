#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

void InicializaLista(Lista *lista){
    lista->Primeira = NULL;
    lista->Tam = 0;
    lista->Ultima = NULL;
}

int Vazia(Lista *lista){
    return (lista->Primeira == NULL && lista->Ultima == NULL && lista->Tam == 0);
} 

int UmaTarefa(Lista * lista){
    return (lista->Primeira == lista->Ultima);
} 


void InserirInicioLista(Tarefa tarefa, Lista *lista){
    Tarefa *NovoNo=NULL;
    NovoNo = (Tarefa*) malloc(sizeof(Tarefa));
    if (NovoNo == NULL) printf("Nao foi possivel alocar a memoria.\n");
    else {
        CopiaTarefa(tarefa, NovoNo);
        NovoNo->Anterior=NULL;
        if (Vazia(lista)){
            NovoNo->Proximo =NULL;
            lista->Primeira=NovoNo;
            lista->Ultima=NovoNo;
        }
        else {
            NovoNo->Proximo = lista->Primeira;    
            lista->Primeira->Anterior = NovoNo;
            lista->Primeira = NovoNo;
        }
        lista->Tam++;
    }
} 

void RemoverFinal(Lista *lista){
    Tarefa * copia;
    if (Vazia(lista)) printf("lista vazia\n");
    else {
        if (UmaTarefa(lista)) {
            free(lista->Primeira);
            InicializaLista(lista);
        }
        else {
            copia = lista->Ultima;
            lista->Ultima = lista->Ultima->Anterior;
            lista->Ultima->Proximo = NULL;
            free(copia);
        }
    }  
} 

void RemoverInicio(Lista *lista){
    Tarefa * copia;
    if (Vazia(lista)) printf("lista vazia\n");
    else {
        if (UmaTarefa(lista)) {
            free(lista->Primeira);
            InicializaLista(lista);
        }
        else {
            copia = lista->Primeira;
            lista->Primeira = lista->Primeira->Proximo;
            lista->Primeira->Anterior= NULL;
            free(copia);
        }
    }  
} 

void Remover(Lista *lista, Tarefa tarefa){
    Tarefa * copia;
    for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo){
        if(TarefasSaoIguais(tarefa, (*copia))){
            if(copia == lista->Primeira){
                RemoverInicio(lista);
                break;
            }
            else if (copia == lista->Ultima){
                RemoverFinal(lista);
                break;
            }
            else{
                copia->Anterior->Proximo = copia->Proximo;
                copia->Proximo->Anterior = copia->Anterior;
                free(copia);
                break;
            }
        }
    } 
}  

void Destruir(Lista * lista){
    Tarefa * copia;
    for (copia = lista->Ultima; copia != NULL; copia = lista->Ultima) RemoverFinal(lista);
} 

void Printar(Lista * lista){
    Tarefa * copia;
    if(Vazia(lista)) printf("Lista vazia\n");
    else for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo) PrintarTarefa(*copia); 
} 

void PrintarReduzido(Lista * lista){
    Tarefa * copia;
    if(Vazia(lista)){
        printf(RED"\n\n\n\n\n                  Lista vazia.\n             Adicione uma tarefa!\n\n\n\n\n\n\n"RESET);
        printf("------------------------------------------------\n");
    }
    else for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo) PrintarTarefaReduzido(*copia);     
}    

void buscarTarefaLista(Lista * lista){
    Tarefa * copia, buscada;
    int flag = 0;
    LeTarefa(&buscada);
    if(!Vazia(lista)){ 
        printf("\n");
        for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(TarefasSaoIguais(buscada, *copia)){
                PrintarTarefa(*copia); 
                flag = 1;
            }
        }
    }
    if(flag == 0) printf("Tarefa nao encontrada\n");
} 

void buscarDataLista(Lista * lista){
    Tarefa * copia;
    Data buscada;
    int flag = 0;
    LeData(&buscada);
    if(!Vazia(lista)){
        printf("\n");
        for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(DataSaoIguais(copia->data, buscada)){
                PrintarTarefa(*copia); 
                flag = 1;
            }
        }
    }
    if(flag == 0) printf("Tarefa nao encontrada\n");
} 

void buscarNomeLista(Lista * lista){
    Tarefa * copia;
    int flag = 0;
    char nome[TAMTAREFA];
    limparBuffer();
    printf("Digite o nome que deseja procurar: ");
    fgets(nome, TAMTAREFA, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    if(!Vazia(lista)){ 
        printf("\n");
        for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(strcmp(copia->Nome, nome) == 0){
                PrintarTarefa(*copia); 
                flag = 1;
            }
        }
    }
    if(flag == 0) printf("Tarefa com o nome %s nao esta na lista\n", nome);
} 

void buscarTAGLista(Lista * lista){
    Tarefa * copia;
    int flag = 0;
    char tag[TAMTAG];
    limparBuffer();
    printf("Digite a TAG que deseja procurar: ");
    fgets(tag, TAMTAG, stdin);
    tag[strcspn(tag, "\n")] = '\0';
    if(!Vazia(lista)){ 
        printf("\n");
        for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo){
            if(strcmp(copia->Tag, tag) == 0){
                PrintarTarefa(*copia); 
                flag = 1;
            }
        }
    }
    if(flag == 0) printf("\nTarefa com a tag %s nao esta na lista\n", tag);
} 

void buscarLista(Lista * lista, int tipo){
    switch (tipo){
        case TAG:
            buscarTAGLista(lista);
            break;

        case DATA: 
            buscarDataLista(lista);
            break;

        case NOME:
            buscarNomeLista(lista);
            break;

        case TAREFA:
            buscarTarefaLista(lista);
            break;
    }
} 

void marcarComoFeitaLista(Lista * lista, Tarefa tarefa){
    Tarefa * copia;
    for (copia = lista->Primeira; copia != NULL; copia = copia->Proximo){
        if (TarefasSaoIguais(*copia, tarefa)){
            copia->Status = FEITA;
            break;
        }
    }
}