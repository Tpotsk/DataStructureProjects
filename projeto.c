#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "FILA.h"

void inserePet ()
{

    int ID = min + rand() % (max - min + 1);

    printf("Insira as informações do(a) paciente: \n\n");

    printf("NOME: ");
    scanf("%[^\n]");

    printf("ESPÉCIE: ");
    scanf("%[^\n]")

    printf("IDADE: ");
    scanf("%d");

    printf("DATA DE NASCIMENTO [d/m/a]: ");
    scanf("%d %d %d")

    printf("PRIORIDADE (0-EMERGENCIA , 1-NORMAL): ")
    printf("%d")

}

int main() {
    int min = 100, max=999;
    srand(time(NULL));
    //Fila *normal = CriaFila();
    //Fila *emergencia = CriaFila();
    int rnum = min + rand() % (max - min + 1);
    /*while(1){
        int rnum = min + rand() % (max - min + 1);
        system("pause");
        printf("Bem vindo à clinica veterinária selecione uma opção: \n");
        printf("(1) - Inserir na Fila de Atendimento\n (2) - Atender"s);#
    }*/
    inserePet();
    return 0;
}



