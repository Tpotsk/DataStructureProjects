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

// Funções lógicas
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

// Funções visuais
void tabelaLinha(char prim, char meio, char ult, int largura){
    printf("\n%c", prim);
    for(int i = 0; i < largura - 2; i++) printf("%c", meio);
    printf("%c\n", ult);
}

void sequenciaDeChar(char prim, char meio, char ult, int largura){
    printf("%c", prim);
    for(int i = 0; i < largura - 2; i++) printf("%c", meio);
    printf("%c", ult);
}

void cabecalho(){
    tabelaLinha(0xC9, 0xCD, 0xBB, 69);
    printf("%c   "NEGRITO"Sistema de Registro Veterinario ~ Bem vindo(a)"RESET"                  %c", 0xBA, 0xBA);
    tabelaLinha(0xC8, 0xCD, 0xBC, 69);
}

void MenuOpcoes(){
    tabelaLinha(0xC9, 0xCD, 0xBB, 69);
    printf("%c "NEGRITO"Servicos:"RESET"                                                         %c", 0xBA, 0xBA);
    tabelaLinha(0xCC, 0xCD, 0xB9, 69);
    printf("%c           "CIANO"( 1 )"RESET" Inserir pet na fila de atendimento                %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 2 )"RESET" Atender pet (remover da fila de atendimento)      %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 3 )"RESET" Buscar pet                                        %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 4 )"RESET" Imprimir fila de atendimento                      %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 5 )"RESET" Proximo atendimento                               %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 6 )"RESET" Pets ja atendidos                                 %c", 0xBA, 0xBA);
    tabelaLinha(0xBA, ' ', 0xBA, 69);
    printf("%c           "VERMELHO"( 7 )"RESET" Finalizar sistema                                 %c", 0xBA, 0xBA);
    tabelaLinha(0xC8, 0xCD, 0xBC, 69);
    printf("\nPressione o ID do servico desejado: ");
}

void ExibirFila(Fila *f){
    if(FilaVazia(f)) return;

    Nos *aux = f->ini;
    Pet t;
    char *temp;

    sequenciaDeChar(0xDA, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 23);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 6);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 13);
    sequenciaDeChar(0xC2, 0xC4, 0xBF, 14);
    printf("\n%c "NEGRITO"ID"RESET"   %c "NEGRITO"NOME"RESET"                                               %c "NEGRITO"ESPECIE"RESET"              %c "NEGRITO"IDD"RESET" %c "NEGRITO"NASCIMENTO"RESET" %c "NEGRITO"PRIORIDADE"RESET" %c\n", 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3);

    while(aux != NULL){
        t = aux->info;
        temp = (t.prioridade == 1)? VERMELHO"Emergente ": CIANO"Normal    ";

        sequenciaDeChar(0xC3, 0xC4, 0xC4, 7);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 23);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 6);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 13);
        sequenciaDeChar(0xC5, 0xC4, 0xB4, 14);

        printf("\n%c %3d  %c %-50s %c %-20s %c %-3d %c %2d/%2d/%4d %c %-s"RESET" %c\n", 0xB3, t.id, 0xB3, t.nome, 0xB3, t.especie, 0xB3, t.idade, 0xB3, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, 0xB3, temp, 0xB3);
        aux = aux->prox;
    }

    sequenciaDeChar(0xC0, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 23);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 6);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 13);
    sequenciaDeChar(0xC1, 0xC4, 0xD9, 14);
}

int main(){
    Fila *fila_normal = InicializarFila();
    Fila *fila_emergente = InicializarFila();
    Fila *fila_antendidos = InicializarFila();

    int controle = 1;
    char input_servico;

    int id_busca;
    char nome_busca[50];

    int min = 100, max=999;
    int rnum;
    srand(time(NULL));

    //data dump
    Pet dump_pet;
    rnum = 100;

    for(int i = 0; i < 10; i++){
        while(BuscarIDNaFila(fila_emergente, rnum) != NULL || BuscarIDNaFila(fila_normal, rnum) != NULL || BuscarIDNaFila(fila_antendidos, rnum) != NULL){
            rnum = min + rand() % (max - min + 1);
        }

        dump_pet.id = rnum;
        strcpy(dump_pet.nome, "Lorem");
        strcpy(dump_pet.especie, "Dolor Astmet");
        dump_pet.data_nasc.dia = (rand() % 30) + 1;
        dump_pet.data_nasc.mes = (rand() % 11) + 1;
        dump_pet.data_nasc.ano = 2010 + rand() % 10;
        dump_pet.idade = 2025 - dump_pet.data_nasc.ano;
        dump_pet.prioridade = rand() % 2;

        if(dump_pet.prioridade == 1){
            InserirNaFila(fila_emergente, dump_pet);
        } else {
            InserirNaFila(fila_normal, dump_pet);
        }
    }

    while(controle){
        cabecalho();
        MenuOpcoes();

        do{
            input_servico = getch();
            controle = input_servico - '0';
            printf("%d", controle);
        }while(controle < 1 || controle > 7);

        switch(controle){
            case 1:
                system("cls");
                printf("serviço 1\n");
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                printf("serviço 2\n");
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                cabecalho();

                printf("\nRealizar busca atraves do: \n\t"CIANO"( 1 )"NEGRITO" ID\n\t"CIANO"( 2 )"NEGRITO" NOME\n\n\t"VERMELHO"( OUTRO )"NEGRITO" CANCELAR"RESET"\n\n> ");

                input_servico = getch();
                controle = input_servico - '0';


                system("cls");
                cabecalho();

                if(controle == 1){
                    printf("\nInsira o ID (3 digitos numericos, entre 100 e 999) que deseja pesquisar: ");
                    scanf("%d", &id_busca);

                    while(id_busca < 100 || id_busca > 999){
                        printf("\nID inserido inválido. Insira novamente: ");
                        scanf("%d", &id_busca);
                    }

                    system("cls");
                    cabecalho();

                    if(BuscarIDNaFila(fila_normal, id_busca) != NULL){
                        ExibirPet(*BuscarIDNaFila(fila_normal, id_busca));
                    } else if(BuscarIDNaFila(fila_emergente, id_busca) != NULL){
                        ExibirPet(*BuscarIDNaFila(fila_emergente, id_busca));
                    } else if(BuscarIDNaFila(fila_antendidos, id_busca) != NULL){
                        ExibirPet(*BuscarIDNaFila(fila_antendidos, id_busca));
                    } else {
                        printf("\nNenhum resultado foi encontrado.");
                    }
                }

                if(controle == 2){
                    printf("\nInsira o Nome que deseja pesquisar: ");
                    scanf("%s", &nome_busca);

                    if(BuscarNomeNaFila(fila_normal, nome_busca) != NULL){
                        ExibirFila(BuscarNomeNaFila(fila_normal, nome_busca));
                        printf("\n");
                    }

                    if(BuscarNomeNaFila(fila_emergente, nome_busca) != NULL){
                        ExibirFila(BuscarNomeNaFila(fila_emergente, nome_busca));
                        printf("\n");
                    }

                    if(BuscarNomeNaFila(fila_antendidos, nome_busca) != NULL){
                        ExibirFila(BuscarNomeNaFila(fila_antendidos, nome_busca));
                        printf("\n");
                    }
                }

                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                cabecalho();

                if(FilaVazia(fila_emergente) && FilaVazia(fila_normal)){
                    printf("\nNao ha pets nas filas de atendimento.\n\n");
                } else {
                    ExibirFila(fila_emergente);
                    printf("\n");
                    ExibirFila(fila_normal);
                    printf("\n\n");
                }

                system("pause");
                system("cls");
                break;

            case 5:
                system("cls");
                printf("serviço 5\n");
                system("pause");
                system("cls");
                break;

            case 6:
                system("cls");
                cabecalho();

                if(FilaVazia(fila_antendidos)){
                    printf("\nNenhum pet foi atendido ate o momento.\n\n");
                } else {
                    ExibirFila(fila_antendidos);
                }

                system("pause");
                system("cls");
                break;

            case 7:
                controle = 0;
                break;
        }
    }
}
