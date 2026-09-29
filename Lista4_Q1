#include <stdio.h>

#define MAX 100

struct lista {
    int qtd;
    int dados[MAX];
};

typedef struct lista Lista;

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
