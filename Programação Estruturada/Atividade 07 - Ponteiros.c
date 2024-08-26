//Atividade 07 - Ponteiros - Programação Estruturada

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int main() {
    char c = 'a';
    char *pc;
    
    pc = &c;
    
    //a) O endereço de c e o valor guardado por ele.
    printf("ponteiro [c]: %p\n", &c);
    printf("valor de c: %c\n", c); 
    
    //b) O valor que pc armazena e o valor guardado no endereço apontado por ele.
    printf("ponteiro: %p\n", pc);
    printf("valor dentro do ponteiro: %c\n", *pc);
    
    //c) O endereço de pc.
    printf("ponteiro [pc]: %p\n", &pc);

    return 0;
}

//QUESTÃO 2
#include <stdio.h>

int main() {
    int i = 18;
    float r = 1.5;
    char c = 'N';
    
    int *pi;
    float *pr;
    char *pc;
    
    pi = &i;
    pr = &r;
    pc = &c;
    
    printf("Valor do Inteiro: %d\n", *pi);
    printf("Valor do Real: %f\n", *pr);
    printf("Valor do Char: %c\n", *pc);
    
    *pi = 20;
    *pr = 2.5;
    *pc = 'O';
    
    printf("Valor do Inteiro: %d\n", *pi);
    printf("Valor do Real: %f\n", *pr);
    printf("Valor do Char: %c\n", *pc);

    return 0;
}

//QUESTÃO 3
#include <stdio.h>

int main() {
    int n1, n2;
    int *pi1, *pi2;

    pi1 = &n1;
    pi2 = &n2;

    printf("Insira o primeiro valor: \n");
    scanf("%d", &n1);
    printf("Insira o segundo valor: \n");
    scanf("%d", &n2);

    printf("Endereço de memória do primeiro valor: %p\n", pi1);
    printf("Endereço de memória do segundo valor: %p\n", pi2);

    return 0;
}

//QUESTÃO 4
#include <stdio.h>

void troca(int *a, int *b) {
    int c;
        c = *a;
        *a = *b;
        *b = c;
}

int main() {
    int n1, n2;
    int *p1, *p2;
 
    printf("Digite o primeiro valor: ");
    scanf("%d", &n1);
    printf("Digite o segundo valor: ");
    scanf("%d", &n2);
 
    p1 = &n1;
    p2 = &n2;
 
    troca(p1, p2);
 
    printf("Primeiro valor: %d\n", n1);
    printf("Segundo valor: %d\n", n2);

    return 0;
}

//QUESTÃO 5
#include <stdio.h>

int troca(int *a, int *b) {
    int *dn1, *dn2;
    dn1 = a;
    dn2 = b;
    *dn1 = (*a * 2);
    *dn2 = (*b * 2);
    return *dn1 + *dn2;
}

int main() {
    int a, b, soma;
    int *p1, *p2;

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);

    p1 = &a;
    p2 = &b;

    soma = troca(p1, p2);

    printf("Primeiro valor: %d\n", a);
    printf("Segundo valor: %d\n", b);
    printf("Soma do dobro dos valores: %d\n", soma);

    return 0;
}




