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

// Funções lógicas
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


void InserirVenda(Arv *r) {
    Venda nova;
    int NovoId;
    do{
    NovoId = IdAleatorio();
    }while (ComparaId(r, NovoId));IdAleatorio()
    novo.id = NovoId;

    printf("\nDigite o nome do cliente: ");
    fgets(novo.cliente,50,stdin);

    printf("\nDigite o nome do vendedor: ");
    fgets(novo.vendedor,50,stdin);

    int gerado = gerarMatricula;
    sprintf(novo.matricula, "V%03d", gerado);

    printf("Dia da transacao: ");
    scanf("%d", &nova.dt_transacao.dia);

    printf("Mes da transacao: ");
    scanf("%d", &nova.dt_transacao.mes);

    printf("Ano da transacao: ");
    scanf("%d", &nova.dt_transacao.ano);

    printf("\nDigite o valor da venda (ex: 199.99): \n\n $");
    scanf("%f", &novo.valor);
    getchar();

}

int main(){
    system("cls");
    int controle = 1;
    char input_servico;

    Arv *vendas = NULL;


     // ==================================================
    // TRECHO ISOLADO PARA POPULAR A ÁRVORE COM DADOS DE TESTE
    // ==================================================
    {
    Venda vendasTeste[] = {
        {1001, "Comprador 1", "Vendedor 1", "V001", {15, 5, 2024}, 150.75},
        {1002, "Comprador 2", "Vendedor 2", "V002", {16, 5, 2024}, 89.90},
        {1003, "Comprador 3", "Vendedor 1", "V001", {17, 5, 2024}, 220.50},
        {1004, "Comprador 4", "Vendedor 3", "V003", {18, 5, 2024}, 75.25},
        {1005, "Comprador 5", "Vendedor 2", "V002", {19, 5, 2024}, 310.00},
        {1006, "Comprador 6", "Vendedor 4", "V004", {20, 5, 2024}, 125.80},
        {1007, "Comprador 7", "Vendedor 3", "V003", {21, 5, 2024}, 95.60},
        {1008, "Comprador 8", "Vendedor 1", "V001", {22, 5, 2024}, 180.30}
    };

        int numVendasTeste = sizeof(vendasTeste) / sizeof(vendasTeste[0]);

        for(int i = 0; i < numVendasTeste; i++) {
                vendas = insere(vendas, vendasTeste[i]);
            }
        }
    // ==================================================
    // FIM DO TRECHO DE POPULAÇÃO
    // ==================================================


    while(controle){
        cabecalho();
        MenuOpcoes();

        do{
            input_servico = getch(stdin);
            controle = input_servico - '0';
            printf("%d", controle);
        }while(controle < 1 || controle > 7);

        switch(controle) {
            case 1: {                                       // INSERIR NOVA VENDA
                system("cls");
                cabecalho();

                printf("Nome do cliente: ");

                printf("Nome do vendedor: ");

                printf("Matricula do vendedor: ");

                printf("Dia da transacao: ");

                printf("Mes da transacao: ");

                printf("Ano da transacao: ");

                printf("Valor da venda: ");

                system("pause");
                system("cls");

                break;
            }

            case 2: {                                       // LISTAR TODAS AS VENDAS
                system("cls");
                cabecalho();

                printf("\nListar vendas de maneira >");
                printf("\n\tCrescente   "CIANO"(PRESSIONE 1)"RESET);
                printf("\n\tDecrescente "CIANO"(PRESSIONE 2)\n\n"RESET);

                int opcao = 0;

                do{
                    printf(">");
                    scanf("%d", &opcao);
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

            case 3: {                                       // BUSCAR VENDA POR VENDEDOR
                system("cls");
                cabecalho();

                printf("\nRealizar busca atraves de >");
                printf("\n\tNome do vendedor      "CIANO"(PRESSIONE 1)"RESET);
                printf("\n\tMatricula do vendedor "CIANO"(PRESSIONE 2)\n\n"RESET);
                printf("\n\tCancelar              "VERMELHO"(PRESSIONE OUTRO)\n\n"RESET);

                int opcao = 0;
                char buscarPor[51];
                char *resultadoBusca;

                do{
                    printf(">");
                    scanf("%d", &opcao);
                } while(opcao != 1 && opcao != 2);

                 getchar();

                if(opcao == 1) {
                    printf("\nInsira o nome do vendedor\n");
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
                        printf("\nNao ha vendedor com esse nome nos registros.\n\n");
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
                        printf("\nNao ha vendedor com essa matricula nos registros.\n\n");
                    }
                }

                system("pause");
                system("cls");

                break;
            }

            case 4: {                                       // LISTAR VENDAS ACIMA OU ABAIXO DE UM VALOR
                system("cls");
                cabecalho();

                printf("\nBuscar Vendas que >");
                printf("\n\tMenor que "CIANO"(PRESSIONE 1)"RESET);
                printf("\n\tMaior que "CIANO"(PRESSIONE 2)\n\n"RESET);

                int opcao = 0;
                float valor = 0.0f;

                do{
                    printf(">");
                    scanf("%d", &opcao);
                } while(opcao != 1 && opcao != 2);

                printf("\nInsira o valor a ser tomado como parametro >");
                scanf("%f", &valor);

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

            case 5: {                                       // EXIBIR ESTATISTICAS
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

            case 6: {                                       // REMOVER VENDA
                system("cls");
                cabecalho();


                int idRemover;
                printf("Digite o ID da venda a remover: ");
                scanf("%d", &idRemover);

                if (ComparaId(venda, idRemover) == 0) {
                    printf("ID %d nao encontrado. Nenhuma venda removida.\n", idRemover);
                } else {
                    raiz = removeVenda(venda, idRemover);
                    printf("Venda removida com sucesso!\n");
                }

                system("pause");
                system("cls");
                break;

                break;
            }

            case 7: {                                       // FINALIZAR
                controle = 0;

                break;
            }

        }
    }
}
