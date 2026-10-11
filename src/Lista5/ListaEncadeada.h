#include <stdio.h>
#include <stdlib.h>

struct tarefa {
    int  codigo;
    char descricao[40];
    int  prioridade;   /* 1 = mais urgente ... 5 = menos urgente */
};
 
typedef struct elemento* ListaTarefas;

