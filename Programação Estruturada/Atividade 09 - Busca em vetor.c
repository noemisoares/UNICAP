//Atividade 09 - Busca em Vetor - Programação Estruturada

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int main() {
  int vetor[10];
  int maior = vetor[0];  
 
  for (int i = 0; i < 10; i++) {
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
 
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
  }
 
  printf("O maior elemento do vetor é: %d\n", maior);

  return 0;
}

//QUESTÃO 2
#include <stdio.h>

int main() {
 
  int vetor[10];
 
  for (int i = 0; i < 10; i++) {
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }
 
  int menor = vetor[0];
  for (int i = 1; i < 10; i++) {
    if (vetor[i] < menor) {
      menor = vetor[i];
    }
  }

  printf("O menor elemento do vetor é: %d\n", menor);

  return 0;
}

//QUESTÃO 3
#include <stdio.h>

int main() {
 
  int vetor[10];
 
  for (int i = 0; i < 10; i++) {
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }
 
  int maior = vetor[0];
  int pmaior = 0;
  for (int i = 1; i < 10; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
      pmaior = i;
    }
  }
 
  printf("O maior elemento do vetor é: %d\n", maior);
  printf("A posição do maior elemento é: %d\n", pmaior + 1);

  return 0;
}

//QUESTÃO 4
#include <stdio.h>

int main() {
 
  int vetor[5];
 
  for (int i = 0; i < 5; i++) {
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }
 
  int maior = vetor[0];
  int menor = vetor[0];
  int pmaior = 0;
  int pmenor = 0;
  for (int i = 1; i < 5; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
      pmaior = i;
    }
    if (vetor[i] < menor) {
      menor = vetor[i];
      pmenor = i;
    }
  }
 
  printf("O maior elemento do vetor é: %d\n", maior);
  printf("A posição do maior elemento é: %d\n", pmaior + 1);
  printf("O menor elemento do vetor é: %d\n", menor);
  printf("A posição do menor elemento é: %d\n", pmenor + 1);

  return 0;
}

//QUESTÃO 5
#include <stdio.h>

int main() {

  int vetor[10];

  for (int i = 0; i < 10; i++) {
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }
 
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (vetor[i] == vetor[j]) {
        printf("O valor %d, da posição %d é igual ao valor %d, da posição %d.\n", vetor[i], i + 1, vetor[j], j + 1);
      }
    }
  }

  return 0;
}
