//Atividade 2 - Listas Simplesmente Encadeadas - Estruturas de Dados Lineares

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{
    int info;
    struct listNode *prox;
} ListNode;

typedef struct lse{
    ListNode *inicio;
    ListNode *fim;
    int qtd;
} LSE;

void inicializar(LSE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LSE *l){
    return l->inicio == NULL;
}

void adicionar(LSE *l, int valor){
    ListNode *novo = (ListNode*)malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;

    if(isEmpty(l)){
        l->inicio = novo;
    } else {
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->qtd++;
    printf("Valor %d adicionado.\n", valor);
}

void listar(LSE *l){
    ListNode *aux =l->inicio;
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

void somar(LSE l1, LSE l2, LSE *l3){
    ListNode *aux1 = l1.inicio;
    ListNode *aux2 = l2.inicio;

    while(aux1 != NULL && aux2 != NULL){
        int soma = aux1->info + aux2->info;
        adicionar(l3, soma);
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    while(aux1 != NULL){
        int soma = aux1->info;
        adicionar(l3, soma);
        aux1 = aux1->prox;
    }
    while(aux2 != NULL){
        int soma = aux2->info;
        adicionar(l3, soma);
        aux2 = aux2->prox;
    }
}

int main(){
    LSE lista1, lista2, lista3;
    inicializar(&lista1);
    inicializar(&lista2);
    inicializar(&lista3);

    adicionar(&lista1, 1);
    adicionar(&lista1, 2);
    adicionar(&lista1, 3);
    printf("Lista 1:\n");
    listar(&lista1);
    adicionar(&lista2, 1);
    adicionar(&lista2, 2);
    adicionar(&lista2, 3);
    adicionar(&lista2, 4);
    printf("Lista 2:\n");
    listar(&lista2);

    somar(lista1, lista2, &lista3);
    printf("Lista 3:\n");
    listar(&lista3);
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{
    int info;
    struct listNode *prox;
} ListNode;

typedef struct lse{
    ListNode *inicio;
    ListNode *fim;
    int qtd;
} LSE;

void inicializar(LSE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LSE *l){
    return l->inicio == NULL;
}

void adicionar(LSE *l, int valor){
    ListNode *novo = (ListNode*)malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;

    if(isEmpty(l)){
        l->inicio = novo;
    } else {
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->qtd++;
    printf("Valor %d adicionado.\n", valor);
}

void listar(LSE *l){
    ListNode *aux =l->inicio;
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

void copiar(LSE l1, LSE *l2){
    ListNode *aux = l1.inicio;
    while(aux != NULL) {
        adicionar(l2, aux->info);
        aux = aux->prox;
    }
}

int main(){
    LSE lista1, lista2;
    inicializar(&lista1);
    inicializar(&lista2);

    adicionar(&lista1, 1);
    adicionar(&lista1, 2);
    adicionar(&lista1, 3);
    adicionar(&lista1, 4);
    printf("Lista 1: \n");
    listar(&lista1);

    copiar(lista1, &lista2);
    printf("Lista 2: \n");
    listar(&lista2);
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100;

typedef struct listNode{
    char nome[100];
    int RG;
    struct listNode *prox;
} ListNode;

typedef struct lse{
    ListNode *inicio;
    ListNode *fim;
    int qtd;
} LSE;

void inicializar(LSE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LSE *l){
    return l->inicio == NULL;
}

int buscar(LSE *l, int RG){
    ListNode *aux = l->inicio;
    if(isEmpty(l)){
        return 0;
    } else {
        while(aux != NULL){
            if(aux->RG == RG){
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

void adicionar(LSE *l, char *nome, int RG){
    ListNode *novo = (ListNode*)malloc(sizeof(ListNode));
    novo->RG = RG;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(buscar(l, RG) != 0){
        printf("Pessoa repetida! Entrada negada.\n");
    } else {
        if(isEmpty(l)){
            l->inicio = novo;
        } else {
            l->fim->prox = novo;
        }
        l->fim = novo;
        l->qtd++;
        printf("%s entrou no predio.\n", novo->nome);
    }    
}

void listar(LSE *l){
    ListNode *aux =l->inicio;
    printf("Pessoas presentes no Predio: \n");
    while (aux != NULL) {
        printf("%s - %d\n", aux->nome, aux->RG);
        aux = aux->prox;
    }
}

void remover(LSE *l, int RG){
    ListNode *atual = l->inicio;
    ListNode *anterior = NULL;

    while(atual != NULL && atual->RG != RG){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("Pessoa não encontrada!\n");
    }
    if(anterior == NULL){
        l->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    if(atual == l->fim){
        l->fim = anterior;
    }
    free(atual);
    l->qtd--;

}

void encontrar(LSE *l, int RG){
    ListNode *atual = l->inicio;
    while(atual != NULL && atual->RG != RG){
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("Pessoa não encontrada!\n");
    }
    if(atual->RG == RG){
        printf("Pessoa encontrada!\n");
    } 
}

int qtd(LSE *l){
    return l->qtd;
}

int main(){
    LSE lista;
    inicializar(&lista);
    int opcao, RG;
    char nome[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar uma pessoa\n");
        printf("2. Cancelar registro\n");
        printf("3. Exibir dados\n");
        printf("4. Verificar se esta no predio\n");
        printf("5. Informar quantos tem\n");
        printf("6. Remover\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o nome da pessoa: ");
                scanf(" %100[^\n]s", nome);
                printf("Informe seu RG: ");
                scanf(" %d", &RG);
                if(buscar(&lista,RG) != 1){
                    adicionar(&lista, nome, RG);
                    printf("Caso queira um cancelamento de registro, escolha a opcao 2.\n");
                } else {
                    printf("Pessoa repetida! Entrada negada.\n");
                }  
                break;
            case 2:
                printf("Informe o RG: ");
                scanf("%d", &RG);
                if(isEmpty(&lista)){
                    printf("A lista se encontra vazia.\n");
                } else {
                    remover(&lista, RG);
                    printf("Cancelado seu acesso!\n");
                }
                break;
            case 3:
                listar(&lista);
                break;
            case 4:
                printf("Informe o RG: ");
                scanf("%d", &RG);
                if(isEmpty(&lista)){
                    printf("A lista se encontra vazia.\n");
                } else {
                    encontrar(&lista, RG);
                }
                break;
            case 5:
                printf("O predio esta com %d residentes.\n", qtd(&lista));
                break;
            case 6:
                printf("Informe o RG: ");
                scanf("%d", &RG);
                if(isEmpty(&lista)){
                    printf("A lista se encontra vazia.\n");
                } else {
                    remover(&lista, RG);
                    printf("Pessoa foi removida!\n");
                }
                break;
            case 7:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

//QUESTÃO 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100;

typedef struct listNode{
    char nome[100];
    int RA, falta;
    float media;
    struct listNode *prox;
} ListNode;

typedef struct lse{
    ListNode *inicio;
    ListNode *fim;
    int qtd;
} LSE;

void inicializar(LSE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LSE *l){
    return l->inicio == NULL;
}

int buscar(LSE *l, int RA){
    ListNode *aux = l->inicio;
    if(isEmpty(l)){
        return 0;
    } else {
        while(aux != NULL){
            if(aux->RA == RA){
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

void adicionar(LSE *l, char *nome, int RA, int falta, float media){
    ListNode *novo = (ListNode*)malloc(sizeof(ListNode));
    novo->RA = RA;
    strcpy(novo->nome, nome);
    novo->falta = falta;
    novo->media = media;
    novo->prox = NULL;

    if(buscar(l, RA) != 0){
        printf("Aluno repetido! Cadastro negado.\n");
    } else {
        if(isEmpty(l)){
            l->inicio = novo;
        } else {
            l->fim->prox = novo;
        }
        l->fim = novo;
        l->qtd++;
        printf("Aluno %s cadastrado.\n", novo->nome);
    }    
}

void listar(LSE *l){
    ListNode *aux = l->inicio;
    printf("Alunos: \n");
    while (aux != NULL) {
        printf("%s - %d - %.2f - %d\n", aux->nome, aux->RA, aux->media, aux->falta);
        aux = aux->prox;
    }
}

void preencher(LSE l, LSE *A, LSE *M, LSE *F){
    ListNode *aux = l.inicio;
    
    while (aux != NULL) {
        if(aux->media >= 7.0){
            adicionar(A, aux->nome, aux->RA, aux->falta, aux->media);
        }
        if(aux->media < 7.0){
            adicionar(M, aux->nome, aux->RA, aux->falta, aux->media);
        }
        if(aux->falta > 18){
            adicionar(F, aux->nome, aux->RA, aux->falta, aux->media);
        }
        aux = aux->prox;
    }
}

int main(){
    LSE turma, aprovados, reprovadosPorMedia, reprovadosPorFalta;
    inicializar(&turma);
    inicializar(&aprovados);
    inicializar(&reprovadosPorMedia);
    inicializar(&reprovadosPorFalta);
    int opcao, esc, RA, faltas;
    float media;
    char nome[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Exibir alunos\n");
        printf("3. Adicionar as listas\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o Nome do Aluno: ");
                scanf(" %100[^\n]s", nome);
                printf("Informe seu RG: ");
                scanf(" %d", &RA);
                printf("Informe suas Faltas: ");
                scanf(" %d", &faltas);
                printf("Informe sua Media: ");
                scanf(" %f", &media);
                if(buscar(&turma,RA) != 1){
                    adicionar(&turma, nome, RA, faltas, media);
                } else {
                    printf("Aluno repetido! Cadastro negado.\n");
                }  
                break;
            case 2:
                printf("1 - Turma, 2- Aprovados, 3 - Reprovados Por Media, 4 - reprovados Por Falta\n");
                printf("Qual lista deseja exibir? ");
                scanf("%d", &esc);
                if(esc == 1){
                    if(isEmpty(&turma)){
                        printf("Lista de Reprovados esta Vazia!\n");
                    } else {
                        listar(&turma);
                    }
                } else if(esc == 2){
                    if(isEmpty(&aprovados)){
                        printf("Lista de Aprovados esta Vazia!\n");
                    } else {
                        listar(&aprovados);
                    }
                } else if(esc == 3){
                    if(isEmpty(&reprovadosPorMedia)){
                        printf("Lista de Reprovados esta Vazia!\n");
                    } else {
                        listar(&reprovadosPorMedia);
                    }
                } else if(esc == 4){
                    if(isEmpty(&reprovadosPorFalta)){
                        printf("Lista de Reprovados esta Vazia!\n");
                    } else {
                        listar(&reprovadosPorFalta);
                    }
                } else {
                    printf("Opcao inorrenta...\n");
                }
                break;
            case 3:
                if(isEmpty(&turma)){
                    printf("A Turma esta vazia!\n");
                } else {
                    preencher(turma, &aprovados, &reprovadosPorMedia, &reprovadosPorFalta);
                    printf("Listas preenchidas.\n");
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}