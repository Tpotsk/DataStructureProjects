#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "FILA.h"

int main() {
    int min = 100, max=999;
    srand(time(NULL));
    //Fila *normal = CriaFila();
    //Fila *emergencia = CriaFila();
    int rnum = min + rand() % (max - min + 1);
    while(1){
        int rnum = min + rand() % (max - min + 1);
        system("pause");
        printf("Bem vindo à clinica veterinária selecione uma opção: \n");
        printf("(1) - Inserir na Fila de Atendimento\n (2) - Atender"s);
    }
    return 0;
}
