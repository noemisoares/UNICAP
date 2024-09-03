//Lista 5 - Implementação do TAD – Stack Encadeada - Estruturas de Dados Lineares

//RESPOSTAS DAS QUESTÕES DE CÓDIGO

//PARTE 1 - STACK
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int info;
    struct StackNode *prox;
} stackNode;

typedef stackNode *stack;

void inicializar(stack *s) {
    *s = NULL;
}

int isEmpty(stack s) {
    return s == NULL;
}

int isFull(){
    return 0;
}

void push(stack *s, int valor) {
    stackNode *novo = malloc(sizeof(stackNode));
    novo->info = valor;
    novo->prox = *s;
    *s = novo;
}

int pop(stack *s) {
    stackNode *aux = *s;
    *s = (*s)->prox;
    int valor = aux->info;
    free(aux);
    return valor;
}

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>
#include "StackNode.h"

int inverterNumero(int numero) {
    stack s;
    inicializar(&s);
    while (numero > 0) {
        push(&s, numero % 10);
        numero /= 10;
    }
    int numeroInvertido = 0;
    int k = 1;
    while (!isEmpty(s)) {
        numeroInvertido += pop(&s) * k;
        k *= 10;
    }
    return numeroInvertido;
}

int main() {
    int numero;

    do {
        printf("Informe um inteiro maior que zero: ");
        scanf("%d", &numero);
    } while (numero <= 0);

    printf("Numero invertido: %d\n", inverterNumero(numero));

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>
#include "StackNode.h"

void converterBinario(int numero) {
    stack s;
    inicializar(&s);

    while (numero) {
        int k = numero % 2;
        push(&s, k);
        numero = numero / 2;
    }

    printf("Em Binario eh: ");
    while (!isEmpty(s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int numero;

    printf("Informe um inteiro: ");
    scanf("%d", &numero);

    converterBinario(numero);

    return 0;
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackNode.h"

int Palindromo(char palavra[]) {
    stack s;
    inicializar(&s);

    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++) {
        push(&s, palavra[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] != pop(&s)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char palavra[100];

    printf("Informe uma palavra: ");
    scanf("%s", palavra);

    if (Palindromo(palavra)) {
        printf("A palavra '%s' eh um palindromo.\n", palavra);
    } else {
        printf("A palavra '%s' nao eh um palindromo.\n", palavra);
    }

    return 0;
}

//PARTE 2 - QUEUE
//QUESTÃO 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct queue {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} queue;

void inicializar(Queue *q) {
    q->inicio = 0;
    q->fim = -1;
    q->tamanho = 0;
}

int isEmpty(Queue *q) {
    return q->tamanho == 0;
}

int isFull(Queue *q) {
    return q->tamanho == MAX;
}

void Enqueue(Queue *q, int valor) {
    if (isFull(q)) {
        printf("Fila cheia. Não é possível enfileirar.\n");
        return;
    }
    q->fim = (q->fim + 1) % MAX;
    q->dados[q->fim] = valor;
    q->tamanho++;
}

int Dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        exit(1);
    }
    int valor = q->dados[q->inicio];
    q->inicio = (q->inicio + 1) % MAX;
    q->tamanho--;
    return valor;
}

int head(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nenhum elemento no início.\n");
        exit(1);
    }
    return q->dados[q->inicio];
}

void exibirOpcoes () {
    printf ("Opcoes \n");
    printf ("1 - Empilhar \n");
    printf ("2 - Desempilhar \n");
    printf ("3 - Ver topo \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opcao desejada: ");
}

int main () {
    queue fila;
    int num, op;

    inicializar(&fila);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: if (isFull (&fila) == 1) {
                        printf ("Stack full! \n");
                    }
                    else {
                        printf ("Informe o valor a ser empilhado: ");
                        scanf ("%d",&num);
                        Enqueue (&fila,num);
                    }
                    break;
            case 2: if (isEmpty (&fila) == 1) {
                        printf ("Stack empty! \n");
                    }
                    else {
                        num = Dequeue (&fila);
                        printf ("Valor desempilhado: %d \n", num);
                    }
                    break;
            case 3: if (isEmpty (&fila) == 1) {
                        printf ("Stack empty! \n");
                    }
                    else {
                        num = head (&fila);
                        printf ("Valor no topo da pilha: %d \n", num);
                    }
                    break;
            case 0: printf ("Bye bye\n");
                    break;
            default: printf ("Opção inválida \n");
        }
    } while (op != 0);
    return 0;
}

//QUESTÃO 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
    int info;
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
}

int Dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nao eh possivel desenfileirar.\n");
        exit(1);
    }
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
    if (isEmpty(q)) {
        printf("Fila vazia. Nenhum elemento.\n");
        exit(1);
    }
    return q->inicio->info;
}

void exibirOpcoes () {
    printf ("Opcoes \n");
    printf ("1 - Empilhar \n");
    printf ("2 - Desempilhar \n");
    printf ("3 - Ver topo \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opcao desejada: ");
}

int main () {
    Queue fila;
    int num, op;

    inicializar(&fila);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1:
                printf ("Informe o valor a ser empilhado: ");
                scanf ("%d",&num);
                Enqueue (&fila,num);
                break;
            case 2: if (isEmpty (&fila) == 1) {
                        printf ("Stack empty! \n");
                    }
                    else {
                        num = Dequeue (&fila);
                        printf ("Valor desempilhado: %d \n", num);
                    }
                    break;
            case 3: if (isEmpty (&fila) == 1) {
                        printf ("Stack empty! \n");
                    }
                    else {
                        num = head (&fila);
                        printf ("Valor no topo da pilha: %d \n", num);
                    }
                    break;
            case 0: printf ("Bye bye\n");
                    break;
            default: printf ("Opção inválida \n");
        }
    } while (op != 0);
    return 0;
}