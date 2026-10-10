#include "ListaEstatica.h"

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

int remove_mais_caro(Lista* li, struct produto *removido){
    if(li == NULL || li->qtd == 0){
        return 0;
    }
    int posicao = 0;
    for(int i = 1; i < li->qtd; i++){
        if(li->dados[i].preco > li->dados[posicao].preco){
            posicao = i;
        }
    }
    *removido = li->dados[posicao];
    li->dados[posicao] = li->dados[li->qtd-1];
    li->qtd--;
    return 1;
}



//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q6
//Implemente a função conta_faixa_preco, que devolve quantos produtos da lista têm o campo preco entre min e max, incluindo os dois limites. A função não deve alterar a lista.
//-------------------------------------------------------------------------------------------------------------------------------------------------------

int conta_faixa_preco(Lista* li, float min, float max)


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q7
//Implemente a função remove_abaixo_de, que remove da lista, utilizando a técnica de remoção otimizada, todos os produtos cujo preco seja menor que precoMinimo. A função devolve o número de produtos removidos.
//Observação: Atenção: após a remoção otimizada de uma posição i, o elemento que passa a ocupar essa posição ainda não foi conferido pela função. Avaliar essa posição novamente, antes de avançar, é parte do problema.
//-------------------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------------------
//Q8
//Implemente a função mescla_listas, que insere ao final de destino cada produto de origem cujo codigo ainda não exista em destino, sem removê-lo de origem. 
//A função respeita o espaço disponível em destino e devolve quantos produtos foram efetivamente inseridos.
//Observação: Se um código já existir em destino, o produto correspondente de origem deve ser ignorado, mesmo que os demais campos sejam diferentes.
//Observação: Se destino ficar cheio antes de todos os produtos de origem serem avaliados, a função deve parar e devolver a contagem obtida até ali.
//-------------------------------------------------------------------------------------------------------------------------------------------------------
