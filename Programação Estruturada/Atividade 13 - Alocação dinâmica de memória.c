//Atividade 13 - Alocação Dinâmica de Memória - Programação Estruturada

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pArray = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero %d: ", i+1);
        scanf(" %d", &pArray[i]);

    }

    if(pArray != NULL){
        for (int i = 0; i < 5; i++) {
            printf("%d ", pArray[i]);
        }
    }
    free(pArray);
    pArray = NULL;

    return 0;
}

//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;

    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &a);

    int *pArray = malloc(a * sizeof(int));

    for (int i = 0; i < a; i++) {
        printf("Digite um numero %d: ", i+1);
        scanf(" %d", &pArray[i]);

    }

    if(pArray != NULL){
        for (int i = 0; i < a; i++) {
            printf("%d ", pArray[i]);
        }
    }
    free(pArray);
    pArray = NULL;

    return 0;
}

//QUESTÃO 3 
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;

    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &a);

    int *pArray = malloc(a * sizeof(int));

    for (int i = 0; i < a; i++) {
        printf("Digite um numero %d: ", i+1);
        scanf(" %d", &pArray[i]);

    }

    int par = 0, impar = 0;
    for (int i = 0; i < a; i++) {
        if(pArray[i] % 2 == 0 ){
            par++;
        } else {
            impar++;
        }

    }

    printf("Quantidade de numeros pares: %d\n", par);
    printf("Quantidade de numeros impares: %d\n", impar);

    free(pArray);
    pArray = NULL;

    return 0;
}

//QUESTÃO 4 
#include <stdio.h>
#include <stdlib.h>

char* Alloc(int tam) {
    char* pStr = malloc(tam * sizeof(char));
    return pStr;
}

int main() {
    int t;

    printf("Digite o tamanho: ");
    scanf("%d", &t);

    char* str = Alloc(t + 1); //'\0'

    printf("Digite uma string: ");
    scanf(" %50[^\n]", str);

    printf("String sem suas vogais: ");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            printf("%c", str[i]);
        }
    }

    free(str);
    str = NULL;

    return 0;
}

//QUESTÃO 5
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, k = 0;
    
    printf("Digite o tamanho: ");
    scanf(" %d", &n);

    int* pVetor = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Digite um valor para a posicao %d: ", i+1);
        scanf(" %d", &pVetor[i]);
    }

    printf("Digite um numero para busca: ");
    scanf(" %d", &x);

    printf("Multiplos do numero %d: ", x);
    for(int i = 0; i < n; i++){
        if(pVetor[i] % x == 0){
            printf("%d ", pVetor[i]);
            k++;
        }
    }
    printf("\nO vetor tem %d multiplos do numero %d ", k, x);

    free(pVetor);
    pVetor = NULL;

    return 0;
}

//QUESTÃO 6
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, p, x, k = 0;
    char escolha = 0;
    int* pVetor;
    
    printf("Digite o tamanho de memoria: ");
    scanf(" %d", &n);

    if(n % sizeof(int) == 0){
        pVetor = calloc(n / sizeof(int) , sizeof(int));
        k++;
    } else {
        printf("Memoria nao alocada! A memoria solicitada deve ser um valor multiplo do tamanho do tipo inteiro\n");
    }

    if(k != 0){
        do{
            printf("\nMenu:\n");
            printf("a. Inserir um valor em uma determinada posicao\n");
            printf("b. Consultar o valor contido em uma determinada posicao\n");
            printf("s. Sair do menu.\n");
            printf("Escolha uma opcao: ");
            scanf(" %c", &escolha);

            switch (escolha){
            case 'a':
                printf("Escolha uma posicao: ");
                scanf(" %d", &p);
                printf("\n");
                for(int i = 0; i < n; i++){
                    if(i == p){ //p >= 0 && p < n / sizeof(int)
                        printf("Posicao %d encontrada.\n", p);
                        printf("Digite seu valor: ");
                        scanf(" %d", &pVetor[i]);
                        printf("\n");
                        printf("Valor %d foi adicionado na Posicao %d.\n", pVetor[i], p);
                    }
                }
                break;
            case 'b':
                printf("Escolha uma posicao para busca: ");
                scanf(" %d", &x);
                printf("\n");
                for(int i = 0; i < n; i++){
                    if(i == x){ //x >= 0 && x < n / sizeof(int)
                        printf("Na Posicao %d foi encontrado o Valor %d.\n", x, pVetor[i]);
                    }
                }
                break;
            case 's':
                printf("Saindo do programa...\n");
                break;         
            default:
                printf("Opcao incorreta. Tente novamente...\n");
                break;
            }
        } while(escolha != 's');
    }

    free(pVetor);
    pVetor = NULL;

    return 0;
}

//QUESTÃO 7
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, k = 0;
    int* pVetor = calloc(1500 , sizeof(int));

        for(i = 0; i < 1500; i++){
            if(pVetor[i] == 0){
                k++;
            }
        }
        printf("O vetor possui %d valores de 0\n", k);
    
        printf("Os 10 primeiros elementos: \n");
        for(i = 0; i < 1500; i++){
            pVetor[i] = i;
            if(i >= 0 && i < 10){
                printf(" %d", pVetor[i]);
            }
        }
        printf("\nOs 10 ultimos elementos: \n");
        for(i = 0; i < 1500; i++){
            pVetor[i] = i;
            if(i >= 1490 && i < 1500){
                printf(" %d", pVetor[i]);
            }
        }

    free(pVetor);
    pVetor = NULL;

    return 0;
}

//QUESTÃO 8
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, m = 1;
    int* pVetor = malloc(m * sizeof(int));
    
        for(i = 0; i < m; i++){
            printf("Digite um valor para posicao %d: ", i);
            scanf(" %d", &pVetor[i]);
            if(pVetor[i] < 0){
                break;
            }
            m++;
            pVetor = realloc(pVetor, m * sizeof(int));
        }

        printf("Vetor:\n");
        for(i = 0; i < m - 1; i++){      
            printf(" %d", pVetor[i]);
        }
        
    free(pVetor);
    pVetor = NULL;

    return 0;
}

//QUESTÃO 9
#include <stdio.h>
#include <stdlib.h>

int BuscaMatriz(int l, int c, int x, int* m[l][c]){
    int i, j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(m[i][j] != NULL && *m[i][j] == x){
                printf("Valor %d escontrado na posicao [%d][%d].\n", *m[i][j], i, j);
                return 1;
            }    
        }
    }
    printf("Valor não encontrado\n");
    return 0;
}

int main() {
    int i, j, l, c, x;
    
        printf("Escolha um numero de linhas: ");
        scanf(" %d", &l);
        printf("Escolha um numero de colunas: ");
        scanf(" %d", &c);

        int* matriz[l][c];

        for(i = 0; i < l; i++){
            for(j = 0; j < c; j++){
                printf("Elemento[%d][%d]: ", i+1,j+1);
                matriz[i][j] = malloc(sizeof(int));
                scanf(" %d", matriz[i][j]);
            }
        }

        printf("Digite um valor para busca: ");
        scanf(" %d", &x);

        if(BuscaMatriz(l, c, x, matriz)){
            printf("Foi encontrado na matriz.\n");
        }else{
            printf("O valor nao foi encontrado na matriz.\n");
        }

        for(i = 0; i < l; i++){
            for(j = 0; j < c; j++){
                free(matriz[i][j]);
            }
        }

    return 0;
}

//QUESTÃO 10
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, l, c;
    
        printf("Escolha um numero de linhas: ");
        scanf(" %d", &l);
        printf("Escolha um numero de colunas: ");
        scanf(" %d", &c);

        float* matriz[l][c];

        for(i = 0; i < l; i++){
            for(j = 0; j < c; j++){
                printf("Elemento[%d][%d]: ", i+1,j+1);
                matriz[i][j] = malloc(sizeof(float));
                scanf(" %f", matriz[i][j]);
            }
        }

        printf("\nImpressao da Matriz:\n");
        for(i = 0; i < l; i++){
            for(j = 0; j < c; j++){
                printf(" %2.2f", *matriz[i][j]);
            }
            printf("\n");
        }

        for(i = 0; i < l; i++){
            for(j = 0; j < c; j++){
                free(matriz[i][j]);
            }
        }

    return 0;
}

//QUESTÃO 11
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, n = 10;
    int* vetor = malloc(n * sizeof(int)); 

    while (1) {
        printf("Digite um valor (0 para encerrar): ");
        scanf(" %d", &vetor[i]);

        if (vetor[i] == 0) { 
            break;
        }

        i++;

        if (i == n) { 
            n += 10;
            int* vetor2 = malloc(n * sizeof(int)); 

            for (int j = 0; j < i; j++) {
                vetor2[j] = vetor[j];
            }

            free(vetor); 
            vetor = vetor2;
        }
    }

    printf("\nVetor:\n");
    for (int j = 0; j < i; j++) { 
        printf("%d ", vetor[j]);
    }
    printf("\n");

    free(vetor);

    return 0;
}
