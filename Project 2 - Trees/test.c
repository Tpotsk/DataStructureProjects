#include "ARVORE.h"

int main(){
    Venda novo;
    novo.valor = 1999;
    novo.id = 192;
    Avl* raiz = criaNo(novo);
    imprimir_in_order(raiz);
}
