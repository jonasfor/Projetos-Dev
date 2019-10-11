#include <stdio.h>
#include <stdlib.h>
#include "cablista.h"

int main(){
    Lista* cabeca;
    Lista* no;
    cabeca = inicia_lista();
    no = cria_no(32);
    insere_no(cabeca, no);
    no = cria_no(42);
    insere_no(cabeca, no);
    no = cria_no(52);
    insere_no(cabeca, no);
    no = cria_no(62);
    insere_no(cabeca, no);
    imprime_lista(cabeca);
    busca_no(cabeca, 52);
    return 0;
}
