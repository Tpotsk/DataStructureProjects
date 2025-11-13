#include <stdio.h>

#define NEGRITO "\033[1;37m"
#define AZUL "\033[1;34m"
#define VERDE "\033[1;32m"
#define VERMELHO "\033[1;31m"
#define CIANO "\033[1;36m"
#define RESET "\033[0m"

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



int main(){
    int controle = 1;
    char input_servico;

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
                printf("\nfuncionalidade -> inserir nova venda\n");
                system("pause");
                system("cls");
                break;
            }

            case 2: {
                system("cls");
                cabecalho();
                printf("\nfuncionalidade -> listar vendas\n");
                system("pause");
                system("cls");
                break;
            }

            case 3: {
                system("cls");
                cabecalho();
                printf("\nfuncionalidade -> listar vendas com filtro\n");
                system("pause");
                system("cls");
                break;
            }

            case 4: {
                system("cls");
                cabecalho();
                printf("\nfuncionalidade -> num total de vendas, faturamento total\n");
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
