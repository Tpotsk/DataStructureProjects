#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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

    int min = 100, max=999;
    int rnum;
    srand(time(NULL));

    int controle = 1;
    char input_servico;

    cabecalho();
    menu_opcoes();
    while(controle){
        do{
            input_servico = getchar();
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
            default:
                printf("Digite uma opção válida!\n");
        }
    }
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
