//Lista 4 - Implementação do TAD – Stack - Estruturas de Dados Lineares

//RESPOSTAS DAS QUESTÕES DE CÓDIGO

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct Stack {
    int dados[TAM];
    int topo;
} stack;

void inicializador(stack* s) {
    s->topo = -1;
}

int isEmpty(stack s) {
    return s.topo == -1;
}

int isFull(stack s) {
    return s.topo == TAM - 1;
}

void push(stack *s, int valor) {
        s->topo = s->topo + 1;
        s->dados[s->topo] = valor;
}

int pop(stack *s) {
        int retorno = s->dados[s->topo];
        s->topo = s->topo - 1;
        return retorno;
}

int top(stack s) {
    return s.dados[s.topo];
}

int inverterNumero(int numero) {
    stack s;
    inicializador(&s);

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

    int r = inverterNumero(numero);

    printf("Numero invertido: %d\n", r);

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>

#define TAM 32

typedef struct Stack {
    int dados[TAM];
    int topo;
} stack;

void inicializador(stack* s) {
    s->topo = -1;
}

int isEmpty(stack s) {
    return s.topo == -1;
}

int isFull(stack s) {
    return s.topo == TAM - 1;
}

void push(stack *s, int valor) {
        s->topo = s->topo + 1;
        s->dados[s->topo] = valor;
}

int pop(stack *s) {
        int retorno = s->dados[s->topo];
        s->topo = s->topo - 1;
        return retorno;
}

int top(stack s) {
    return s.dados[s.topo];
}

void converterBinario(int numero) {
    stack s;
    inicializador(&s);

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

#define TAM 100

typedef struct Stack {
    int dados[TAM];
    int topo;
} stack;

void inicializador(stack* s) {
    s->topo = -1;
}

int isEmpty(stack s) {
    return s.topo == -1;
}

int isFull(stack s) {
    return s.topo == TAM - 1;
}

void push(stack *s, int valor) {
        s->topo = s->topo + 1;
        s->dados[s->topo] = valor;
}

int pop(stack *s) {
        int retorno = s->dados[s->topo];
        s->topo = s->topo - 1;
        return retorno;
}

int top(stack s) {
    return s.dados[s.topo];
}


int Palindromo(char palavra[]) {
    stack s;
    inicializador(&s);

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
    char palavra[TAM];

    printf("Informe uma palavra: ");
    scanf("%s", palavra);

    if (Palindromo(palavra)) {
        printf("A palavra '%s' eh um palindromo.\n", palavra);
    } else {
        printf("A palavra '%s' nao eh um palindromo.\n", palavra);
    }

    return 0;
}