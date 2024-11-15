//Atividade 3 - Listas Circulares - Estruturas de Dados Lineares

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ledcNode{
    int info;
    struct ledcNode *ant;
    struct ledcNode *prox;
} LDECnode;

typedef struct ldec {
    LDECnode *inicio;
    LDECnode *fim;
    int qtd;
} LDEC;

void inicializar(LDEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDEC *l){
    return(l->qtd == 0);
}

LDECnode *criarNo(int valor){
    LDECnode *novo = (LDECnode*) malloc(sizeof(LDECnode));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void inserir(LDEC *l, int valor){
    if(isEmpty(l)){
        LDECnode *novo = criarNo(valor);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LDECnode *novo = criarNo(valor);
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->inicio->ant = l->fim;
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao efetuada! \n");
}

void listar(LDEC *l){
    if(isEmpty(l)){
        printf("Lista vazia!\n");
    } else {
        printf("Lista: ");
        LDECnode *aux = l->inicio;
        do{
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != l->inicio);
        printf("\nQTD: %d\n", l->qtd);
    }
}

void concatenar(LDEC *l1, LDEC *l2) {
    if (isEmpty(l2)) {
        printf("Lista 2 esta vazia! Nada a concatenar.\n");
        return;
    }
    if (isEmpty(l1)) {
        l1->inicio = l2->inicio;
        l1->fim = l2->fim;
        l1->qtd = l2->qtd;
    } else {
        l1->fim->prox = l2->inicio;
        l2->inicio->ant = l1->fim;
        l2->fim->prox = l1->inicio;
        l1->inicio->ant = l2->fim;
        l1->fim = l2->fim;
        l1->qtd = l1->qtd + l2->qtd;
    }  
    inicializar(l2);
    printf("Concatenacao concluida!\n");
}

int main(){
    LDEC lista1, lista2;
    inicializar(&lista1);
    inicializar(&lista2);
    int esc, list, valor;

    do{
        printf("MENU DE OPCOES: \n");
        printf("1 - Inserir \n");
        printf("2 - Listar \n");
        printf("3 - Concatenar \n");
        printf("0 - Sair \n");
        printf("Escolha: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Deseja inserir na lista 1 ou lista 2? ");
                scanf("%d", &list);
                if(list == 1){
                    inserir(&lista1, valor);
                } else if(list == 2){
                    inserir(&lista2, valor);
                } else {
                    printf("Escolha invalida!\n");
                }
                break;
            case 2:
                printf("Deseja exibir a lista 1 ou lista 2? ");
                scanf("%d", &list);
                if(list == 1){
                    listar(&lista1);
                } else if(list == 2){
                    listar(&lista2);
                } else {
                    printf("Escolha invalida!\n");
                }
                break;
            case 3:
                concatenar(&lista1,&lista2);
                break;
            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao incorreta! tente novamente... \n");
                break;
        }
    } while( esc != 0);

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ledcNode{
    int info;
    struct ledcNode *ant;
    struct ledcNode *prox;
} LDECnode;

typedef struct ldec {
    LDECnode *inicio;
    LDECnode *fim;
    int qtd;
} LDEC;

void inicializar(LDEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDEC *l){
    return(l->qtd == 0);
}

LDECnode *criarNo(int valor){
    LDECnode *novo = (LDECnode*) malloc(sizeof(LDECnode));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void inserir(LDEC *l, int valor){
    if(isEmpty(l)){
        LDECnode *novo = criarNo(valor);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LDECnode *novo = criarNo(valor);
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->inicio->ant = l->fim;
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao efetuada! \n");
}

void listar(LDEC *l){
    if(isEmpty(l)){
        printf("Lista vazia!\n");
    } else {
        printf("Lista: ");
        LDECnode *aux = l->inicio;
        do{
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != l->inicio);
        printf("\nQTD: %d\n", l->qtd);
    }
}

LDEC dividir(LDEC *l1) {
    LDEC l2;
    inicializar(&l2);

    if (isEmpty(l1)) {
        printf("Lista 1 esta vazia! Nada a ser dividido.\n");
        return l2;
    } else if (l1->qtd == 1){
        printf("Lista 1 possui um unico elemento! Nada a ser dividido.\n");
        return l2;
    }

    LDECnode *aux = l1->inicio;
    int k = 0, meio = l1->qtd/2;

    while(k < meio){
        aux = aux->prox;
        k++;
    }

    l2.inicio = aux;
    l2.fim = l1->fim;

    l1->fim = aux->ant;
    l1->inicio->ant = l1->fim;
    l1->fim->prox = l1->inicio;

    l2.inicio->ant = l2.fim;
    l2.fim->prox = l2.inicio;

    l2.qtd = l1->qtd - meio;
    l1->qtd = meio;

    printf("Divisao foi realizada!\n");
    return l2;
}

int main(){
    LDEC lista1, lista2;
    inicializar(&lista1);
    inicializar(&lista2);
    int esc, list, valor;

    do{
        printf("MENU DE OPCOES: \n");
        printf("1 - Inserir \n");
        printf("2 - Listar \n");
        printf("3 - Dividir \n");
        printf("0 - Sair \n");
        printf("Escolha: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(&lista1, valor);
                break;
            case 2:
                printf("Deseja exibir a lista 1 ou lista 2? ");
                scanf("%d", &list);
                if(list == 1){
                    listar(&lista1);
                } else if(list == 2){
                    listar(&lista2);
                } else {
                    printf("Escolha invalida!\n");
                }
                break;
            case 3:
                lista2 = dividir(&lista1);
                break;
            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao incorreta! tente novamente... \n");
                break;
        }
    } while( esc != 0);

    return 0;
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ledcNode{
    int info;
    struct ledcNode *prox;
} LDECnode;

typedef struct ldec {
    LDECnode *inicio;
    LDECnode *fim;
    int qtd;
} LDEC;

void inicializar(LDEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDEC *l){
    return(l->qtd == 0);
}

LDECnode *criarNo(int valor){
    LDECnode *novo = (LDECnode*) malloc(sizeof(LDECnode));
    novo->info = valor;
    novo->prox = NULL;
    return novo;
}

void inserir(LDEC *l, int valor){
    if(isEmpty(l)){
        LDECnode *novo = criarNo(valor);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LDECnode *novo = criarNo(valor);
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao efetuada! \n");
}

void listar(LDEC *l){
    if(isEmpty(l)){
        printf("Lista vazia!\n");
    } else {
        printf("Lista: ");
        LDECnode *aux = l->inicio;
        do{
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != l->inicio);
        printf("\nQTD: %d\n", l->qtd);
    }
}

int comparar(LDEC *l1, LDEC *l2){
    if (isEmpty(l1) && isEmpty(l2)) {
        return 1;
    }
    if (isEmpty(l1) || isEmpty(l2)) {
        return 0;
    }
    if (l1->qtd != l2->qtd) {
        return 0;
    }

    LDECnode *aux1 = l1->inicio;
    LDECnode *aux2 = l2->inicio;

    do{
        if(aux1->info != aux2->info){
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    } while(aux1 != l1->inicio && aux2 != l2->inicio);

    return 1;
}

int main(){
    LDEC lista1, lista2;
    inicializar(&lista1);
    inicializar(&lista2);
    int esc, list, valor, comp;

    do{
        printf("MENU DE OPCOES: \n");
        printf("1 - Inserir \n");
        printf("2 - Listar \n");
        printf("3 - Comparar \n");
        printf("0 - Sair \n");
        printf("Escolha: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Deseja inserir na lista 1 ou lista 2? ");
                scanf("%d", &list);
                if(list == 1){
                    inserir(&lista1, valor);
                } else if(list == 2){
                    inserir(&lista2, valor);
                } else {
                    printf("Escolha invalida!\n");
                }
                break;
            case 2:
                printf("Deseja exibir a lista 1 ou lista 2? ");
                scanf("%d", &list);
                if(list == 1){
                    listar(&lista1);
                } else if(list == 2){
                    listar(&lista2);
                } else {
                    printf("Escolha invalida!\n");
                }
                break;
            case 3:
                comp = comparar(&lista1, &lista2);
                if(comp == 0){
                    printf("As Listas 1 e 2 sao diferentes!\n");
                } else {
                    printf("As Listas 1 e 2 sao iguais!\n");
                }
                break;
            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao incorreta! tente novamente... \n");
                break;
        }
    } while( esc != 0);

    return 0;
}

//QUESTÃO 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct infoAluno {
    char nome[100];
    int matricula;
    float media;
    int faltas;
} InfoAluno;

typedef struct ledcNode{
    InfoAluno *info;
    struct ledcNode *ant;
    struct ledcNode *prox;
} LDECnode;

typedef struct ldec {
    LDECnode *inicio;
    LDECnode *fim;
    int qtd;
} LDEC;

void inicializar(LDEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDEC *l){
    return(l->qtd == 0);
}

LDECnode *criarNo(char *nome, int matricula, float media, int faltas){
    InfoAluno *infos = (InfoAluno*) malloc(sizeof(InfoAluno));
    strcpy(infos->nome, nome);
    infos->matricula = matricula;
    infos->faltas = faltas;
    infos->media = media;
    LDECnode *novo = (LDECnode*) malloc(sizeof(LDECnode));
    novo->info = infos;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void inserir(LDEC *l, char *nome, int matricula, float media, int faltas){
    if(isEmpty(l)){
        LDECnode *novo = criarNo(nome, matricula, media, faltas);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LDECnode *novo = criarNo(nome, matricula, media, faltas);
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->inicio->ant = l->fim;
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao efetuada! \n");
}

void listar(LDEC *l){
    if(isEmpty(l)){
        printf("Lista vazia!\n");
    } else {
        printf("Lista de Alunos: \n");
        LDECnode *aux = l->inicio;
        do{
            printf("%s - %d - %.2f - %d \n", aux->info->nome, aux->info->matricula, aux->info->media, aux->info->faltas);
            aux = aux->prox;
        } while (aux != l->inicio);
        printf("Quantidade Total de Alunos: %d\n", l->qtd);
    }
}

void classificar(LDEC l, LDEC *aprovados, LDEC *reprovadosFalta, LDEC *reprovadosMedia){
    LDECnode *aux = l.inicio;
    do {
        if(aux->info->media >= 7 && aux->info->faltas <= 18){
            inserir(aprovados, aux->info->nome, aux->info->matricula, aux->info->media, aux->info->faltas);
        } else if(aux->info->media < 7 && aux->info->faltas <= 18){
            inserir(reprovadosMedia, aux->info->nome, aux->info->matricula, aux->info->media, aux->info->faltas);
        } else if(aux->info->faltas > 18){
            inserir(reprovadosFalta, aux->info->nome, aux->info->matricula, aux->info->media, aux->info->faltas);
        }
        aux = aux->prox;
    } while(aux != l.inicio);
    printf("Alunos foram classificados!\n");
}

int main(){
    LDEC turma, aprovados, reprovadosFalta, reprovadosMedia;
    inicializar(&turma);
    inicializar(&aprovados);
    inicializar(&reprovadosFalta);
    inicializar(&reprovadosMedia);
    char nome[100];
    float media;
    int esc, faltas, matricula;

    do{
        printf("MENU DA TURMA: \n");
        printf("1 - Inserir um Aluno\n");
        printf("2 - Lista de Alunos \n");
        printf("3 - Classificar Alunos \n");
        printf("4 - Alunos Aprovados \n");
        printf("5 - Alunos Reprovados por Falta \n");
        printf("6 - Alunos Reprovados por Media \n");
        printf("0 - Sair \n");
        printf("Escolha: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o nome do aluno: ");
                scanf(" %100[^\n]s ", nome);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                printf("Digite a media do aluno: ");
                scanf("%f", &media);
                printf("Digite a quantidade de faltas do aluno: ");
                scanf("%d", &faltas);
                inserir(&turma, nome, matricula, media, faltas);
                break;
            case 2:
                listar(&turma);
                break;
            case 3:
                classificar (turma, &aprovados, &reprovadosFalta, &reprovadosMedia);
                break;
            case 4:
                listar(&aprovados);
                break;
            case 5:
                listar(&reprovadosFalta);
                break;
            case 6:
                listar(&reprovadosMedia);
                break;
            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao incorreta! tente novamente... \n");
                break;
        }
    } while( esc != 0);

    return 0;
}

//QUESTÃO 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct infoPessoa {
    char nome[100];
    int RG, idade;
    float peso, altura;
} InfoPessoa;

typedef struct ledcNode{
    InfoPessoa *info;
    struct ledcNode *prox;
} LDECnode;

typedef struct ldec {
    LDECnode *inicio;
    LDECnode *fim;
    int qtd;
} LDEC;

void inicializar(LDEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDEC *l){
    return(l->qtd == 0);
}

LDECnode *criarNo(char *nome, int RG, int idade, float peso, float altura){
    InfoPessoa *infos = (InfoPessoa*) malloc(sizeof(InfoPessoa));
    strcpy(infos->nome, nome);
    infos->RG = RG;
    infos->idade = idade;
    infos->peso = peso;
    infos->altura = altura;
    LDECnode *novo = (LDECnode*) malloc(sizeof(LDECnode));
    novo->info = infos;
    novo->prox = NULL;
    return novo;
}

void inserir(LDEC *l, char *nome, int RG, int idade, float peso, float altura){
    if(isEmpty(l)){
        LDECnode *novo = criarNo(nome, RG, idade, peso, altura);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LDECnode *novo = criarNo(nome, RG, idade, peso, altura);
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao efetuada! \n");
}

void listar(LDEC *l){
    if(isEmpty(l)){
        printf("Lista vazia!\n");
    } else {
        printf("Lista: \n");
        LDECnode *aux = l->inicio;
        do{
            printf("%s - %d - %d - %.2f m - %.2f kg \n", aux->info->nome, aux->info->RG, aux->info->idade, aux->info->altura, aux->info->peso);
            aux = aux->prox;
        } while (aux != l->inicio);
        printf("Quantidade Total de Pessoas: %d\n", l->qtd);
    }
}

int buscarRG(LDEC *l, int RG){
    if(isEmpty(l)){
        return 0;
    } else {
        LDECnode *aux = l->inicio;
        do{
            if(aux->info->RG == RG){
                return 1;
            }
            aux = aux->prox;
        }while(aux != l->inicio);
    }
    return 0;
}

void inserirOrdenado(LDEC *l, char *nome, int RG, int idade, float peso, float altura){
    if(buscarRG(l, RG)){
        return;
    }
    LDECnode *novo = criarNo(nome, RG, idade, peso, altura);
    if(isEmpty(l)){  
        l->inicio = novo;
        l->fim = novo;
    } else {
        LDECnode *atual = l->inicio;
        LDECnode *anterior = NULL;
        do{
            if(strcmp(novo->info->nome, atual->info->nome) < 0){
                break;
            }
            anterior = atual;
            atual = atual->prox;
        } while(atual != l->inicio);

        if(anterior == NULL){
            novo->prox = l->inicio;
            l->inicio = novo;
        } else if(atual == l->inicio){
            l->fim->prox = novo;
            l->fim = novo;
        } else {
            anterior->prox = novo;
            novo->prox = atual;
        }
    }
    l->fim->prox = l->inicio;
    l->qtd++;
}

LDEC ordenar(LDEC l) {
    LDEC Ordenada;
    inicializar(&Ordenada);

    if (isEmpty(&l)){
        return Ordenada;
    } 

    LDECnode *aux = l.inicio;
    do {
        inserirOrdenado(&Ordenada, aux->info->nome, aux->info->RG, aux->info->idade, aux->info->peso, aux->info->altura);
        aux = aux->prox;
    } while (aux != l.inicio);

    printf("A lista foi ordenada!\n");
    return Ordenada;
}

int main(){
    LDEC listaOriginal, listaOrdenada;
    inicializar(&listaOriginal);
    inicializar(&listaOrdenada);
    char nome[100];
    float altura, peso;
    int esc, list, RG, idade;

    do{
        printf("MENU DE OPCOES: \n");
        printf("1 - Inserir\n");
        printf("2 - Listar \n");
        printf("3 - Criar uma Lista Ordenada \n");
        printf("0 - Sair \n");
        printf("Escolha: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o nome da pessoa: ");
                scanf(" %100[^\n]s ", nome);
                printf("Digite o RG da pessoa: ");
                scanf("%d", &RG);
                printf("Digite a idade da pessoa: ");
                scanf("%d", &idade);
                printf("Digite o peso da pessoa: ");
                scanf("%f", &peso);
                printf("Digite a altura da pessoa: ");
                scanf("%f", &altura);
                inserir(&listaOriginal, nome, RG, idade, peso, altura);
                break;
            case 2:
                printf("Dseseja listar a Lista Original (1) ou a Ordenada (2)? ");
                scanf("%d", &list);
                if(list == 1){
                    listar(&listaOriginal);
                } else if(list == 2){
                    listar(&listaOrdenada);
                }
                break;
            case 3:
                listaOrdenada = ordenar(listaOriginal);
                break;
            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao incorreta! tente novamente... \n");
                break;
        }
    } while( esc != 0);

    return 0;
}

//QUESTÃO 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ledcNode{
    int info;
    struct ledcNode *ant;
    struct ledcNode *prox;
} LDECnode;

typedef struct ldec {
    LDECnode *inicio;
    LDECnode *fim;
    int qtd;
} LDEC;

void inicializar(LDEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDEC *l){
    return(l->qtd == 0);
}

LDECnode *criarNo(int valor){
    LDECnode *novo = (LDECnode*) malloc(sizeof(LDECnode));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

int buscar(LDEC *l, int valor){
    if(isEmpty(l)){
        return 0;
    } else {
        LDECnode *aux = l->inicio;
        do{
            if(aux->info == valor){
                return 1;
            }
            aux = aux->prox;
        }while(aux != l->inicio);
    }
    return 0;
}

void inserir(LDEC *l, int valor){
    if(buscar(l, valor) == 1){
        printf("Valor repetido! Nao podera ser adicionado.\n");
        return;
    }
    if(isEmpty(l)){
        LDECnode *novo = criarNo(valor);
        l->inicio = novo;
        l->fim = novo;
    } else {
        LDECnode *novo = criarNo(valor);
        LDECnode *aux = l->inicio;

        if(valor < l->inicio->info){
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
        } else if(valor > l->fim->info){
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;
        } else {
            while(aux->prox != l->inicio && aux->prox->info < valor){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            novo->ant = aux;
            aux->prox->ant = novo;
            aux->prox = novo;
        }
    }
    l->inicio->ant = l->fim;
    l->fim->prox = l->inicio;
    l->qtd++;
    printf("Insercao efetuada! \n");
}

void listar(LDEC *l){
    if(isEmpty(l)){
        printf("Lista vazia!\n");
    } else {
        printf("Lista: ");
        LDECnode *aux = l->inicio;
        do{
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != l->inicio);
        printf("\nQTD: %d\n", l->qtd);
    }
}

LDEC intercalar(LDEC *l1, LDEC *l2) {
    LDEC l3;
    inicializar(&l3);

    if (isEmpty(l1) && isEmpty(l2)) {
        printf("Ambas as listas estao vazias!\n");
        return l3;
    }
    
    LDECnode *aux1 = l1->inicio;
    LDECnode *aux2 = l2->inicio;

    do{
        inserir(&l3, aux1->info);
        aux1 = aux1->prox;
    }while(aux1 != l1->inicio);

    do{
        inserir(&l3, aux2->info);
        aux2 = aux2->prox;
    }while(aux2 != l2->inicio);
    
    printf("Intercalacao concluida!\n");
    return l3;
}

int main(){
    LDEC l1, l2, l3;
    inicializar(&l1);
    inicializar(&l2);
    inicializar(&l3);
    int esc, list, valor;

    do{
        printf("MENU DE OPCOES: \n");
        printf("1 - Inserir \n");
        printf("2 - Listar \n");
        printf("3 - Intercalar \n");
        printf("0 - Sair \n");
        printf("Escolha: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Deseja inserir na lista 1 ou 2? ");
                scanf("%d", &list);
                if(list == 1){
                    inserir(&l1, valor);
                } else if(list == 2){
                    inserir(&l2, valor);
                } else {
                    printf("Escolha invalida!\n");
                }
                break;
            case 2:
                printf("Deseja exibir a lista 1, 2 ou 3? ");
                scanf("%d", &list);
                if(list == 1){
                    listar(&l1);
                } else if(list == 2){
                    listar(&l2);
                } else if(list == 3){
                    listar(&l3);
                } else {
                    printf("Escolha invalida!\n");
                }
                break;
            case 3:
                l3 = intercalar(&l1,&l2);
                break;
            case 0:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opcao incorreta! tente novamente... \n");
                break;
        }
    } while( esc != 0);

    return 0;
}