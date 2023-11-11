#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tempo.h"
#include <unistd.h>

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

int Bissexto(Data data){
    return ((data.Ano%4 == 0 && data.Ano%100 != 0) || data.Ano%400 == 0);
} 

Data DataAtual(){
    Data data;
    timer_t TempoAtual = time(&TempoAtual);
    struct tm * tempoLocal = localtime(&TempoAtual);
    data.Dia = tempoLocal->tm_mday;
    data.Mes = tempoLocal->tm_mon + 1;
    data.Ano = tempoLocal->tm_year + 1900;
    return data;
} 

int DataValida(Data data){
    Data Atual = DataAtual();
    if(data.Mes < 1 
    || data.Mes > 12
    || data.Dia < 1
    || data.Dia > 31
    || data.Ano < Atual.Ano
    || ((data.Ano == Atual.Ano) && (data.Mes < Atual.Mes))
    || ((data.Ano == Atual.Ano) && (data.Mes == Atual.Mes) && (data.Dia < Atual.Dia))
    || (((data.Mes == ABRIL) || (data.Mes == JUNHO) 
        || (data.Mes == SETEMBRO) || (data.Mes == NOVEMBRO)) && (data.Dia > 30))
    || ((data.Mes == FEVEREIRO) && (data.Dia > 29))
    ) return 0;    
    else{
        if (Bissexto(data)) return 1;
        else{
            if((data.Mes == FEVEREIRO) && (data.Dia > 28)) return 0;
            else return 1;
        }            
    }
} 

void LeData(Data * data){
    while (1){
        printf("Dia: ");
        scanf("%d", &data->Dia);
        printf("Mes: ");
        scanf("%d", &data->Mes);
        printf("Ano: ");
        scanf("%d", &data->Ano);
        if (DataValida((*data))) break;
        else{
            printf("Data invalida!\nTente novamente\n\n");
        }
    }
} 

void printaData(Data data){
    printf("%02d/%02d/%04d\n", data.Dia, data.Mes, data.Ano);
} 

void CopiaData(Data dataOrigem, Data * dataDestino){
    dataDestino->Dia = dataOrigem.Dia;
    dataDestino->Mes = dataOrigem.Mes;
    dataDestino->Ano = dataOrigem.Ano;
} 

int tempoValido(int minutosTrabalho, int minutosDescanso, int Nrepeticoes){
    return(minutosTrabalho > 0 && minutosDescanso > 0 && Nrepeticoes > 0);
} 

void Cronometro(int Tempo, int Configuracao){
    int horas=0, minutos=0, segundos=0, referencia;
    for (referencia = 0; referencia < Tempo; referencia++){
        sleep(1);
        system("clear");
        segundos++;
        if (segundos == 60){
            segundos = 0;
            minutos++;
        }
        if(minutos == 60){
            minutos = 0;
            horas++;
        }
        if (Configuracao == TRABALHAR) printf("Trabalhe!\n\n");
        else if (Configuracao == DESCANSAR)printf("Descanse!\n\n");        
        printf("%02d:%02d:%02d\n", horas, minutos, segundos);
        fflush(stdout);
    }
}

void Pomodoro(){
    int MinutosTrabalho, MinutosDescanso, Nrepeticoes = 0, Contador;
    while(1){
        printf("Defina quantos minutos voce trabalhara: ");
        scanf("%d", &MinutosTrabalho);
        printf("Defina quantos minutos voce descansara: ");
        scanf("%d", &MinutosDescanso);
        printf("Quantas vezes voce pretente fazer essa rotina hoje: ");
        scanf("%d", &Nrepeticoes);
        if(!tempoValido(MinutosTrabalho, MinutosDescanso, Nrepeticoes))
        printf("\nTempo invalido!\nTente novamente\n");
        else break;
    }
    printf("\n");
    for(Contador = 0; Contador < Nrepeticoes; Contador++){
        Cronometro(MinutosTrabalho*MINUTO, TRABALHAR);
        Cronometro(MinutosDescanso*MINUTO, DESCANSAR);
    }
    printf("\n\7Parabens, voce completou sua atividade\n");
} 

int DataSaoIguais(Data data1, Data data2){
    return (data1.Ano == data2.Ano && data1.Mes == data2.Mes && data1.Dia == data2.Dia);
} 

int DataEhMenor(Data menor, Data maior){
    int flag=0;
    if(menor.Ano < maior.Ano) flag = 1;
    else if (menor.Ano == maior.Ano){
        if (menor.Mes < maior.Mes) flag = 1;
        else if (menor.Mes == maior.Mes){
            if (menor.Dia < maior.Dia) flag = 1;
        }        
    }
    return flag;
} 

