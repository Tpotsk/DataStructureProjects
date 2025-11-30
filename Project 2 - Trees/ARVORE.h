#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct venda
{
    int id;
    char cliente[51];
    char vendedor[51];
    char matricula[5];
    Data dt_transacao;
    float valor;
} Venda;

typedef struct Arvore
{
    Venda venda;
    struct Arvore *esq;
    struct Arvore *dir;
} Arv;

Arv* insere(Arv *Pai, Venda Nvenda)
{
    if (Pai == NULL)
    {
        Pai = (Arv*)malloc(sizeof(Arv));
        Pai->venda = Nvenda;
        Pai->esq = NULL;
        Pai->dir = NULL;
        return Pai; // Retorna o novo endereço
    }

    if (Nvenda.id > Pai->venda.id)
    {
        Pai->dir = insere(Pai->dir, Nvenda);
    }
    else if (Nvenda.id < Pai->venda.id)
    {
        Pai->esq = insere(Pai->esq, Nvenda);
    }
    else
    {
        printf("Erro: ID %d ja existe na arvore\n", Nvenda.id);
    }

    return Pai;
}

Arv* removeVenda(Arv* Pai, int ID) {
    if (Pai == NULL) {
        return NULL;
    }

    if (ID > Pai->venda.id) {
        Pai->dir = removeVenda(Pai->dir, ID);
    }
    else if (ID < Pai->venda.id) {
        Pai->esq = removeVenda(Pai->esq, ID);
    }
    else {
        
        // Caso 1: Nó sem filhos (folha) ou apenas 1 filho
        if (Pai->dir == NULL) {
            Arv* aux = Pai->esq;
            free(Pai);
            return aux;
        }
        else if (Pai->esq == NULL) {
            Arv* aux = Pai->dir;
            free(Pai);
            return aux;
        }

        Arv* aux = Pai->dir;
        while (aux->esq != NULL) {
            aux = aux->esq;
        }

        Pai->venda = aux->venda; 
        Pai->dir = removeVenda(Pai->dir, aux->venda.id);
    }
    return Pai;
}

Arv* buscarID(Arv* Pai, int ID) {
    if (Pai == NULL) {
        return NULL;
    }

    if (ID > Pai->venda.id) {
        return buscarID(Pai->dir, ID);
    }
    else if (ID < Pai->venda.id) {
        return buscarID(Pai->esq, ID);
    }
    else {
        return Pai;
    }
}
void imprimir_in_order(Arv *pai)
{
    if (pai->esq != NULL)
    {
        imprimir_in_order(pai->esq);
    }
    printf(" %0.2f", pai->venda.valor);
    if (pai->dir != NULL)
    {
        imprimir_in_order(pai->dir);
    }
}

#endif // FILA_H_INCLUDED
