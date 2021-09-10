/***************************************************
* Nome do(a) estudante: Maurício Jornada Bastos
*
* Professor(a): Graziela Santos de Araujo
*/

#include "michael_jackson.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
celula *lista = NULL;
celula *lst2 = NULL;
celula *lst3 = NULL;

int num, op, contador, menu;
float media;
    do{

        printf("\n1 - Inserir numero na lista ordenada");
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
            printf("Defina em qual lista deseja inserir o elemento. (1) ou (2)\n");
            scanf("%d", &menu);
            if(menu == 1){
                printf("Elemento: \n");
                scanf("%d", &num);
                insere_ordenado(num, &lista);
            }
            else if(menu == 2){
                printf("Elemento: \n");
                scanf("%d", &num);
                insere_ordenado(num, &lst2);
            }else{
                printf("Opcao invalida. ");
            }
        }
        if(op == 2)
        {
            system("cls");
            printf("Digite qual lista deseja verificar. (1), (2) ou (3)\n");
            scanf("%d", &menu);
            if(menu == 1){
                verifica(&lista);
            }else if(menu == 2){
                verifica(&lst2);
            }else if(menu == 3){
                verifica(&lst3);
            }
        }
        else if(op == 3)
        {
            system("cls");
            printf("Defina de qual lista deseja remover o elemento. (1) ou (2)\n");
            scanf("%d", &menu);
            if(menu == 1){
                printf("Digite o numero a ser removido. \n");
                scanf("%d", &num);
                remover(num, &lista);
            }else if(menu == 2){
                printf("Digite o numero a ser removido. \n");
                scanf("%d", &num);
                remover(num, &lst2);
            }
        }
        else if(op == 4)
        {
            system("cls");
            printf("Defina de qual lista deseja remover o elemento. (1) ou (2)\n");
            scanf("%d", &menu);
            if(menu == 1){
                printf("Digite a posicao do numero a ser removido. [Nota: primeira posicao = 0]\n");
                scanf("%d", &num);
                removerPos(num, &lista);
            }else if(menu == 2){
                printf("Digite a posicao do numero a ser removido. [Nota: primeira posicao = 0]\n");
                scanf("%d", &num);
                removerPos(num, &lst2);
            }
        }
        else if(op == 5)
        {
            system("cls");
            printf("Defina de qual lista deseja contar o nos. (1), (2) ou (3)\n");
            scanf("%d", &menu);
            if(menu == 1){
                contador = contaNos(lista);
                printf("A lista contem %d elementos.", contador);
            }else if(menu == 2){
                contador = contaNos(lst2);
                printf("A lista contem %d elementos.", contador);
            }else if(menu == 3){
                contador = contaNos(lst3);
                printf("A lista contem %d elementos.", contador);
            }
        }
        else if(op == 6)
        {
            system("cls");
            printf("Defina de qual lista deseja calcular a media. (1), (2) ou (3)\n");
            scanf("%d", &menu);
            if(menu == 1){
                media = mediaA(lista);
                printf("A media aritmetica da lista e: %f", media);
            }else if(menu == 2){
                media = mediaA(lst2);
                printf("A media aritmetica da lista e: %f", media);
            }else if(menu == 3){
                media = mediaA(lst3);
                printf("A media aritmetica da lista e: %f", media);
            }
        }
        else if(op == 7)
        {
            system("cls");
            iguais(&lista, &lst2);
        }
        else if(op == 8)
        {
            system("cls");
            intercala(lista, lst2, &lst3);
        }
        else if(op == 9)
        {
            system("cls");
            printf("Digite qual lista deseja imprimir. (1), (2) ou (3)\n");
            scanf("%d", &menu);
            if(menu == 1){
                imprimir(lista);
            }else if(menu == 2){
                imprimir(lst2);
            }else if(menu == 3){
                imprimir(lst3);
            }
        }
    }while(op != 0);

    apagar(&lista);
    apagar(&lst2);
    apagar(&lst3);
    return 0;
}


