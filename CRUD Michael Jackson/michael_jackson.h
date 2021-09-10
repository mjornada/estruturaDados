#include <stdio.h>
#include <stdlib.h> /*malloc, calloc, free*/

typedef struct cel
{
    int chave;
    struct cel *prox;
}celula;

void apagar(celula **L);

void insere_ordenado(int n, celula **lst);

float mediaA(celula *lst);

int contaNos(celula *lst);

void remover(int x, celula **lst);

void removerPos(int x, celula **lst);

void imprimir(celula *lst);

void iguais(celula **lista, celula **lst2);

void verifica(celula **L);

int teste(celula **L);

void intercala(celula *lista, celula *lst2, celula **lst3);
