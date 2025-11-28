#include "ARVORE.h"

int main(){
    Venda novo, novo2;
    novo.valor = 1999;
    novo.id = 192;
    novo2.id = 180;
    novo2.valor = 1299;
    Arv* raiz = criaNo(novo);
    insere(raiz,novo2);
    removeVenda(raiz, 192);
    imprimir_in_order(raiz);
}
