#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct produto{
    int codigo;
    char nome[50];
    float preco;
};

struct lista{
    int qtd;
    struct produto dados[MAX];
};

typedef struct lista Lista;

//Q1
int lista_tem_espaco(Lista* li, int n);

//Q2
float soma_precos(Lista* li);

//Q3
int busca_por_nome(Lista* li, char *nome, struct produto *p);

//Q4
int insere_lista_decrescente(Lista* li, struct produto p);

//Q5
int remove_mais_caro(Lista* li, struct produto *removido);

//Q6
int conta_faixa_preco(Lista* li, float min, float max);

//Q7
int remove_abaixo_de(Lista* li, float precoMinimo);

//Q8
int mescla_listas(Lista* destino, Lista* origem);

#endif
