//Atividade 1 - Lista Duplamente Encadeada - Estruturas de Dados Lineares

//QUESTÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaNode {
    int info;
    struct listaNode *prox;
    struct listaNode *ant;    
}ListaNode;

typedef struct lde {
    ListaNode *inicio;
    ListaNode *fim;
    int qtd;
}LDE;

void inicializar(LDE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDE *l){
    return l->qtd == 0;
}

int buscar(LDE *l, int valor){
    ListaNode *aux = l->inicio;
    if(isEmpty(l)){
        printf ("Lista vazia \n");
        return 0;
    } else {
        while (aux != NULL) {
            if(aux->info == valor){
                return 1;
            }
            aux = aux->prox;
        }
        
    }
    return 0;
}

void inserirInicio(LDE *l, int valor){
    ListaNode *novo = (ListaNode*) malloc(sizeof(ListaNode));
    novo->info = valor;
    novo->prox = l->inicio;
    novo->ant = NULL;

    if(buscar(l, valor)){
        printf("Nao pode ser inderido valores iguais\n");
    } else {
        if(isEmpty(l)){
            l->inicio = novo;
            l->fim = novo;
        } else {
            l->inicio->ant = novo;
            l->inicio = novo;
        }
        l->qtd++;
        printf("Insercao efetuada! \n");
    }
}

void inserirFim(LDE *l, int valor){
    ListaNode *novo = (ListaNode*) malloc(sizeof(ListaNode));
    novo->info = valor;
    novo->prox = NULL;
    novo->ant = l->fim;

    if(buscar(l, valor)){
        printf("Nao pode ser inderido valores iguais\n");
    } else {
        if(isEmpty(l)){
            novo->ant = NULL;
            l->inicio = novo;
            l->fim = novo;
        } else {
            l->fim->prox = novo;
        }
        l->fim = novo;
        l->qtd++;
        printf("Insercao efetuada! \n");
    }
}

void listarNormal (LDE l) { 
    ListaNode* aux = l.inicio;
    if (isEmpty(&l)) {
        printf ("Lista vazia \n");
    }
    else {
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void listarContrario (LDE l) { 
    ListaNode* aux = l.fim;
    if (isEmpty(&l)) {
        printf ("Lista vazia \n");
    } else {
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->ant;
        }
        printf("\n");
    }
}

void removerInicio (LDE* l) {
    ListaNode* aux = l->inicio;
    if (isEmpty(l)) {
        printf("Lista vazia!\n");
    } else if (l->qtd == 1) {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
    } else {
        l->inicio = l->inicio->prox;
        l->inicio->ant = NULL;
        free(aux);
    }
    l->qtd--;
    printf("Remocao efetuada!\n");
}

void removerFim (LDE* l) {
    ListaNode* aux = l->fim;
    if (isEmpty(l)) {
        printf("Lista vazia!\n");
    } else if (l->qtd == 1) {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
    } else {
        l->fim = l->fim->ant;
        l->fim->prox = NULL;
        free(aux);
    }
    l->qtd--;
    printf("Remocao efetuada!\n");
}

void remover(LDE *l, int valor){
    ListaNode *atual = l->inicio;
    ListaNode *anterior = NULL;

    if(isEmpty(l)){
        printf("Lista vazia!\n");
    } else {
        while(atual != NULL && atual->info != valor){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == NULL){
            printf("Valor nao encontrado!\n");
        }
        if(anterior == NULL){
            l->inicio = atual->prox;
            l->inicio->ant = NULL;
        } else {
            anterior->prox = atual->prox;
            atual->prox->ant = anterior;
        }
        if(atual == l->fim){
            anterior->prox = NULL;
            l->fim = anterior;
        }
        free(atual);
        l->qtd--;
        printf("Remocao efetuada!\n");
    }
}

void esvaziarLista(LDE *l) {
    ListaNode* atual = l->inicio;
    ListaNode* anterior = NULL;

    while (atual != NULL) {
        anterior = atual;    
        atual = atual->prox;
        free(anterior);
    }
    printf("Lista esvaziada com sucesso.\n");
}

void exibirOpcoes() {
    printf("Opcoes \n");
    printf("1 - Inserir \n");
    printf("2 - Remover \n");
    printf("3 - Listar \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opcao desejada: ");
}

int main() {
    LDE lista;
    int num, op = 0, esc;

    inicializar(&lista);
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &num);
                
                printf("1 - Inserir no inicio\n");
                printf("2 - Inserir no final\n");
                printf("Digite: ");
                scanf("%d", &esc);

                if(esc == 1){
                    inserirInicio(&lista, num);
                } else if(esc == 2){
                    inserirFim(&lista, num);
                } else {
                    printf("Esta opcao nao existe\n");
                }
                break;
            case 2:
                printf("1 - Remover no inicio\n");
                printf("2 - Remover no final\n");
                printf("3 - Remover\n");
                printf("Digite: ");
                scanf("%d", &esc);

                if(esc == 1){
                    removerInicio(&lista);
                } else if(esc == 2){
                    removerFim(&lista);
                } else if(esc == 3){
                    printf("Informe o valor a ser removido: ");
                    scanf("%d", &num);
                    remover(&lista, num);
                } else {
                    printf("Esta opcao nao existe\n");
                }
                break;
            case 3:
                printf("1 - Listar do inicio ao fim\n");
                printf("2 - Listar do fim ao inicio\n");
                printf("Digite: ");
                scanf("%d", &esc);

                if(esc == 1){
                    listarNormal(lista);
                } else if(esc == 2){
                    listarContrario(lista);
                } else {
                    printf("Esta opcao não existe\n");
                }
                break;
            case 0:
                esvaziarLista(&lista);
                printf("Bye bye\n");
                break;
            default:
                printf("Opção inválida \n");
        }
    } while (op != 0);

    return 0;
}