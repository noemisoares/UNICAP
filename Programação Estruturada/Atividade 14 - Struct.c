//Atividade 14 - Struct - Programação Estruturada

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Horario {
    int hora;
    int minutos;
    int segundos;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char texto[100];
};

int main() {
    struct Compromisso compromisso;

    printf("Digite o Horario (Horas Minutos Segundos): ");
    scanf("%d %d %d", &compromisso.horario.hora, &compromisso.horario.minutos, &compromisso.horario.segundos);

    printf("Digite a Data (Dia Mês Ano): ");
    scanf("%d %d %d", &compromisso.data.dia, &compromisso.data.mes, &compromisso.data.ano);

    printf("Digite seu Texto de Compromisso: ");
    scanf(" %100[^\n]s", compromisso.texto);

    printf("\nCompromisso agendado:\n");
    printf("Horario: %02d:%02d:%02d\n", compromisso.horario.hora, compromisso.horario.minutos, compromisso.horario.segundos);
    printf("Data: %02d/%02d/%04d\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
    printf("Texto: %s\n", compromisso.texto);

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cadastro {
    char nome[50];
    int idade;
    char endereco[50];
};

int main() {
    struct Cadastro cadastro;

    printf("Digite seu Nome: ");
    scanf(" %50[^\n]s", cadastro.nome);

    printf("Digite sua Idade: ");
    scanf(" %d", &cadastro.idade);

    printf("Digite seu Endereco (Rua, Numero): ");
    scanf(" %50[^\n]s", cadastro.endereco);

    printf(" Nome: %s\n Idade: %d\n Endereco: %s\n", cadastro.nome, cadastro.idade, cadastro.endereco);
        
    return 0;
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[100];
    int matricula;
    char curso[100];
};

int main() {
    struct Aluno cadastro[5];
    
    for(int i = 0; i < 5; i++){
        printf("Digite o Nome do Aluno %d: ", i+1);
        scanf(" %100[^\n]s", cadastro[i].nome);

        printf("Digite a Matricula do Aluno %d: ", i+1);
        scanf(" %d", &cadastro[i].matricula);

        printf("Digite o Curso do Aluno %d: ", i+1);
        scanf(" %100[^\n]s", cadastro[i].curso);
    }

    printf("\nInformacoes dos Alunos\n");
    for(int i = 0; i < 5; i++){
        printf("Aluno %d: %s, %d, %s\n", i+1, cadastro[i].nome, cadastro[i].matricula, cadastro[i].curso);

    }
        
    return 0;
}

//QUESTÃO 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados{
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
    float media;
};

int main() {
    struct Dados alunos[5];

    for(int i = 0; i < 5; i++){
        printf("Digite a Matricula do Aluno %d: ", i+1);
        scanf(" %d", &alunos[i].matricula);

        printf("Digite o Nome do Aluno %d: ", i+1);
        scanf(" %50[^\n]s", alunos[i].nome);

        printf("Digite a Primeira Nota do Aluno %d: ", i+1);
        scanf(" %f", &alunos[i].nota1);

        printf("Digite a Primeira Nota do Aluno %d: ", i+1);
        scanf(" %f", &alunos[i].nota2);

        printf("Digite a Primeira Nota do Aluno %d: ", i+1);
        scanf(" %f", &alunos[i].nota3);
    }

    float maiorNota1 = alunos[0].nota1;
    int k;
    for(int i = 0; i < 5; i++){
        if(alunos[i].nota1 > maiorNota1){
            maiorNota1 = alunos[i].nota1;
            k = i;
        }
    }
    printf("Aluno com a maior Primeira Nota: %s, com nota %.2f\n", alunos[k].nome, maiorNota1);
    
    for(int i = 0; i < 5; i++){
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3;
    }
    
    printf("\nAlunos Aprovados: \n");
    for(int i = 0; i < 5; i++){
        if(alunos[i].media >= 6){
            printf("%s foi aprovado com media %.2f.\n", alunos[i].nome, alunos[i].media);
        }
    }
    printf("\nAlunos Reprovados: \n");
    for(int i = 0; i < 5; i++){
        if(alunos[i].media < 6){
            printf("%s foi reprovado com media %.2f.\n", alunos[i].nome, alunos[i].media);
        }
    }

    float maiorMedia = alunos[0].media, menorMedia = alunos[0].media;
    int a, b;
    for(int i = 0; i < 5; i++){
        if(alunos[i].media > maiorMedia){
            maiorMedia = alunos[i].media;
            a = i;
        } else if(alunos[i].media < menorMedia){
            menorMedia = alunos[i].media;
            b = i;
        }
    }
    printf("\n");
    printf("Aluno com a Maior Media: %s, com nota %.2f \n", alunos[a].nome, maiorMedia);
    printf("Aluno com a Menor Media: %s, com nota %.2f \n", alunos[b].nome, menorMedia);

    return 0;
}

//QUESTÃO 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vetor{
    float x;
    float y;
    float z;
};

int main() {
    struct Vetor vetor[2];
    
    for(int i = 0; i < 2; i++){
        printf("Digite o valor X do Vetor %d: ", i+1);
        scanf(" %f", &vetor[i].x);

        printf("Digite o valor Y do Vetor %d: ", i+1);
        scanf(" %f", &vetor[i].y);

        printf("Digite o valor Z do Vetor %d: ", i+1);
        scanf(" %f", &vetor[i].z);
    }

    printf("Vetor 1: (%.2f, %.2f, %.2f);\n", vetor[0].x, vetor[0].y, vetor[0].z);
    printf("Vetor 2: (%.2f, %.2f, %.2f);\n", vetor[1].x, vetor[1].y, vetor[1].z);
    printf("Soma dos Vetores: (%.2f, %.2f, %.2f);", vetor[0].x + vetor[1].x, vetor[0].y + vetor[1].y, vetor[0].z + vetor[1].z);

    return 0;
}

//QUESTÃO 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Turma{
    int matricula;
    char nome[100];
    int codigo;
    float nota1;
    float nota2;
    float media;
};

int main() {
    struct Turma alunos[10];

    for(int i = 0; i < 10; i++){
        printf("Digite a Matricula do Aluno %d: ", i+1);
        scanf(" %d", &alunos[i].matricula);

        printf("Digite o Nome do Aluno %d: ", i+1);
        scanf(" %100[^\n]s", alunos[i].nome);

        printf("Digite o Codigo da Disciplina: ");
        scanf(" %d", &alunos[i].codigo);

        printf("Digite a Nota 1 do Aluno %d: ", i+1);
        scanf(" %f", &alunos[i].nota1);

        printf("Digite a Nota 2 do Aluno %d: ", i+1);
        scanf(" %f", &alunos[i].nota2);
    }

    printf("\nListagem Final dos Alunos\n");
    for(int i = 0; i < 10; i++){
        alunos[i].media = (1*alunos[i].nota1 + 2*alunos[i].nota2)/3;
        printf("%s | Media: %.2f \n", alunos[i].nome, alunos[i].media);
    }
 
    return 0;
}

//QUESTÃO 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Registro{
    int idade;
    char nome[100];
    char sexo;
    char cpf[15];
    char data[10];
    int codigo;
    char cargo[30];
    float salario;
};

int main() {
    struct Registro funcionario;

        printf("Digite seu Nome: ");
        scanf(" %100[^\n]s", funcionario.nome);

        printf("Digite sua Idade: ");
        scanf(" %d", &funcionario.idade);

        printf("Digite seu Sexo(M/F): ");
        scanf(" %c", &funcionario.sexo);

        printf("Digite seu CPF(000.000.000-00): ");
        scanf(" %15[^\n]s", funcionario.cpf);

        printf("Digite sua Data de Nascimento(dd mm aa): ");
        scanf(" %10[^\n]s", funcionario.data);

        printf("Digite o Codigo do Setor onde trabalha(0-99): ");
        scanf(" %d", &funcionario.codigo); 

        printf("Digite o Cargo que ocupa: ");
        scanf(" %30[^\n]s", funcionario.cargo);    

        printf("Digite seu Salario: ");
        scanf(" %f", &funcionario.salario);

        printf("\nINFORMACOES DO FUNCIONARIO\n");
        printf("Nome do Funcionario: %s\n", funcionario.nome);
        printf("Idade: %d\n", funcionario.idade);
        printf("Genero: %c\n", funcionario.sexo);
        printf("CPF: %s\n", funcionario.cpf);
        printf("Data de Nascimento: %s\n", funcionario.data);
        printf("Codigo: %d\n", funcionario.codigo);
        printf("Cargo na Empresa: %s\n", funcionario.cargo);
        printf("Salario: R$ %.2f\n", funcionario.salario);
 
    return 0;
}

//QUESTÃO 8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Registro_Pessoas{
    char nome[100];
    char endereco[100];
    char telefone[20];
};

int main() {
    struct Registro_Pessoas pessoas[5], k;

        for(int i = 0; i < 5; i++){
            printf("Digite o Nome da Pessoa %d: ", i+1);
            scanf(" %100[^\n]s", pessoas[i].nome);

            printf("Digite o Endereco (Rua, Numero) da Pessoa %d: ", i+1);
            scanf(" %100[^\n]s", pessoas[i].endereco);

            printf("Digite o Telefone (+55 DDD 9XXXX-YYYY) da Pessoa %d: ", i+1);
            scanf(" %20[^\n]s", pessoas[i].telefone);
        }

        for (int i = 0; i < 5 - 1; i++) {
            for (int j = 0; j < 5 - 1 - i; j++) {
                if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                    k = pessoas[j];
                    pessoas[j] = pessoas[j + 1];
                    pessoas[j + 1] = k;
                }
            }
        }

        printf("\nPessoas em Ordem Alfabetica:\n\n");
        for (int i = 0; i < 5; i++) {
            printf("Nome: %s\n", pessoas[i].nome);
            printf("Endereco: %s\n", pessoas[i].endereco);
            printf("Telefone: %s\n\n", pessoas[i].telefone);
        }

    return 0;
}

//QUESTÃO 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados {
    char nome[100];
    int matricula;
    float media;
};

int main() {
    struct Dados alunos[10], aprovados[10], reprovados[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o Nome do Aluno %d: ", i+1);
        scanf(" %100[^\n]s", alunos[i].nome);

        printf("Digite a Matricula do Aluno %d: ", i+1);
        scanf(" %d", &alunos[i].matricula);

        printf("Digite a Media Final do Aluno %d: ", i+1);
        scanf(" %f", &alunos[i].media);
    }

    for(int i = 0; i < 10; i++){
        aprovados[i].media = 0;
        strcpy(aprovados[i].nome, "vazio");
        reprovados[i].media = 0;
        strcpy(reprovados[i].nome, "vazio");
    }

    int k = 0, c = 0;
    for(int i = 0; i < 10; i++){
        if(alunos[i].media >= 5.0){
            aprovados[k].media = alunos[i].media;
            strcpy(aprovados[k].nome, alunos[i].nome);
            k++;
        } else if(alunos[i].media < 5.0){
            reprovados[c].media = alunos[i].media;
            strcpy(reprovados[c].nome, alunos[i].nome);
            c++;
        }
    }

    printf("\nAlunos Aprovados:\n");
    for(int i = 0; i < 10; i++){
        printf(" %s | Media: %.2f\n", aprovados[i].nome, aprovados[i].media);
    }

    printf("\nAlunos Reprovados:\n");
    for(int i = 0; i < 10; i++){
        printf(" %s | Media: %.2f\n", reprovados[i].nome, reprovados[i].media);
    }

    return 0;
}

//QUESTÃO 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Baralho {
    char naipe[10];
    char valor[3];
};

int main() {
    struct Baralho cartas[52], jogador1[5], jogador2[5], temp;
    char *naipes[] = {"Espadas", "Paus", "Copas", "Ouros"};
    char *valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    int i, j, k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            strcpy(cartas[k].naipe, naipes[i]);
            strcpy(cartas[k].valor, valores[j]);
            k++;
        }
    }

    for (i = 0; i < 52; i++) {
        int e = rand() % 52;
        temp = cartas[i];
        cartas[i] = cartas[e];
        cartas[e] = temp;
    }

    for (i = 0; i < 5; i++) {
        jogador1[i] = cartas[i * 2];
        jogador2[i] = cartas[i * 2 + 1];
    }

    printf("Cartas do Jogador 1:\n");
    for (i = 0; i < 5; i++) {
        printf("%s de %s\n", jogador1[i].valor, jogador1[i].naipe);
    }

    printf("\nCartas do Jogador 2:\n");
    for (i = 0; i < 5; i++) {
        printf("%s de %s\n", jogador2[i].valor, jogador2[i].naipe);
    }

    return 0;
}

//QUESTÃO 11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados {
    char marca[15];
    int ano;
    float preco;
};

int main() {
    struct Dados carros[5];
    float p;

    for(int i = 0; i < 5; i++){
        printf("Digite a Marca do Carro %d: ", i+1);
        scanf(" %15[^\n]s", carros[i].marca);

        printf("Digite o Ano do Carro %d: ", i+1);
        scanf(" %d", &carros[i].ano);

        printf("Digite o Preco do Carro %d: ", i+1);
        scanf(" %f", &carros[i].preco);
    }

    printf("Digite um valor para procura: ");
    scanf(" %f", &p);

    printf("\nPrecos Menores:\n");
    for(int i = 0; i < 5; i++){
        if(carros[i].preco <= p){
            printf("%s | %d | R$ %.2f\n", carros[i].marca, carros[i].ano, carros[i].preco);
        }
    }
    return 0;
}

//QUESTÃO 12
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados_Livros {
    char titulo[30];
    char autor[15];
    int ano;
};

int main() {
    struct Dados_Livros livros[5];
    char procura[30];
    int k = 0;

    for(int i = 0; i < 5; i++){
        printf("Digite o Titulo do Livro %d: ", i+1);
        scanf(" %30[^\n]s", livros[i].titulo);

        printf("Digite o Autor do Livro %d: ", i+1);
        scanf(" %15[^\n]s", livros[i].autor);

        printf("Digite o Ano do Livro %d: ", i+1);
        scanf(" %d", &livros[i].ano);
    }

    printf("Digite o Titulo do livro que quer buscar: ");
    scanf(" %30[^\n]s", procura);

    printf("\nLivro Encontrado: \n");
    for(int i = 0; i < 5; i++){
        if(strcmp(livros[i].titulo,procura) == 0){
            printf("%s | %s, %d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
            k++;
        }   
    }
    if (k == 0) {
        printf("Nenhum livro com o título '%s' encontrado.\n", procura);
    }

    return 0;
}

//QUESTÃO 13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Consumo {
    char nome[15];
    float potencia;
    float tempo;
};

int main() {
    struct Consumo eletro[5];
    int t;
    float consumos[5], consumoTotal = 0;

    for(int i = 0; i < 5; i++){
        printf("Digite o Nome do Eletrodomestico %d: ", i+1);
        scanf(" %15[^\n]s", eletro[i].nome);

        printf("Digite a Potencia do Eletrodomestico %d: ", i+1);
        scanf(" %f", &eletro[i].potencia);

        printf("Digite o Tempo Ativo do Eletrodomestico %d: ", i+1);
        scanf(" %f", &eletro[i].tempo);

        consumos[i] = eletro[i].potencia * eletro[i].tempo;
        consumoTotal += consumos[i];
    }

    printf("Digite um Numero de Dias para calcular: ");
    scanf(" %d", &t);

    printf("\nConsumo Total: %.2f kW/h\n", consumoTotal * t);

    printf("\nConsumo Relativo:\n");
    for(int i = 0; i < 5; i++){
        float consumoRelativo = consumos[i] / consumoTotal;
        printf("%s: %.2f kw/h\n", eletro[i].nome, consumoRelativo);
    }

    return 0;
}

//QUESTÃO 14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estoque {
    char nome[15];
    int codigo;
    int quantidade;
    float preco;
};

int main() {
    struct Estoque produtos[5];
    int c = 1, q;

    for(int i = 0; i < 5; i++){
        printf("Digite o Codigo do Produto %d: ", i+1);
        scanf(" %d", &produtos[i].codigo);

        printf("Digite o Nome do Produto %d: ", i+1);
        scanf(" %15[^\n]s", produtos[i].nome);

        printf("Digite a Quantidade do Produto %d: ", i+1);
        scanf(" %d", &produtos[i].quantidade);

        printf("Digite o Preco do Produto %d: ", i+1);
        scanf(" %f", &produtos[i].preco);
    }

    while (c != 0) {
        int k = 0;

        printf("Digite o Codigo do Produto que quer comprar: ");
        scanf(" %d", &c);

        printf("Digite a Quantidade que deseja comprar: ");
        scanf(" %d", &q);

        for(int i = 0; i < 5; i++){
            if(c == produtos[i].codigo && q <= produtos[i].quantidade){
                printf("Produto %s possui %d unidades em estoque, o suficiente para realizar a compra.\n", produtos[i].nome, produtos[i].quantidade);
                produtos[i].quantidade -= q;
                printf("Compra de R$ %.2f realizada com sucesso! Restou %d unidades em estoque.\n", produtos[i].preco*q, produtos[i].quantidade);
            } else if(c == produtos[i].codigo && q > produtos[i].quantidade){
                printf("Produto %s possui %d unidades em estoque, nao eh suficiente para realizar a compra.\n", produtos[i].nome, produtos[i].quantidade);
                printf("Compra nao foi realizada! Restou %d unidades em estoque.\n", produtos[i].quantidade);
            } else if(c != produtos[i].codigo && q > produtos[i].quantidade){
                k++;
            }
        }
        if(k == 5){
            printf("Produto nao encontrado em estoque!\n");
        }
    }

    return 0;
}

//QUESTÃO 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ingrediente {
    char nome[100];
    int quantidade;
};

struct Livro {
    char nome[25];
    int quantidade;
    struct Ingrediente ingredientes[100];
};

int main() {
    struct Livro receitas[5];
    char procura[25];

    for(int i = 0; i < 5; i++){
        printf("Digite o nome da receita %d: ", i+1);
        scanf(" %25[^\n]s", receitas[i].nome);

        printf("Digite a quantidade de ingredientes da receita %d: ", i+1);
        scanf(" %d", &receitas[i].quantidade);

        for(int j = 0; j < receitas[i].quantidade; j++){
            printf("Digite o nome do igrediente %d da receita %d: ", j+1, i+1);
            scanf(" %100[^\n]s", receitas[i].ingredientes[j].nome);
            printf("Digite o nome do igrediente %d da receita %d: ", j+1, i+1);
            scanf(" %d", &receitas[i].ingredientes[j].quantidade);
        }
    }

    while (1){
        int k = 0;

        printf("\nDigite o nome da receita que quer achar: ");
        scanf(" %25[^\n]s", procura);

        if (strcmp(procura, "") == 0) {
            break;
        }

        for(int i = 0; i < 5; i++){
            if(strcmp(procura, receitas[i].nome) == 0){
                printf("Receita encontrada!\n");
                printf("\nRECEITA: %s\n", receitas[i].nome);
                printf("Ingredientes:\n");
                
                for(int j = 0; j < receitas[i].quantidade; j++){
                    printf("%s | Quantidade: %d \n", receitas[i].ingredientes[j].nome, receitas[i].ingredientes[j].quantidade);
                }
            } else {
                k++;
            }
        }
        if(k == 5){
            printf("\nReceita nao encontrada!\n");
        }
    }

    return 0;
}

//QUESTÃO 16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char nome[20];
    int ano;
    char duracao[20];
};

struct Diretor {
    char nome[20];
    int quantidade;
    struct Movie filmes[100];
};

int main() {
    struct Diretor diretores[5];
    char procura[20];

    for(int i = 0; i < 5; i++){
        printf("Digite o nome do diretor %d: ", i+1);
        scanf(" %20[^\n]s", diretores[i].nome);

        printf("Digite a quantidade de filmes do diretor %d: ", i+1);
        scanf(" %d", &diretores[i].quantidade);

        for(int j = 0; j < diretores[i].quantidade; j++){
            printf("Digite o titulo do filme %d do diretor %d: ", j+1, i+1);
            scanf(" %20[^\n]s", diretores[i].filmes[j].nome);
            printf("Digite o ano de lancamento do filme %d do diretor %d: ", j+1, i+1);
            scanf(" %d", &diretores[i].filmes[j].ano);
            printf("Digite a duracao do filme %d do diretor %d: ", j+1, i+1);
            scanf(" %20[^\n]s", diretores[i].filmes[j].duracao);
        }
    }

    while (1){
        int k = 0;

        printf("\nDigite o nome do diretor que quer achar: ");
        scanf(" %20[^\n]s", procura);

        if (strcmp(procura, "") == 0) {
            break;
        }

        for(int i = 0; i < 5; i++){
            if(strcmp(procura, diretores[i].nome) == 0){
                printf("Diretor encontrado!\n");
                printf("\nDIRETOR: %s\n", diretores[i].nome);
                printf("Filmes:\n");
                
                for(int j = 0; j < diretores[i].quantidade; j++){
                    printf("%s | Ano: %d | Duracao: %s\n", diretores[i].filmes[j].nome, diretores[i].filmes[j].ano, diretores[i].filmes[j].duracao);
                }
            } else {
                k++;
            }
        }
        if(k == 5){
            printf("\nDiretor nao encontrado!\n");
        }
    }

    return 0;
}

//QUESTÃO 17
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Endereco {
    char rua[50];
    int numero;
    char complemento[50];
    char bairro[50];
    int cep;
    char cidade[30];
    char estado[30];
    char pais[30];
};

struct Telefone {
    int DDD;
    int numero;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Agenda_de_Telefone {
    char nome[50];
    char email[50];
    struct Endereco endereco;
    struct Telefone telefone;
    struct Data aniversario;
    char observacoes[100];
};

int main() {
    struct Agenda_de_Telefone agenda[100];
    int escolha, i, j, k = 0, pMes, pMesDia, pMesDia2;
    char pNome[50], rNome[50];

    do {
        printf("\nMenu de Agenda Telefonica:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Remover Contado\n");
        printf("3. Buscar por Nome\n");
        printf("4. Buscar por Mes de Aniversario\n");
        printf("5. Buscar por Dia e Mes de Aniversario\n");
        printf("6. Imprimir Agenda (Nome, Telefone e Email)\n");
        printf("7. Imprimir Agenda Completa\n");
        printf("0. Sair da Agenda\n");
        printf("Digite sua opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (k < 100) {
                    printf("\nDigite o nome: ");
                    scanf(" %50[^\n]s", agenda[k].nome);

                    printf("Digite o email: ");
                    scanf(" %50[^\n]s", agenda[k].email);

                    printf("Digite a rua: ");
                    scanf(" %50[^\n]s", agenda[k].endereco.rua);

                    printf("Digite o numero: ");
                    scanf(" %d", &agenda[k].endereco.numero);

                    printf("Digite o complemento: ");
                    scanf(" %50[^\n]s", agenda[k].endereco.complemento);

                    printf("Digite o bairro: ");
                    scanf(" %50[^\n]s", agenda[k].endereco.bairro);

                    printf("Digite o CEP: ");
                    scanf(" %d", &agenda[k].endereco.cep);

                    printf("Digite a cidade: ");
                    scanf(" %30[^\n]s", agenda[k].endereco.cidade);

                    printf("Digite o estado: ");
                    scanf(" %30[^\n]s", agenda[k].endereco.estado);

                    printf("Digite o pais: ");
                    scanf(" %30[^\n]s", agenda[k].endereco.pais);

                    printf("Digite o DDD do telefone: ");
                    scanf(" %d", &agenda[k].telefone.DDD);

                    printf("Digite o numero do telefone: ");
                    scanf(" %d", &agenda[k].telefone.numero);

                    printf("Digite o dia de aniversario: ");
                    scanf(" %d", &agenda[k].aniversario.dia);

                    printf("Digite o mes de aniversario: ");
                    scanf(" %d", &agenda[k].aniversario.mes);

                    printf("Digite o ano de aniversario: ");
                    scanf(" %d", &agenda[k].aniversario.ano);

                    printf("Digite observacoes: ");
                    scanf(" %100[^\n]s", agenda[k].observacoes);

                    k++;

                    for (i = 0; i < k - 1; i++) {
                        for (j = i + 1; j < k; j++) {
                            if (strcmp(agenda[i].nome, agenda[j].nome) > 0) {
                                struct Agenda_de_Telefone agentaTemp = agenda[i];
                                agenda[i] = agenda[j];
                                agenda[j] = agentaTemp;
                            }
                        }
                    }
                } else {
                    printf("Agenda cheia!\n");
                }
                break;
            
            case 2:
                printf("Digite o nome do contato que quer remover: ");
                scanf(" %50[^\n]s", rNome);

                for(i = 0; i < k; i++){
                    if(strcmp(rNome, agenda[i].nome) == 0){
                        for(j = i; j < k - 1; j++){
                            agenda[j] = agenda[j + 1];
                        }
                        k--;
                        printf("Contato removido\n");
                    }
                }
                break;

            case 3:
                printf("\nDigite o nome que deseja buscar: ");
                scanf(" %50[^\n]s", pNome);

                printf("\nContatos Encontrados:\n");
                for (i = 0; i < k; i++) {
                    if (strstr(agenda[i].nome, pNome) != NULL) {
                        printf("Nome: %s\n", agenda[i].nome);
                        printf("Email: %s\n", agenda[i].email);
                        printf("Telefone: (%d) %d\n", agenda[i].telefone.DDD, agenda[i].telefone.numero);
                        printf("Aniversario: %02d/%02d/%04d\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano);
                        printf("Observacoes: %s\n", agenda[i].observacoes);
                        printf("Endereco: Rua %s, nº %d, %s, %s, %d, %s - %s, %s\n", 
                            agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.complemento, agenda[i].endereco.bairro, 
                            agenda[i].endereco.cep, agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
                        printf("\n");
                    }
                }
                break;

            case 4:
                printf("\nDigite o mes de aniversario que deseja buscar: ");
                scanf(" %d", &pMes);
                printf("\nContatos Encontrados:\n");
                for (i = 0; i < k; i++) {
                    if (agenda[i].aniversario.mes == pMes) {
                        printf("Nome: %s\n", agenda[i].nome);
                        printf("Email: %s\n", agenda[i].email);
                        printf("Telefone: (%d) %d\n", agenda[i].telefone.DDD, agenda[i].telefone.numero);
                        printf("Aniversario: %02d/%02d/%04d\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano);
                        printf("Observacoes: %s\n", agenda[i].observacoes);
                        printf("\n");
                    }
                }
                break;

            case 5:
                printf("\nDigite o dia de aniversario que deseja buscar: ");
                scanf(" %d", &pMesDia);
                printf("Digite o mes de aniversario que deseja buscar: ");
                scanf(" %d", &pMesDia2);
                printf("\nContatos Encontrados:\n");
                for (i = 0; i < k; i++) {
                    if (agenda[i].aniversario.dia == pMesDia && agenda[i].aniversario.mes == pMesDia2) {
                        printf("Nome: %s\n", agenda[i].nome);
                        printf("Email: %s\n", agenda[i].email);
                        printf("Telefone: (%d) %d\n", agenda[i].telefone.DDD, agenda[i].telefone.numero);
                        printf("Aniversario: %02d/%02d/%04d\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano);
                        printf("Observacoes: %s\n", agenda[i].observacoes);
                        printf("\n");
                    }
                }
                break;

            case 6:
                printf("\nAgenda (Nome, Telefone e Email):\n");
                for (i = 0; i < k; i++) {
                    printf("Nome: %s | Telefone: (%d) %d | Email: %s\n", agenda[i].nome, agenda[i].telefone.DDD, agenda[i].telefone.numero, agenda[i].email);
                }
                break;

            case 7:
                printf("\nAgenda Completa:\n");
                for (i = 0; i < k; i++) {
                    printf("Nome: %s\n", agenda[i].nome);
                    printf("Email: %s\n", agenda[i].email);
                    printf("Telefone: (%d) %d\n", agenda[i].telefone.DDD, agenda[i].telefone.numero);
                    printf("Aniversario: %02d/%02d/%04d\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano);
                    printf("Observacoes: %s\n", agenda[i].observacoes);
                    printf("Endereco: Rua %s, nº %d, %s, %s, %d, %s - %s, %s\n", 
                        agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.complemento, agenda[i].endereco.bairro, 
                        agenda[i].endereco.cep, agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
                    printf("\n");
                }
                break;

            case 0:
                printf("Saindo da agenda...\n");
                break;

            default:
                printf("\nOpcao incorreta! Tente novamente...\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}
