//Atividade 10 - Ordenação por Inserção e Busca Binária - Programação Estruturada

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int buscaBinaria(int *vetor, int tam, int valor, int *numite) {
  int i = 0;
  int f = tam - 1;
  int m;
  *numite = 0;

  while (i <= f) {
    (*numite)++;
    m = (i + f) / 2;

    if (vetor[m] == valor) {
      return m;
    } else if (vetor[m] < valor) {
      i = m + 1;
    } else {
      f = m - 1;
    }
  }

  return -1;
}

int main() {
    int vetor[] = {1, 3, 4, 5, 7, 9, 11, 15, 29, 43, 65, 77, 97};
  int tam = sizeof(vetor) / sizeof(vetor[0]);
  int valor, posicao, numite;

  printf("Digite o valor que deseja buscar: ");
  scanf("%d", &valor);

  posicao = buscaBinaria(vetor, tam, valor, &numite);

  if (posicao == -1) {
    printf("Valor não encontrado.\n");
  } else {
    printf("Valor encontrado na posição %d.\n", posicao);
    printf("Número de iterações: %d\n", numite);
  }

  return 0;
}
