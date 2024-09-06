//Lista 6 - Implementação do TAD – Queue - Estruturas de Dados Lineares

//RESPOSTAS DAS QUESTÕES DE CÓDIGO

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Queue {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} queue;

void inicializar(queue *q) {
    q->inicio = 0;
    q->fim = -1;
    q->tamanho = 0;
}

int isEmpty(queue *q) {
    return q->tamanho == 0;
}

int isFull(queue *q) {
    return q->tamanho == MAX;
}

void Enqueue(queue *q, int valor) {
    q->fim = (q->fim + 1) % MAX;
    q->dados[q->fim] = valor;
    q->tamanho++;
    printf("Senha %d emitida com sucesso.\n", valor);
}

int Dequeue(queue *q) {
    int valor = q->dados[q->inicio];
    q->inicio = (q->inicio + 1) % MAX;
    q->tamanho--;
    return valor;
}

int head(queue *q) {
    return q->dados[q->inicio];
}

int main() {
    queue q;
    inicializar(&q);
    int opcao, senha = 1, atendido = -1, proxSenha = -1;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Solicitar uma nova senha\n");
        printf("2. Atender um cliente\n");
        printf("3. Mostrar a proxima senha a ser atendida\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (isFull(&q)) {
                    printf("Nao ha senhas disponiveis.\n");
                } else {
                    Enqueue(&q, senha++);
                }
                break;
            case 2:
                if (isEmpty(&q)) {
                    printf("Nao ha clientes na fila de espera.\n");
                    atendido = -1;
                } else {
                    atendido = Dequeue(&q);
                }
                if (atendido != -1) {
                    printf("Atendendo senha: %d\n", atendido);
                }
                break;
            case 3:
                if (isEmpty(&q)) {
                    printf("A fila esta vazia.\n");
                    proxSenha = -1;
                } else {
                    proxSenha = head(&q);    
                }
                if (proxSenha != -1) {
                    printf("A proxima senha a ser atendida eh: %d\n", proxSenha);
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>

#define MAX 8

typedef struct Queue {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} queue;

void inicializar(queue *q) {
    q->inicio = 0;
    q->fim = -1;
    q->tamanho = 0;
}

int isEmpty(queue *q) {
    return q->tamanho == 0;
}

int isFull(queue *q) {
    return q->tamanho == MAX;
}

void Enqueue(queue *q, int valor) {
    q->fim = (q->fim + 1) % MAX;
    q->dados[q->fim] = valor;
    q->tamanho++;
    printf("Elemento %d adicionado a fila.\n", valor);
}

int Dequeue(queue *q) {
    int valor = q->dados[q->inicio];
    q->inicio = (q->inicio + 1) % MAX;
    q->tamanho--;
    return valor;
}

int head(queue *q) {
    return q->dados[q->inicio];
}

int main() {
    queue q;
    inicializar(&q);
    int opcao, valor;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar um elemento\n");
        printf("2. Remover um elemento\n");
        printf("3. Mostrar o proximo elemento a ser removido\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                if (isFull(&q)) {
                    printf("A fila esta cheia. Nao eh possivel adicionar.\n");
                } else {
                    printf("Digite o valor a ser adicionado: ");
                    scanf("%d", &valor);
                    Enqueue(&q, valor);
                }
                break;
            case 2:
                if (isEmpty(&q)) {
                    printf("A fila esta vazia.\n");
                } else {
                    int removido = Dequeue(&q);
                    if (removido != -1) {
                        printf("Elemento removido: %d\n", removido);
                    }
                }
                break;
            case 3:
                if (isEmpty(&q)) {
                    printf("A fila esta vazia.\n");
                } else {
                int proxElemento = head(&q);
                    if (proxElemento != -1) {
                        printf("Proximo elemento a ser removido: %d\n", proxElemento);
                    }
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
    int info;
    struct queueNode *prox;
} QueueNode;

typedef struct queue {
    QueueNode *inicio;
    QueueNode *fim;
} Queue;

void inicializar(Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int isEmpty(Queue *q) {
    return q->inicio == NULL;
}

void Enqueue(Queue *q, int valor) {
    QueueNode *novo = malloc(sizeof(QueueNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(q)) {
        q->inicio = novo;
    } else {
        q->fim->prox = novo;
    }
    q->fim = novo;
    printf("Senha %d emitida com sucesso.\n", valor);
}

int Dequeue(Queue *q) {
    QueueNode *aux = q->inicio;
    int valor = aux->info;
    q->inicio = aux->prox;
    if (q->inicio == NULL) {
        q->fim = NULL;
    }
    free(aux);
    return valor;
}

int head(Queue *q) {
    return q->inicio->info;
}

int main() {
    Queue q;
    inicializar(&q);
    int opcao, senha = 1, atendido = -1, proxSenha = -1;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Solicitar uma nova senha\n");
        printf("2. Atender um cliente\n");
        printf("3. Mostrar a proxima senha a ser atendida\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Enqueue(&q, senha++);
                break;
            case 2:
                if (isEmpty(&q)) {
                    printf("Nao ha clientes na fila de espera.\n");
                    atendido = -1;
                } else {
                    atendido = Dequeue(&q);
                }
                if (atendido != -1) {
                    printf("Atendendo senha: %d\n", atendido);
                }
                break;
            case 3:
                if (isEmpty(&q)) {
                    printf("A fila esta vazia.\n");
                    proxSenha = -1;
                } else {
                    proxSenha = head(&q);    
                }
                if (proxSenha != -1) {
                    printf("A proxima senha a ser atendida eh: %d\n", proxSenha);
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}