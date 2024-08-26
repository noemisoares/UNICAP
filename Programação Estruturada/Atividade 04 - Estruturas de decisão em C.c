//Atividade 04 - Estrutura de Decisão em C - Programação Estruturada

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int main() {
    int number;

    printf("Digite um número inteiro: ");
    scanf("%d", &number);

    if (number > 10) {
        printf("O valor é maior que 10NnN");
    } else if (number = 10) {
        printf("O número é igual a 10NN");
    } else {
        printf("O valor é menor que 10Xn");
    }

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;

    printf("Digite um simbolo de pontuacao: ");
    ch = getchar();
    switch ( ch ) {
        case '.': printf("Ponto.yn.\n"); break;
        case ',': printf("Virgula.yvn.\n" ); break;
        case ':': printf("Dois pontos.yn.\n"); break;
        case ';': printf("Ponto e virgula.yn.\n"); break;
        default : printf("Nao eh pontuacao.Yyn.\n");
    }
    system ("pause");
    return 0;
}

//QUESTÃO 3
#include <stdio.h>

int main() {
    int n;
  
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    
    if (n > 0){
        printf("O número digitado é positivo.");
    } else if (n < 0) {
        printf("O número é negativo.");
    } else {
        printf("O número é igual a zero.");
    }

    return 0;
}

//QUESTÃO 4
#include <stdio.h>

int main() {
    int idade;
 
    printf("Digite a idade: ");
    scanf("%d", &idade);
 
    if (idade >= 18) {
        printf("A pessoa é maior de idade.\n");
    } else {
        printf("A pessoa é menor de idade.\n");
    }

    return 0;
}

//QUESTÃO 5
#include <stdio.h>

int main() {
    int n1, n2;
    
    printf("Digite um número: ");
    scanf("%d", &n1);
    printf("Digite um outro número: ");
    scanf("%d", &n2);
    
    if (n1 > n2){
        printf("O maior é número digitado é %d", n1);
    } else if (n1 == n2){
        printf("Os números são iguais.");
    } else {
        printf("O maior número digitado é %d", n2);
    }
    

    return 0;
}

//QUESTÃO 6
#include <stdio.h>

int main() {
    int n1;

    printf("Digite um número: ");
    scanf("%d", &n1);
    
    if (n1 % 2 == 0){
        printf("O número digitado é par.");
    } else {
        printf("O número é impar.");
    }
   
    

    return 0;
}

//QUESTÃO 7
#include <stdio.h>

int main() {
    float nota1, nota2, nota3, media;
    
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);
    
    media = (nota1 + nota2 + nota3)/3;
    
    if (media >= 7){
        printf("Aluno aprovado.");
    } else {
        printf("Aluno reprovado.");
    }
    

    return 0;
}

//QUESTÃO 8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nome1[20], nome2[20];
    int Itamanho, IItamanho;
    
    printf("Digite um nome: ");
    scanf("%s", nome1);
    printf("Digite um outro nome: ");
    scanf("%s", nome2);
    
    Itamanho = strlen(nome1);
    IItamanho = strlen(nome2);
    
    if (Itamanho > IItamanho){
        printf("O nome com mais caracteres é %s", nome1);
    } else {
        printf("O nome com mais caracteres é %s", nome2);
    }

    return 0;
}

//QUESTÃO 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char caractere;
    
    printf("Digite um caractere qualquer: ");
    scanf("%c", &caractere);
    
    caractere = toupper(caractere);  
    
    if(caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U'){
        printf("Vogal.");
    } else {
        printf("Consoante.");
    }
    
    return 0;
}

//QUESTÃO 10
#include <stdio.h>

int main() {
    int n1, n2, n3;
    printf("Digite um número: ");
    scanf("%d", &n1);
    printf("Digite um outro número: ");
    scanf("%d", &n2);
    printf("Digite mais um número: ");
    scanf("%d", &n3);
 
    if (n1 >= n2 && n1 >= n3){
        if(n2>n3){
            printf("%i, %i, %i", n3, n2, n1);
        }else{
            printf("%i, %i, %i", n2, n3, n1);
        }
    }else if (n2 > n1 && n2 > n3){
        if(n1>n3){
            printf("%i, %i, %i", n3, n1, n2);
        }else{
            printf("%i, %i, %i", n1, n3, n2);
        }
    }else{
        if(n1>n2){
            printf("%i, %i, %i", n2, n1, n3);
        }else{
            printf("%i, %i, %i", n1, n2, n3);    
        }
    }
    return 0;
}

//QUESTÃO 11
#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);
    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
 
    printf("O IMC calculado é: %.2f\n", imc);
    if (imc < 18.5) {
        printf("Categoria: Abaixo do peso\n");
    } else if (imc >= 18.5 && imc < 25) {
        printf("Categoria: Peso normal\n");
    } else if (imc >= 25 && imc < 30) {
        printf("Categoria: Sobrepeso\n");
    } else if (imc >= 30 && imc < 35) {
        printf("Categoria: Obeso\n");
    } else {
        printf("Categoria: Muito obeso\n");
    }

    return 0;
}

//QUESTÃO 12
#include <stdio.h>

int main()
{
    int mes;
    
    printf("Digite o número do mês: ");
    scanf("%d", &mes);
    fflush(stdin);
    
    switch(mes){
        
        case 1: 
            printf("Janeiro.\n");
            break;
        case 2: 
            printf("Fevereiro.\n");
            break;
        case 3:
            printf("Março.\n");
            break;
        case 4:
            printf("Abril.\n");
            break;
        case 5: 
            printf("Maio.\n");
            break;
        case 6: 
            printf("Junho.\n");
            break;
        case 7:
            printf("Julho.\n");
            break;
        case 8:
            printf("Agosto.\n");
            break;
        case 9:
            printf("Setembro.\n");
            break;
        case 10: 
            printf("Outubro.\n");
            break;
        case 11: 
            printf("Novembro.\n");
            break;
        case 12:
            printf("Dezembro.\n");
            break;
        default:
            printf("Esse número não corresponde a um mês.\n");
            break;
    }

    return 0;
}

//QUESTÃO 13
#include <stdio.h>


int main() {
    float salario, aumento, total;
    
    printf("Digite o valor do seu salário: ");
    scanf("%f", &salario);
    fflush(stdin);
    
    if(salario > 1.500){
        aumento = (salario * 0.10);
    } else {
        aumento = (salario * 0.15);
    }
    
    total = (salario + aumento);
    
    printf("O seu salário atual é R$ %.2f. \nO seu aumento é de R$ %.2f. \nSeu novo salário é: R$ %.2f", salario, aumento, total);

    return 0;
}

//QUESTÃO 14
#include <stdio.h>

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    if (num % 3 == 0 && num % 5 == 0) {
        printf("%d é divisível por 3 e por 5 ao mesmo tempo.\n", num);
    } else {
        printf("%d não é divisível por 3 e por 5 ao mesmo tempo.\n", num);
    }

    return 0;
}

//QUESTÃO 15
#include <stdio.h>
#include <string.h>

void toLowercase(char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

int main() {
    char diasemana[20];

    printf("Digite o dia da semana (por extenso): ");
    scanf("%[^\n]s", diasemana);

    toLowercase(diasemana);

    if (strcmp(diasemana, "segunda-feira") == 0 || strcmp(diasemana, "terca-feira") == 0 ||
        strcmp(diasemana, "quarta-feira") == 0 || strcmp(diasemana, "quinta-feira") == 0 ||
        strcmp(diasemana, "sexta-feira") == 0) {
        printf("Dia util.\n");
    } else if (strcmp(diasemana, "sabado") == 0 || strcmp(diasemana, "domingo") == 0) {
        printf("Fim de semana.\n");
    } else {
        printf("Dia invalido.\n");
    }

    return 0;
}

//QUESTÃO 16
#include <stdio.h>

int main() {
    int nota;

    printf("Digite um número inteiro de 1 a 5: ");
    if (scanf("%d", &nota) != 1 || nota < 1 || nota > 5) {
        printf("Erro: Entrada inválida. Certifique-se de inserir um número válido entre 1 e 5.\n");
        return 1;
    }

    switch (nota) {
        case 5:
            printf("Muito bom\n");
            break;
        case 4:
            printf("Bom\n");
            break;
        case 3:
            printf("Regular\n");
            break;
        case 2:
            printf("Insuficiente\n");
            break;
        case 1:
            printf("Muito insuficiente\n");
            break;
        default:
            printf("Erro: Opção inválida.\n");
            return 1;
    }

    return 0;
}

//QUESTÃO 17 
#include <stdio.h>

int main() {
    int numdia;

    printf("Digite um número entre 1 e 7: ");
    if (scanf("%d", &numdia) != 1 || numdia < 1 || numdia > 7) {
        printf("Erro: Entrada inválida. Certifique-se de inserir um número válido entre 1 e 7.\n");
        return 1;
    }

    switch (numdia) {
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda-feira\n");
            break;
        case 3:
            printf("Terça-feira\n");
            break;
        case 4:
            printf("Quarta-feira\n");
            break;
        case 5:
            printf("Quinta-feira\n");
            break;
        case 6:
            printf("Sexta-feira\n");
            break;
        case 7:
            printf("Sábado\n");
            break;
        default:
            printf("Erro: Opção inválida.\n");
            return 1;
    }

    return 0;
}

//QUESTÃO 18
#include <stdio.h>
#include <math.h>

int main() {
    double numdec;
    int numint;
 
    printf("Digite um numero decimal: ");
    scanf("%lf", &numdec);
 
    if (numdec >= 0) {
        numint = (int)(numdec + 0.5);
    } else {
        numint = (int)(numdec - 0.5);
    }
 
    printf("O numero arredondado mais proximo e: %d\n", numint);

    return 0;
}

//QUESTÃO 19
#include <stdio.h>

int main() {
    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if (idade >= 0 && idade <= 1) {
        printf("Você é um bebê.\n");
    } else if (idade > 1 && idade <= 12) {
        printf("Você é uma criança.\n");
    } else if (idade >= 13 && idade <= 18) {
        printf("Você é um adolescente.\n");
    } else if (idade > 18) {
        printf("Você é um adulto.\n");
    } else {
        printf("Idade inválida.\n");
    }

    return 0;
}

//QUESTÃO 20

#include <stdio.h>

int main() {
    char estadocivil;

    printf("Digite o seu estado civil:\n");
    printf("S - Solteiro\n");
    printf("C - Casado\n");
    printf("D - Divorciado\n");
    printf("V - Viúvo\n");
    printf("Escolha a letra correspondente ao seu estado civil: ");
    scanf(" %c", &estadocivil);

    switch (estadocivil) {
        case 'S':
        case 's':
            printf("Você é Solteiro.\n");
            break;
        case 'C':
        case 'c':
            printf("Você é Casado.\n");
            break;
        case 'D':
        case 'd':
            printf("Você é Divorciado.\n");
            break;
        case 'V':
        case 'v':
            printf("Você é Viúvo.\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}


//QUESTÃO 21 
#include <stdio.h>

int main() {
    int num1, num2, escolha;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    printf("Escolha a operação:\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("Digite o número da operação desejada: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Resultado da Soma: %d\n", num1 + num2);
            break;
        case 2:
            printf("Resultado da Subtração: %d\n", num1 - num2);
            break;
        case 3:
            printf("Resultado da Multiplicação: %d\n", num1 * num2);
            break;
        case 4:
            if (num2 != 0) {
                printf("Resultado da Divisão: %.2f\n", (float)num1 / num2);
            } else {
                printf("Erro: Divisão por zero não permitida.\n");
            }
            break;
        default:
            printf("Erro: Opção inválida.\n");
    }

    return 0;
}

//QUESTÃO 22
#include <stdio.h>

int main() {
    char nome[50];
    int idade;

    printf("Digite o nome: ");
    scanf("%s", nome);

    while (1) {
        printf("Digite a idade: ");

        if (scanf("%d", &idade) == 1) {
            break; 
        } else {
            printf("Erro: A idade deve ser um valor inteiro válido.\n");

            while (getchar() != '\n');
        }
    }

    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);

    return 0;
}

//QUESTÃO 23
#include <stdio.h>

int main() {
    float metros;

    printf("Digite o valor em metros: ");
    if (scanf("%f", &metros) != 1) {
        printf("Erro: Entrada inválida.\n");
        return 1;
    }

    if (metros < 0) {
        printf("Erro: O valor em metros deve ser não negativo.\n");
        return 1;
    }

    float centimetros = metros * 100;
    float milimetros = metros * 1000;
    float quilometros = metros / 1000;

    printf("%.2f metros é igual a:\n", metros);
    printf("%.2f centímetros\n", centimetros);
    printf("%.2f milímetros\n", milimetros);
    printf("%.5f quilômetros\n", quilometros);

    return 0;
}
