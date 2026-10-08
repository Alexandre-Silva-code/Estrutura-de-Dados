#include "ListaEstatica.h"


int main(){
    Lista* lista_nula = NULL;
    printf("Teste nulo = R$%.2f\n", soma_precos(lista_nula));

    Lista minha_lista;
    minha_lista.qtd = 3;

    minha_lista.dados[0].preco= 10.5;
    minha_lista.dados[1].preco= 7.5;
    minha_lista.dados[2].preco= 12.0;

    float total = soma_precos(&minha_lista);
    printf("O total é R$%.2f\n", total);
    return 0;
}
