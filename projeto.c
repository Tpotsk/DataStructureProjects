#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "FILA.h"

void ExibirFila(Fila *f){
    Nos *aux = f->ini;
    Pet t;

    while(aux != NULL){
        t = aux->info;
        printf("| %3d | %-50s | %-20s | %2d/%2d/%4d | %2d |\n", t.id, t.nome, t.especie, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, t.idade);
        aux = aux->prox;
    }
}

void ExibirPetDump(Pet t){
    printf("%d - %s - %s - %d/%d/%d - %d\n", t.id, t.nome, t.especie, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, t.idade);
}

Pet *BuscarIDNaFila(Fila *f, int id){
    if(FilaVazia(f)) return NULL;

    Nos *aux = f->ini;

    while(aux != NULL && aux->info.id != id){
        aux = aux->prox;
    }

    if(aux == NULL) return NULL;

    return &aux->info;
}

Fila *BuscarNomeNaFila(Fila *f, char *nome){
    if(FilaVazia(f)) return NULL;

    Nos *aux = f->ini;
    Fila *resultado = InicializarFila();

    while(aux != NULL){
        if(strcmp(aux->info.nome, nome) == 0){
            InserirNaFila(resultado, aux->info);
        }
        aux = aux->prox;
    }

    if(FilaVazia(resultado)){
        LiberarFila(resultado);
        return NULL;
    }

    return resultado;
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
    rnum = 100;

    for(int i = 0; i < 10; i++){
        while(BuscarIDNaFila(fila_dump, rnum) != NULL){
            rnum = min + rand() % (max - min + 1);
        }

        dump_pet.id = rnum;
        strcpy(dump_pet.nome, "Lorem Ipsum");
        strcpy(dump_pet.especie, "Dolor Astmet");
        dump_pet.data_nasc.dia = (rand() % 30) + 1;
        dump_pet.data_nasc.mes = (rand() % 11) + 1;
        dump_pet.data_nasc.ano = 2010 + rand() % 10;
        dump_pet.idade = 2025 - dump_pet.data_nasc.ano;

        InserirNaFila(fila_dump, dump_pet);
    }

    ExibirFila(fila_dump);

    Fila *teste_busca = BuscarNomeNaFila(fila_dump, "Lorem Ipsum");

    printf("\n\nresultado da busca por nome\n");
    ExibirFila(teste_busca);

    printf("\n\nresultado da busca por id\n");
    Pet *dump_pet2 = BuscarIDNaFila(fila_dump, 100);
    ExibirPetDump(*dump_pet2);
}
