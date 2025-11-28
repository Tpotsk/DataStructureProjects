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
    char cliente[50];
    char vendedor[50];
    char matricula[4];
    Data dt_transacao;
    float valor;
} Venda;

typedef struct Arvore
{
    Venda venda;
    struct Arvore *esq;
    struct Arvore *dir;
} Arv;

Arv *criaNo(Venda venda)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));
    p->venda = venda;
    p->dir = NULL;
    p->esq = NULL;
    return p;
}

void insere(Arv *Pai, Venda Nvenda)
{
    if (Pai == NULL)
    {
        Pai = (Arv*)malloc(sizeof(Arv));
        Pai->dir = NULL;
        Pai->esq = NULL;
        Pai->venda = Nvenda;
    }
    else if (Nvenda.id > Pai->venda.id)
    {
        if (Pai->dir == NULL)
        {
            Pai->dir = (Arv*)malloc(sizeof(Arv));
            Pai->dir->dir = NULL;
            Pai->dir->esq = NULL;
            Pai->dir->venda = Nvenda;
        }
        else
        {
            insere(Pai->dir, Nvenda);
        }
    }
    else if (Nvenda.id < Pai->venda.id)
    {
        if (Pai->esq == NULL)
        {
            Pai->esq = (Arv*)malloc(sizeof(Arv));
            Pai->esq->dir = NULL;
            Pai->esq->esq = NULL;
            Pai->esq->venda = Nvenda;
        }
        else
        {
            insere(Pai->esq, Nvenda);
        }
    }
    else
    {
        printf("Erro: ID %d ja  existe na  arvore\n", Nvenda.id);
    }
}

Arv* removeVenda(Arv* Pai, int ID){
    if(Pai == NULL){
        return NULL;
    }
    if(ID > Pai->venda.id && Pai->dir != NULL){
        Pai->dir = removeVenda(Pai->dir, ID);
    }
    if(ID < Pai->venda.id && Pai->esq != NULL){
        Pai->esq = removeVenda(Pai->esq, ID);
    }
    if(ID == Pai->venda.id){
        if(Pai->dir == NULL && Pai->esq == NULL){
            free(Pai);
            return NULL;
        }
        if(Pai->dir == NULL){
            Arv* aux = Pai->esq;
            free(Pai);
            return aux;
        }
        if(Pai->esq == NULL){
            Arv* aux = Pai->dir;
            free(Pai);
            return aux;
        }
        Arv* aux = Pai->dir;
        while(aux->esq != NULL){
            aux = aux->esq;
        }
        Pai->venda = aux->venda;
        Pai->dir = removeVenda(Pai->dir, aux->venda.id);
    }
    return Pai;
}

Arv * buscaID(Arv *Pai, int ID){
    if(Pai == NULL){
        return NULL;
    }
    if(ID > Pai->venda.id && Pai->dir != NULL){
       return buscaID(Pai->dir, ID);
    }
    if(ID < Pai->venda.id && Pai->esq != NULL){
       return buscaID(Pai->esq, ID);
    }
    if(ID == Pai->venda.id){
        return Pai;
    }
}

void imprimir_in_order(Arv *pai)
{
    if (pai->dir != NULL)
    {
        imprimir_in_order(pai->dir);
    }
    printf(" %0.2f", pai->venda.valor);
    if (pai->esq != NULL)
    {
        imprimir_in_order(pai->esq);
    }
}

#endif // FILA_H_INCLUDED
