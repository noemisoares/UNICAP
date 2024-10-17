//Atividade 2 - Lista Duplamente Encadeada - Estruturas de Dados Lineares

//QUESTÃO 1
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

ListaNode *buscar(LDE *l, int valor){
    ListaNode *aux = l->inicio;
    if(isEmpty(l)){
        return NULL;
    } else {
        while (aux != NULL) {
            if(aux->info == valor){
                return aux;
            } else if (aux->info > valor){
                return NULL;
            }
            aux = aux->prox;
        }
        
    }
    return NULL;
}

ListaNode *criarNovo(int valor){
    ListaNode *aux = (ListaNode*) malloc (sizeof(ListaNode));
    aux->info = valor;
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
}

void inserir(LDE *l, int valor){
    if(isEmpty(l)){
        ListaNode *novo = criarNovo(valor);
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        printf("Insercao efetuada! \n");
    } else if(buscar(l, valor) != NULL){
        printf("Valor repetido! Nao podera ser inserido.\n");
    } else {
        if(valor < l->inicio->info){
            ListaNode *novo = criarNovo(valor);
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
            l->qtd++;
            printf("Insercao efetuada! \n");
        } else if (valor > l->fim->info){
            ListaNode *novo = criarNovo(valor);
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;
            l->qtd++;
            printf("Insercao efetuada! \n");
        } else {
            ListaNode *aux = l->inicio;
            while(1){
                if (aux->info > valor){
                    ListaNode *novo = criarNovo(valor);
                    aux->ant->prox = novo;
                    novo->ant = aux->ant;
                    novo->prox = aux;
                    aux->ant = novo;
                    l->qtd++;
                    printf("Insercao efetuada! \n");
                    return;
                }
                aux = aux->prox;
            }
        }
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

void remover(LDE *l, int valor){
    ListaNode *aux = buscar(l, valor);

    if(aux == NULL){
        printf("Valor %d nao encontrado na lista.\n", valor);
        return;
    } else if (aux == l->inicio && aux == l->fim) {
        l->inicio = NULL;
        l->fim = NULL;
    } else if(aux == l->inicio){
        l->inicio = aux->prox;
        l->inicio->ant = NULL;
    } else if (aux == l->fim) {
        l->fim = aux->ant;
        l->fim->prox = NULL;
    } else {
        if(aux->ant != NULL){
            aux->ant->prox = aux->prox;
        }
        if(aux->prox != NULL){
            aux->prox->ant = aux->ant;
        }
    }
    free(aux);
    printf("Valor %d removido com sucesso.\n", valor);
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
                printf("Bye bye\n");
                break;
            default:
                printf("Opção inválida \n");
        }
    } while (op != 0);

    return 0;
}

//QUESTÃO 2
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

ListaNode *buscar(LDE *l, int valor){
    ListaNode *aux = l->inicio;
    if(isEmpty(l)){
        return NULL;
    } else {
        while (aux != NULL) {
            if(aux->info == valor){
                return aux;
            } else if (aux->info < valor){
                return NULL;
            }
            aux = aux->prox;
        }
        
    }
    return NULL;
}

ListaNode *criarNovo(int valor){
    ListaNode *aux = (ListaNode*) malloc (sizeof(ListaNode));
    aux->info = valor;
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
}

void inserir(LDE *l, int valor){
    if(isEmpty(l)){
        ListaNode *novo = criarNovo(valor);
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        printf("Insercao efetuada! \n");
    } else if(buscar(l, valor) != NULL){
        printf("Valor repetido! Nao podera ser inserido.\n");
    } else {
        if(valor > l->inicio->info){
            ListaNode *novo = criarNovo(valor);
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
            l->qtd++;
            printf("Insercao efetuada! \n");
        } else if (valor < l->fim->info){
            ListaNode *novo = criarNovo(valor);
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;
            l->qtd++;
            printf("Insercao efetuada! \n");
        } else {
            ListaNode *aux = l->inicio;
            while(1){
                if (aux->info < valor){
                    ListaNode *novo = criarNovo(valor);
                    aux->ant->prox = novo;
                    novo->ant = aux->ant;
                    novo->prox = aux;
                    aux->ant = novo;
                    l->qtd++;
                    printf("Insercao efetuada! \n");
                    return;
                }
                aux = aux->prox;
            }
        }
    }
}

void listarContrario (LDE l) { 
    ListaNode* aux = l.fim;
    if (isEmpty(&l)) {
        printf ("Lista vazia \n");
    }
    else {
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->ant;
        }
        printf("\n");
    }
}

void remover(LDE *l, int valor){
    ListaNode *aux = buscar(l, valor);

    if(aux == NULL){
        printf("Valor %d nao encontrado na lista.\n", valor);
        return;
    } else if (aux == l->inicio && aux == l->fim) {
        l->inicio = NULL;
        l->fim = NULL;
    } else if(aux == l->inicio){
        l->inicio = aux->prox;
        l->inicio->ant = NULL;
    } else if (aux == l->fim) {
        l->fim = aux->ant;
        l->fim->prox = NULL;
    } else {
        if(aux->ant != NULL){
            aux->ant->prox = aux->prox;
        }
        if(aux->prox != NULL){
            aux->prox->ant = aux->ant;
        }
    }
    free(aux);
    printf("Valor %d removido com sucesso.\n", valor);
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
                listarContrario(lista);
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

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

typedef struct listaNode {
    char tarefa[TAM];
    int prioridade;
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

ListaNode *buscar(LDE *l, char* tarefa){
    ListaNode *aux = l->inicio;
    if(isEmpty(l)){
        return NULL;
    } else {
        while (aux != NULL) {
            if(strcmp(aux->tarefa, tarefa) == 0){
                return aux;
            }
            aux = aux->prox;
        }
        
    }
    return NULL;
}

ListaNode *criarNovo(char *tarefa, int prioridade){
    ListaNode *aux = (ListaNode*) malloc (sizeof(ListaNode));
    aux->prioridade = prioridade;
    strcpy(aux->tarefa, tarefa);
    aux->ant = NULL;
    aux->prox = NULL;
    return aux;
}

void inserir(LDE *l, int prioridade, char* tarefa){
    if(prioridade < 1 || prioridade > 10) {
        printf("Prioridade invalida. Deve ser entre 1 e 10.\n");
        return;
    }
    if(isEmpty(l)){
        ListaNode *novo = criarNovo(tarefa, prioridade);
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        printf("Tarefa adicionada! \n");
        return;
    } else if(buscar(l, tarefa) != NULL){
        printf("Esta tarefa ja foi adicionada! Nao podera ser inserida.\n");
        return;
    } else {
        ListaNode *novo = criarNovo(tarefa, prioridade);
        ListaNode *aux = l->inicio;
        if(prioridade > l->inicio->prioridade){
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
        } 
        else if (prioridade < l->fim->prioridade){
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;
        } 
        else {
            while (aux != NULL && aux->prioridade >= prioridade) {
                if (aux->prioridade == prioridade) {
                    while (aux->prox != NULL && aux->prox->prioridade == prioridade) {
                        aux = aux->prox;
                    }
                    novo->prox = aux->prox;
                    novo->ant = aux;
                    if (aux->prox != NULL) {
                        aux->prox->ant = novo;
                    } else {
                        l->fim = novo; 
                    }
                    aux->prox = novo;
                    break;
                }
                aux = aux->prox;
            }
            if (aux != NULL && aux->prioridade < prioridade) {
                novo->prox = aux;
                novo->ant = aux->ant;
                if (aux->ant != NULL) {
                    aux->ant->prox = novo;
                }
                aux->ant = novo;
            }
        }
        l->qtd++;
        printf("Tarefa adicionada!\n");
    }
}


void listarTarefas(LDE *l) {
    ListaNode *aux = l->inicio;
    if(isEmpty(l)){
        printf("Nenhuma tarefa cadastrada.\n");
    } else {
        while(aux != NULL) {
            printf("Tarefa: %s | Prioridade: %d\n", aux->tarefa, aux->prioridade);
            aux = aux->prox;
        }
    }
}

void listarPorPrioridade(LDE *l, int prioridade) {
    ListaNode *aux = l->inicio;
    int k = 0;
    while (aux != NULL) {
        if (aux->prioridade == prioridade) {
            printf("Tarefa: %s\n", aux->tarefa);
            k++;
        }
        aux = aux->prox;
    }
    printf("Total de tarefas com prioridade %d: %d\n", prioridade, k);
}

int contar(LDE *l, char *tarefa) {
    ListaNode *aux = l->inicio;
    int count = 0;
    while (aux != NULL && strcmp(aux->tarefa, tarefa) != 0) {
        count++;
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Tarefa nao encontrada.\n");
        return -1;
    }
    return count;
}

ListaNode* executarTarefa(LDE *l) {
    if (isEmpty(l)) {
        printf("Nenhuma tarefa para executar.\n");
        return NULL;
    }
    ListaNode *aux = l->inicio;
    l->inicio = l->inicio->prox;
    if (l->inicio != NULL) {
        l->inicio->ant = NULL;
    } else {
        l->fim = NULL;
    }
    l->qtd--;
    printf("Tarefa '%s' com prioridade %d executada.\n", aux->tarefa, aux->prioridade);
    return aux;
}

void cancelarTarefa(LDE *l, char *tarefa) {
    ListaNode *aux = buscar(l, tarefa);
    if(aux == NULL){
        printf("Tarefa nao encontrada.\n");
        return;
    }

    if(aux == l->inicio) {
        l->inicio = aux->prox;
        l->inicio->ant = NULL;
    } else if(aux == l->fim) {
        l->fim = aux->ant;
        l->fim->prox = NULL;
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    free(aux);
    l->qtd--;
    printf("Tarefa '%s' cancelada.\n", tarefa);
}

void alterarPrioridade(LDE *l, char *tarefa, int novaPrioridade) {
    ListaNode *aux = buscar(l, tarefa);
    if(aux == NULL) {
        printf("Tarefa nao encontrada.\n");
        return;
    }
    cancelarTarefa(l, tarefa);
    inserir(l, novaPrioridade, tarefa);
}

void exibirOpcoes() {
    printf("MENU:\n");
    printf("1 - Inserir tarefa\n");
    printf("2 - Executar tarefa\n");
    printf("3 - Cancelar tarefa\n");
    printf("4 - Listar tarefas\n");
    printf("5 - Listar por prioridade\n");
    printf("6 - Alterar prioridade de tarefa\n");
    printf("7 - Contar tarefas antes de uma tarefa\n");
    printf("0 - Encerrar programa\n");
    printf("Digite sua escolha: ");
}

int main() {
    LDE lista;
    inicializar(&lista);
    int op, prioridade;
    char tarefa[TAM];

    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite a descricao da tarefa: ");
                scanf(" %1000[^\n]", tarefa);
                printf("Digite a prioridade (1 a 10): ");
                scanf("%d", &prioridade);
                inserir(&lista, prioridade, tarefa);
                break;
            case 2:
                executarTarefa(&lista);
                break;
            case 3:
                printf("Digite a descricao da tarefa a ser cancelada: ");
                scanf(" %1000[^\n]", tarefa);
                cancelarTarefa(&lista, tarefa);
                break;
            case 4:
                listarTarefas(&lista);
                break;
            case 5:
                printf("Digite a prioridade para listar: ");
                scanf("%d", &prioridade);
                listarPorPrioridade(&lista, prioridade);
                break;
            case 6:
                printf("Digite a descricao da tarefa: ");
                scanf(" %1000[^\n]", tarefa);
                printf("Digite a nova prioridade: ");
                scanf("%d", &prioridade);
                alterarPrioridade(&lista, tarefa, prioridade);
                break;
            case 7:
                printf("Digite a descricao da tarefa: ");
                scanf(" %1000[^\n]", tarefa);
                int qtd = contar(&lista, tarefa);
                if (qtd != -1){ 
                    printf("Existem %d tarefas antes da tarefa '%s'.\n", qtd, tarefa);
                }
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while(op != 0);
    return 0;
}

//QUESTÃO 4 E QUESTÃO 5
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
        ListaNode *aux = l->inicio;
        if (valor < l->inicio->info) {
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
        } else if (valor > l->fim->info) {
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;
        } else {
            while (aux != NULL && aux->info < valor) {
                aux = aux->prox;
            }
            novo->prox = aux;
            novo->ant = aux->ant;
            if (aux->ant != NULL) {
                aux->ant->prox = novo;
            } else {
                l->inicio = novo;
            }
            aux->ant = novo;
        }
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
    int encontrou = 0;

    while (aux != NULL) {
        if (aux->info == valor) {
            encontrou = 1;
            ListaNode *remover = aux;
            aux = aux->prox;

            if (remover->ant != NULL) {
                remover->ant->prox = remover->prox;
            } else {
                l->inicio = remover->prox;
            }
            if (remover->prox != NULL) {
                remover->prox->ant = remover->ant;
            } else {
                l->fim = remover->ant;
            }
            free(remover);
            l->qtd--;
        } else {
            aux = aux->prox;
        }
    }

    if (encontrou) {
        printf("Removidas todas os valores do valor %d.\n", valor);
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