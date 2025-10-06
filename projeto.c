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

// Fun��es visuais
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
    if(f == NULL || FilaVazia(f)) return;

    Nos *aux = f->ini;
    Pet t;
    char *temp;

    sequenciaDeChar(0xDA, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 33);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 6);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 13);
    sequenciaDeChar(0xC2, 0xC4, 0xBF, 14);
    printf("\n%c "NEGRITO"ID"RESET"   %c "NEGRITO"NOME"RESET"                                               %c "NEGRITO"ESPECIE"RESET"                        %c "NEGRITO"IDD"RESET" %c "NEGRITO"NASCIMENTO"RESET" %c "NEGRITO"PRIORIDADE"RESET" %c\n", 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3);

    while(aux != NULL){
        t = aux->info;
        temp = (t.prioridade == 1)? VERMELHO"Emergente ": CIANO"Normal    ";

        sequenciaDeChar(0xC3, 0xC4, 0xC4, 7);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 33);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 6);
        sequenciaDeChar(0xC5, 0xC4, 0xC4, 13);
        sequenciaDeChar(0xC5, 0xC4, 0xB4, 14);

        printf("\n%c %3d  %c %-50s %c %-30s %c %-3d %c %2d/%2d/%4d %c %-s"RESET" %c\n", 0xB3, t.id, 0xB3, t.nome, 0xB3, t.especie, 0xB3, t.idade, 0xB3, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, 0xB3, temp, 0xB3);
        aux = aux->prox;
    }

    sequenciaDeChar(0xC0, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 33);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 6);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 13);
    sequenciaDeChar(0xC1, 0xC4, 0xD9, 14);
}

void ExibirPet(Pet t){
    char *temp = (t.prioridade == 1)? VERMELHO"Emergente                              ": CIANO"Normal                                 ";

    sequenciaDeChar(0xDA, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 42);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 5);
    sequenciaDeChar(0xC2, 0xC4, 0xBF, 7);

    printf("\n%c"NEGRITO" ATENDIMENTO "RESET"%c %s"RESET" %c"NEGRITO" ID "RESET"%c %d %c\n", 0xB3, 0xB3, temp, 0xB3, 0xB3, t.id, 0xB3);

    sequenciaDeChar(0xC3, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 42);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 5);
    sequenciaDeChar(0xC1, 0xC4, 0xB4, 7);

    printf("\n%c"NEGRITO"        NOME "RESET"%c %-50s"RESET" %c\n", 0xB3, 0xB3, t.nome, 0xB3);

    sequenciaDeChar(0xC3, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC5, 0xC4, 0xB4, 54);

    printf("\n%c"NEGRITO"     ESPECIE "RESET"%c %-50s"RESET" %c\n", 0xB3, 0xB3, t.especie, 0xB3);

    sequenciaDeChar(0xC3, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC5, 0xC4, 0xC2, 22);
    sequenciaDeChar(0xC4, 0xC4, 0xC2, 8);
    sequenciaDeChar(0xC4, 0xC4, 0xB4, 24);

    printf("\n%c"NEGRITO"  NASCIMENTO "RESET"%c %2d/%2d/%4d         %c"NEGRITO" IDADE "RESET"%c %-2d ANOS               %c\n",0xB3, 0xB3, t.data_nasc.dia, t.data_nasc.mes, t.data_nasc.ano, 0xB3, 0xB3, t.idade, 0xB3);

    sequenciaDeChar(0xC0, 0xC4, 0xC1, 15);
    sequenciaDeChar(0xC4, 0xC4, 0xC1, 21);
    sequenciaDeChar(0xC4, 0xC4, 0xC1, 8);
    sequenciaDeChar(0xC4, 0xC4, 0xD9, 24);

    printf("\n");
}

// Fun��es l�gicas
// o retorno da fun��o ser um ponteiro permite que haja o retorno NULL
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
    { // prioridade para emerg�ncia
        Pet atendido_e = Emergencia->ini->info;
        printf("\nAtendendo (EMERG�NCIA):\n");
        ExibirPet(atendido_e);
    }
    else if(!FilaVazia(Normal))
    {//normais logo em seguida, caso n�o tenham emergencias
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
    { // prioridade para emerg�ncia
        Pet atendido_e = RemoverDaFila(Emergencia);
        InserirNaFila(Atendidos, atendido_e); // salva no hist�rico
        ExibirPet(atendido_e);
    }
    else if(!FilaVazia(Normal))
    {//normais logo em seguida, caso n�o tenham emergencias
        Pet atendido_n = RemoverDaFila(Normal);
        InserirNaFila(Atendidos, atendido_n); // salva no hist�rico
        ExibirPet(atendido_n);
    }
}

void ImprimirRelatorio(Fila *Emergencia, Fila *Normal)
{
    printf("\n--- FILA EMERG�NCIA ---\n");
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
        gerado = min + rand() % (max - min + 1); // Gera um n�mero aleat�rio dentro do intervalo

        Pet *encontrado_E = BuscarIDNaFila(Emergencia, gerado); // Verifica se o ID j� existe na fila de emerg�ncia

        Pet *encontrado_N = BuscarIDNaFila(Normal, gerado); // Verifica se o ID j� existe na fila normal

        // Se n�o foi encontrado em nenhuma das filas
        if (encontrado_E == NULL && encontrado_N == NULL) {
            existe = 0; // ID � �nico, sai do loop
        } else {
            existe = 1; // ID j� existe, volta para o loop
        }

    } while (existe);

    return gerado;
}

Data criarData(){
    int ano,mes,dia;
    Data info;
    do {
        printf("Insira o Ano de Nascimento: ");
        scanf("%i", &ano);
    } while (ano < 0);

    do {
        printf("Insira o M�s de Nascimento: ");
        scanf("%i", &mes);
    } while (mes < 1 || mes > 12);

    do {
        printf("Insira o Dia de Nascimento: ");
        scanf("%i", &dia);
    } while (dia < 0 || dia > 30);
    info.ano = ano;
    info.mes = mes;
    info.dia = dia;
    return info;
}

void InserirPet(Fila * normal, Fila *emergencia ){
    Pet novo;
    int idade, prioridade;
    struct tm *data_local;
    time_t segundos;

    novo.id = IdAleatorio(normal,emergencia);
    printf("O id do pet �: %d", novo.id);
    printf("Digite o nome do Pet: \n");

    fgets(novo.nome,50,stdin);
    printf("Digite a esp�cie: \n");
    fgets(novo.especie,50,stdin);
    novo.data_nasc = criarData();

    time(&segundos);
    data_local = localtime(&segundos);

    novo.idade = (data_local->tm_year + 1900) - novo.data_nasc.ano;

    do {
        printf("Digite a Prioridade: Normal(0) ou Emerg�ncia (1): \n");
        scanf("%i", &prioridade);
    } while((prioridade != 1) && (prioridade != 0));

    if(prioridade == 1){
        InserirNaFila(emergencia, novo);
    } else {
        InserirNaFila(normal, novo);
    }

}

int main(){
    Fila *fila_normal = InicializarFila();
    Fila *fila_emergente = InicializarFila();
    Fila *fila_antendidos = InicializarFila();

    int controle = 1;
    char input_servico;

    //data dump
    int min = 100, max=999;
    int rnum;
    srand(time(NULL));
    Pet dump_pet;
    rnum = 100;

    for(int i = 0; i < 10; i++){
        while(BuscarIDNaFila(fila_emergente, rnum) != NULL || BuscarIDNaFila(fila_normal, rnum) != NULL || BuscarIDNaFila(fila_antendidos, rnum) != NULL){
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
            input_servico = getchar();
            controle = input_servico - '0';
            printf("%d", controle);
        }while(controle < 1 || controle > 7);

        switch(controle){
            case 1:
                system("cls");
                InserirPet(fila_normal, fila_emergente);
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                AtenderPet(fila_emergente, fila_normal, fila_antendidos);
                system("pause");
                system("cls");
                break;

            case 3: {
                int id_busca, i, status_busca = 0;
                char nome_busca[50];
                Pet *p[3];
                Fila *l[3];

                system("cls");
                cabecalho();

                printf("\nRealizar busca atraves do: \n\t"CIANO"( 1 )"NEGRITO" ID\n\t"CIANO"( 2 )"NEGRITO" NOME\n\n\t"VERMELHO"( OUTRO )"NEGRITO" CANCELAR"RESET"\n\n> ");
                input_servico = getchar();
                controle = input_servico - '0';

                system("cls");
                cabecalho();

                if(controle == 1){
                    printf("\nInsira o ID (3 digitos numericos, entre 100 e 999) que deseja pesquisar: ");
                    scanf("%d", &id_busca);
                    getchar();

                    while(id_busca < 100 || id_busca > 999){
                        printf("\nID inserido inv�lido. Insira novamente: ");
                        scanf("%d", &id_busca);
                    }

                    p[0] = BuscarIDNaFila(fila_normal, id_busca);
                    p[1] = BuscarIDNaFila(fila_emergente, id_busca);
                    p[2] = BuscarIDNaFila(fila_antendidos, id_busca);

                    for(i = 0; i < 3; i++){
                        if(p[i] != NULL){
                            ExibirPet(*p[i]);
                            status_busca = 1;
                        }
                    }

                    if(!status_busca) printf("\nNenhum resultado foi encontrado. ");
                }

                if(controle == 2){
                    printf("\nInsira o Nome que deseja pesquisar: ");

                    fgets(nome_busca, 50, stdin);
                    nome_busca[strcspn(nome_busca, "\n")] = '\0';

                    l[0] = BuscarNomeNaFila(fila_normal, nome_busca);
                    l[1] = BuscarNomeNaFila(fila_emergente, nome_busca);
                    l[2] = BuscarNomeNaFila(fila_antendidos, nome_busca);

                    if(l[0] == NULL && l[1] == NULL && l[2] == NULL){
                        printf("\nNenhum resultado foi encontrado. ");
                        printf("\n");
                    } else {
                        printf("\n");
                        ExibirFila(l[0]);
                        printf("\n");
                        ExibirFila(l[1]);
                        printf("\n");
                        ExibirFila(l[2]);
                        printf("\n");
                    }
                }

                system("pause");
                system("cls");
                break;
            }

            case 4: {
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

            }

            case 5:
                system("cls");
                printf("Imprimir Próximo Atendimento\n");
                system("pause");
                system("cls");
                break;

            case 6: {
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
            }

            case 7:
                controle = 0;
                break;
        }
    }
}
