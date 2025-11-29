#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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
    printf("%c   "NEGRITO"Sistema de Registro Veterinario ~ Bem vindo(a)"RESET"                 %c", 0xBA, 0xBA);
    tabelaLinha(0xC8, 0xCD, 0xBC, 68);
}

void MenuOpcoes(){
    tabelaLinha(0xC9, 0xCD, 0xBB, 68);
    printf("%c "NEGRITO"Servicos:"RESET"                                                        %c", 0xBA, 0xBA);
    tabelaLinha(0xCC, 0xCD, 0xB9, 68);
    printf("%c           "CIANO"( 1 )"RESET" Inserir venda                                    %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 2 )"RESET" Listar vendas                                    %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 3 )"RESET" Buscar vendas                                    %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 4 )"RESET" Estatisticas                                     %c\n", 0xBA, 0xBA);
    printf("%c           "CIANO"( 5 )"RESET" Remover venda                                    %c", 0xBA, 0xBA);
    tabelaLinha(0xBA, ' ', 0xBA, 68);
    printf("%c           "VERMELHO"( 6 )"RESET" Finalizar sistema                                %c", 0xBA, 0xBA);
    tabelaLinha(0xC8, 0xCD, 0xBC, 68);
    printf("\nPressione o ID do servico desejado: ");
}

void CabecalhoVenda1(){
    sequenciaDeChar(0xDA, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 12);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC2, 0xC4, 0xBF, 13);
    printf("\n%c "NEGRITO"ID"RESET"   %c "NEGRITO"NOME VENDEDOR"RESET"                                      %c "NEGRITO"MATRICULA"RESET" %c "NEGRITO"NOME COMPRADOR"RESET"                                     %c "NEGRITO"DATA TRANS."RESET" %c "NEGRITO"VALOR"RESET"     %c\n", 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3);
}

void ExibirVenda1(Venda venda) {               // usado pra exibir as vendas na listagem de vendas e buscar de vendas por valor
    sequenciaDeChar(0xC3, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 12);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC5, 0xC4, 0xB4, 13);
    printf("\n%c %4d %c %-50s %c %-10s %c %-50s %c %2d/%2d/%-5d %c %-9.2f %c\n", 0xB3, venda.id, 0xB3, venda.vendedor, 0xB3, venda.matricula, 0xB3, venda.cliente, 0xB3, venda.dt_transacao.dia, venda.dt_transacao.mes, venda.dt_transacao.ano, 0xB3, venda.valor, 0xB3);

}

void FecharVenda1(){
    sequenciaDeChar(0xC0, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 12);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC1, 0xC4, 0xD9, 13);
    printf("\n\n");
}

void CabecalhoVenda2(){               // usado pra exibir as vendas na busca de vendas por vendedor
    sequenciaDeChar(0xDA, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC2, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC2, 0xC4, 0xBF, 9);
    printf("\n%c "NEGRITO"ID"RESET"   %c "NEGRITO"NOME VENDEDOR"RESET"                                      %c "NEGRITO"DATA TRANS."RESET" %c "NEGRITO"VALOR"RESET" %c\n", 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3);

    sequenciaDeChar(0xC3, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC5, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC5, 0xC4, 0xB4, 9);
}

void ExibirVenda2() {
    int id = 1234;
    char comprador[50] = {"CompradorComprador Comprador"};
    int dia = 12;
    int mes = 12;
    int ano = 2012;
    double valor = 20.99;

    printf("\n%c %4d %c %-50s %c %2d/%2d/%-5d %c %.2f %c\n", 0xB3, id, 0xB3, comprador, 0xB3, dia, mes, ano, 0xB3, valor, 0xB3);
}

void FecharVenda2(){
    sequenciaDeChar(0xC0, 0xC4, 0xC4, 7);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 53);
    sequenciaDeChar(0xC1, 0xC4, 0xC4, 14);
    sequenciaDeChar(0xC1, 0xC4, 0xD9, 9);
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
void ExibirVendas(Arv *r) {
    if(r != NULL) {
        ExibirVenda1(r->venda);

        ExibirVendas(r->dir);
        ExibirVendas(r->esq);
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
            {1001, "João Silva", "Maria Santos", "V001", {15, 5, 2024}, 150.75},
            {1002, "Ana Oliveira", "Carlos Lima", "V002", {16, 5, 2024}, 89.90},
            {1003, "Pedro Costa", "Maria Santos", "V001", {17, 5, 2024}, 220.50},
            {1004, "Mariana Souza", "Paulo Rocha", "V003", {18, 5, 2024}, 75.25},
            {1005, "Lucas Pereira", "Carlos Lima", "V002", {19, 5, 2024}, 310.00},
            {1006, "Julia Fernandes", "Ana Beatriz", "V004", {20, 5, 2024}, 125.80},
            {1007, "Ricardo Alves", "Paulo Rocha", "V003", {21, 5, 2024}, 95.60},
            {1008, "Fernanda Lima", "Maria Santos", "V001", {22, 5, 2024}, 180.30}
        };

        int numVendasTeste = sizeof(vendasTeste) / sizeof(vendasTeste[0]);

        for(int i = 0; i < numVendasTeste; i++) {
            if(vendas == NULL) {
                vendas = criaNo(vendasTeste[i]);
            } else {
                insere(vendas, vendasTeste[i]);
            }
        }
    }
    // ==================================================
    // FIM DO TRECHO DE POPULAÇÃO
    // ==================================================


    while(controle){
        cabecalho();
        MenuOpcoes();

        do{
            input_servico = getch();
            controle = input_servico - '0';
            printf("%d", controle);
        }while(controle < 1 || controle > 7);

        switch(controle){
            case 1:{
                system("cls");
                cabecalho();
                printf("\nfuncionalidade -> inserir vendas\n");
                system("pause");
                system("cls");
                break;
            }

            case 2: {
                system("cls");
                cabecalho();
                CabecalhoVenda1();
                ExibirVendas(vendas);
                FecharVenda1();
                system("pause");
                system("cls");
                break;
            }

            case 3: {
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

            case 4: {
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

            case 5: {
                system("cls");
                cabecalho();
                printf("\nfuncionalidade -> remover vendas\n");
                system("pause");
                system("cls");
                break;
            }

            case 6: {
                controle = 0;
                break;
            }
        }
    }
}
