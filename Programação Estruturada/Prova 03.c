#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Local{
    char nome[50];
    int numero;
};

struct Lista {
    char nomepalestra[50];
    char instituicao[50];
};

struct Conferencia {
    char nome[50];
    char estudo[50];
    char data[50];
    int dias;
    struct Local locais;
    struct Lista palestrantes[4];
};

int main(){
    int memoria = 3;
    struct Conferencia *lista_conferencias = malloc(memoria * sizeof(struct Conferencia));
    int escolha, k = 0, c = 0, a = 0, b = 0, n = 0;
    char nomeConf[50], nomePredio[50];

        do{
            printf("\nMenu de Conferencias: \n");
            printf("1. Adicionar nova conferencia.\n");
            printf("2. Remover conferencia.\n");
            printf("3. Buscar conferencias por nome do predio.\n");
            printf("4. Alocar memoria.\n");
            printf("5. Imprimir lista de conferencias.\n");
            printf("6. Sair do sistema.\n");
            printf("Selecione sua opcao: ");
            scanf(" %d", &escolha);
            printf("\n");

            switch (escolha) {
                case 1:
                    if(k < memoria){
                        printf("Digite o nome da conferencia: ");
                        scanf(" %50[^\n]s", lista_conferencias[k].nome);

                        printf("Digite a area de estudos: ");
                        scanf(" %50[^\n]s", lista_conferencias[k].estudo);

                        printf("Digite a data da conferencia: ");
                        scanf(" %50[^\n]s", lista_conferencias[k].data);

                        printf("Digite a duracao da conferencia: ");
                        scanf(" %d", &lista_conferencias[k].dias);

                        printf("Digite o local da conferencia: \n");
                        printf("Nome do local: ");
                        scanf(" %50[^\n]s", lista_conferencias[k].locais.nome);
                        printf("Numero do local: ");
                        scanf(" %d", &lista_conferencias[k].locais.numero);

                        printf("Digite o numero de palestrantes (Max. 4): ");
                        scanf(" %d", &n);
                        
                        for(int i = 0; i < 4; i++){
                            strcpy(lista_conferencias[k].palestrantes[i].nomepalestra, " ");
                            strcpy(lista_conferencias[k].palestrantes[i].instituicao, " ");                                
                        }

                        printf("Digite a lista de palestrantes: \n");
                        for(int i = 0; i < n; i++){
                            printf("Nome do palestrante %d: ", c+1);
                            scanf(" %50[^\n]s", lista_conferencias[k].palestrantes[c].nomepalestra);
                            printf("Instituicao do palestrante: ");
                            scanf(" %50[^\n]s", lista_conferencias[k].palestrantes[c].instituicao);
                        }
                        k++;
                    } else {
                        printf("Lista cheia! Seleciona a opcao 4 para aumentar a lista.");
                    }
                    printf("\n");
                    break;
                
                case 2:
                    printf("Digite o nome da conferencia: ");
                    scanf(" %50[^\n]s", nomeConf);

                    a = 0;
                    for(int i = 0; i < k; i++){
                        if(strcmp(nomeConf, lista_conferencias[i].nome) == 0){
                            a = 1;
                            for(int j = i; j < k -1; j++){
                                lista_conferencias[j] = lista_conferencias[j + 1];
                            }
                            k--;
                            printf("Conferencia removida!\n");
                        }
                    }
                    if(a == 0){
                        printf("Nenhuma conferencia encontrada\n");
                    }
                    printf("\n");
                    break;

                case 3:
                    printf("Digite do predio da conferencia: ");
                    scanf(" %50[^\n]s", nomePredio);

                    b = 0;
                    for(int i = 0; i < k; i++){
                        printf("\nConferencias relacionadas ao predio %s:\n", nomePredio);
                        if(strcmp(nomePredio, lista_conferencias[i].locais.nome) == 0){
                            b = 1;
                            printf("Nome da conferencia: %s\n", lista_conferencias[i].nome);
                            printf("Area de estudo: %s\n", lista_conferencias[i].estudo);
                            printf("Data: %s\n", lista_conferencias[i].data);
                            printf("\n");
                        }
                    }
                    if(b == 0){
                            printf("Nenhuma conferencia esta localizada neste predio.\n");
                    }
                    printf("\n");
                    break;

                case 4:
                    memoria += 3;
                    lista_conferencias = realloc(lista_conferencias, memoria * sizeof(struct Conferencia));
                    printf("Memoria alocada! Nova memoria da lista: %d ", memoria);
                    printf("\n");
                    break;

                case 5:
                    printf("Lista das Conferencias: \n");

                    for(int i = 0; i < k; i++){
                        printf("Nome da conferencia: %s\n", lista_conferencias[i].nome);
                        printf("Area de estudo: %s\n", lista_conferencias[i].estudo);
                        printf("Data: %s\n", lista_conferencias[i].data);
                        printf("Duracao: %d dias\n", lista_conferencias[i].dias);
                        printf("Local: %s, numero %d\n", lista_conferencias[i].locais.nome, lista_conferencias[i].locais.numero);
                        printf("Palestrantes: \n");
                            for(int j = 0; j < 4; j++){
                                printf("%s | %s\n", lista_conferencias[i].palestrantes[j].nomepalestra, lista_conferencias[i].palestrantes[j].instituicao);
                            }
                        printf("\n");
                    }
                    break;

                case 6:
                    printf("Saindo do programa...\n");
                    free(lista_conferencias);
                    lista_conferencias = NULL;
                    escolha = 0;
                    printf("\n");
                    break;

                default:
                    printf("Opcao incorreta! Tente novamente...\n");
                    printf("\n");
                    break;
            }

        } while(escolha != 0);

    return 0;
}