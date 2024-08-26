//Atividade 05 - Estruturas de Repetição em C - Programação Estruturada

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int main() {
    float notas[5];
    int aprovados = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);

        if (notas[i] >= 7.0) {
            aprovados++;
        }
    }

    printf("Quantidade de alunos aprovados: %d\n", aprovados);

    return 0;
}

//QUESTÃO 2
#include <stdio.h>

int main() {
    int num, soma = 0, dig;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    while (num != 0) {
        dig = num % 10; 
        soma += dig; 
        num /= 10; 
    }

    printf("A soma dos digitos do numero e: %d\n", soma);

    return 0;
}

//QUESTÃO 3
#include <stdio.h>

int main() {
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("Divisores de %d: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

//QUESTÃO 4
#include <stdio.h>

int main() {
    int num = 5;
    float alt, soma_alt = 0, media_alt;

    for (int i = 0; i < num; i++) {
        printf("Digite a altura da pessoa %d: ", i + 1);
        scanf("%f", &alt);
        soma_alt += alt;
    }

    media_alt = soma_alt / num;

    printf("A media de altura das %d pessoas e: %.2f metros\n", num, media_alt);

    return 0;
}

//QUESTÃO 5
#include <stdio.h>

int main() {
    for (int i = 1; i <= 100; i++) {

        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz ");
        }
        else if (i % 3 == 0) {
            printf("Fizz ");
        }
        else if (i % 5 == 0) {
            printf("Buzz ");
        }
        else {
            printf("%d ", i);
        }
    }

    return 0;
}

//QUESTÃO 6
#include <stdio.h>

int main() {
    int num, dig, soma = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    while (num != 0) {
        dig = num % 10; 
        if (dig % 2 == 0) { 
            soma += dig; 
        }
        num /= 10; 
    }

    printf("A soma dos digitos pares do numero e: %d\n", soma);

    return 0;
}

//QUESTÃO 7
#include <stdio.h>

int main() {
    int num, dig, inverso = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    while (num != 0) {
        dig = num % 10; 
        inverso = inverso * 10 + dig; 
        num /= 10; 
    }

    printf("O numero invertido e: %d\n", inverso);

    return 0;
}

//QUESTÃO 8
#include <stdio.h>

int main() {
    int num = 1; 
    int soma; 

    while (num <= 100) {
        soma += num;
        num++; 
    }

    printf("A soma dos numeros de 1 a 100 e: %d\n", soma);

    return 0;
}

//QUESTÃO 9
#include <stdio.h>

int main() {
    int num = 1; 
    int produto = 1; 

    while (num <= 5) {
        produto *= num;
        num++; 
    }

    printf("O produto dos numeros de 1 a 5 e: %d\n", produto);

    return 0;
}

//QUESTÃO 10
#include <stdio.h>

int main() {
    int multi = 1;
    
    printf("Tabuada do 9:\n");

    while (multi <= 10) {
        int resul = 9 * multi; 
        printf("9 x %d = %d\n", multi, resul); 
        multi++;
    }

    return 0;
}

//QUESTÃO 11
#include <stdio.h>

int main() {
    int num, maior, menor;
    int quantid = 0;

    printf("Digite um numero inteiro (0 para parar): ");
    scanf("%d", &num);

    if (num != 0) {
        maior = menor = num;
        quantid = 1; 
    }

    while (num != 0) {
        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }
        printf("Digite um numero inteiro (0 para parar): ");
        scanf("%d", &num);

        if (num != 0) {
            quantid++;
        }
    }

    if (quantid > 0) {
        printf("O maior numero digitado foi: %d\n", maior);
        printf("O menor numero digitado foi: %d\n", menor);
    } else {
        printf("Nenhum numero foi digitado.\n");
    }
    
    return 0;
}

//QUESTÃO 12
#include <stdio.h>

int main() {
    int num, soma = 0, quant = 0;

    printf("Digite um numero inteiro (-1 para parar): ");
    scanf("%d", &num);

    while (num != -1) {
        soma += num; 
        quant++; 
        
        printf("Digite um numero inteiro (-1 para parar): ");
        scanf("%d", &num);
    }

    if (quant > 0) {
        double media = (double) soma / quant; 
        printf("A media dos numeros digitados e: %.2f\n", media);
    } else {
        printf("Nenhum numero foi digitado.\n");
    }

    return 0;
}

//QUESTÃO 13
#include <stdio.h>
#include <math.h>

int main() {
    int num, dig, soma = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    int a = num;
    while (a != 0) {
        dig = a % 10;  
        soma += pow(dig, 3);  
        a /= 10;  
    }

    printf("A soma dos digitos elevados ao cubo do numero e: %d\n", soma);

    return 0;
}

//QUESTÃO 14
#include <stdio.h>

int main() {
    int num = 1;
 
    printf("Numeros impares de 1 a 100:\n");
    while (num <= 100) {
        if (num % 2 != 0) {
            printf("%d ", num);
        }
        num++;
    }
    printf("\n");

    return 0;
}

//QUESTÃO 15
#include <stdio.h>

int main() {
    int num = 1;
 
    printf("Multiplos de 3 de 1 a 50:\n");
    while (num <= 50) {
        if (num % 3 == 0) {
            printf("%d ", num);
        }
        num++;
    }
    printf("\n");

    return 0;
}

//QUESTÃO 16
#include <stdio.h>

int main() {
    int cont = 0;
    int contaprovados = 0;
    float nota;

    printf("Digite as 5 notas dos alunos:\n");
 
    while (cont < 5) {
        printf("Nota do aluno %d: ", cont + 1);
        scanf("%f", &nota);

        if (nota >= 7.0) {
            contaprovados++;
        }

        cont++;
    }
 
    printf("Quantidade de alunos aprovados: %d\n", contaprovados);
    return 0;
}

//QUESTÃO 17
#include <stdio.h>

int main() {
    int num;
    int pares = 0;
    int impar = 0;
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");
 
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num % 2 == 0 && !impar) {
            pares++;
        } else {
            impar = 1;
        }
    }
 
    printf("Quantidade de numeros pares antes do primeiro impar: %d\n", pares);

    return 0;
}

//QUESTÃO 18
#include <stdio.h>

int main() {
    int num;
    int pares = 0;
    int impares = 0;
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");
 
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
 
    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);

    return 0;
}

//QUESTÃO 19
#include <stdio.h>

int main() {
    int num;
    int dois = 0;
    int tres = 0;
    int cinco = 0;
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");
 
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num % 2 == 0) {
            dois++;
        } else if (num % 3 == 0) {
            tres++;
        } else if (num % 5 == 0){
            cinco++;
        }
    }
 
    printf("Quantidade de divisíveis por 2: %d\n", dois);
    printf("Quantidade de divisíveis por 3: %d\n", tres);
    printf("Quantidade de divisíveis por 5: %d\n", cinco);

    return 0;
}

//QUESTÃO 20
#include <stdio.h>

int main() {
    int num;
    int soma = 0;
    int quantidade = 0;
    float media;
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");
 
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num % 3 == 0) {
            soma += num;
            quantidade++;
        }
    }

    if (quantidade > 0) {
        media = (float)soma / quantidade;
        printf("Media dos numeros divisiveis por 3: %.2f\n", media);
    } else {
        printf("Nenhum numero divisivel por 3 foi digitado.\n");
    }

    return 0;
}

//QUESTÃO 21
#include <stdio.h>

int main() {
    int num;
    int numtres = 0;
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");

    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num == 0) {
            break;  
        }
 
        if (num >= 1000 || num <= -1000) {
            numtres++;
        }
    }
 
    printf("Quantidade de numeros com mais de tres digitos: %d\n", numtres);

    return 0;
}

//QUESTÃO 22
#include <stdio.h>

int main() {
    int num;
    int soma = 0;
    int quantidade = 0;
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");
 
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num == 0) {
            break;  
        }
 
        if (num >= 50 && num <= 100) {
            soma += num;
            quantidade++;
        }
    }
 
    if (quantidade > 0) {
        float media = (float)soma / quantidade;
        printf("Media dos numeros entre 50 e 100: %.2f\n", media);
    } else {
        printf("Nenhum numero entre 50 e 100 foi digitado.\n");
    }

    return 0;
}

//QUESTÃO 23
#include <stdio.h>

int main() {
    int numero;
    int menorposit = 0;  
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");
 
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero == 0) {
            break; 
        }

        if ((numero > 0 && numero % 2 != 0) && (menorposit == 0 || numero < menorposit)) {
            menorposit = numero;
        }
    }
 
    if (menorposit != 0) {
        printf("O menor valor positivo e impar digitado foi: %d\n", menorposit);
    } else {
        printf("Nenhum valor positivo e impar foi digitado.\n");
    }

    return 0;
}

//QUESTÃO 24
#include <stdio.h>

int main() {
    int num;
    int primeiro = 0;
    int ultimo = 0;
    int pares = 0;
    int impares = 0;
 
    printf("Digite uma sequencia de numeros inteiros (0 para parar):\n");
 
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num == 0) {
            break; 
        }
 
        if (primeiro == 0) {
            primeiro = num;
        }
 
        ultimo = num;
 
        if (num % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
 
    printf("Quantidade de numeros pares entre %d e %d: %d\n", primeiro, ultimo, pares);
    printf("Quantidade de numeros impares entre %d e %d: %d\n", primeiro, ultimo, impares);

    return 0;
}
