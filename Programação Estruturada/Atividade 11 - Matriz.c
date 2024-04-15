//Atividade 11 - Matriz - Programação Estruturada
//Aluna: Noemi Soares Gonçalves da Silva  RA:00000851329

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int main() {
   int m[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; 
   int i,j;
   int a = 0; 

   printf("Os valores maiores que 10 sao: ");
   
   for(i=0; i<4; i++) { 
      for(j=0; j<4; j++) { 
         if (m[i][j] > 10) {
            printf("%d. ", m[i][j]);
            a++;
            }
        }
    }
    printf("\n");
    printf("A Matriz possui %d valores maiores que 10.\n", a);
    return 0;
}

//QUESTÃO 2
#include <stdio.h>

int main() {
    int m[5][5] = {{1,0,0,0,0},
                    {0,1,0,0,0},
                    {0,0,1,0,0},
                    {0,0,0,1,0},
                    {0,0,0,0,1}}; 
    int i,j; 

    for(i=0; i<5; i++) { 
        for(j=0; j<5; j++){ 
            printf("%d ", m[i][j]); 
        }
        printf("\n");
    }
}

//QUESTÃO 3
#include <stdio.h>

int main() {
   int m[3][3]; 
   int i, j;

      for(i=0; i<3; i++) { 
         for(j=0; j<3; j++) { 
            m[i][j]=i*j;
            printf("%d ", m[i][j]); 
         }
      printf("\n");
   }
   return 0;
}

//QUESTÃO 4
#include <stdio.h>

int main() {
   int m[4][4] = {{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}}; 
   int i, j, a=0, b=0, c=0;

      printf("A matriz:\n");

      for(i=0; i<4; i++) { 
         for(j=0; j<4; j++) {
               printf("%d ", m[i][j]);
               if(c > m[i][j]){
               } else {
                  c = m[i][j];
                  a = i;
                  b = j;
               }
            }
            printf("\n");
         }
         printf("O maior valor da matriz se encontra na posicao %dx%d.\n", a + 1, b + 1);
         printf("Esse valor e: %d\n", c);

   return 0;
}

//QUESTÃO 5
#include <stdio.h>

int main() {
  int matriz[5][5];
  int v, i, j;
  int encontrado = 0; 

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("Digite o valor da linha %d, coluna %d: ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }

  printf("\nDigite o valor a ser buscado: ");
  scanf("%d", &v);

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (matriz[i][j] == v) {
        encontrado = 1;
        break;
      }
    }
  }
    
  if (encontrado) {
    printf("\nValor encontrado na linha %d, coluna %d!", i + 1, j + 1);
  } else {
    printf("\nValor não encontrado na matriz.");
  }

  return 0;
}

//QUESTÃO 6
#include <stdio.h>

int main() {
  int m[4][4],m2[4][4],m3[4][4];
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("Digite o valor da Matriz 1, linha %d, coluna %d: ", i + 1, j + 1);
      scanf("%d", &m[i][j]);
      
      printf("Digite o valor da Matriz 2, linha %d, coluna %d: ", i + 1, j + 1);
      scanf("%d", &m2[i][j]);
    }
  }
  
    printf("\nMatriz 1:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    } 
    printf("\nMatriz 2:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        if (m[i][j] > m2[i][j]) {
        m3[i][j] = m[i][j];
        } else {
        m3[i][j] = m2[i][j];
        }
    }
  }

  printf("\nMatriz 3:\n");
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("%d ", m3[i][j]);
    }
    printf("\n");
  }

  return 0;
}

//QUESTÃO 7
#include <stdio.h>

int main() {
   int m[10][10]; 
   int i, j;
   
   for(i=0;i<10;i++){
      for(j=0;j<10;j++){
         if(i<j) {
            m[i][j] = 2*i + 7*j;
         } else if (i==j) {
            m[i][j] = 3*i*i;
         } else {
            m[i][j] = 5*j*j +1;
         }
      }
   }
   
   for(i = 0; i < 10; i++){
       for(j = 0; j < 10; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
   }
   
   return 0;
}

//QUESTÃO 8
#include <stdio.h>

int main() {
   int m[3][3]; 
   int i, j, soma = 0;
   
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite o valor da linha %d, coluna %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i < j) {
            soma += m[i][j];
            }
        }
   }
   
   printf("\nA Matriz 3x3:\n");
   for(i = 0; i < 3; i++){
       for(j = 0; j < 3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
   }
   
   printf("\nSoma dos elementos acima da diagonal principal: %d", soma);
   
   return 0;
}

//QUESTÃO 9
#include <stdio.h>

int main() {
   int m[3][3]; 
   int i, j, soma = 0;
   
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite o valor da linha %d, coluna %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > j) {
            soma += m[i][j];
            }
        }
   }
   
   printf("\nA Matriz 3x3:\n");
   for(i = 0; i < 3; i++){
       for(j = 0; j < 3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
   }
   
   printf("\nSoma dos elementos abaixo da diagonal principal: %d", soma);
   
   return 0;
}

//QUESTÃO 10
#include <stdio.h>

int main() {
   int m[3][3]; 
   int i, j, soma = 0;
   
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite o valor da linha %d, coluna %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
            soma += m[i][j];
            }
        }
   }
   
   printf("\nA Matriz 3x3:\n");
   for(i = 0; i < 3; i++){
       for(j = 0; j < 3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
   }
   
   printf("\nSoma dos elementos da diagonal principal: %d", soma);
   
   return 0;
}

//QUESTÃO 11
#include <stdio.h>

int main() {
   int m[3][3]; 
   int i, j, soma = 0;
   
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite o valor da linha %d, coluna %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        soma += m[2 - i][i];
   }
   
   printf("\nA Matriz 3x3:\n");
   for(i = 0; i < 3; i++){
       for(j = 0; j < 3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
   }
   
   printf("\nSoma dos elementos da diagonal secundaria: %d", soma);
   
   return 0;
}

//QUESTÃO 12
#include <stdio.h>

int main() {
   int m[3][3]; 
   int i, j, soma = 0;
   
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite o valor da linha %d, coluna %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
   printf("\nA Matriz:\n");
   for(i = 0; i < 3; i++){
       for(j = 0; j < 3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
   }
   
   printf("\nA Matriz Transposta:\n");
   for(i = 0; i < 3; i++){
       for(j = 0; j < 3; j++){
            printf("%d ", m[j][i]);
        }
        printf("\n");
   }
   
   return 0;
}

//QUESTÃO 13
#include <stdio.h>
#include <stdlib.h>

void gerar(int m[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m[i][j] = rand() % 20 + 1;
    }
  }
}

void triangular(int m[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < i; j++) {
      m[i][j] = 0;
    }
  }
}

int main() {
    int m[4][4]; 
    int i, j;
    
    gerar(m);
    
    printf("\nA Matriz Original:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
   
    triangular(m);
   
    printf("\nA Matriz Triangular Inferior:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%2d ", m[j][i]);
        }
        printf("\n");
   }
   
   return 0;
}

//QUESTÃO 14
#include <stdio.h>
#include <stdlib.h>

int existeNum(int cartela[5][5], int i, int j, int num) {
  for (int n = 0; n < 5; n++) {
    if (cartela[i][n] == num || cartela[n][j] == num) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int cartela[5][5];
  int i,j;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      int num;
      do { num = rand() % 100;
      } while (existeNum(cartela, i, j, num));

      cartela[i][j] = num;
    }
  }

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%02d ", cartela[i][j]);
    }
    printf("\n");
  }

  return 0;
}

//QUESTÃO 15
#include <stdio.h>

int main() {
  char respostas[5][10];
  char gabarito[10];
  int resultado[5];
  int i,j;

  for (i = 0; i < 5; i++) {
    resultado[i] = 0;
  }

  printf("Digite o gabarito das questões (a, b, c ou d):\n");
  for (i = 0; i < 10; i++) {
    printf("Questão %d: ", i + 1);
    scanf(" %c", &gabarito[i]);
  }

  for (i = 0; i < 5; i++) {
    printf("\nDigite as respostas do aluno %d:\n", i + 1);
    for (int j = 0; j < 10; j++) {
        printf("Questão %d: ", j + 1);
        scanf(" %c", &respostas[i][j]);
    }
  }

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 10; j++) {
      if (respostas[i][j] == gabarito[j]) {
        resultado[i]++;
      }
    }
  }

  printf("\nResultados:\n");
  for (i = 0; i < 5; i++) {
    printf("Aluno %d: %d pontos\n", i + 1, resultado[i]);
  }

  return 0;
}

//QUESTÃO 16
#include <stdio.h>

int main() {
    char notas[10][3];
    int a, p;
    int pior1 = 0, pior2 = 0, pior3 = 0;
    
    for (a = 0; a < 10; a++) {
        for (p = 0; p < 3; p++) {
            printf("Digite a nota do aluno %d na prova %d: ", a + 1, p + 1);
            scanf("%d", &notas[a][p]);
        }
    }

    for (a = 0; a < 10; a++) {
        int piorAtual = notas[a][0];
        int pior = 1;

    for (p = 1; p < 3; p++) {
        if (notas[a][p] < piorAtual) {
            piorAtual = notas[a][p];
            pior = p + 1;
      }
    }

    switch (pior) {
      case 1:
        pior1++;
        break;
      case 2:
        pior2++;
        break;
      case 3:
        pior3++;
        break;
    }
  }

  printf("\nResultados:\n");
  printf("   Alunos com pior nota na prova 1: %d\n", pior1);
  printf("   Alunos com pior nota na prova 2: %d\n", pior2);
  printf("   Alunos com pior nota na prova 3: %d\n", pior3);

  return 0;
}

//QUESTÃO 17
#include <stdio.h>

int main() {
    int m[3][3], v[3] = {0};
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite um valor para linha %d, coluna %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }

    printf("\nA Matriz:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    
    for(j = 0; j < 3; j++) {
        for(i = 0; i < 3; i++){
            v[j] += m[i][j];
        }
    }
    
    printf("\nO Vetor:\n");
        for(j = 0; j < 3; j++){
            printf("%2d ", v[j]);
        }

  return 0;
}

//QUESTÃO 18
#include <stdio.h>

int main() {
    int dados[5][4];
    int i, j;

    printf("Digite as informações dos alunos:\n");
    for (i = 0; i < 5; i++) {
    printf("Aluno %d:\n", i + 1);
        for (j = 0; j < 4 - 1; j++) {
            if (j == 0) {
                printf("Matrícula: ");
            } else if (j == 1) {
                printf("Média Provas: ");
            } else {
                printf("Média Trabalhos: ");
            }
            scanf("%d", &dados[i][j]);
        }
    }
    
    for (i = 0; i < 5; i++) {
        dados[i][3] = dados[i][1] + dados[i][2];
    }

    printf("\nMatriz de dados dos alunos:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%4d ", dados[i][j]);
        }
        printf("\n");
    }

    int matricula = dados[0][0];
    int nota = dados[0][3];
    for (i = 1; i < 5; i++) {
        if (dados[i][3] > nota) {
            matricula = dados[i][0];
            nota = dados[i][3];
        }
    }

    int somanotas = 0;
    for (i = 0; i < 5; i++) {
        somanotas += dados[i][3];
    }
    float medianotas = (float) somanotas / 5;
  
    printf("\nResultados:\n");
    printf("Matrícula com maior nota final: %d\n", matricula);
    printf("Média aritmética das notas finais: %.2f\n", medianotas);

    return 0;
}

//QUESTÃO 19
#include <stdio.h>

int main() {
    int m[3][6];
    int i, j, soma = 0, media = 0;
    
    for (i = 0; i < 3; i++){
        for (j=0;j<6;j++){
            printf("Digite um valor para a linha %d, coluna %d: ", i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }
    
    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++){
        for (j = 0;j < 6; j++){
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
    
    for(i = 0; i < 3; i++){
        soma += m[i][0] + m[i][2] + m[i][4];
    }
    printf("\nSoma de todos os elementos das colunas ímpares: %d\n", soma);
    
    for(i = 0; i < 3; i++){
        media += m[i][1] + m[i][3];
    }
    float medart = (float) media / 2;
    
    printf("\nMédia aritmética dos elementos da segunda e quarta coluna: %.2f\n", medart);

    for(i = 0; i < 3; i++){
        m[i][5] = 0;
        m[i][5] += m[i][0] + m[i][1];
    }
    
    printf("\nNovos valores da sexta coluna: %d %d %d\n", m[0][5], m[1][5], m[2][5]);
    
    printf("\nMatriz Modificada:\n");
    for (i = 0; i < 3; i++){
        for (j = 0;j < 6; j++){
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

//QUESTÃO 20
#include <stdio.h>

void lerMatriz(float matriz[2][2], char nomeMatriz) {
  int i, j;

  printf("\nDigite os valores da matriz %c:\n", nomeMatriz);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      printf("Elemento [%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matriz[i][j]);
    }
  }
}

void imprimirMatriz(float matriz[2][2], char nomeMatriz) {
  int i, j;

  printf("\nMatriz %c:\n", nomeMatriz);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      printf("%.2f ", matriz[i][j]);
    }
    printf("\n");
  }
}

void somarMatrizes(float matrizA[2][2], float matrizB[2][2], float resultado[2][2]) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      resultado[i][j] = matrizA[i][j] + matrizB[i][j];
    }
  }
}

void subtrairMatrizes(float matrizA[2][2], float matrizB[2][2], float resultado[2][2]) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      resultado[i][j] = matrizA[i][j] - matrizB[i][j];
    }
  }
}

void adicionarConstante(float matriz[2][2], float constante) {
  int i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      matriz[i][j] += constante;
    }
  }
}

int main() {
  float matriz1[2][2], matriz2[2][2], resultado[2][2];
  int escolha;
  float constante;

  do {
    printf("\nMenu de Opções:\n");
    printf("1. Somar Matrizes\n");
    printf("2. Subtrair Matrizes\n");
    printf("3. Adicionar Constante às Matrizes\n");
    printf("4. Imprimir Matrizes\n");
    printf("0. Sair\n");
    printf("\nDigite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
      case 1:
        lerMatriz(matriz1, 'A');
        lerMatriz(matriz2, 'B');
        somarMatrizes(matriz1, matriz2, resultado);
        imprimirMatriz(resultado, 'C');
        break;
      case 2:
        lerMatriz(matriz1, 'A');
        lerMatriz(matriz2, 'B');
        subtrairMatrizes(matriz1, matriz2, resultado);
        imprimirMatriz(resultado, 'C');
        break;
      case 3:
        lerMatriz(matriz1, 'A');
        lerMatriz(matriz2, 'B');
        printf("Digite o valor da constante: ");
        scanf("%f", &constante);
        adicionarConstante(matriz1, constante);
        adicionarConstante(matriz2, constante);
        printf("Constantes adicionadas às matrizes A e B.\n");
        break;
      case 4:
        imprimirMatriz(matriz1, 'A');
        imprimirMatriz(matriz2, 'B');
        break;
      case 0:
        printf("\nSaindo do programa.\n");
        break;
      default:
        printf("\nOpção inválida. Tente novamente.\n");
        break;
    }
  } while (escolha != 0);

  return 0;
}

//QUESTÃO 21
#include <stdio.h>

int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j, k;
    
    printf("\nMatriz A:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite um valor para linha %d, coluna %d: ", i+1,j+1);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\nMatriz B:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite um valor para linha %d, coluna %d: ", i+1,j+1);
            scanf("%d", &B[i][j]);
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = 0; 
            for (k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }
    
    printf("\nA multiplicação das matrizes A e B: \n");
    printf("Matriz C:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//QUESTÃO 22
#include <stdio.h>

int main() {
    int A[3][3], B[3][3];
    int i, j, k;
    
    printf("\nMatriz A:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite um valor para linha %d, coluna %d: ", i+1,j+1);
            scanf("%d", &A[i][j]);
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            B[i][j] = 0; 
            for (k = 0; k < 3; k++) {
                B[i][j] += A[i][k] * A[k][j]; 
            }
        }
    }
    
    printf("Matriz B:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%2d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}