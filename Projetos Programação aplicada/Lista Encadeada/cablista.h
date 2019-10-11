#ifndef CABLISTA_INCLUDED
#define CABLISTA_INCLUDED

typedef struct no Lista;
void imprime_lista(Lista* cabeca);
Lista* inicia_lista ();
void insere_no (Lista* cabeca, Lista* novo_no);
Lista* cria_no (int dado);
int busca_no(Lista* cabeca, int valor);
#endif // CABLISTA_INCLUDED
