//Lista 1 - Ponteiros e Alocação Dinâmica de Memória - Estruturas de Dados Lineares
//Aluna: Noemi Soares Gonçalves da Silva  RA:00000851329

//RESPOSTAS DAS QUESTÕES DE CÓDIGO

//QUESTÃO 3.A
#include <stdio.h>
#include <stdlib.h>

int main(){
    char key, choice;
    int num, count;
    long date;
    float yield;
    double price;

    printf("Endereco de Key: %p\n", &key);
    printf("Endereco de Choice: %p\n", &choice);
    printf("Endereco de Num: %p\n", &num);
    printf("Endereco de Count: %p\n", &count);
    printf("Endereco de Date: %p\n", &date);
    printf("Endereco de Yield: %p\n", &yield);
    printf("Endereco de Price: %p\n", &price);

    return 0;
}

//QUESTÃO 3.B
#include <stdio.h>
#include <stdlib.h>

int main(){
    char key, choice;
    int num, count;
    long date;
    float yield;
    double price;

    printf("Endereco de Key: %p\n", &key);
    printf("Endereco de Choice: %p\n", &choice);
    printf("Endereco de Num: %p\n", &num);
    printf("Endereco de Count: %p\n", &count);
    printf("Endereco de Date: %p\n", &date);
    printf("Endereco de Yield: %p\n", &yield);
    printf("Endereco de Price: %p\n", &price);
    printf("\n");
    printf("Quantidade de Memoria Tipo Char | Key e Choice: %u bytes\n", sizeof(char));
    printf("Quantidade de Memoria Tipo Int | Num e Count: %u bytes\n", sizeof(int));
    printf("Quantidade de Memoria Tipo Long | Date: %u bytes\n", sizeof(long));
    printf("Quantidade de Memoria Tipo Float | Yield: %u bytes\n", sizeof(float));
    printf("Quantidade de Memoria Tipo Double | Price: %u bytes\n", sizeof(double));

    return 0;
}

//QUESTÃO 9
#include <stdio.h>
#include <stdlib.h>

void yyy(int vetor[], int tamanho, int *minimo, int *maximo) {

    *minimo = vetor[0];
    *maximo = vetor[0];

    for(int i = 0; i < tamanho; i++){
        if(*minimo > vetor[i]){
            *minimo = vetor[i];
        } else if (*maximo < vetor[i]){
            *maximo = vetor[i];
        }
    } 
}

int main(){
    int v[] = {17,86,34,59,78,21};
    int tam = sizeof(v) / sizeof(v[0]);
    int min, max;

    yyy(v,tam,&min,&max);

    printf("Valor Minimo: %d\n", min);
    printf("Valor Maximo: %d\n", max);
    
    return 0;
}

//QUESTÃO 10
#include <stdio.h>
#include <stdlib.h>

struct Dados {
    char sexo;
    float altura;
    int idade;
    char cor_dos_olhos;
};

int main(){
    int memoria = 0, k = 0;
    struct Dados *dado = malloc(memoria * sizeof(struct Dados));

    printf("Bem-vindo ao Sistema de Coleta de Dados!\n"); 
    printf("Informe a quantidade de habitantes que serao registrados: ");
    scanf(" %d", &memoria);
    printf("\n");

    do{
        printf("Digite os dados da Pessoa %d: \n", k+1);
        printf("Digite seu sexo (M/F): ");
        scanf(" %c", &dado[k].sexo);
        printf("Digite sua altura (Ex: 1.60): ");
        scanf(" %f", &dado[k].altura);
        printf("Digite sua idade: ");
        scanf(" %d", &dado[k].idade);
        printf("A - Azuis | V - Verdes | C - Castanhos | P - Pretos\n");
        printf("Digite a letra que corresponde a cor dos seus olhos: ");
        scanf(" %c", &dado[k].cor_dos_olhos);
        printf("\n");
        k++;
    } while (k < memoria);

    int somaIdade = 0;
    for(int i = 0; i < k; i++){
        if((dado[i].cor_dos_olhos == 'C' || dado[i].cor_dos_olhos == 'c') && dado[i].altura > 1.60){
            somaIdade = somaIdade + dado[i].idade;
        }
    }
    float mediaIdade = (float)somaIdade / 2;
    printf("A Media de Idade das pessoas com olhos castanhos e altura superior a 1,60 m: %.2f anos\n", mediaIdade);

    int maiorIdade = 0;
    for(int i = 0; i < k; i++){
        if(dado[i].idade > maiorIdade){
            maiorIdade = dado[i].idade;
        }
    }
    printf("A Maior Idade entre os habitantes: %d anos\n", maiorIdade);

    int quantFeminino = 0;
    for(int i = 0; i < k; i++){
        if((dado[i].sexo == 'F' || dado[i].sexo == 'f') && dado[i].altura < 1.70 && ((dado[i].idade >= 20 && dado[i].idade <= 45) || (dado[i].cor_dos_olhos == 'V' || dado[i].cor_dos_olhos == 'v'))){
            quantFeminino++;
        }
    }
    printf("A Quantidade de Mulheres cuja idade esteja entre 20 e 45 anos ");
    printf("ou que tenham olhos verdes, e altura inferior a 1,70m: %d Mulheres \n", quantFeminino);

    float percHomem = 0;
    int Man = 0, Women = 0;
    for(int i = 0; i < k; i++){
        if(dado[i].sexo == 'M' || dado[i].sexo == 'm'){
            Man++;
        } else {
            Women++;
        }
    }
    int total = Man + Women;
    if (total > 0) {
        percHomem = ((float)Man / total) * 100;
    }
    printf("O Percentual de Homens: %f%%\n", percHomem);
    
    return 0;
}