#include <stdio.h>
#define JANEIRO 1
#define FEVEREIRO 2
#define MARCO 3
#define ABRIL 4 
#define MAIO 5
#define JUNHO 6
#define JULHO 7
#define AGOSTO 8
#define SETEMBRO 9
#define OUTUBRO 10
#define NOVEMBRO 11
#define DEZEMBRO 12
#define MINUTO 60
#define TRABALHAR 1
#define DESCANSAR 2

/*
Criado por:
Luis Felipe Baptista da Silva - 202200536 - UFG
Geovanne Rodrigues Pinheiro - 202203979 - UFG
*/

typedef struct {
    int Dia;
    int Mes;
    int Ano;
}Data;

int Bissexto(Data data); 
Data DataAtual(); 
int DataValida(Data data); 
void LeData(Data * data); 
void printaData(Data data);
void CopiaData(Data dataOrigem, Data * dataDestino); 
int tempoValido(int minutosTrabalho, int minutosDescanso, int Nrepeticoes); 
void Cronometro(int Tempo, int Configuracao);
void Pomodoro(); 
int DataSaoIguais(Data data1, Data data2); 
int DataEhMenor(Data menor, Data maior); 
