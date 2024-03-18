//Atividade 08 - Recursão - Programação Estruturada
//Aluna: Noemi Soares Gonçalves da Silva  RA:00000851329

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int soma(int n) {
  if (n == 0) {
    return 0;
  }
  return n + soma(n - 1);
}

int main() {
  int n;

  printf("Escolha um número para o somatório: ");
  scanf("%d", &n);

  int resultado = soma(n);
  
  printf("O somatório de 1 a %d é: %d\n", n, resultado);
  return 0;
}

//QUESTÃO 2
#include <stdio.h>

int fatorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * fatorial(n - 1);
}

int main() {
  int n;
 
  printf("Digite um número para calcular o fatorial: ");
  scanf("%d", &n);
 
  int resultado = fatorial(n);
  
  printf("O fatorial de %d é: %d\n", n, resultado);
  return 0;
}

//QUESTÃO 3
#include <stdio.h>

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n;
 
  printf("Digite o número do termo da sequência Fibonacci que você quer: ");
  scanf("%d", &n);
 
  int resultado = fibonacci(n);
  
  printf("O %dº termo da sequência Fibonacci é: %d\n", n, resultado);
  return 0;
}

//QUESTÃO 4
#include <stdio.h>

void impnum(int n) {
  if (n < 0) {
    return;
  }
  impnum(n - 1);
  printf("%d ", n);
}

int main() {
  int n;
 
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);
 
  impnum(n);
  
  printf("\n");
  return 0;
}

//QUESTÃO 5
#include <stdio.h>

void impnumdec(int n) {
  if (n < 0) {
    return;
  }
  printf("%d ", n);
  impnumdec(n - 1);
}

int main() {
  int n;
 
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);
 
  impnumdec(n);
  
  printf("\n");
  return 0;
}
