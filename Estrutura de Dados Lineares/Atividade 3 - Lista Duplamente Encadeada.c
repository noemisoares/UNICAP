//Atividade 3 - Lista Duplamente Encadeada - Estruturas de Dados Lineares

//QUESTÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaNode {
    int info;
    struct listaNode *prox;
    struct listaNode *ant;
} ListaNode;

typedef struct lde {
    ListaNode *inicio;
    ListaNode *fim;
    int qtd;
} LDE;

void inicializar(LDE *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDE *l) {
    return l->qtd == 0;
}

ListaNode *criarNovo(int valor) {
    ListaNode *aux = (ListaNode*) malloc(sizeof(ListaNode));
    aux->info = valor;
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
}

void inserir(LDE *l, int valor) {
    ListaNode *novo = criarNovo(valor);

    if (isEmpty(l)) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->qtd++;
    printf("Insercao efetuada!\n");
}

void remover(LDE *l, int valor) {
    if (isEmpty(l)) {
        printf("Lista vazia.\n");
        return;
    }

    ListaNode *aux = l->inicio;
    int encontrou = 0, count = 0;

    while (aux != NULL) {
        if (aux->info == valor) {
            encontrou = 1;
            ListaNode *remover = aux;
            aux = aux->prox;

            if(remover == l->inicio){
                l->inicio = l->inicio->prox;
                l->inicio->ant = NULL;
            } else if (remover == l->fim){
                l->fim = l->fim->ant;
                l->fim->prox = NULL;
            } else {
                remover->ant->prox = remover->prox;
                remover->prox->ant = remover->ant;
            }
            free(remover);
            l->qtd--;
            count++;
        } else {
            aux = aux->prox;
        }
    }

    if (encontrou) {
        printf("Foram removidos %d valores iguais a %d.\n", count, valor);
    } else {
        printf("Valor %d nao encontrado na lista.\n", valor);
    }
}

void listarNormal(LDE l) {
    ListaNode *aux = l.inicio;
    if (isEmpty(&l)) {
        printf("Lista vazia.\n");
    } else {
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void exibirOpcoes() {
    printf("Opcoes\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Listar\n");
    printf("0 - Encerrar programa\n");
    printf("Informe a opcao desejada: ");
}

int main() {
    LDE lista;
    int num, op;

    inicializar(&lista);
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &num);
                inserir(&lista, num);
                break;
            case 2:
                printf("Informe o valor: ");
                scanf("%d", &num);
                remover(&lista, num);
                break;
            case 3:
                listarNormal(lista);
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (op != 0);

    return 0;
}