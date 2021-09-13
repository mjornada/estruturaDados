/**************************************************
*
* Maurício Jornada Bastos
* Rafael Patricio Rodrigues
* Trabalho 1 - Analisador Lexico
* Professor(a): Fabio Henrique Viduani Martinez
*
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;
const int tamanho = 41;
#define MAX 100
//struct hash{
//    int chave;
//    hash* proximo;
//};

struct hash{
    char lexico[20];
    int linhas[MAX];
    hash* proximo;
} typedef t_hash;

struct hash *novo;
struct hash *prim = NULL;

int valor(char palavra[]){
int i, soma=0;
    //CALCULA A SOMA DOS VALORES ASCII DOS CARACTERES DA PALAVRA
    for (i = 0; palavra[i] != '\0'; i++){
        soma = soma + palavra[i];
    }
    return soma;
}

void inserirPal(t_hash* tabela[], int posicao, char palavra[]){
t_hash* aux;
    cout << " \n == INSERINDO == \n";
        //VERIFICA SE A PALAVRA JA FOI INSERIDA ANTERIORMENTE
        aux = tabela[posicao];
        while(aux!=NULL){
            if(strcmp(aux->lexico, palavra) == 0){
                cout << " \n Esta palavra ja foi inserida anteriormente. \n";
                return;
            }
            aux = aux->proximo;
        }
        //INSERE A PALAVRA
        struct hash *novo = (struct hash*) malloc(sizeof(struct hash));
        strcpy(novo->lexico, palavra);
        novo->proximo = tabela[posicao];
        tabela[posicao] = novo;

    cout << "\n Elemento " << novo->lexico << " inserido com sucesso! \n";
}

int hashing (int numero){
    cout << "\n == FUNCAO HASING == \n";
    //CALCULA A POSICAO QUE A PALAVRA DEVE SER INSERIDA
    int posicao;
    posicao = numero%41;
    return (posicao);
}

void imprimir(t_hash* tabela[]){
   /* cout << "\n == IMPRIMINDO == \n";
    t_hash* aux;
    for(int i=0; i<tamanho; i++){
        aux = tabela[i];
        cout<< i << ": ";
        while(aux!=NULL){
            cout<< aux->chave << " ";
           // cout<< i << ": " <<  " Chave: " << aux->chave;
            aux = aux->proximo;
        }
    cout << "\n";
    }
    cout << "\n";*/
}

void imprimirPal(t_hash* tabela[]){
    cout << "\n == IMPRIMINDO == \n";
    t_hash* aux;
    for(int i=0; i<tamanho; i++){
        aux = tabela[i];
        cout<< i << ": ";
            while(aux!=NULL){
                cout<< aux->lexico << " ";
                aux = aux->proximo;
            }
    cout << "\n";
    }
    cout << "\n";
}

void excluir(t_hash* tabela[], int numero){
/*    cout << " \n == EXCLUINDO == \n";
    int posicao = hashing(numero);
    t_hash* aux;
    if(tabela[posicao] != NULL){
        if(tabela[posicao]->chave == numero){
            aux = tabela[posicao];
            cout << " \n Numero " << aux->chave << " excluido com sucesso! \n";
            delete aux;
        }
        else{
            aux = tabela[posicao]->proximo;
            t_hash* ant = tabela[posicao];

            while((aux != NULL)&&(aux->chave != numero)){
                ant = aux;
                aux = aux->proximo;
            }
            if( aux != NULL){
                ant->proximo = aux->proximo;
                cout <<" \n Numero " << aux->chave << " excluido com sucesso! \n";
                delete aux;
            }
            else{
                cout << "\n Numero nao encontrado. \n";
            }
        }
    }
    else{
        cout << " \n Numero nao encontrado. \n";
    }*/
}

void excluirPalavra(t_hash* tabela[], char palavra[]){
int val, posicao;
t_hash* atual;
t_hash* ant;
    cout << " \n == EXCLUINDO == \n";
    //ENCONTRA POSICAO NA TABELA E CRIA STRUCTS AUXILIARES
    val = valor(palavra);
    posicao = hashing(val);
    atual = tabela[posicao];
    ant = atual;
    //PERCORRE A LISTA ATE ENCONTRAR A PALAVRA E EXCLUI

    while((atual!=NULL) && (strcmp(atual->lexico, palavra) != 0)){
        ant=atual;
        atual=atual->proximo;
    }

    if (atual == NULL || tabela == NULL){
        cout<<"Elemento nao encontrado. ";
        return;
    }
    else if(ant == NULL){
        tabela[posicao] = atual->proximo;
    }else if(atual->proximo == NULL){
        ant->proximo = NULL;
    }else{
        ant->proximo = atual->proximo;
    }
    printf("\n  Nome removido com sucesso!\n\n");
    delete(atual);
    return;
}

void excluirPal(t_hash* tabela[], char palavra[]){
int val, posicao;
t_hash* aux;
t_hash* ant;

    cout << " \n == EXCLUINDO == \n";
    val = valor(palavra);
    posicao = hashing(val);

    if(tabela[posicao] != NULL){
        if(strcmp(tabela[posicao]->lexico, palavra) == 0){
            aux = tabela[posicao];
            cout << " \n Palavra " << aux->lexico << " excluida com sucesso! \n";
            delete aux;
        }
        else{
            aux = tabela[posicao]->proximo;
            ant = tabela[posicao];

            while((aux != NULL)&&(strcmp(aux->lexico, palavra) != 0)){
                ant = aux;
                aux = aux->proximo;
            }
            if( aux != NULL){
                ant->proximo = aux->proximo;
                cout <<" \n Palavra " << aux->lexico << " excluida com sucesso! \n";
                delete aux;
            }
            else{
                cout << "\n Palavra nao encontrada. \n";
            }
        }
    }
    else{
        cout << " \n Palavra nao encontrada. \n";
    }
}

void inicializar(t_hash* tabela[]){
    cout << " \n == INICIALIZANDO == \n";
    //INICIALIZA A TABELA HASH
    for(int i=0; i<tamanho; i++){
        tabela[i] = NULL;
    }
}

void destruir(t_hash* tabela[]){
    cout << " \n == DESTRUINDO == \n";
    //LIBERA O ESPAÇO DA MEMORIA
    t_hash* aux;
    for(int i=0; i<tamanho; i++){
        while(tabela[i] != NULL){
            aux = tabela[i];
            tabela[i] = tabela[i]->proximo;
            delete aux;
        }
    }
}

void analisador(t_hash* tabela[], char arquivoEntrada[]){
FILE *ptentrada;
    ptentrada = fopen(arquivoEntrada, "r");
}

int main(){
t_hash* tabela[tamanho];
t_hash	* aux;
int opcao, posicao, numero, val;
char palavra[20];
char arquivoEntrada[MAX+1];
FILE *ptentrada;

do{
    cout <<" \n | MENU                |";
    cout <<" \n | 1. Inicializar      |";
    cout <<" \n | 2. Inserir          |";
    cout <<" \n | 3. Analisar Arquivo |";
    cout <<" \n | 4. Imprimir         |";
    cout <<" \n | 5. Destruir         |";
    cout <<" \n | 6. Sair             |";
    cout <<" \n";
    cout <<" \n Digite a opcao desejada:    \n";
    cin >> opcao;

    switch(opcao){
    case 1:
        system("cls");
        inicializar(tabela);
        break;
    case 2:
        system("cls");
        cout << " \n Digite uma palavra: ";
        cin >> palavra;
        val = valor(palavra);
        posicao = hashing(val);
        inserirPal(tabela, posicao, palavra);
        break;
    case 3:
        system("cls");
        cout << " \n Digite o nome do Arquivo a ser Analisado: ";
        cin >> arquivoEntrada;
        analisador(tabela, arquivoEntrada);
        break;
    case 4:
        system("cls");
        imprimirPal(tabela);
        break;
    case 5:
        system("cls");
        destruir(tabela);
        break;
    default:
        cout << " \n OPCAO INVALIDA ";
    }
}
while(opcao!=6);
return 0;
}



