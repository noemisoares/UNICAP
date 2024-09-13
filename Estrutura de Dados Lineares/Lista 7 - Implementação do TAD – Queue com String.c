//Lista 7 - Implementação do TAD – Queue com String - Estruturas de Dados Lineares

//RESPOSTAS DAS QUESTÕES DE CÓDIGO

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct QueueNode {
    char info[TAM];
    struct QueueNode *prox;
} QueueNode;

typedef struct {
    QueueNode *inicio;
    QueueNode *fim;
} Queue;

void inicializar(Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

char isEmpty(Queue *q) {
    return q->inicio == NULL;
}

void Enqueue(Queue *q, char* valor) {
    QueueNode *novo = malloc(sizeof(QueueNode));
    strcpy(novo->info, valor);
    novo->prox = NULL;
    if (isEmpty(q)) {
        q->inicio = novo;
    } else {
        q->fim->prox = novo;
    }
    q->fim = novo;
}

char* Dequeue(Queue *q) {
    QueueNode *aux = q->inicio;
    char* valor = malloc(sizeof (char) * 100);
    q->inicio = aux->prox;
    if (q->inicio == NULL) {
        q->fim = NULL;
    }
    strcpy(valor, aux->info);
    free(aux);
    return valor;
}

char* head(Queue q) {
    return q.inicio->info;
}

void list (Queue q) {
    QueueNode *aux = q.inicio;
    printf("Todos os Arquivos na fila:\n");
    while(aux != NULL){
        printf("%s\n", aux->info);
        aux = aux->prox;
    }
}

void cancel (Queue* q, char* valor) {
    QueueNode *aux = q->inicio;
    QueueNode *k = NULL;
    while(aux != NULL && strcmp(aux->info, valor) != 0){
        k = aux;
        aux = aux->prox;
    }
    if(aux == NULL) {
        printf("Arquivo %s nao encontrado na fila.\n", valor);
        return;
    }
    if(k == NULL){
        q->inicio = aux->prox;
    } else {
        k->prox = aux->prox;
    }
    if(aux == q->fim){
        q->fim = k;
    }
    free(aux);
    printf("Arquivo %s foi removido da fila.\n", valor);  
}

int main() {
    Queue fila;
    inicializar(&fila);
    int escolha;
    char nomeArquivo[TAM];
    char* r;

    do {
        printf("\nMenu da Fila:\n");
        printf("1 - Adicionar arquivo\n");
        printf("2 - Remover arquivo\n");
        printf("3 - Exibir primeiro arquivo\n");
        printf("4 - Listar todos os arquivos\n");
        printf("5 - Cancelar a impressao de um arquivo\n");
        printf("0 - Sair do menu\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                printf("Digite o nome do arquivo a ser adicionado: ");
                scanf("%100[^\n]s", nomeArquivo);
                Enqueue(&fila, nomeArquivo);
                break;

            case 2:
                r = Dequeue(&fila);
                if (r != NULL) {
                    printf("Arquivo removido: %s\n", r);
                    free(r);
                }
                break;

            case 3:
                printf("Primeiro arquivo na fila: %s\n", head(fila));
                break;

            case 4:
                list(fila);
                break;

            case 5:
                printf("Digite o nome do arquivo a ser cancelado: ");
                scanf("%100[^\n]s", nomeArquivo);
                cancel(&fila, nomeArquivo);
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 500

typedef struct QueueNode {
    char info[TAM];
    int num;
    struct QueueNode *prox;
} QueueNode;

typedef struct {
    QueueNode *inicio;
    QueueNode *fim;
} Queue;

void inicializar(Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

char isEmpty(Queue *q) {
    return q->inicio == NULL;
}

void Enqueue(Queue *q, int num, char* valor) {
    QueueNode *novo = malloc(sizeof(QueueNode));
    strcpy(novo->info, valor);
    novo->num = num;
    novo->prox = NULL;
    if (isEmpty(q)) {
        q->inicio = novo;
    } else {
        q->fim->prox = novo;
    }
    q->fim = novo;
    printf("Pedido %d adicionado: %s\n", num, valor);
}

void Dequeue(Queue *q) {
    QueueNode *aux = q->inicio;
    char* valor = malloc(sizeof (char) * 1000);
    q->inicio = aux->prox;
    strcpy(valor, aux->info);
    int num = aux->num;
    if (q->inicio == NULL) {
        q->fim = NULL;
    }
    free(aux);
    printf("Pedido %d esta pronto!: %s\n", num, valor);
}

char* head(Queue q) {
    return q.inicio->info;
}

void list (Queue q) {
    QueueNode *aux = q.inicio;
    printf("Pedidos aguardando atendimento::\n");
    while(aux != NULL){
        printf("Pedido %d: %s\n", aux->num, aux->info);
        aux = aux->prox;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueString.h"

int main() {
    Queue fila;
    inicializar(&fila);

    int escolha, numero;
    char descricao[TAM];

    do {
        printf("\nMenu de Atendimento:\n");
        printf("1 - Adicionar novo pedido\n");
        printf("2 - Atender pedido\n");
        printf("3 - Listar pedidos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                printf("Digite o numero do pedido: ");
                scanf("%d", &numero);
                getchar();
                printf("Digite a descricao do pedido: ");
                scanf("%500[^\n]s ", descricao);
                Enqueue(&fila, numero, descricao);
                break;

            case 2:
                if (isEmpty(&fila)) {
                    printf("Nao ha pedidos para atender.\n");
                } else {
                    Dequeue(&fila);
                }
                break;

            case 3:
                if (isEmpty(&fila)) {
                    printf("Nenhum pedido na fila.\n");
                } else {
                    list(fila);
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}