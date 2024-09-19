//Atividade 1 - Listas Simplesmente Encadeadas - Estruturas de Dados Lineares

//QUESTÃO
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int info;
    struct listNode* prox;
} ListNode;

typedef struct lse {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LSE;

void inicializar (LSE* l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LSE l) {
    return l.inicio == NULL;
}

void inserirFinal (LSE* l, int valor) {
    ListNode* novo = malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;

    if (isEmpty(*l)) {
        l->inicio = novo;
    } else {
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->qtd++;
}

void inserirInicio (LSE* l, int valor) {
    ListNode* novo = malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = l->inicio;
    l->inicio = novo;

    if (l->qtd == 0) {
        l->fim = novo;
    }
    l->qtd++;
}

void removerInicio (LSE* l) {
    ListNode* novo = l->inicio;
    l->inicio = l->inicio->prox;
    free(novo);

    if (l->inicio == NULL) {
        l->fim = NULL;
    }
    l->qtd--;
}

void removerUltimo (LSE* l) {
    if (l->inicio == l->fim) {
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
    } else {
        ListNode* atual = l->inicio;
        while (atual->prox != l->fim) {
            atual = atual->prox;
        }
        free(l->fim);
        l->fim = atual;
        l->fim->prox = NULL;
    }
    l->qtd--;
}

void list (LSE l) {
    ListNode *atual = l.inicio;
    printf("Lista:\n");
    while(atual != NULL){
        printf("%d \n", atual->info);
        atual = atual->prox;
    }
}

void remover (LSE* l, int valor) {
    ListNode* atual = l->inicio;
    ListNode* anterior = NULL;

    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Nao encontrado\n");
        return;
    }

    if (anterior == NULL) {
        l->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    if (atual == l->fim) {
        l->fim = anterior;
    }
    free(atual);
    l->qtd--;
}

void exibirOpcoes() {
    printf("Opcoes \n");
    printf("1 - Adicionar \n");
    printf("2 - Remover \n");
    printf("3 - Listar \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opcao desejada: ");
}

int main() {
    LSE lista;
    int num, op, escolha = 0;

    inicializar(&lista);
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &num);

                printf("1 - Adicionar no inicio\n");
                printf("2 - Adicionar no final\n");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    inserirInicio(&lista, num);
                } else if (escolha == 2) {
                    inserirFinal(&lista, num);
                } else {
                    printf("Opcao invalida\n");
                }
                break;
            case 2:
                if (isEmpty(lista)) {
                    printf("List empty! \n");
                } else {
                    printf("1 - Remover\n");
                    printf("2 - Remover no inicio\n");
                    printf("3 - Remover no final\n");
                    scanf("%d", &escolha);

                    if (escolha == 1) {
                        printf("Informe o valor a ser removido: ");
                        scanf("%d", &num);
                        remover(&lista, num);
                        printf("Valor removido\n");
                    } else if (escolha == 2) {
                        removerInicio(&lista);
                        printf("Valor removido\n");
                    } else if (escolha == 3) {
                        removerUltimo(&lista);
                        printf("Valor removido\n");
                    } else {
                        printf("Opcao invalida\n");
                    }
                }
                break;
            case 3:
                if (isEmpty(lista)) {
                    printf("List empty! \n");
                } else {
                    list(lista);
                }
                break;
            case 0:
                printf("Bye bye\n");
                break;
            default:
                printf("Opção inválida \n");
        }
    } while (op != 0);

    return 0;
}