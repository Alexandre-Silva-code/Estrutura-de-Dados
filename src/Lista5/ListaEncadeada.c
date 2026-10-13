#include "ListaEncadeada.h"

/* Cada elemento guarda os dados e o endereco do proximo elemento.
   O ultimo elemento aponta para NULL. */
struct elemento {
    struct tarefa dados;
    struct elemento *prox;
};
typedef struct elemento Elem;




//Q1
int conta_tarefas_prioridade(ListaTarefas* li, int prioridade){
    if(li == NULL){
        return -1;
    }
    int contador = 0;
    Elem* atual = *li;

    while(atual != NULL){
        if(atual->dados.prioridade == prioridade){
            contador++;
        }
        atual = atual->prox;
    }

    return contador;

}



//Q2
int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t){
    if(li == NULL || *li == NULL || t == NULL){
        return 0;
    }
    Elem* atual = *li;

    *t = atual->dados;
    atual = atual->prox;

    while(atual != NULL){
        if(t->prioridade == 1){
            break;
        }
        if(t->prioridade > atual->dados.prioridade){
            *t = atual->dados;
        }
        atual = atual->prox;

    }
    return 1;
    
}



//Q3
int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t){
    if(li == NULL || *li == NULL || t == NULL || texto == NULL){
        return 0;
    }

    ListaTarefas atual = *li;
    while(atual != NULL){
        if(strstr(atual->dados.descricao, texto)){
            *t = atual->dados;
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}



//Q4

int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t) {
    if (li == NULL) {
        return 0;
    }

    Elem* novo = (Elem*) malloc(sizeof(Elem));
    if (novo == NULL) {
        return 0;
    }
    novo->dados = t;
    novo->prox = NULL;

    if (*li == NULL) {
        *li = novo;
        return 1;
    }

    Elem* atual = *li;
    Elem* ultimo_igual = NULL;

    while (atual != NULL) {
        if (atual->dados.prioridade == t.prioridade) {
            ultimo_igual = atual;
        }
        atual = atual->prox;
    }

    if (ultimo_igual != NULL) {
        novo->prox = ultimo_igual->prox;
        ultimo_igual->prox = novo;
    } else {
        atual = *li;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }

    return 1;
}



//Q5

int remove_tarefas_prioridade(ListaTarefas* li, int prioridade) {
    if (li == NULL) {
        return -1;
    }

    int removidas = 0;
    Elem* atual = *li;
    Elem* ant = NULL;

    while (atual != NULL) {
        if (atual->dados.prioridade == prioridade) {
            Elem* aux = atual;

            if (ant == NULL) {
                *li = atual->prox;
                atual = *li;
            } else {
                ant->prox = atual->prox;
                atual = atual->prox;
            }

            free(aux);
            removidas++;
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }

    return removidas;
}



//Q6

int inverte_lista(ListaTarefas* li) {
    if (li == NULL) {
        return 0;
    }
    
    if (*li == NULL || (*li)->prox == NULL) {
        return 1;
    }

    Elem* anterior = NULL;
    Elem* atual = *li;
    Elem* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *li = anterior;
    return 1;
}



//Q7

int remove_tarefa_pos(ListaTarefas* li, int pos) {
    if (li == NULL || *li == NULL || pos <= 0) {
        return 0;
    }

    Elem* atual = *li;
    Elem* ant = NULL;
    int i = 1;

    while (atual != NULL && i < pos) {
        ant = atual;
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        return 0;
    }

    if (ant == NULL) {
        *li = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    return 1;
}



//Q8

int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src) {
    if (dst == NULL || src == NULL) {
        return -1;
    }

    if (*src == NULL) {
        return 0;
    }

    int contador = 0;
    Elem* atual = *src;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    if (*dst == NULL) {
        *dst = *src;
    } else {
        Elem* ultimo = *dst;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = *src;
    }

    *src = NULL;
    return contador;
}
