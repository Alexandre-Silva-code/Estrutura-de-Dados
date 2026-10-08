#include <stdio.h>
#include <string.h>
#include "ListaEstatica.h"

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

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q1
//Implemente a função lista_tem_espaco, que devolve 1 se a lista comportar mais n inserções sem exceder o tamanho máximo, e 0 caso contrário (incluindo quando li é NULL).
//Observação: Não utilize inserções de teste: a resposta deve vir apenas da comparação entre os campos da lista e o parâmetro n.
//-------------------------------------------------------------------------------------------------------------------------------------------------------

int lista_tem_espaco(Lista* li, int n){
    if(li == NULL || n < 0){
        return 0;
    }
    if (li-> qtd + n <= MAX){
        return 1;
    } else{
        return 0;
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q2
//Implemente a função soma_precos, que devolve a soma do campo preco de todos os produtos armazenados na lista. Se li for NULL, a função deve devolver 0.
//-------------------------------------------------------------------------------------------------------------------------------------------------------

float soma_precos(Lista* li){
    if(li == NULL){
        return 0;
    }
    float preco = 0;
    for(int i = 0; i < li->qtd; i++){
        preco = preco + li->dados[i].preco;
    }
    return preco;
}



//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q3
//Implemente a função busca_por_nome, que busca na lista o primeiro produto cujo campo nome seja igual à string apontada por nome, e copia esse produto para *p. 
//A função devolve 1 em caso de sucesso e 0 caso o nome não seja encontrado ou li seja NULL.
//Observação: Utilize a função strcmp da biblioteca string.h para comparar as strings.
//-------------------------------------------------------------------------------------------------------------------------------------------------------

int busca_por_nome(Lista* li, char *nome, struct produto *p){
    if(li == NULL || nome == NULL || p == NULL){
        return 0;
    }

    for(int i = 0; i < li->qtd; i++){
        if(strcmp(li->dados[i].nome, nome) == 0){
            *p = li->dados[i];
            return 1;
        }
    }
    return 0;

}


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q4
//Implemente a função insere_lista_decrescente, que insere o produto p na lista mantendo-a ordenada de forma decrescente pelo campo preco. 
//A função segue a mesma convenção de retorno das demais funções de inserção.
//-------------------------------------------------------------------------------------------------------------------------------------------------------

int insere_lista_decrescente(Lista* li, struct produto p){
    if(li== NULL || li->qtd == MAX){
        return 0;
    }
    int i = 0;
    struct produto temp;
    li->dados[li->qtd]=p;
    li->qtd += 1;
    while(i != li->qtd){
        for(int t = 0; t < li->qtd-1; t++){
            if(li->dados[t].preco < li->dados[t+1].preco){
                temp = li->dados[t];
                li->dados[t] = li->dados[t+1];
                li->dados[t+1] = temp;
            }
        }
        i++;

    }
    return 1;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q5
//Implemente a função remove_mais_caro, que localiza o produto de maior preco na lista, remove-o utilizando a técnica de remoção otimizada (Aula 05) e copia o produto removido para *removido. 
//A função devolve 1 em caso de sucesso e 0 se a lista estiver vazia ou li for NULL.
//Observação: Em caso de empate entre dois ou mais produtos de maior preço, remova o primeiro deles na ordem em que aparece na lista.
//-------------------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q6

//-------------------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q7

//-------------------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q8

//-------------------------------------------------------------------------------------------------------------------------------------------------------
