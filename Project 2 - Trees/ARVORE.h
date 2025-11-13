#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct venda {
    int id;
    char cliente[50];
    char vendedor[50];
    char matricula[4];
    Data dt_transacao;
    float valor;
} Venda;

typedef struct Arvore_AVL
{
      Venda venda;
      struct Arvore_AVL *esq;
      struct Arvore_AVL *dir;
      int FB;
}Avl;

Avl * criaNo(Venda venda)
{
    Avl *p=(Avl*)malloc(sizeof(Avl));
    p->venda=venda;
    p->dir=NULL;
    p->esq=NULL;
    p->FB=0;
    return p;

}

Avl * rotacionarEsq(Avl *a,int *status)
{
    Avl *b,*c;
    b=a->dir;
    if(b->FB==1)//rota��o simples
    {
        printf("\n\nROTA��O SIMPLES -ESQUERDA \n\n");
        a->dir=b->esq;
        b->esq=a;
        a->FB=0;
        a=b;
    }
    else //rota��o dupla
    {
        printf("\n\nROTA��O DUPLA -ESQUERDA \n\n");
        c=b->esq;
        b->esq=c->dir;
        c->dir=b;
        a->dir=c->esq;
        c->esq=a;
        if(c->FB==1)
        {
            a->FB=-1;
        }
        else
        {
            a->FB=0;
        }
        if(c->FB==-1)
        {
            b->FB=1;
        }
        else
        {
            b->FB=0;
        }
        a=c;
    }
    a->FB=0;
    *status=1;
    return a;
}
Avl * rotacionarDir(Avl *a,int *status)
{
    Avl *b,*c;
    printf("\n Entrou Rota��o direita FB de a =%d",a->FB);
    b=a->esq;
    if(b->FB== -1)//rota��o simples
    {
        printf("\n\nROTA��O SIMPLES -DIREITA \n\n");
        a->esq=b->dir;
        b->dir=a;
        a->FB=0;
        a=b;
    }
    else //rota��o dupla
    {
        printf("\n\nROTA��O DUPLA -DIREITA \n\n");
        printf("\n FB de a =%d",a->FB);
        printf("\n FB de b =%d",b->FB);
        c=b->dir;
        printf("\n FB de c =%d",c->FB);
        b->dir=c->esq;
        c->esq=b;
        a->esq=c->dir;
        c->dir=a;
        if(c->FB== -1)
        {
            a->FB= 1;
        }
        else
        {
            a->FB=0;
        }
        if(c->FB== 1)
        {
            b->FB=-1;
        }
        else
        {
            b->FB=0;
        }
        a=c;
    }
    a->FB=0;
    *status=1;
    printf("\n FB de a =%d no= %d",a->FB,a->venda.valor);
    printf("\n FB de b =%d no= %d",b->FB,b->venda.valor);
    fflush(stdin);
    getchar();
    return a;
}


void insere(Avl **no, Venda Nvenda, int *status)
{
    if((*no)==NULL)
    {
        *no=criaNo(Nvenda);
        *status=0;

    }
    else
    {
        if((*no)->venda.id==Nvenda.valor)
        {
            printf("\n\n==> Elemento REPETIDO - TECLE ENTER");
            fflush(stdin);
            getchar();
        }
        else
        {
            if(Nvenda.valor < (*no)->venda.valor)
            {
                printf("\n insere esquerda:\n\n");
                insere(&(*no)->esq,Nvenda,status);
                printf("status = %d\n",*status);
                if(*status==0)//true
                {
                    printf("%d FB = %d\n",(*no)->venda.valor,(*no)->FB);
                    switch((*no)->FB)
                    {
                        case 1:
                            (*no)->FB=0;
                              printf("mudou status = %d\n\n",*status);
                            *status=1;//false
                        break;
                        case 0:
                            printf("%d mudou FB para -1\n",(*no)->venda.valor);
                            (*no)->FB=-1;
                        break;
                        case -1:
                            printf("\n\n rotacionar direita\n");
                            (*no)=rotacionarDir((*no),status);
                        break;
                    }
                }
            }
          else // num > no->info => direita
          {
                insere(&(*no)->dir,Nvenda,status);
                printf("status = %d\n",*status);
                if(*status==0)//true
                {
                    printf("%d FB = %d\n",(*no)->venda.valor,(*no)->FB);
                    switch((*no)->FB)
                    {
                        case-1:
                            (*no)->FB=0;
                             printf("mudou status = %d\n\n",*status);
                            *status=1;//false
                        break;
                        case 0:
                            printf("%d mudou FB para 1\n",(*no)->venda.valor);
                            (*no)->FB=1;
                        break;
                        case 1:
                            printf("\n\nrotacionar esquerda\n");
                            (*no)=rotacionarEsq((*no),status);
                        break;
                    }
                }
            }
        }
    }
}

void imprimir_in_order(Avl *pai)
{
    if(pai->dir!=NULL)
    {
        imprimir_in_order(pai->dir);
    }
    printf(" %0.2f", pai->venda.valor);
    if(pai->esq!=NULL)
    {
        imprimir_in_order(pai->esq);
    }
}

#endif // FILA_H_INCLUDED
