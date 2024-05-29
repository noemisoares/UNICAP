//Atividade 15 - Arquivos - Programação Estruturada
//Aluna: Noemi Soares Gonçalves da Silva  RA:00000851329

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arquivo;
    char c;
    
    arquivo = fopen("arq.txt", "w");

    if(arquivo == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }

    while(1){
        printf("Entre com um caractere (0 para sair): ");
        scanf(" %c", &c);

        if(c == '0'){
            break;
        }
        
        fputc(c, arquivo);
    }

    fclose(arquivo);

    arquivo = fopen("arq.txt", "r");

    printf("Conteudo do arquivo: \n");
    while ((c = fgetc(arquivo)) != EOF) {
        printf("%c", c);
    }

    fclose(arquivo);

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arquivo;
    char nomeArq[100];
    char c;
    int k = 0;

    printf("Digite o nome do arquivo: ");
    scanf(" %s", nomeArq);

    arquivo = fopen(nomeArq, "r");
    while((c = fgetc(arquivo)) != EOF){
        if(c == '\n'){
            k++;
        }
    }

    fclose(arquivo);

    printf("O arquivo possui %d linhas\n", k);

    return 0;
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arquivo;
    char nomeArq[100];
    char c;
    int k = 0;

    printf("Digite o nome do arquivo: ");
    scanf(" %s", nomeArq);

    arquivo = fopen(nomeArq, "r");
    while((c = fgetc(arquivo)) != EOF){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            k++;
        }
    }

    fclose(arquivo);

    printf("O arquivo possui %d vogais\n", k);

    return 0;
}

//QUESTÃO 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arquivo;
    char nomeArq[100];
    char c, a;
    int k = 0;

    printf("Digite o nome do arquivo: ");
    scanf(" %s", nomeArq);

    printf("Digite um caractere para busca: ");
    scanf(" %c", &a);

    arquivo = fopen(nomeArq, "r");
    while((c = fgetc(arquivo)) != EOF){
        if(c == a){
            k++;
        }
    }

    fclose(arquivo);

    printf("O arquivo possui %d letras %c\n", k, a);

    return 0;
}

//QUESTÃO 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arquivo1, *arquivo2;
    char nomeArq[100];
    char nomeArqNovo[100];
    char c;

    printf("Digite o nome do arquivo: ");
    scanf(" %s", nomeArq);

    arquivo1 = fopen(nomeArq, "r");

    printf("Digite o nome do novo arquivo: ");
    scanf(" %s", nomeArqNovo);

    arquivo2 = fopen(nomeArqNovo, "w");

    while((c = fgetc(arquivo1)) != EOF){
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }
        fputc(c, arquivo2);
    }

    fclose(arquivo1);
    fclose(arquivo2);

    printf("Conversao feita!\n");

    return 0;
}

//QUESTÃO 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arquivo;
    char nomeArq[100];
    char c;
    char string[100];
    int k = 0, i = 0;

    printf("Digite o nome do arquivo: ");
    scanf(" %s", nomeArq);

    arquivo = fopen(nomeArq, "r");

    printf("Digite a palavra para busca: ");
    scanf(" %s", string);

    int tam = strlen(string);  

    while((c = fgetc(arquivo)) != EOF){
        if(c == string[i]){
            i++;
            if (i == tam) {
                k++;
                i = 0;
            }    
        } else {
            i = 0;
        }
    }

    fclose(arquivo);

    printf("a palavra %s aparece %d vezes no arquivo.\n", string, k);

    return 0;
}

//QUESTÃO 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cadastro {
    char nome[50];
    char telefone[50]; 
};

int main(){
    struct Cadastro cadastros;
    FILE *arquivo;
    int i = 1;

    arquivo = fopen("Cadastros.txt", "w");

    while (1) {
        printf("Digite um nome %d: ", i);
        scanf(" %50[^\n]s", cadastros.nome);

        printf("Digite um telefone %d (0 para sair): ", i);
        scanf(" %50[^\n]s", cadastros.telefone);

        i++;

        if(strcmp(cadastros.telefone, "0") == 0){
            printf("Arquivo de Cadastros foi criado!\n");
            break;
        }

        fprintf(arquivo, "%s\n", cadastros.nome);
        fprintf(arquivo, "%s\n", cadastros.telefone);

    }

    fclose(arquivo);

    return 0;
}

//QUESTÃO 8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    char nome[50];
    float preco;
};

int main(){
    struct Produto produtos;
    FILE *arquivo = fopen("produtos.txt", "w");
    int i = 1;
    float total = 0;
    char esc;

    while(1){
        printf("Digite o nome do produto %d: ", i);
        scanf(" %50[^\n]s", produtos.nome);

        printf("Digite o preco do produto %d: ", i);
        scanf(" %f", &produtos.preco);

        i++;

        total += produtos.preco;
        fprintf(arquivo, "%s\n", produtos.nome);
        fprintf(arquivo, "%.2f\n", produtos.preco);

        printf("Deseja continuar (s/n)? \n");
        scanf(" %c", &esc);

        if(esc == 'n' || esc == 'N'){
            break;
        }
    }

    printf("Valor total para pagamento: R$%.2f", total);

    return 0;
}

//QUESTÃO 9 COM .DAT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aniversario{
    int dia;
    int mes;
};

struct Contato {
    char nome[100];
    char telefone[30];
    struct Aniversario aniversarios;
};

int main(){
    struct Contato contatos[100];
    FILE *arquivo;
    char nomeRemove[100], nomeEncontrado[100];
    char escolha, letra;
    int k = 0, mes, a = 0;

    arquivo = fopen("Contatos.dat", "rb");
    if(arquivo != NULL){
        while(fread(&contatos[k], sizeof(struct Contato), 1, arquivo)){
            k++;
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo...\n");
    }

    do{
        printf("\nMenu de Opcoes\n");
        printf("a. Inserir contato.\n");
        printf("b. Remover contato.\n");
        printf("c. Pesquisar um contato pelo nome.\n");
        printf("d. Listar todos os contatos.\n");
        printf("e. Listar os contatos cujo nome inicia com uma letra.\n");
        printf("f. Imprimir os aniversariantes do mes.\n");
        printf("s. Sair do menu.\n");
        printf("Selecione sua escolha: ");
        scanf(" %c", &escolha);
        printf("\n");

        switch (escolha) {
            case 'a':
                if(k < 100){
                    printf("Digite o nome do contato: ");
                    scanf(" %100[^\n]s", contatos[k].nome);

                    printf("Digite o numero de telefone do contato: ");
                    scanf(" %30[^\n]s", contatos[k].telefone);

                    printf("Digite o  aniversario do contato: \n");
                    printf("Dia: ");
                    scanf(" %d", &contatos[k].aniversarios.dia);
                    printf("Mes: ");
                    scanf(" %d", &contatos[k].aniversarios.mes);

                    k++;
                    printf("Contato adicionado!\n");
                } else {
                    printf("Agenda cheita!\n");
                }
                printf("\n");     
                break;

            case 'b':
                printf("Digite o nome do contato que quer remover: ");
                scanf(" %100[^\n]s", nomeRemove);
                a = 0;
                for(int i = 0; i < k; i++){
                    if(strcmp(nomeRemove, contatos[i].nome) == 0){
                        a = 1;
                        for(int j = i; j < k - 1; j++){
                            contatos[j] = contatos[j+1];
                        }
                        k--;
                        printf("Contato removido!\n");
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");  
                break;
            
            case 'c':
                printf("Digite o nome do contato que quer encontrar: ");
                scanf(" %100[^\n]s", nomeEncontrado);
                a = 0;
                for(int i = 0; i < k; i++){
                    if(strcmp(nomeEncontrado, contatos[i].nome) == 0){
                        a = 1;
                        printf("Contato encontrado!\n");
                        printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");  
                break;

            case 'd':
                printf("Contatos armazenados: \n");

                for(int i = 0; i < k; i++){
                    printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                }
                printf("\n");  
                break;

            case 'e':
                printf("Digite uma letra para buscar contatos: ");
                scanf(" %c", &letra);
                a = 0;
                printf("Contatos que comecam com a letra %c: \n", letra);
                for(int i = 0; i < k; i++){
                    if(letra == contatos[i].nome[0]){
                        a = 1;
                        printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");  
                break;

            case 'f':
                printf("Digite um mes para buscar contatos: ");
                scanf(" %d", &mes);
                a = 0;
                printf("Contatos que fazem aniversario no mes %d: \n", mes);
                for(int i = 0; i < k; i++){
                    if(mes == contatos[i].aniversarios.mes){
                        a = 1;
                        printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");
                break;
            
            case 's':
                printf("Saindo do programa...\n");
                printf("\n"); 
                break;
            
            default:
                printf("Selecao incorreta... Tente novamente\n");
                printf("\n");  
                break;
        }

    } while( escolha != 's');
    
    arquivo = fopen("Contatos.dat", "wb");
    if(arquivo != NULL){
        fwrite(&contatos, sizeof(struct Contato), k, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo...\n");
    }

    return 0;
}

//QUESTAO 9 COM .TXT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aniversario{
    int dia;
    int mes;
};

struct Contato {
    char nome[100];
    char telefone[30];
    struct Aniversario aniversarios;
};

int main(){
    struct Contato contatos[100];
    FILE *arquivo;
    char nomeRemove[100], nomeEncontrado[100];
    char escolha, letra;
    int k = 0, mes, a = 0;

    arquivo = fopen("Contatos.txt", "r");
    if(arquivo != NULL){
        while(fscanf(arquivo, "%s - %s - %d/%d\n", contatos[k].nome, contatos[k].telefone, &contatos[k].aniversarios.dia, &contatos[k].aniversarios.mes) == 4){
            k++;
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }

    do{
        printf("\nMenu de Opcoes\n");
        printf("a. Inserir contato.\n");
        printf("b. Remover contato.\n");
        printf("c. Pesquisar um contato pelo nome.\n");
        printf("d. Listar todos os contatos.\n");
        printf("e. Listar os contatos cujo nome inicia com uma letra.\n");
        printf("f. Imprimir os aniversariantes do mes.\n");
        printf("s. Sair do menu.\n");
        printf("Selecione sua escolha: ");
        scanf(" %c", &escolha);
        printf("\n");

        switch (escolha) {
            case 'a':
                if(k < 100){
                    printf("Digite o nome do contato: ");
                    scanf(" %100[^\n]s", contatos[k].nome);

                    printf("Digite o numero de telefone do contato: ");
                    scanf(" %30[^\n]s", contatos[k].telefone);

                    printf("Digite o  aniversario do contato: \n");
                    printf("Dia: ");
                    scanf(" %d", &contatos[k].aniversarios.dia);
                    printf("Mes: ");
                    scanf(" %d", &contatos[k].aniversarios.mes);

                    k++;
                    printf("Contato adicionado!\n");
                } else {
                    printf("Agenda cheita!\n");
                }
                printf("\n");     
                break;

            case 'b':
                printf("Digite o nome do contato que quer remover: ");
                scanf(" %100[^\n]s", nomeRemove);
                a = 0;
                for(int i = 0; i < k; i++){
                    if(strcmp(nomeRemove, contatos[i].nome) == 0){
                        a = 1;
                        for(int j = i; j < k - 1; j++){
                            contatos[j] = contatos[j+1];
                        }
                        k--;
                        printf("Contato removido!\n");
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");  
                break;
            
            case 'c':
                printf("Digite o nome do contato que quer encontrar: ");
                scanf(" %100[^\n]s", nomeEncontrado);
                a = 0;
                for(int i = 0; i < k; i++){
                    if(strcmp(nomeEncontrado, contatos[i].nome) == 0){
                        a = 1;
                        printf("Contato encontrado!\n");
                        printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");  
                break;

            case 'd':
                printf("Contatos armazenados: \n");

                for(int i = 0; i < k; i++){
                    printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                }
                printf("\n");  
                break;

            case 'e':
                printf("Digite uma letra para buscar contatos: ");
                scanf(" %c", &letra);
                a = 0;
                printf("Contatos que comecam com a letra %c: \n", letra);
                for(int i = 0; i < k; i++){
                    if(letra == contatos[i].nome[0]){
                        a = 1;
                        printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");  
                break;

            case 'f':
                printf("Digite um mes para buscar contatos: ");
                scanf(" %d", &mes);
                a = 0;
                printf("Contatos que fazem aniversario no mes %d: \n", mes);
                for(int i = 0; i < k; i++){
                    if(mes == contatos[i].aniversarios.mes){
                        a = 1;
                        printf("%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
                    }
                }
                if(a == 0){
                    printf("Nenhum contato encontrado.\n");
                }
                printf("\n");
                break;
            
            case 's':
                printf("Saindo do programa...\n");
                printf("\n"); 
                break;
            
            default:
                printf("Selecao incorreta... Tente novamente\n");
                printf("\n");  
                break;
        }

    } while( escolha != 's');
    
    arquivo = fopen("Contatos.txt", "w");
    if(arquivo != NULL){
        for(int i = 0; i < k; i++){
            fprintf(arquivo, "%s - %s - %02d/%02d\n", contatos[i].nome, contatos[i].telefone, contatos[i].aniversarios.dia, contatos[i].aniversarios.mes);
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo...\n");
    }

    return 0;
}