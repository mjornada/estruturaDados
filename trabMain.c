/*
* Nome do(a) estudante: Maurício Jornada Bastos
*
* Professor(a): Graziela Santos de Araújo
*/
#include <stdio.h>
#include <stdlib.h> /*malloc, calloc, free*/

typedef struct cel
{
    int chave;
    struct cel *prox;
}celula;

float mediaA(celula *lst);

/*Funcao que apaga todos os nos da lista L*/
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

void inserir_inicio(int n, celula **lst){
celula *novo;

    novo = (celula*) malloc(sizeof(celula));
    novo->chave = n;
    novo->prox = NULL;

    novo->prox = *lst;
    *lst = novo;

}

void inserir_fim(int n, celula **lst)
{
    celula *novo, *p;

    novo = (celula*) malloc(sizeof(celula));
    novo->chave = n;
    novo->prox = NULL;

    if(*lst == NULL)
        *lst = novo;
    else{
        p = *lst;
        while(p->prox != NULL)
            p = p->prox;

        p->prox = novo;
    }
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
int contador, soma =0;
float media;
contador = 0;

    for(p=lst; p!=NULL; p=p->prox){
        contador++;
        soma = soma + p->chave;
    }
    //media = soma / contador;
    return (soma/contador);

}

int contaNos(celula *lst){
celula *p;
int contador=0;

    for(p=lst; p!=NULL; p=p->prox)
        contador++;

    /*
    p = lst;
    while(p != NULL){
    contador++;
    p=p->prox;
    }*/
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

/*Funcao imprime o campo chave armazenado em cada no da lista L*/
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

    if(p->chave == NULL && q->chave == NULL){
        printf("As listas sao iguais. \n");
    }
    if(p->chave == NULL || q->chave == NULL){
        printf("As listas sao diferentes. \n");
    }
    while(p->prox != NULL && p->prox != NULL){
        if(p->chave != q->chave){
            printf("As listas sao diferentes. \n");
        }else if(p->prox == NULL && q->prox == NULL && p->chave == q->chave){
            printf("As listas sao iguais. \n");
        }
        p = p->prox;
        q = q->prox;
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

/**/
int main(){
celula *lista = NULL;
celula *lst2 = NULL;  /*lista sem cabeca vazia*/

int num, op, contador, menu, testVer;
float media;
    do{

        printf("\n\n1 - Inserir numero na lista ordenada");
        printf("\n2 - Verificar se a lista esta vazia");
        printf("\n3 - Remover um elemento da lista");
        printf("\n4 - Remover uma posicao da lista");
        printf("\n5 - Calcular o tamanho da lista");
        printf("\n6 - Media aritmetica dos elementos da lista");
        printf("\n7 - Conferir se as 2 listas sao iguais");
        printf("\n8 - Intercalar as 2 listas");
        printf("\n9 - Imprimir lista");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if(op == 1)
        {
            system("cls");
            printf("Defina em qual lista deseja inserir o elemento. (1) ou (2)");
            printf("\n");
            scanf("%d", &menu);
            if(menu == 1){
                printf("Elemento: ");
                scanf("%d", &num);
                insere_ordenado(num, &lista);
            }
            else if(menu == 2){
                printf("Elemento: ");
                scanf("%d", &num);
                insere_ordenado(num, &lst2);
            }else{
                printf("Opcao invalida. ");
            }
        }
        if(op == 2)
        {
            system("cls");
            printf("Digite qual lista deseja verificar. (1) ou (2)");
            printf("\n");
            scanf("%d", &menu);
            if(menu == 1){
                verifica(&lista);
            }else if(menu == 2){
                verifica(&lst2);
            }
        }
        else if(op == 3)
        {
            system("cls");
            printf("Defina de qual lista deseja remover o elemento. (1) ou (2)");
            printf("\n");
            scanf("%d", &menu);
            if(menu == 1){
                printf("Digite o numero a ser removido. ");
                scanf("%d", &num);
                remover(num, &lista);
            }else if(menu == 2){
                printf("Digite o numero a ser removido. ");
                scanf("%d", &num);
                remover(num, &lst2);
            }
        }
        else if(op == 4)
        {
            system("cls");
            printf("Defina de qual lista deseja remover o elemento. (1) ou (2)");
            printf("\n");
            scanf("%d", &menu);
            if(menu == 1){
                printf("Digite a posicao do numero a ser removido. ");
                scanf("%d", &num);
                removerPos(num, &lista);
            }else if(menu == 2){
                printf("Digite a posicao do numero a ser removido. ");
                scanf("%d", &num);
                removerPos(num, &lst2);
            }
        }
        else if(op == 5)
        {
            system("cls");
            printf("Defina de qual lista deseja contar o nos. (1) ou (2)");
            printf("\n");
            scanf("%d", &menu);
            if(menu == 1){
                contador = contaNos(lista);
                printf("A lista contem %d elementos.", contador);
            }else if(menu == 2){
                contador = contaNos(lst2);
                printf("A lista contem %d elementos.", contador);
            }
        }
        else if(op == 6)
        {
            system("cls");
            printf("Defina de qual lista deseja calcular a media. (1) ou (2)");
            printf("\n");
            scanf("%d", &menu);
            if(menu == 1){
                media = mediaA(lista);
                printf("A media aritmetica da lista e: %f", media);
            }else if(menu == 2){
                media = mediaA(lst2);
                printf("A media aritmetica da lista e: %f", media);
            }
        }
        else if(op == 7)
        {
            //system("cls");
            iguais(&lista, &lst2);
        }
        else if(op == 8)
        {

        }
        else if(op == 9)
        {
            system("cls");
            printf("Digite qual lista deseja imprimir. (1) ou (2)");
            printf("\n");
            scanf("%d", &menu);
            if(menu == 1){
                imprimir(lista);
            }else if(menu == 2){
                imprimir(lst2);
            }
        }
    }while(op != 0);

    /*apagar toda a lista encadeada alocada dinamicamente*/
    apagar(&lista);
    apagar(&lst2);
    return 0;
}
