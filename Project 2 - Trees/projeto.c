#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "ARVORE.h"

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
    tabelaLinha(0xC9, 0xCD, 0xBB, 68);
    printf("%c   "NEGRITO"Sistema de Registro de Vendas ~ Bem vindo(a)"RESET"                   %c", 0xBA, 0xBA);
    tabelaLinha(0xC8, 0xCD, 0xBC, 68);
}

void MenuOpcoes(){
    tabelaLinha(0xC9, 0xCD, 0xBB, 68);
    printf("%c "NEGRITO"Servicos:"RESET"                                                        %c", 0xBA, 0xBA);
    tabelaLinha(0xCC, 0xCD, 0xB9, 68);
    printf("%c           "CIANO"( 1 )"RESET" Inserir venda                                    %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 2 )"RESET" Listar vendas                                    %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 3 )"RESET" Buscar vendas por vendedor                       %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 4 )"RESET" Buscar vendas por valor                          %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 5 )"RESET" Estatisticas                                     %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 6 )"RESET" Remover venda                                    %c", 0xBA, 0xBA);
    tabelaLinha(0xBA, ' ', 0xBA, 68);
    printf("%c           "VERMELHO"( 7 )"RESET" Finalizar sistema                                %c", 0xBA, 0xBA);
    tabelaLinha(0xC8, 0xCD, 0xBC, 68);
    printf("\nPressione o ID do servico desejado: ");
}

void CabecalhoVenda1(){
    sequenciaDeChar(0xDA, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 12);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC2, 0xC4, 0xBF, 14);
    printf("\n%c "NEGRITO"ID"RESET"   %c "NEGRITO"NOME VENDEDOR"RESET"                                      %c "NEGRITO"MATRICULA"RESET" %c "NEGRITO"NOME COMPRADOR"RESET"                                     %c "NEGRITO"DATA"RESET"        %c "NEGRITO"VALOR (R$)"RESET" %c\n", 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3);
}

void ExibirVenda1(Venda venda) {               // usado pra exibir as vendas na listagem de vendas e buscar de vendas por valor
    sequenciaDeChar(0xC3, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 12);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC5, 0xC4, 0xB4, 14);
    printf("\n%c %4d %c %-50s %c %-10s %c %-50s %c %2d/%2d/%-5d %c %-10.2f %c\n", 0xB3, venda.id, 0xB3, venda.vendedor, 0xB3, venda.matricula, 0xB3, venda.cliente, 0xB3, venda.dt_transacao.dia, venda.dt_transacao.mes, venda.dt_transacao.ano, 0xB3, venda.valor, 0xB3);
}

void FecharVenda1(){
    sequenciaDeChar(0xC0, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 12);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC1, 0xC4, 0xD9, 14);
    printf("\n\n");
}

void CabecalhoVenda2(){               // usado pra exibir as vendas na busca de vendas por vendedor
    sequenciaDeChar(0xDA, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC2, 0xC4, 0xBF, 14);
    printf("\n%c "NEGRITO"ID"RESET"   %c "NEGRITO"NOME CLIENTE"RESET"                                       %c "NEGRITO"DATA TRANS."RESET" %c "NEGRITO"VALOR (R$)"RESET" %c\n", 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3);
}

void ExibirVenda2(Venda v) {
    sequenciaDeChar(0xC3, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC5, 0xC4, 0xB4, 14);
    printf("\n%c %4d %c %-50s %c %2d/%2d/%-5d %c %-10.2f %c\n", 0xB3, v.id, 0xB3, v.cliente, 0xB3, v.dt_transacao.dia, v.dt_transacao.mes, v.dt_transacao.ano, 0xB3, v.valor, 0xB3);
}

void FecharVenda2(){
    sequenciaDeChar(0xC0, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC1, 0xC4, 0xD9, 14);
    printf("\n\n");
}

void ExibirEstatisticas(int quantidade, float faturamento) {
    float valorMedio = (quantidade > 0) ? faturamento / quantidade : 0.0f ;

    sequenciaDeChar(0xDA, 0xC4, 0xC2, 24);
    sequenciaDeChar(0xC4, 0xC4, 0xBF, 15);
    printf("\n%c      FATURAMENTO     %c R$ %-9.2f %c\n", 0xB3, 0xB3,faturamento, 0xB3);
    sequenciaDeChar(0xC3, 0xC4, 0xC5, 24);
    sequenciaDeChar(0xC4, 0xC4, 0xB4, 15);
    printf("\n%c QUANTIDADE DE VENDAS %c %-8d un. %c\n", 0xB3, 0xB3, quantidade, 0xB3);
    sequenciaDeChar(0xC3, 0xC4, 0xC5, 24);
    sequenciaDeChar(0xC4, 0xC4, 0xB4, 15);
    printf("\n%c VALOR MEDIO DE VENDA %c R$ %-9.2f %c\n", 0xB3, 0xB3, valorMedio, 0xB3);
    sequenciaDeChar(0xC0, 0xC4, 0xC1, 24);
    sequenciaDeChar(0xC4, 0xC4, 0xD9, 15);
    printf("\n\n");
}

void EntradaDeString(char *str) {
    int flag = 0;

    while(!flag) {
        printf("> ");
        fflush(stdin);
        fgets(str, 50, stdin);

        int tam = 0;

        while(str[tam] != '\0') {
            if(str[tam] == '\n') {
                str[tam] = '\0';
            } else {
                tam++;
            }
        }

        flag = 1;
    }
}

char *BuscarNomePorMatricula(Arv *r, char *matricula) {
    if(r == NULL) {
        return NULL;
    }

    if(strcmp(matricula, r->venda.matricula) == 0){
        return r->venda.vendedor;
    }

    char *resultadoDir = BuscarNomePorMatricula(r->dir, matricula);
    if(resultadoDir != NULL) return resultadoDir;

    return BuscarNomePorMatricula(r->esq, matricula);
}

char *BuscarMatriculaPorNome(Arv *r, char *nome) {
    if(r == NULL) {
        return NULL;
    }

    if(strcmp(nome, r->venda.vendedor) == 0){
        return r->venda.matricula;
    }

    char *resultadoDir = BuscarMatriculaPorNome(r->dir, nome);
    if(resultadoDir != NULL) return resultadoDir;

    return BuscarMatriculaPorNome(r->esq, nome);
}

void ExibirVendasPorMatricula(Arv *r, char *matricula) {
    if(r != NULL) {
        if(strcmp(r->venda.matricula, matricula) == 0) ExibirVenda2(r->venda);

        ExibirVendasPorMatricula(r->dir, matricula);
        ExibirVendasPorMatricula(r->esq, matricula);
    }
}

void ExibirVendasCrescente(Arv *r) {
    if(r != NULL) {
        ExibirVendasCrescente(r->esq);
        ExibirVenda1(r->venda);
        ExibirVendasCrescente(r->dir);
    }
}

void ExibirVendasDecrescente(Arv *r) {
    if(r != NULL) {
        ExibirVendasDecrescente(r->dir);
        ExibirVenda1(r->venda);
        ExibirVendasDecrescente(r->esq);
    }
}

void ExibirVendasAbaixoDe(Arv *r, float v) {
    if(r != NULL) {
        if(r->venda.valor < v) ExibirVenda1(r->venda);

        ExibirVendasAbaixoDe(r->dir, v);
        ExibirVendasAbaixoDe(r->esq, v);
    }
}

void ExibirVendasAcimaDe(Arv *r, float v) {
    if(r != NULL) {
        if(r->venda.valor >= v) ExibirVenda1(r->venda);

        ExibirVendasAcimaDe(r->dir, v);
        ExibirVendasAcimaDe(r->esq, v);
    }
}

float CalcularFaturamento(Arv *r) {
    if(r == NULL) return 0.0f;

    float faturamento = r->venda.valor;

    faturamento += CalcularFaturamento(r->dir);
    faturamento += CalcularFaturamento(r->esq);

    return faturamento;
}

int QuantidadeDeVendas(Arv *r) {
    if(r == NULL) return 0;

    int quantidade = 1;

    quantidade += QuantidadeDeVendas(r->dir);
    quantidade += QuantidadeDeVendas(r->esq);

    return quantidade;
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Data criarData(){
    int ano,mes,dia;
    int err;
    Data info;
    struct tm *data_local;
    time_t segundos;
    time(&segundos);
    data_local = localtime(&segundos);

    printf("\n"NEGRITO"Data da Venda\n"RESET);
    do {
        printf("\nInsira o Ano da Venda:\n> ");
        err = scanf("%i", &ano);
        limparBufferEntrada();
    } while (ano < 0 || ano > (data_local->tm_year + 1900) || err == 0);

    do {
        printf("\nInsira o Mes da Venda:\n> ");
        err = scanf("%i", &mes);
        limparBufferEntrada();
    } while (mes < 1 || mes > 12 || err == 0);

    do {
        printf("\nInsira o Dia da Venda:\n> ");
        err = scanf("%i", &dia);
        limparBufferEntrada();
    } while (dia < 0 || dia > 30 || err == 0);
    info.ano = ano;
    info.mes = mes;
    info.dia = dia;
    return info;
}

int ComparaId(Arv *r, int v){
    if (r == NULL){return 0;}

    if (v == r->venda.id){return 1;}

    if (v > r->venda.id){
        return ComparaId(r->dir, v);
    }
    else {
        return ComparaId(r->esq, v);
    }
}

int IdAleatorio(){
    srand(time(NULL));

    int min = 1000;
    int max = 9999;

    int gerado;
    gerado = min + rand() % (max - min + 1);
    return gerado;
}

int gerarMatricula() {
    srand(time(NULL));
    int min = 0;
    int max = 999;
    int gerado;
    gerado = min + rand() % (max - min + 1);
    return gerado;
}


Arv* InserirVenda(Arv *r) {
    Venda venda;
    int NovoId, n_matricula;
    do {
        NovoId = IdAleatorio();
    }while (ComparaId(r, NovoId));

    venda.id = NovoId;
    limparBufferEntrada();
    printf("\n"CIANO"Digite o nome do cliente:\n"RESET);
    EntradaDeString(venda.cliente);

    printf("\n"CIANO"Digite o nome do vendedor:\n"RESET);
    EntradaDeString(venda.vendedor);

    int opcaomatricula;
    printf("\n"NEGRITO"Matricula do vendedor:\n"RESET);
    printf("\n\tGerar uma matricula aleatoria     "CIANO"(PRESSIONE 1)"RESET);
    printf("\n\tInserir manualmente a matricula   "CIANO"(PRESSIONE 2)\n\n"RESET);

    do {
        printf("> ");
        scanf("%d", &opcaomatricula);
        limparBufferEntrada();
    } while (opcaomatricula < 1 || opcaomatricula > 2);

    if (opcaomatricula == 1) {
        n_matricula = gerarMatricula();
    } else {
        do {
            printf("\nInsira o número de matricula do vendedor (0-999):\n> ");
            scanf("%d", &n_matricula);
            limparBufferEntrada();
        } while (n_matricula < 0 || n_matricula > 999);
    }

    sprintf(venda.matricula, "V%03d", n_matricula);

    venda.dt_transacao = criarData();

    do {
        printf("\n"AZUL"Digite o valor da venda (ex: 199.99): \n\n$"RESET);
        scanf("%f", &venda.valor);
    } while (venda.valor < 0);

    r = insere(r, venda);
    return r;
}

int main(){
    system("cls");
    int controle = 1;
    char input_servico;

    Arv *vendas = NULL;  

    while(controle){
        cabecalho();
        MenuOpcoes();

        do{
            input_servico = getc(stdin);
            controle = input_servico - '0';
            printf("%d", controle);
        }while(controle < 1 || controle > 7);

        switch(controle) {
            case 1: {
                system("cls");
                cabecalho();
                vendas = InserirVenda(vendas);
                printf("\n"CIANO"Venda inserida com sucesso!"RESET);
                system("pause");
                system("cls");
                break;
            }

            case 2: {
                system("cls");
                cabecalho();

                printf("\n"NEGRITO"Listar vendas de maneira:\n"RESET);
                printf("\n\tCrescente   "CIANO"(PRESSIONE 1)"RESET);
                printf("\n\tDecrescente "CIANO"(PRESSIONE 2)\n\n"RESET);

                int opcao = 0;

                do{
                    printf(">");
                    scanf("%d", &opcao);
                    limparBufferEntrada();
                } while(opcao != 1 && opcao != 2);

                printf("\n");

                CabecalhoVenda1();

                if(opcao == 1) {
                    ExibirVendasCrescente(vendas);
                } else {
                    ExibirVendasDecrescente(vendas);
                }

                FecharVenda1();
                system("pause");
                system("cls");

                break;
            }

            case 3: {
                system("cls");
                cabecalho();

                printf("\nRealizar busca atraves de >");
                printf("\n\tNome do vendedor      "CIANO"(PRESSIONE 1)"RESET);
                printf("\n\tMatricula do vendedor "CIANO"(PRESSIONE 2)\n\n"RESET);
                printf("\n\tCancelar              "VERMELHO"(PRESSIONE OUTRO)\n\n"RESET);

                int opcao = 0;
                char buscarPor[51];
                char *resultadoBusca;

                printf(">");
                scanf("%d", &opcao);
                limparBufferEntrada();

                if(opcao == 1) {
                    printf("\n"NEGRITO"Insira o nome do vendedor\n"RESET);
                    EntradaDeString(buscarPor);

                    system("cls");
                    cabecalho();

                    resultadoBusca = BuscarMatriculaPorNome(vendas, buscarPor);

                    if(resultadoBusca != NULL) {
                        printf("\nVendedor : %s", buscarPor);
                        printf("\nMatricula: %s\n\n", resultadoBusca);

                        CabecalhoVenda2();
                        ExibirVendasPorMatricula(vendas, resultadoBusca);
                        FecharVenda2();
                    } else {
                        printf("\n"VERMELHO"Nao ha vendedor com esse nome nos registros.\n\n"RESET);
                    }
                } else if(opcao == 2) {
                    printf("\nInsira a matricula do vendedor\n");
                    EntradaDeString(buscarPor);

                    system("cls");
                    cabecalho();

                    resultadoBusca = BuscarNomePorMatricula(vendas, buscarPor);

                    if(resultadoBusca != NULL) {
                        printf("\nVendedor : %s", resultadoBusca);
                        printf("\nMatricula: %s\n\n", buscarPor);

                        CabecalhoVenda2();
                        ExibirVendasPorMatricula(vendas, buscarPor);
                        FecharVenda2();
                    } else {
                        printf("\n"VERMELHO"Nao ha vendedor com essa matricula nos registros.\n\n"RESET);
                    }
                } else {
                    printf("\n"VERMELHO"Operacao cancelada!\n\n"RESET);
                }

                system("pause");
                system("cls");

                break;
            }

            case 4: {
                system("cls");
                cabecalho();

                printf("\n"NEGRITO"Buscar Vendas\n"RESET);
                printf("\n\tMenor que "CIANO"(PRESSIONE 1)"RESET);
                printf("\n\tMaior que "CIANO"(PRESSIONE 2)\n\n"RESET);

                int opcao = 0;
                float valor = 0.0f;

                do{
                    printf("> ");
                    scanf("%d", &opcao);
                    limparBufferEntrada();
                } while(opcao != 1 && opcao != 2);

                do{
                    printf("\n"CIANO"Insira o valor a ser tomado como parametro:\n> "RESET);
                    scanf("%f", &valor);
                    limparBufferEntrada();
                } while(valor < 0);

                system("cls");
                cabecalho();
                CabecalhoVenda1();

                if(opcao == 1) {
                    ExibirVendasAbaixoDe(vendas, valor);
                } else if(opcao == 2) {
                    ExibirVendasAcimaDe(vendas, valor);
                }

                FecharVenda1();
                system("pause");
                system("cls");
                break;
            }

            case 5: {                                      
                system("cls");
                cabecalho();
                printf("\n");

                int quantidade = QuantidadeDeVendas(vendas);
                float faturamento = CalcularFaturamento(vendas);

                ExibirEstatisticas(quantidade, faturamento);
                system("pause");
                system("cls");

                break;
            }

            case 6: {                                       
                system("cls");
                cabecalho();
                printf("\n");
                ExibirVendasCrescente(vendas);
                
                printf("\n\n");
                int idRemover;
                do {
                    printf("Digite o ID da venda a remover: \n> ");
                    scanf("%d", &idRemover);
                    limparBufferEntrada();
                }while(idRemover < 1000 || idRemover > 9999);
                
                if (ComparaId(vendas, idRemover) == 0) {
                    printf("\n"VERMELHO"ID %d nao encontrado. Nenhuma venda removida.\n"RESET, idRemover);
                } else {
                    Arv* aux = buscarID(vendas, idRemover);
                    ExibirVenda1(aux->venda);
                    vendas = removeVenda(vendas, idRemover);
                    printf("\n"VERDE"Venda removida com sucesso!\n"RESET);
                }

                system("pause");
                system("cls");
                break;
            }

            case 7: {                                       
                controle = 0;
                break;
            }

        }
    }
}
