#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "FILA.h"

#define NEGRITO "\033[1;37m"
#define AZUL "\033[1;34m"
#define VERDE "\033[1;32m"
#define VERMELHO "\033[1;31m"
#define CIANO "\033[1;36m"
#define RESET "\033[0m"

void ExibirFila(Fila *f){
    Nos *aux = f->ini;
    Pet t;

    while(aux != NULL){
        t = aux->info;
        printf("| %3d | %-50s | %-20s | %2d | %2d/%2d/%4d | %d |\n", t.id, t.nome, t.especie, t.idade, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, t.prioridade);
        aux = aux->prox;
    }
}

void ExibirPet(Pet t){
    printf("%d - %s - %s - %d - %d/%d/%d - %d \n", t.id, t.nome, t.especie, t.idade, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, t.prioridade);
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

void cabecalho(){
    printf(RESET " ___________________________________________________________________\n");
    printf("|   " CIANO "Sistema de Registro Veterinario ~ Bem vindo(a)" RESET "                  |\n");
    printf("|___________________________________________________________________|");
}

void menu_opcoes(){
    printf(RESET "\n ___________________________________________________________________");
    printf("\n| Serviços:                                                         |\n");
    printf("|           "CIANO"( 1 )"RESET" Inserir pet na fila de atendimento                |\n");
    printf("|           "CIANO"( 2 )"RESET" Atender pet (remover da fila de atendimento)      |\n");
    printf("|           "CIANO"( 3 )"RESET" Buscar pet                                        |\n");
    printf("|           "CIANO"( 4 )"RESET" Imprimir fila de atendimento                      |\n");
    printf("|           "CIANO"( 5 )"RESET" Proximo atendimento                               |\n");
    printf("|           "CIANO"( 6 )"RESET" Pets ja atendidos                                 |\n");
    printf("|                                                                   |\n");
    printf("|           "VERMELHO"( 5 )"RESET" Finalizar sistema                                 |\n");
    printf("|                                                                   |\n");
    printf("| pressione o ID do servico desejado                                |\n");
    printf("|___________________________________________________________________|");
}

int main(){
    Fila *fila_normal = InicializarFila();
    Fila *fila_emergente = InicializarFila();
    Fila *fila_antendidos = InicializarFila();

    int controle = 1;
    char input_servico;

    int min = 100, max=999;
    int rnum;
    srand(time(NULL));

    while(controle){
        do{
            input_servico = getch();
            controle = input_servico - '0';
            printf("%d", controle);
        }while(controle < 0 || controle > 7);

        switch(controle){
            case 1:
                printf("serviço 1\n");
                break;

            case 2:
                printf("serviço 2\n");
                break;

            case 3:
                printf("serviço 3\n");
                break;

            case 4:
                printf("serviço 4\n");
                break;

            case 5:
                printf("serviço 5\n");
                break;

            case 6:
                printf("serviço 6\n");
                break;

            case 7:
                controle = 0;
                break;
        }
    }

    /*
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
        dump_pet.prioridade = rand() % 2;

        InserirNaFila(fila_dump, dump_pet);
    }
    */
}
