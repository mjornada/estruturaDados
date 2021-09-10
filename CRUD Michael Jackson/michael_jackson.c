#include "michael_jackson.h"
#include <stdio.h>
#include <stdlib.h>

void apagar(celula **L){
//*L é o ponteiro para o primeiro elemento da lista
celula *p;

    while(*L){
        p=*L;
        *L=(*L)->prox;
        free(p);
    }
    *L=NULL;
}

void insere_ordenado(int n, celula **lst){
celula *novo, *ant, *p;

    novo = (celula*) malloc(sizeof(celula));
    novo->chave = n;
    novo->prox = NULL;

    if(*lst == NULL)
        *lst = novo;
    else{
        p = *lst;
        ant = NULL;
        while( p != NULL && p->chave < novo->chave){
            ant = p;
            p = p->prox;
        }
        if(ant == NULL)
        {
            novo->prox = p;
            *lst = novo;
        }
        else{
        novo->prox = p;
        ant->prox = novo;
        }
    }
}

float mediaA(celula *lst){
celula *p;
float media, contador, soma=0;
contador = 0;

    for(p=lst; p!=NULL; p=p->prox){
        contador++;
        soma = soma + p->chave;
    }
    media = soma / contador;
    return (media);

}

int contaNos(celula *lst){
celula *p;
int contador=0;

    for(p=lst; p!=NULL; p=p->prox)
        contador++;

    return contador;
}

void remover(int x, celula **lst)
{
celula *p, *q;
p = NULL;
q = *lst;
    while (q != NULL && q->chave != x) {
        p = q;
        q = q->prox;
    }
    if(q == NULL)
        printf("%d nao foi encontrado.", x);
    else{
        if (p != NULL)
            p->prox = q->prox;
        else
            *lst = q->prox;

        free(q);
    }
}

void removerPos(int x, celula **lst){
celula *p, *q;
p = NULL;
q = *lst;
int contaPos=0;
    while (q != NULL && contaPos != x) {
        contaPos++;
        p = q;
        q = q->prox;

    }
    if(q == NULL)
        printf("%d nao foi encontrado.", x);
    else{
        if (p != NULL)
            p->prox = q->prox;
        else
            *lst = q->prox;

        free(q);
    }
}

void imprimir(celula *lst)
{
    celula *p;
    for(p = lst; p != NULL; p = p->prox)
        printf("%d ", p->chave);

}

void iguais(celula **lista, celula **lst2){
celula *p, *q;
p = *lista;
q = *lst2;

    if(p == NULL && q == NULL){
        printf("As listas sao iguais. \n");
    return;
    }
    if(p == NULL || q == NULL){
        printf("As listas sao diferentes. \n");
        return;
    }
    while(p != NULL && q != NULL){
        if(p->chave != q->chave){
            printf("As listas sao diferentes. \n");
            return;
        }/*else if(p->prox == NULL && q->prox == NULL && p->chave == q->chave){
            printf("As listas sao iguais. \n");
        }*/
        p = p->prox;
        q = q->prox;
    }
    if(p == NULL && q==NULL){
            printf("As listas sao iguais. \n");
    }
    if(p == NULL && q != NULL){
            printf("As listas sao diferentes. \n");
    }
    if(p != NULL && q == NULL){
            printf("As listas sao diferentes. \n");
    }
}

void intercala(celula *lista, celula *lst2, celula **lst3){
int chavex, chavey, chavez;

    for(chavex =0, chavey=0; lista!=NULL && lst2!=NULL; ){
        chavex = lista->chave;
        chavey = lst2->chave;
        if(chavex < chavey){
            chavez = chavex;
            insere_ordenado(chavez, lst3);
            lista = lista->prox;
        }else{
            chavez = chavey;
            insere_ordenado(chavez, lst3);
            lst2 = lst2->prox;
        }
    }
    while(lista != NULL){
        insere_ordenado(lista->chave, lst3);
        lista = lista->prox;
    }
    while(lst2 != NULL){
        insere_ordenado(lst2->chave, lst3);
        lst2 = lst2->prox;
    }
}

void verifica(celula **L){
    if(*L != NULL){
        printf("A lista nao esta vazia.");
    }else{
        printf("A lista esta vazia.");
    }
}

int teste(celula **L){
    if(*L != NULL){
        return 1;
    }else{
        return 0;
    }
}
