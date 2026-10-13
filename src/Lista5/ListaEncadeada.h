#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tarefa {
    int  codigo;
    char descricao[40];
    int  prioridade;   /* 1 = mais urgente ... 5 = menos urgente */
};
 
typedef struct elemento* ListaTarefas;

//Q1
int conta_tarefas_prioridade(ListaTarefas* li, int prioridade);

//Q2
int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t);

//Q3
int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t);

//Q4
int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t);

//Q5
int remove_tarefas_prioridade(ListaTarefas* li, int prioridade);

//Q6
int inverte_lista(ListaTarefas* li);

//Q7
int remove_tarefa_pos(ListaTarefas* li, int pos);

//Q8
int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src);

#endif
