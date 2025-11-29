#include "ARVORE.h"

int main(){
    Arv* vendas = NULL;
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
    vendas  = removeVenda(vendas, 1002);
    imprimir_in_order(vendas);
}
