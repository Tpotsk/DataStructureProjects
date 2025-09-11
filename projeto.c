#include <stdio.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct pet{
    int id;
    char nome[50];
    char especie[20];
    int idade;
    Data data_nasc;
    int prioridade;
}Pet;

typedef struct fila{
    Pet *ini;
    Pet *fim;
}Fila;

int main() {
    Fila *normal;
    Fila *emergencia;
}
