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
        dump_pet.prioridade = rand() % 2;

        InserirNaFila(fila_dump, dump_pet);
    }

    ExibirFila(fila_dump);

    Fila *teste_busca = BuscarNomeNaFila(fila_dump, "Lorem Ipsum");

    printf("\n\nresultado da busca por nome\n");
    ExibirFila(teste_busca);

    printf("\n\nresultado da busca por id\n");
    Pet *dump_pet2 = BuscarIDNaFila(fila_dump, 100);
    ExibirPet(*dump_pet2);
}


//juntar depois
void PrintAtenderPet(Fila *Emergencia, Fila *Normal, Fila *Atendidos)
{
    if(!FilaVazia(Emergencia))
    { // prioridade para emergência
        Pet atendido_e = Emergencia->ini->info;
        printf("\nAtendendo (EMERGÊNCIA):\n");
        ExibirPet(atendido_e);
    }
    else if(!FilaVazia(Normal))
    {//normais logo em seguida, caso não tenham emergencias
        Pet atendido_n = Normal->ini->info;
        printf("\nAtendendo (NORMAL):\n");
        ExibirPet(atendido_n);
    }
    else
    {
        printf("\nNenhum pet na fila!\n");
    }
}


void AtenderPet(Fila *Emergencia, Fila *Normal, Fila *Atendidos)
{
    if(!FilaVazia(Emergencia))
    { // prioridade para emergência
        Pet atendido_e = RemoverDaFila(Emergencia);
        InserirNaFila(Atendidos, atendido_e); // salva no histórico
    }
    else if(!FilaVazia(Normal))
    {//normais logo em seguida, caso não tenham emergencias
        Pet atendido_n = RemoverDaFila(Normal);
        InserirNaFila(Atendidos, atendido_n); // salva no histórico
    }
}


void ImprimirRelatorio(Fila *Emergencia, Fila *Normal)
{
    printf("\n--- FILA EMERGÊNCIA ---\n");
    ExibirFila(Emergencia);

    printf("\n--- FILA NORMAL ---\n");
    ExibirFila(Normal);
}


void ProximoAtendido(Fila *Emergencia, Fila *Normal)
{
    if(!FilaVazia(Emergencia))
    {
        ExibirPet(Emergencia->ini->info);
    }

    else if (!FilaVazia(Normal))
    {
        ExibirPet(Normal->ini->info);
    }

    else
    {
        printf("\nNenhum Pet na fila\n");
    }
}


void PetsAtendidos(Fila *Atendidos)
{
    printf("\nPets atendidos\n");
    ExibirFila(Atendidos);
}


int IdAleatorio(Fila *Emergencia, Fila *Normal)
{
    int min = 100;//mudar depois
    int max = 999;

    int gerado;
    int existe;

    do {
        gerado = min + rand() % (max - min + 1); // Gera um número aleatório dentro do intervalo

        Pet *encontrado_E = BuscarIDNaFila(Emergencia, gerado); // Verifica se o ID já existe na fila de emergência

        Pet *encontrado_N = BuscarIDNaFila(Normal, gerado); // Verifica se o ID já existe na fila normal

        // Se não foi encontrado em nenhuma das filas
        if (encontrado_E == NULL && encontrado_N == NULL) {
            existe = 0; // ID é único, sai do loop
        } else {
            existe = 1; // ID já existe, volta para o loop
        }

    } while (existe);

    return gerado;
}
