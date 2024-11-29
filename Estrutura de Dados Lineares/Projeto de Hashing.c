#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 57
typedef struct carro {
	char placa[8];
	char marca[15];
	char modelo[15];
	char cor[15];
	int status;
} CARRO;

typedef struct noTabela {
	char placa[8];
	int posicao;
	struct noTabela* prox;
	struct noTabela* ant;
} NO;

FILE* prepararArquivo(char nome[]) {
	FILE *arq = fopen(nome, "r+b");
	if(arq == NULL){
		arq = fopen(nome, "r+b");
		if(arq == NULL){
			printf("Erro ao abrir arquivo.\n");
			return NULL;
		}
	}
	return arq;
}

void fecharArquivo(FILE* arq){
    fclose(arq);
}

int hashing(char placa[]) {
    int soma = 0;
    int tam = strlen(placa);
    for (int i = 0; i < tam; i++) {
        soma += (placa[i] << (i % 8));
    }
    return abs(soma) % N;
}

int buscar(NO* tabelaHashing[], char placa[]){
    int indice = hashing(placa);
    NO* aux = tabelaHashing[indice];
    while (aux != NULL) {
        if (strcmp(aux->placa, placa) == 0) {
            return aux->posicao;
        }
        aux = aux->prox;
    }
    return -1;
}

void liberarArquivo(FILE* arq) {
    FILE* arquivo = fopen("arquivo.dat", "w+b");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");
        return;
    }

    CARRO carrinho;
    rewind(arq);

    while (fread(&carrinho, sizeof(CARRO), 1, arq)) {
        if (carrinho.status == 1) {
            fwrite(&carrinho, sizeof(CARRO), 1, arquivo);
        }
    }

    fecharArquivo(arq);
    fecharArquivo(arquivo);
    remove("carros.dat");
    rename("arquivo.dat", "carros.dat");
    printf("Arquivo liberado!\n");
}

void inserirTabelaHash(NO* tabelaHashing[], char placa[], int posicao) {
    int indice = hashing(placa);

    NO* novo = (NO*)malloc(sizeof(NO));
    strcpy(novo->placa, placa);
    novo->posicao = posicao;
    novo->prox = NULL;
    novo->ant = NULL;

    NO* atual = tabelaHashing[indice];
    
    if (atual == NULL || strcmp(atual->placa, placa) > 0) {
        novo->prox = tabelaHashing[indice];
        if (tabelaHashing[indice] != NULL) {
            tabelaHashing[indice]->ant = novo;
        }
        tabelaHashing[indice] = novo;
    } else {
        while (atual->prox != NULL && strcmp(atual->prox->placa, placa) < 0) {
            atual = atual->prox;
        }
        
        novo->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = novo;
        }
        atual->prox = novo;
        novo->ant = atual;
    }
}

void cadastrar(FILE* arq, NO* tabelaHashing[]) {
    CARRO carrinho;

    printf("Informe a placa do carro: ");
    scanf(" %7[^\n]", carrinho.placa);

    if (buscar(tabelaHashing, carrinho.placa) != -1) {
        printf("Carro ja cadastrado!\n");
        return;
    }

    printf("Informe a marca: ");
    scanf(" %14[^\n]", carrinho.marca);
    printf("Informe o modelo: ");
    scanf(" %14[^\n]", carrinho.modelo);
    printf("Informe a cor: ");
    scanf(" %14[^\n]", carrinho.cor);
    carrinho.status = 1;

    fseek(arq, 0, SEEK_END);
    int posicao = ftell(arq) / sizeof(CARRO);
    fwrite(&carrinho, sizeof(CARRO), 1, arq);
    inserirTabelaHash(tabelaHashing, carrinho.placa, posicao);

    printf("Carro cadastrado com sucesso!\n");
}

void consultar(FILE* arq, NO* tabelaHashing[]) {
    char placa[8];
    printf("Informe a placa do carro: ");
    scanf(" %7[^\n]", placa);

    int posicao = buscar(tabelaHashing, placa);
    if (posicao == -1) {
        printf("Carro nao encontrado!\n");
        return;
    }

    CARRO carrinho;
    fseek(arq, posicao * sizeof(CARRO), SEEK_SET);
    fread(&carrinho, sizeof(CARRO), 1, arq);

    printf("Carro foi encontrado:\n");
    printf("Placa: %s\n", carrinho.placa);
    printf("Marca: %s\n", carrinho.marca);
    printf("Modelo: %s\n", carrinho.modelo);
    printf("Cor: %s\n", carrinho.cor);
}

void alterar(FILE* arq, NO* tabelaHashing[]) {
    char placa[8];
    printf("Informe a placa do carro a ser alterado: ");
    scanf(" %7[^\n]s", placa);

    int posicao = buscar(tabelaHashing, placa);
    if (posicao == -1) {
        printf("Carro nao encontrado!\n");
        return;
    }

    CARRO carrinho;
    fseek(arq, posicao * sizeof(CARRO), SEEK_SET);
    fread(&carrinho, sizeof(CARRO), 1, arq);

    printf("Dados atuais:\n");
    printf("Marca: %s\n", carrinho.marca);
    printf("Modelo: %s\n", carrinho.modelo);
    printf("Cor: %s\n", carrinho.cor);

	int escolha = 0;
	do{
		printf("1 - Marca | 2 - Modelo | 3 - Cor\n");
		printf("Quais dados deseja alterar (0 - Sair): ");
		scanf(" %d", &escolha);
		if(escolha == 1){
			printf("Informe a nova marca: ");
    		scanf(" %14[^\n]s", carrinho.marca);
		} else if(escolha == 2){
			printf("Informe o novo modelo: ");
    		scanf(" %14[^\n]s", carrinho.modelo);
		} else if(escolha == 3){
			printf("Informe a nova cor: ");
    		scanf(" %14[^\n]s", carrinho.cor);
		}
	} while(escolha != 0);

    fseek(arq, posicao * sizeof(CARRO), SEEK_SET);
    fwrite(&carrinho, sizeof(CARRO), 1, arq);
    printf("Dados foram alterados!\n");
}

void removerTabelaHash(NO* tabelaHashing[], char placa[], int posTabela) {
    NO* aux = tabelaHashing[posTabela];
    while (aux != NULL && strcmp(aux->placa, placa) != 0) {
        aux = aux->prox;
    }

    if (aux == NULL){
		return;
	}

    if (aux->ant != NULL) {
        aux->ant->prox = aux->prox;
    } else {
        tabelaHashing[posTabela] = aux->prox;
    }

    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }

    free(aux);
}

void remover(FILE* arq, NO* tabelaHashing[]) {
    char placa[8];
    printf("Informe a placa do carro a ser removido: ");
    scanf(" %7[^\n]s", placa);

    int posicao = buscar(tabelaHashing, placa);
    if (posicao == -1) {
        printf("Carro nao encontrado!\n");
        return;
    }

    CARRO carrinho;
    fseek(arq, posicao * sizeof(CARRO), SEEK_SET);
    fread(&carrinho, sizeof(CARRO), 1, arq);
    
    int escolha;
    printf("Dados do carro:\n");
    printf("Placa: %s\n", carrinho.placa);
    printf("Marca: %s\n", carrinho.marca);
    printf("Modelo: %s\n", carrinho.modelo);
    printf("Cor: %s\n", carrinho.cor);
    printf("Deseja realmente remover este carro? 1 - Sim | 0 - Nao: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        carrinho.status = 0;
        fseek(arq, posicao * sizeof(CARRO), SEEK_SET);
        fwrite(&carrinho, sizeof(CARRO), 1, arq);

        removerTabelaHash(tabelaHashing, placa, hashing(placa));
        printf("Carro removido!\n");
    } else {
		printf("Carro nao foi removido!\n");
	}
}

void exibirCadastro(FILE* arq) {
    if (arq == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    CARRO carro;
    rewind(arq);
    int k = 0;
    printf("\nLista de Carros:\n");
    while (fread(&carro, sizeof(CARRO), 1, arq) == 1) {
        if (carro.status == 1) {
            k = 1;
            printf("\nPlaca: %s\n", carro.placa);
            printf("Marca: %s\n", carro.marca);
            printf("Modelo: %s\n", carro.modelo);
            printf("Cor: %s\n", carro.cor);
        }
    }

    if(k == 0) {
        printf("Nenhum carro ativo encontrado no cadastro.\n");
    }
}


void criarIndice(FILE* arq, NO* tabelaHashing[]) {
    for (int i = 0; i < N; i++) {
        tabelaHashing[i] = NULL;
    }

    CARRO carrinho;
    rewind(arq);
    int posicao = 0;
    while (fread(&carrinho, sizeof(CARRO), 1, arq)) {
        if (carrinho.status == 1) {
            inserirTabelaHash(tabelaHashing, carrinho.placa, posicao);
        }
        posicao++;
    }
}

void desalocarIndice(NO* tabelaHashing[]) {
    for (int i = 0; i < N; i++) {
        NO* atual = tabelaHashing[i];
        NO* anterior = NULL;
        while (atual != NULL) {
            anterior = atual;
            atual = atual->prox;
            free(anterior);
        }
        tabelaHashing[i] = NULL;
    }
}

void exibirOpcoes() {
	printf("\nOpcoes \n");
	printf("1 - Cadastrar um carro \n");
	printf("2 - Consultar carro \n");
	printf("3 - Alterar dados do carro \n");
	printf("4 - Remover carro \n");
	printf("5 - Exibir carros cadastrados \n");
	printf("0 - Encerrar programa \n");
	printf("Informe a opcao: ");
}

int main() {
	char nomeArq[] = "carros.dat";
	int op;
	FILE* cadastro;
	NO* tabelaHashing[N];
	cadastro = prepararArquivo(nomeArq);
	if (cadastro == NULL)
		printf("Erro na abertura do arquivo. Programa encerrado \n");
	else {
		criarIndice(cadastro, tabelaHashing);
		do {
			exibirOpcoes();
			scanf("%d",&op); fflush(stdin);
			switch (op) {
			case 1: cadastrar(cadastro, tabelaHashing);
		                break;
			case 2: consultar(cadastro, tabelaHashing);
			            break;
			case 3: alterar(cadastro, tabelaHashing);
			            break;
			case 4: remover(cadastro, tabelaHashing);
			            break;
			case 5: exibirCadastro(cadastro);
			            break;
			case 0: liberarArquivo(cadastro);
			            desalocarIndice(tabelaHashing);
			            break;
			default: printf("Opcao invalida \n");
			}
		} while (op != 0);
	}
	return 0;
}