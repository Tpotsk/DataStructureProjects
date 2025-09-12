#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "FILA.h"

void ExibirFilaDump(Fila *f){
    Nos *aux = f->ini;
    Pet t;

    while(aux != NULL){
        t = aux->info;
        printf("%d - %s - %s - %d/%d/%d - %d\n", t.id, t.nome, t.especie, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, t.idade);
        aux = aux->prox;
    }
}

int main(){

    Fila *fila_normal = InicializarFila();
    Fila *fila_emergente = InicializarFila();

    int min = 100, max=999;
    int rnum;
    srand(time(NULL));


    //data dump
    Pet dump_pet;
    Fila *fila_dump = InicializarFila();

    for(int i = 0; i < 10; i++){
        dump_pet.id = min + rand() % (max - min + 1);
        strcpy(dump_pet.nome, "Lorem Ipsum");
        strcpy(dump_pet.especie, "Dolor Astmet");
        dump_pet.data_nasc.dia = (rand() % 30) + 1;
        dump_pet.data_nasc.mes = (rand() % 11) + 1;
        dump_pet.data_nasc.ano = 2010 + rand() % 10;
        dump_pet.idade = 2025 - dump_pet.data_nasc.ano;

        InserirNaFila(fila_dump, dump_pet);
    }

    ExibirFilaDump(fila_dump);
}
