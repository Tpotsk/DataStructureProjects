#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "FILA.h"

void atendePet(Fila *normal, Fila *emergencia){
    Pet removido;
    if(FilaVazia(emergencia)){
        if(FilaVazia(normal)){
             removido = RemoveDaFila(normal);
        } else {
            printf("Não há Pets a serem atendidos!");
        }
    } else {
        Pet removido = RemoveDaFila(emergencia);
    }

}

int main() {
    int min = 100, max=999;
    srand(time(NULL));
    //Fila *normal = inicializaFila();
    //Fila *emergencia = inicializaFila();
    int rnum = min + rand() % (max - min + 1);
    while(1){
        int rnum = min + rand() % (max - min + 1);
        system("pause");
        printf("Bem vindo à clinica veterinária selecione uma opção: \n");
        printf("(1) - Inserir na Fila de Atendimento\n (2) - Atender");
    }
    return 0;
}
