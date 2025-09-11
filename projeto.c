#include <stdio.h>
#include <stdlib.h>
#include "FILA.h"

int main() {
    Fila *normal = InicializarFila();
    Fila *emergencia = InicializarFila();

    Pet novo;
    novo.id = 1;
    novo.idade = 1;

    printf("%d, %d", novo.id, novo.idade);
}
