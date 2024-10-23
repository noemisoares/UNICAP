//Atividade 1 - Listas Circulares - Estruturas de Dados Lineares

//QUESTÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lseNode{
    int info;
    struct lseNode *prox;
} LSENode;

typedef struct lde{
    LSENode *inicio;
    LSENode *fim;
    int qtd;
} LSEC;

void inicializar(LSEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LSEC *l){
    return (l->qtd == 0);
}

int buscar(LSEC *l, int valor){
    if(isEmpty(l)){
        return 0;
    } else {
        LSENode *aux = l->inicio;
        do{
            if(aux->info == valor){
                return 1;
            }
            aux = aux->prox;
        } while(aux != l->inicio);
    }
    return 0;
}

LSENode *criarNo(int valor){
    LSENode *novo = (LSENode*) malloc (sizeof(LSENode));
    novo->info = valor;
    novo->prox = NULL;
    return novo;
}

void inserirInicio(LSEC *l, int valor){
    if(buscar(l, valor) == 1){
        printf("Valor igual encontrada! A insercao nao sera feita.\n");
        return;
    } else if(isEmpty(l)){
        LSENode *novo = criarNo(valor);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LSENode *novo = criarNo(valor);
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao feita no inicio!\n");
}

void inserirFim(LSEC *l, int valor){
    if(buscar(l, valor) == 1){
        printf("Valor igual encontrada! A insercao nao sera feita.\n");
        return;
    } else if(isEmpty(l)){
        LSENode *novo = criarNo(valor);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LSENode *novo = criarNo(valor);
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao feita no fim!\n");
}

void removerInicio(LSEC *l){
    LSENode *aux = l->inicio;
    l->inicio = aux->prox;
    l->fim->prox = l->inicio;
    l->qtd--;
    free(aux);
    printf("Remocao feita no inicio!\n");
}

void removerFim(LSEC *l){
    LSENode *aux = l->inicio;
    while(aux->prox != l->fim){
        aux = aux->prox;
    }
    l->fim = aux;
    aux = aux->prox;
    l->fim->prox = l->inicio;
    l->qtd--;
    free(aux);
    printf("Remocao feita no fim!\n");
}

void remover(LSEC *l, int valor){
    if(buscar(l, valor) == 0){
        printf("Valor nao esta na lista!\n");
        return;
    }
    LSENode *atual = l->inicio;
    LSENode *anterior = NULL;

    while(atual->info != valor){
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = atual->prox;
    l->qtd--;
    free(atual);
    printf("Remocao feita!\n");
}

void exibir(LSEC l) {
    LSENode *aux = l.inicio;
    if (isEmpty(&l)) {
        printf("Lista vazia.\n");
    } else {
        printf("Lista: ");
        do {
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != l.inicio);
        printf("\n");
    }
}

void removerTodos(LSEC *l){
    LSENode *atual = l->inicio;
    LSENode *anterior = NULL;
    do{
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }while(atual != l->inicio);
}

void exibirOpcoes() {
    printf("Opcoes: \n");
    printf("1 - Inserir valor no inicio da lista \n");
    printf("2 - Inserir valor no final da lista \n");
    printf("3 - Remover primeiro da lista \n");
    printf("4 - Remover ultimo da lista \n");
    printf("5 - Remover um valor especifico \n");
    printf("6 - Exibir todos os valores da lista \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opcao desejada: ");
}

int main() {
    LSEC lista;
    int num, op;

    inicializar(&lista);
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &num);
                inserirInicio(&lista, num);
                break;
            case 2:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &num);
                inserirFim(&lista, num);
                break;
            case 3:
                removerInicio(&lista);
                break;
            case 4:
                removerFim(&lista);
                break;
            case 5:
                printf("Informe o valor a ser removido: ");
                scanf("%d", &num);
                remover(&lista, num);
                break;
            case 6:
                exibir(lista);
                break;
            case 0:
                removerTodos(&lista);
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (op != 0);

    return 0;
}