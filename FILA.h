#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct pet{
    int id;
    char nome[50];
    char especie[20];
    int idade;
    Data data_nasc;
    int prioridade;
}Pet;

typedef struct nos{
    Pet info;
    struct nos *prox;
}Nos;

typedef struct fila{
    Nos *ini;
    Nos *fim;
}Fila;

int FilaVazia(Fila *f){
    if(f->ini == NULL) return 1;
    return 0;
}

Fila* InicializarFila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void InserirNaFila(Fila *f, Pet novo){
    Nos *aux = (Nos*) malloc(sizeof(Nos));
    aux->info = novo;
    aux->prox = NULL;

    if(f->ini == NULL){
        f->ini = aux;
    }else{
        f->fim = aux;
    }

    f->fim = novo;
}

#endif // FILA_H_INCLUDED
