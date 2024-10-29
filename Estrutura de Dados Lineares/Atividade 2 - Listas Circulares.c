//Atividade 2 - Listas Circulares - Estruturas de Dados Lineares

//QUESTÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro {
    char nome[100];
    float mediaFinal;
    int faltas;
}Cadastro;


typedef struct listaCadastro {
    Cadastro *info;
    struct listaCadastro *prox;
    struct listaCadastro *ant;
}ListaCadastro;

typedef struct listaAluno{
    ListaCadastro *inicio;
    ListaCadastro *fim;
    int qtd;
}ListaAluno;

int isEmpty(ListaAluno *l){
    return (l->qtd == 0);
}

void inicializar(ListaAluno *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

ListaCadastro *consultarAluno (ListaAluno *l, char *nome){
    if(isEmpty(l)){
        return NULL;
    } else {
        ListaCadastro *aux = l->inicio;
        do {
            if(strcmp(aux->info->nome, nome) == 0){
                return aux;
            }
            aux = aux->prox;
        } while(aux != l->inicio);
    }
    return NULL;
}

ListaCadastro *criarNo(char *nome, float media, int faltas){
    Cadastro *infos = (Cadastro*) malloc(sizeof(Cadastro));
    strcpy(infos->nome, nome);
    infos->mediaFinal = media;
    infos->faltas = faltas;
    ListaCadastro *novo = (ListaCadastro*) malloc(sizeof(ListaCadastro));
    novo->info = infos;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void cadastrar(ListaAluno *l, char *nome) {
    float media = 0;
    int faltas = 0;

    if (consultarAluno(l, nome) != NULL) {
        printf("Este aluno ja foi cadastrado! Ele nao sera inserido nesta lista.\n");
        return;
    }

    ListaCadastro *novo = criarNo(nome, media, faltas);
    if (isEmpty(l)) {
        l->inicio = novo;
        l->fim = novo;
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
    } else {
        ListaCadastro *atual = l->inicio;
        ListaCadastro *anterior = NULL;
        do {
            if (strcmp(nome, atual->info->nome) < 0) {
                break;
            }
            anterior = atual;
            atual = atual->prox;
        } while (atual != l->inicio);

        if (atual == l->inicio && strcmp(nome, atual->info->nome) < 0) {
            novo->prox = l->inicio;
            novo->ant = l->fim;
            l->inicio->ant = novo;
            l->fim->prox = novo;
            l->inicio = novo;
        } else if (anterior == l->fim) {
            novo->prox = l->inicio;
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->inicio->ant = novo;
            l->fim = novo;
        } else {
            anterior->prox = novo;
            novo->prox = atual;
            novo->ant = anterior;
            atual->ant = novo;
        }
    }
    l->qtd++;
    printf("Aluno %s cadastrado com sucesso!\n", nome);
}

void listar(ListaAluno *l){
    ListaCadastro *aux = l->inicio;
    if(isEmpty(l)){
        printf("Lista da Turma esta vazia!\n");
    } else {
        printf("TURMA:\n");
        do{
            printf("Nome: %s | Media Final: %.2f | QTD Faltas: %d \n", aux->info->nome, aux->info->mediaFinal, aux->info->faltas);
            aux = aux->prox;
        } while(aux != l->inicio);
    }
}

void alterarMedia(ListaAluno *l, char *nome){
    float media;
    if(isEmpty(l)){
        printf("Lista da Turma esta vazia!\n");
    } else {
        ListaCadastro *aux = consultarAluno(l,nome);
        if(aux != NULL){
            printf("Aluno %s foi encontrado na turma!\n", aux->info->nome);
            printf("Digite a nova Media Final: ");
            scanf("%f", &media);
            if(media >= 0){
                aux->info->mediaFinal = media;
                printf("Aluno %s possui nova Media Final: %.2f\n", aux->info->nome, aux->info->mediaFinal);
            } else {
                printf("Nao pode ser inserido um numero negativo. Alteracao cancelada!\n");
            }
        } else {
            printf("O aluno %s nao esta cadastrado na turma!\n", nome);
        }
    }
}

void alterarFaltas(ListaAluno *l, char *nome){
    int faltas, esc;
    if(isEmpty(l)){
        printf("Lista da Turma esta vazia!\n");
    } else {
        ListaCadastro *aux = consultarAluno(l,nome);
        if(aux != NULL){
            printf("Aluno %s foi encontrado na turma!\n", aux->info->nome);
            printf("1 - Adicionar faltas\n");
            printf("2 - Abonar faltas\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &esc);
            printf("Informe a quantidade de faltas: ");
            scanf("%d", &faltas);
            if(esc == 1){
                aux->info->faltas = aux->info->faltas + faltas;
                printf("Faltas adicionadas! Aluno %s possui %d faltas agora.\n", aux->info->nome, aux->info->faltas);
            } else if (esc == 2) {
                aux->info->faltas = aux->info->faltas - faltas;
                if(aux->info->faltas < 0){
                    aux->info->faltas = 0;
                    printf("Retirada de faltas em excesso! A quantidade de faltas se encontra zerada.\n");
                }
                printf("Faltas abonadas! Aluno %s possui %d faltas agora.\n", aux->info->nome, aux->info->faltas);
            } else {
                printf("Opcao invalida! Nenhuma alteracao foi feita.\n");
            }
        } else {
            printf("O aluno %s nao esta cadastrado na turma!\n", nome);
        }
    }
}

void exibir(ListaAluno *l, char *nome){
    if(isEmpty(l)){
        printf("Lista da Turma esta vazia!\n");
    } else {
        ListaCadastro *aux = consultarAluno(l,nome);
        if(aux != NULL){
            printf("ALUNO: %s\n", aux->info->nome);
            printf("Media Final: %.2f | QTD Faltas: %d \n", aux->info->mediaFinal, aux->info->faltas);
        } else {
            printf("O aluno %s nao esta cadastrado na turma!\n", nome);
        }
    }
}

void remover(ListaAluno *l, char *nome){
    if (isEmpty(l)) {
        printf("Lista da Turma esta vazia!\n");
        return;
    }
    
    ListaCadastro *aluno = consultarAluno(l, nome);
    if (aluno == NULL) {
        printf("Aluno %s nao encontrado na turma.\n", nome);
        return;
    }

    if (l->inicio == l->fim) {
        free(aluno->info);
        free(aluno);
        l->inicio = NULL;
        l->fim = NULL;
    } else {
        aluno->ant->prox = aluno->prox;
        aluno->prox->ant = aluno->ant;
        if (aluno == l->inicio) {
            l->inicio = aluno->prox;
        }
        if (aluno == l->fim) {
            l->fim = aluno->ant;
        }
        free(aluno->info);
        free(aluno);
    }
    l->inicio->ant = l->fim;
    l->fim->prox = l->inicio;
    l->qtd--;
    printf("Aluno %s removido da turma.\n", nome);
}

void limpar(ListaAluno *l){
    if(isEmpty(l)){
        printf("Lista da Turma esta vazia!\n");
    } else {
        ListaCadastro *aux = l->inicio;
        do{ 
            aux = aux->prox;
            free(aux->ant);
            l->qtd--;
        } while(aux != l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
    }
}

void exibirOpcoes () {
    printf ("Opcoes \n");
    printf ("1 - Cadastrar aluno em uma turma\n");
    printf ("2 - Exibir todos os alunos de uma turma \n");
    printf ("3 - Alterar media de um aluno \n");
    printf ("4 - Alterar a quantidade de faltas de um aluno \n");
    printf ("5 - Exibir os dados de um aluno \n");
    printf ("6 - Remover um aluno de uma turma \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opcao desejada: ");
}

int main () {
    ListaAluno turma1;
    ListaAluno turma2;
    int turma, op;
    char nome [100];
    inicializar(&turma1);
    inicializar(&turma2);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: 
                printf("Nome do aluno: ");
                scanf(" %100[^\n]", nome);
                printf("Turma (1 ou 2): ");
                scanf ("%d", &turma);
                if (turma == 1) {
                    cadastrar (&turma1, nome);
                } else if (turma == 2) {
                    cadastrar (&turma2, nome);
                } else {
                    printf ("Turma invalida \n");
                }
                break;
            case 2:
                printf("Turma (1 ou 2): ");
                scanf ("%d", &turma);
                if (turma == 1) {
                    listar(&turma1);
                } else if (turma == 2) {
                    listar(&turma2);
                } else {
                    printf ("Turma invalida \n");
                }
                break;
            case 3:
                printf("Nome do aluno: ");
                scanf(" %100[^\n]", nome);
                printf("Turma (1 ou 2): ");
                scanf ("%d", &turma);
                if (turma == 1) {
                    alterarMedia (&turma1, nome);
                } else if (turma == 2) {
                    alterarMedia (&turma2, nome);
                } else {
                    printf ("Turma invalida \n");
                }
                break;
            case 4:
                printf("Nome do aluno: ");
                scanf(" %100[^\n]", nome);
                printf("Turma (1 ou 2): ");
                scanf ("%d", &turma);
                if (turma == 1) {
                    alterarFaltas (&turma1, nome);
                } else if (turma == 2) {
                    alterarFaltas (&turma2, nome);
                } else {
                    printf ("Turma invalida \n");
                }
                break;
            case 5: 
                printf("Nome do aluno: ");
                scanf(" %100[^\n]", nome);
                printf("Turma (1 ou 2): ");
                scanf ("%d", &turma);
                if (turma == 1) {
                    exibir (&turma1, nome);
                } else if (turma == 2) {
                    exibir (&turma2, nome);
                } else {
                    printf ("Turma invalida \n");
                }
                break;
            case 6:
                printf("Nome do aluno: ");
                scanf(" %100[^\n]", nome);
                printf("Turma (1 ou 2): ");
                scanf("%d", &turma);
                if (turma == 1){
                    remover(&turma1, nome);
                } else if (turma == 2){
                    remover(&turma2, nome);
                } else {
                    printf("Turma invalida\n");
                }
                break;
            case 0: 
                limpar(&turma1);
                limpar(&turma2);
                printf("Programa encerrado.\n");
                break;
            default: 
                printf ("Opcao invalida \n");
            }
    } while (op != 0);
    return 0;
}