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
    struct Arvore_AVL *esq;
    struct Arvore_AVL *dir;
} Arv;

Arv *criaNo(Venda venda)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));
    p->venda = venda;
    p->dir = NULL;
    p->esq = NULL;
    return p;
}

void insere(Arv* Pai, Venda Nvenda)
{
    if(Pai == NULL){
        Arv* novo = (Arv*)malloc(sizeof(Arv));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->venda = Nvenda;
        Pai = novo;
    }
    if(Nvenda.id > Pai->venda.id){
        insere(Pai->dir,Nvenda);
    }
    if(Nvenda.id < Pai->venda.id){
        insere(Pai->dir,Nvenda);
    }
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
