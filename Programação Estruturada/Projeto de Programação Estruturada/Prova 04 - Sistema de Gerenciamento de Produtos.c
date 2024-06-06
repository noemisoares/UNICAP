//Prova 04 - Prof. Augusto César - Programação Estruturada
//Alunos: Noemi Soares Gonçalves da Silva RA:00000851329
//        Marcos Vinicius Medeiros Ferreira  RA:00000851337

//Sistema de Gerenciamento de Produtos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    char nome[100];
    int codigo;
    int quantidade;
    float preco;
};

int main(){
    int memoria = 100;
    struct Produto *produtos = malloc(memoria * sizeof(struct Produto));
    FILE *arquivo;
    char escolha, listar, opcaoIF, atualizarEsc, comprar, confirmar, atualizarConf;
    int k = 0, atualizar, a = 0, comprarCodigo, buscarCodigo, remoCodigo, comprarQuant, idealQuant;
    float valortotal = 0;

    arquivo = fopen("Produtos.txt", "r");
    while(fscanf(arquivo, "%99[^-]- %f - %d - %d\n", produtos[k].nome, &produtos[k].preco, &produtos[k].codigo, &produtos[k].quantidade) == 4){
        k++;
    }
    fclose(arquivo);

    do{
        printf("\nMENU DE GERENCIAMENTO DE PRODUTOS\n");
        printf("1. Adicionar um produto.\n"); 
        printf("2. Listar registros.\n");
        printf("3. Buscar um registro.\n");
        printf("4. Atualizar um registro.\n");
        printf("5. Remover um registro.\n");
        printf("6. Verificar produtos com estoque baixo.\n");
        printf("7. Adcionar mais espaco para produtos.\n");
        printf("8. Realizar uma compra.\n");
        printf("0. Sair do Menu.\n");
        printf("Digite uma escolha: ");
        scanf(" %c", &escolha);
        printf("\n");

        switch (escolha) {
            case '1':
                if(k < memoria){
                    printf("Digite o codigo do produto: ");
                    scanf(" %d", &produtos[k].codigo);

                    printf("Digite o nome do produto: ");
                    scanf(" %100[^\n]s", produtos[k].nome);

                    printf("Digite a quantidade do produto em estoque: ");
                    scanf(" %d", &produtos[k].quantidade);

                    printf("Digite o preco do produto: ");
                    scanf(" %f", &produtos[k].preco);

                    printf("Quer adicionar este registro no inicio (i) ou no final (f) do arquivo? ");
                    scanf(" %c", &opcaoIF);
                    
                    if(opcaoIF != 'I' && opcaoIF != 'i' && opcaoIF != 'F' && opcaoIF != 'f'){
                        printf("Opcao incorreta! Produto nao foi adicionado ao arquivo.\n");
                        k--;
                    }

                    if(opcaoIF == 'I' || opcaoIF == 'i') {
                        k++;
                        produtos[k] = produtos[k-1]; 
                        for (int i = k-1; i > 0; i--) {
                            produtos[i] = produtos[i - 1];
                        }
                        produtos[0] = produtos[k];
                        k--;
                        printf("Produto adicionado no inicio do arquivo!\n");
                    }
                    k++;

                    if(opcaoIF == 'F' || opcaoIF == 'f'){
                        printf("Produto adicionado no final do arquivo!\n");
                    }

                    if(opcaoIF == 'I' || opcaoIF == 'i' || opcaoIF == 'F' || opcaoIF == 'f'){
                        arquivo = fopen("Produtos.txt", "w");
                        for(int i = 0; i < k; i++){
                            fprintf(arquivo, "%s- %.2f - %d - %d\n", produtos[i].nome, produtos[i].preco, produtos[i].codigo, produtos[i].quantidade);
                        }
                        fclose(arquivo);
                    }
                } else {
                    printf("Todos os espaços estao lotados! Selecione a opcao 7 para adcionar mais espaco.\n");
                }
                printf("\n");
                break;
            
            case '2':
                printf("a. Os 5 primeiros registros.\n");
                printf("b. Os 5 ultimos registros.\n");
                printf("c. Todos os registros.\n");
                printf("Digite o formato de listagem dos registros: ");
                scanf(" %c", &listar);
                printf("\n");
                
                if(listar == 'a'){
                    printf("Registros dos 5 Primeiros Produtos:\n\n");
                    for(int i = 0; i < 5; i++){
                        printf("Nome do Produto: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Preco: R$%.2f\n", produtos[i].preco);
                        printf("Quantidade em Estoque: %d\n", produtos[i].quantidade);
                        printf("\n");
                    }
                } else if(listar == 'b'){
                    printf("Registros dos 5 Ultimos Produtos:\n\n");
                    for(int i = k - 5; i < k; i++){
                        printf("Nome do Produto: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Preco: R$%.2f\n", produtos[i].preco);
                        printf("Quantidade em Estoque: %d\n", produtos[i].quantidade);
                        printf("\n");
                    }
                } else if(listar == 'c'){
                    printf("Registros de Todos os Produtos:\n\n");
                    for(int i = 0; i < k; i++){
                        printf("Nome do Produto: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Preco: R$%.2f\n", produtos[i].preco);
                        printf("Quantidade em Estoque: %d\n", produtos[i].quantidade);
                        printf("\n");
                    }
                } else {
                    printf("Essa opcao nao existe! tente novamente...\n");
                }
                break;

            case '3':
                printf("Digite o codigo do produto que deseja buscar: ");
                scanf(" %d", &buscarCodigo);
                a = 0;
                for(int i = 0; i < k; i++){
                    if(buscarCodigo == produtos[i].codigo){
                        printf("Produto encontrado!\n\n");
                        a = 1;
                        printf("Nome do Produto: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Preco: R$%.2f\n", produtos[i].preco);
                        printf("Quantidade em Estoque: %d\n", produtos[i].quantidade);
                        printf("\n");
                    }
                }
                if(a == 0){
                    printf("Nenhum produto com o codigo %d foi encontrado no sistema!\n", buscarCodigo);
                }
                printf("\n");
                break;

            case '4':
                printf("Digite o codigo do produto que deseja atualizar: ");
                scanf(" %d", &atualizar);
                a = 0;
                for(int i = 0; i < k; i++){
                    if(produtos[i].codigo == atualizar){
                        printf("Produto encontrado!\n\n");
                        a = 1;
                        while(atualizarEsc != 'f'){
                            printf("Selecione o que deseja editar:\n");
                            printf("a. Codigo do Produto\n");
                            printf("b. Nome do Produto\n");
                            printf("c. Quantidade em Estoque\n");
                            printf("d. Preco do Produto\n");
                            printf("e. Todos os Parametros\n");
                            printf("f. Parar de Atualizar o Produto\n");
                            printf("Escolha o que deseja atualizar: ");
                            scanf(" %c", &atualizarEsc);

                            if(atualizarEsc == 'a'){
                                printf("Digite o novo codigo do produto: ");
                                scanf(" %d", &produtos[i].codigo);
                                printf("Codigo atualizado!\n");
                                printf("\n");
                            } else if(atualizarEsc == 'b'){
                                printf("Digite o novo nome do produto: ");
                                scanf(" %100[^\n]s", produtos[i].nome);
                                printf("Nome atualizado!\n");
                                printf("\n");
                            } else if(atualizarEsc == 'c'){
                                printf("Digite a nova quantidade do produto: ");
                                scanf(" %d", &produtos[i].quantidade);
                                printf("Quantidade atualizada!\n");
                                printf("\n");
                            } else if(atualizarEsc == 'd'){
                                printf("Digite o novo preco do produto: ");
                                scanf(" %f", &produtos[i].preco);
                                printf("Preco atualizado!\n");
                                printf("\n");
                            } else if(atualizarEsc == 'e'){
                                printf("Digite o novo codigo do produto: ");
                                scanf(" %d", &produtos[i].codigo);
                                printf("Digite o novo nome do produto: ");
                                scanf(" %100[^\n]s", produtos[i].nome);
                                printf("Digite a nova quantidade do produto: ");
                                scanf(" %d", &produtos[i].quantidade);
                                printf("Digite o novo preco do produto: ");
                                scanf(" %f", &produtos[i].preco);
                                printf("Todos os parametros foram atualizados!\n");
                                printf("\n");
                            } else if(atualizarEsc == 'f'){
                                printf("\n");
                                printf("Voltando ao menu principal...\n");
                            } else {
                                printf("Opcao inexistente! Tente novamente...\n\n");
                            }

                            printf("Confirmar as alteracoes (s/n)? ");
                            scanf(" %c", &atualizarConf);

                            if(atualizarConf == 's' || atualizarConf == 'S'){
                                arquivo = fopen("Produtos.txt", "w");
                                for(int i = 0; i < k; i++){
                                    fprintf(arquivo, "%s- %.2f - %d - %d\n", produtos[i].nome, produtos[i].preco, produtos[i].codigo, produtos[i].quantidade);
                                }
                                fclose(arquivo);
                            } else if(atualizarConf == 'n' || atualizarConf == 'N'){
                                printf("Alteracoes descartadas! Selecione outra opcao ou volte para o menu inicial\n\n");
                            }    
                        }
                    }
                }
                if(a == 0){
                    printf("Nenhum produto com o codigo %d foi encontrado no sistema!\n", atualizar);
                }
                printf("\n");
                break;

            case '5':
                printf("Digite o codigo do produto que deseja remover: ");
                scanf(" %d", &remoCodigo);
                a = 0;
                for(int i = 0; i < k; i++){
                    if(produtos[i].codigo == remoCodigo){
                        a = 1;
                        for(int j = i; j < k-1; j++){
                            produtos[j] = produtos[j+1];
                        }
                        k--;
                        printf("Produto removido com sucesso!\n");
                    }
                }
                arquivo = fopen("Produtos.txt", "w");
                for(int i = 0; i < k; i++){
                    fprintf(arquivo, "%s- %.2f - %d - %d\n", produtos[i].nome, produtos[i].preco, produtos[i].codigo, produtos[i].quantidade);
                }
                fclose(arquivo);
                if(a == 0){
                    printf("Nenhum produto com o codigo %d foi encontrado no sistema!\n", remoCodigo);
                }
                printf("\n");
                break;

            case '6':
                printf("Digite a quantidade ideal que um produto deve ter em estoque: ");
                scanf(" %d", &idealQuant);
                a = 0;
                printf("\n");
                printf("Produtos de Estoque Abaixo de %d:\n\n", idealQuant);
                for(int i = 0; i < k; i++){   
                    if(produtos[i].quantidade < idealQuant){
                        a = 1;
                        printf("Nome do Produto: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Quantidade em Estoque: %d\n", produtos[i].quantidade);
                        printf("Quantidade que deve ser adcionada: %d\n", idealQuant - produtos[i].quantidade);
                        printf("\n");
                    }
                }
                if(a == 0){
                    printf("Nenhum produto com o quantidade menor que %d foi encontrado no sistema!\n", idealQuant);
                }
                break;
            
            case '7':
                memoria += 50;
                produtos = realloc(produtos, memoria * sizeof(struct Produto));
                printf("Espaco alocado com sucesso! Um total de %d produtos podem ser armazenados!", memoria);
                printf("\n");
                break;
            
            case '8':
                while(1){
                    printf("Digite o codigo do produto que deseja comprar: ");
                    scanf(" %d", &comprarCodigo);
                    printf("Digite a quantidade que deseja comprar: ");
                    scanf(" %d", &comprarQuant);

                    a = 0;
                    for(int i = 0; i < k; i++){
                        if(comprarCodigo == produtos[i].codigo){
                            a = 1;
                            valortotal += (produtos[i].preco * comprarQuant);
                            produtos[i].quantidade -= comprarQuant;
                            printf("Produto adcionado!\n\n");
                        }
                    }
                    if(a == 0){
                        printf("Nenhum produto com o codigo %d foi encontrado no sistema!\n", comprarCodigo);
                        printf("Tente novamente com outro codigo.\n\n");
                    }

                    if(a != 0){
                        printf("Deseja adicionar outro produto (s/n)? ");
                        scanf(" %c", &comprar);

                        if(comprar == 'n'|| comprar == 'N'){
                            printf("\n");
                            printf("Valor total da compra: R$%.2f\n", valortotal);
                            printf("Quantidade dos produtos foram atualizadas.\n");
                            printf("\n");
                            break;
                        }
                    }
                }
                while(1){
                    printf("Confirmar compra (s/n)? ");
                    scanf(" %c", &confirmar);

                    if(confirmar == 's' || confirmar == 'S'){
                        printf("Compra realizada! Produtos sairam do estoque.\n");
                        arquivo = fopen("Produtos.txt", "w");
                        for(int i = 0; i < k; i++){
                            fprintf(arquivo, "%s- %.2f - %d - %d\n", produtos[i].nome, produtos[i].preco, produtos[i].codigo, produtos[i].quantidade);
                        }
                        fclose(arquivo);
                        break;
                    } else if(confirmar == 'n' || confirmar == 'N'){
                        printf("Compra cancelada! Produtos voltaram para o estoque.\n");
                        break;
                    } else {
                        printf("Confirmacao incorreta! Compra nao realizada ate confirmacao...\n");
                    }
                    printf("\n");
                }
                break;
            
            case '0':
                printf("Saindo do programa...\n");
                printf("\n");
                break;
        
            default:
                printf("Selecao incorreta! Tente novamente...\n");
                printf("\n");
                break;
        }
    } while(escolha != '0');

    arquivo = fopen("Produtos.txt", "w");
    for(int i = 0; i < k; i++){
        fprintf(arquivo, "%s- %.2f - %d - %d\n", produtos[i].nome, produtos[i].preco, produtos[i].codigo, produtos[i].quantidade);
    }
    fclose(arquivo);

    return 0;
}