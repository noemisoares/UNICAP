//Atividade 12 - Manipulação de Strings - Programação Estruturada
//Aluna: Noemi Soares Gonçalves da Silva  RA:00000851329

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
#include <stdio.h>

int main(){
   char str[100];

   printf("Digite uma palavra: ");
   scanf("%s", str);

   printf("A palavra digitada foi: %s", str);


return 0;
}

//QUESTÃO 2
#include <stdio.h>

int main(){
   char str[100];
   int k = 0;

   printf("Digite uma palavra: ");
   scanf(" %s", str);

   while(str[k] != '\0'){
      k++;
   }

   printf("O comprimento da string eh: %d", k);

    return 0;
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[10] = "Maio"; 
    char str2[10] = "Marco";
    int k, i;

    for(i=0; i<10; i++){
        if(str1[i] == str2[i]){
        } else {
            k++;
        }
    }
    
    if(k == 0){
        printf("\nStrings Iguais\n");
    } else {
        printf("\nStrings Diferentes\n");
    }

    return 0;
}

//QUESTÃO 4
#include <stdio.h>

int main(){
   char nome[100];
   int i;

   printf("Digite um nome: ");
   scanf("%s", nome);

   printf("As 4 primeiras letras do nome: ");
   for(i = 0; i < 4 && nome[i] != '\0'; i++){
      printf("%c", nome[i]);
   }
   printf("\n");

return 0;
}

//QUESTÃO 5
#include <stdio.h>

int main(){
   char str[100];
   int k = 0;

   printf("Digite um nome: ");
   scanf(" %s", str);

   while(str[k] != '\0'){
      k++;
   }

   printf("O nome digitado tem %d letras.", k);

    return 0;
}

//QUESTÃO 6
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[50], sexo;
    int idade;

    printf("Digite seu primeiro nome: ");
    scanf(" %s", nome);

    printf("\nDigite o sexo (M/F): ");
    scanf(" %c", &sexo);
    
    printf("\nDigite sua idade: ");
    scanf(" %d", &idade);
    
    if(sexo == 'F' || sexo == 'f' && idade < 25){
        printf("\n%s FOI ACEITA\n", nome);
    } else {
        printf("\n%s NÃO FOI ACEITA\n", nome);
    }
    
    return 0;
}

//QUESTÃO 7
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[30] = "Banana"; 
    int k, i;

    for(i=0; i<30; i++){
        if(str[i] == 'a' || str[i] == 'A'){
            k++;
        }
    }
    
    printf("\nA quantidade de letras A na palavra é: %d", k);

    return 0;
}

//QUESTÃO 8
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[30]; 
    int i;

    printf("Digite uma string: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a'){
            str[i] = 'b';
        }
    }
    
    printf("\nString com substituicao: %s", str);

    return 0;
}

//QUESTÃO 9
#include <stdio.h>

int main() {
    char nome[30];
    
    printf("Digite um nome: ");
    scanf("%30[^\n]", nome);
    
    if (nome[0] == 'a' || nome[0] == 'A'){
        printf("O nome digitado foi: %s", nome);
    } else {
        printf("A primeira letra do nome não começa com A");
    }
}

//QUESTÃO 10 
#include <stdio.h>

int main() {
    char str[30];
    int i, k = 0;

    printf("Digite una palavra: ");
    scanf("%s", str);

    while(str[k] != 0){
        k++;
    }
    
    printf("\nPalavra de Tras-pra-frente: ");
    for(i = k - 1; i >= 0; i--){
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

//QUESTÃO 11
#include <stdio.h>

int main() {
    char str[30]; 
    int i;

    printf("Digite uma string: ");
    scanf("%30[^\n]", str);

    printf("\nString sem vogais:");
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'){
            printf("%c", str[i]);
        }
    }

    return 0;
}

//QUESTÃO 12
#include <stdio.h>

int main() {
    char str[30], p; 
    int i, k=0;

    printf("Digite uma string: ");
    scanf("%30[^\n]", str);

    printf("Entre com um caractere (vogal ou consoante): ");
    scanf(" %c", &p);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' && str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            k++;
            str[i] = p;
        }
    }

    printf("\nA String possui %d vogais: ", k);
    printf("\nString modificada com o catactere: %s", str);

    return 0;
}

//QUESTÃO 13
#include <stdio.h>

int main() {
    char str[100]; 
    int i, k=0;

    printf("Digite uma string: ");
    scanf("%100[^\n]", str);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            k++;
        }
    }

    printf("\nA frase possui %d caracteres brancos ", k);

    return 0;
}

//QUESTÃO 14
#include <stdio.h>

int main() {
    char str[51]; 
    int i;

    printf("Digite uma string (máximo de 50 letras): ");
    scanf("%51[^\n]", str);

    for(i = 0; str[i] != '\0'; i++){
        str[i]++;
    }

    printf("\nPalavra apos adicionar 1 ao valor ASCII de cada caractere: %s ", str);

    return 0;
}

//QUESTÃO 15
#include <stdio.h>

int main() {
    char str[100]; 
    int i;

    printf("Digite uma string com letras minusculas: ");
    scanf("%100[^\n]", str);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }

    printf("\nCadeia de caracteres com letras Maiusculas: %s ", str);

    return 0;
}

//QUESTÃO 16
#include <stdio.h>

int main() {
    char str[100]; 
    int i;

    printf("Digite uma string com letras maiusculas: ");
    scanf("%100[^\n]", str);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
    }

    printf("\nCadeia de caracteres com letras Minusculas: %s ", str);

    return 0;
}

//QUESTÃO 17
#include <stdio.h>

int main() {
    char str[100], str2[100]; 
    int i, k = 0;

    printf("Digite uma frase: ");
    scanf("%100[^\n]", str);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            str2[k++] = str[i];
        }
    }
    str2[k] = '\0';

    printf("\nA frase sem os espacoes em branco: %s ", str2);

    return 0;
}

//QUESTÃO 18
#include <stdio.h>

int main() {
    char str[100], l1, l2; 
    int i;

    printf("Digite uma string: ");
    scanf("%100[^\n]", str);

    printf("Entre com um caractere que deseja substituir: ");
    scanf(" %c", &l1);

    printf("Entre com outro caractere que ira substituir o anterior: ");
    scanf(" %c", &l2);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == l1){
            str[i] = l2;
        }
    }

    printf("\nA string modificada: %s ", str);

    return 0;
}

//QUESTÃO 19
#include <stdio.h>

int main() {
    char nome[100], nomej[100], nomev[100]; 
    int i, idade, idadej = 100, idadev = -1;

    printf("Digite idade -1 para finalizar o programa.");

    while(1){
        printf("\nDigite seu primeiro nome: ");
        scanf(" %100[^\n]", nome);

        printf("\nDigite sua idade: ");
        scanf(" %d", &idade);

        if(idade < 0){
            break;
        }

        if(idade < idadej){
            idadej = idade;
            for(i=0; nome[i] != '\0'; i++){
                nomej[i] = nome[i];
            }
            nomej[i] = '\0';
        }

        if(idade > idadev){
            idadev = idade;
            for(i=0; nome[i] != '\0'; i++){
                nomev[i] = nome[i];
            }
            nomev[i] = '\0';
        }
    }

    if(idadej == 100 && idadev == -1){
        printf("Nenhum dado foi inserido");
    } else {
        printf("\nPessoa mais jovem: %s, %d anos", nomej, idadej);
        printf("\nPessoa mais velha: %s, %d anos", nomev, idadev);
    }

    return 0;
}

//QUESTÃO 20
#include <stdio.h>

int main() {
    char modelo[5][20] = {"Fusca","Gol","Vestra","Corolla","Civic"}; 
    float consumo[5] = {11.5, 11.0, 10.2, 13.5, 14.1};
    int i;

    float menorconsumo = consumo[0];
    int mais_eco = 0;
    for(i = 0; i < 5; i++){
        if(consumo[i] < 0 && consumo[i] > menorconsumo){
            menorconsumo = consumo[i];
            mais_eco = i;
        }
    }

    printf("O modelo mais economeco eh: %s\n", modelo[mais_eco]);

    printf("litros de combustivel necessario para percorrer 1.000 km:\n");
    for(i = 0; i < 5; i++){
        float litros = 100/ consumo[i];
        printf("%s: %.2f litros\n", modelo[i], litros);
    }

    return 0;
}

//QUESTÃO 21
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100]; 
    int i, k;

    printf("Digite uma frase: ");
    scanf("%100[^\n]", str);

    while(str[k] != '\0'){
        k++;
    }
    
    printf("\nFrase de tras pra frente com A substituido por *:");
    for(i = k - 1; i >= 0; i--){
        if(str[i] == 'a' || str[i] == 'A'){
            str[i] = '*';
        }
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

//QUESTÃO 22
#include <stdio.h>
#include <stdlib.h>

int main() {
    char produto[100];
    float valor, valortotal, valordesconto;
    int pagamento;

    printf("Digite um produto: ");
    scanf("%100[^\n]", produto);

    printf("Digite o valor do produto: ");
    scanf(" %f", &valor);

    printf("Selecione o pagamento A Vista(1) ou Cartao(2): ");
    scanf(" %d", &pagamento);

    if(pagamento == 1){
        valordesconto = (10 * valor) / 100;
        valortotal = valor - valordesconto;
    } else {
        valortotal = valor;
    }

    printf("O produto %s custa R$%.2f.", produto, valor);
    printf("\nCom o desconto de R$%.2f, o valor a ser pago sera de R$%.2f ", valordesconto, valortotal);

    return 0;
}

//QUESTÃO 23
#include <stdio.h>

int calcularComprimento(char *str) {
    int c = 0;
    while (str[c] != '\0') {
        c++;
    }
    return c;
}

void imprimirSegmento(char *str, int inicio, int fim) {
    int i;
    int comprimento = calcularComprimento(str);

    if (inicio < 0 || inicio >= comprimento || fim < 0 || fim >= comprimento) {
        printf("Indices invalidos.\n");
        return;
    }
    printf("Os segmentos escolhidos representam as letras: ");
    for (i = inicio; i <= fim; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[1000];
    int i, j;

    printf("Digite a string: ");
    scanf("%1000[^\n]", str);

    int k = 0;
    while (str[k] != '\n' && str[k] != '\0') {
        k++;
    }
    str[k] = '\0';

    printf("Digite o indice inicial (I): ");
    scanf("%d", &i);

    printf("Digite o indice final (J): ");
    scanf("%d", &j);

    imprimirSegmento(str, i, j);

    return 0;
}

//QUESTÃO 24
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[100], c;
    int i = 0;

    printf("Digite uma string: ");
    scanf("%100[^\n]", s);

    printf("\nDigite um caractere: ");
    scanf(" %c", &c);

    printf("\nDigite uma posicao: ");
    scanf(" %d", &i);

    for(i; s[i] != '\0'; i++){
        if(s[i] == c){
            printf("\nO caractere se encontra na posicao %d", i);
        } else {
            printf("\nO carctere nao foi encontrado na posicao %d", i);
        }
    }
    return 0;
}

//QUESTÃO 25
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100], str2[100];
    int i = 0;

    printf("Digite uma string: ");
    scanf("%100[^\n]", str);
    
    printf("Digite outra string: ");
    scanf(" %100[^\n]", str2);

    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] < str2[i]) {
            printf("\n%s vem antes de %s na ordem alfabética.", str, str2);
            return 0;
        } else if (str[i] > str2[i]) {
            printf("\n%s vem antes de %s na ordem alfabética.", str2, str);
            return 0;
        } else if (str[i] == '\0' && str2[i] == '\0') {
            printf("\nAs palavras são iguais.");
            return 0;
        }
        i++;
    }

    return 0;
}

//QUESTÃO 26
#include <stdio.h>
#include <string.h>

void codificarCesar(char *str) {
    int i, deslocamento = 3;
    char caractere;

    for(i = 0; str[i] != '\0'; ++i) {
        caractere = str[i];

        if(caractere >= 'a' && caractere <= 'z') {
            caractere = caractere + deslocamento;
            if(caractere > 'z') {
                caractere = caractere - 'z' + 'a' - 1;
            }
            str[i] = caractere;
        } else if(caractere >= 'A' && caractere <= 'Z') {
            caractere = caractere + deslocamento;
            if(caractere > 'Z') {
                caractere = caractere - 'Z' + 'A' - 1;
            }
            str[i] = caractere;
        }
    }
}

int main() {
    char str[1000];

    printf("Digite a string a ser codificada: ");
    fgets(str, sizeof(str), stdin);

    if(str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    codificarCesar(str);

    printf("Nova string codificada: %s\n", str);

    return 0;
}

//QUESTÃO 27
#include <stdio.h>

int verificarSubsequencia(char *str1, char *str2) {
    int len1 = 0, len2 = 0;

    while (str1[len1] != '\0') {
        len1++;
    }
    while (str2[len2] != '\0') {
        len2++;
    }

    if (len2 > len1) {
        return 0;
    }

    int i = len1 - len2;
    int j = 0;
    while (str1[i] != '\0' && str2[j] != '\0') {
        if (str1[i] != str2[j]) {
            return 0;
        }
        i++;
        j++;
    }
    return 1; 
}

int main() {
    char str1[1000], str2[1000];

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite um caractere de string: ");
    scanf("%s", str2);

    if (verificarSubsequencia(str1, str2)) {
        printf("A segunda string esta contida no final da primeira.\n");
    } else {
        printf("A segunda string nao esta contida no final da primeira.\n");
    }

    return 0;
}

//QUESTÃO 28
#include <stdio.h>

void lerString(char *s1) {
    printf("Digite a string S1 (max 20 caracteres): ");
    scanf("%20s", s1);
}

int calcularTamanho(const char *s1) {
    int tamanho = 0;
    while (s1[tamanho] != '\0' && tamanho < 20) {
        tamanho++;
    }
    return tamanho;
}

int compararStrings(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (s1[i] == s2[i]) {
        return 0;
    } else if (s1[i] < s2[i]) {
        return -1;
    } else {
        return 1;
    }
}

void concatenarStrings(char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && i < 20) {
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < 20) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

void imprimirReverso(const char *s1) {
    int tamanho = calcularTamanho(s1);
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", s1[i]);
    }
    printf("\n");
}

int contarCaractere(const char *s1, char c) {
    int count = 0;
    int i = 0;
    while (s1[i] != '\0' && i < 20) {
        if (s1[i] == c) {
            count++;
        }
        i++;
    }
    return count;
}

void substituirCaractere(char *s1, char c1, char c2) {
    int i = 0;
    while (s1[i] != '\0' && i < 20) {
        if (s1[i] == c1) {
            s1[i] = c2;
            return;
        }
        i++;
    }
}

int verificarSubstring(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && i < 20) {
        int j = 0;
        while (s1[i + j] == s2[j] && s2[j] != '\0') {
            j++;
        }
        if (s2[j] == '\0') {
            return i;
        }
        i++;
    }
    return -1;
}

void retornarSubstring(const char *s1, int posicao, int tamanho, char *substring) {
    int i = 0;
    while (s1[posicao + i] != '\0' && i < tamanho) {
        substring[i] = s1[posicao + i];
        i++;
    }
    substring[i] = '\0';
}

int main() {
    char s1[21], s2[21], c1, c2, substring[21], escolha;
    int posicao, tamanho;

    do {
        printf("\nMenu:\n");
        printf("a. Ler uma string S1\n");
        printf("b. Imprimir o tamanho da string S1\n");
        printf("c. Comparar a string S1 com uma nova string S2\n");
        printf("d. Concatenar a string S1 com uma nova string S2\n");
        printf("e. Imprimir a string S1 de forma reversa\n");
        printf("f. Contar quantas vezes um dado caractere aparece na string S1\n");
        printf("g. Substituir a primeira ocorrencia do caractere C1 da string S1 pelo caractere C2\n");
        printf("h. Verificar se uma string S2 e substring de S1\n");
        printf("i. Retornar uma substring da string S1\n");
        printf("s. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case 'a':
                lerString(s1);
                break;
            case 'b':
                printf("O tamanho da string S1 e: %d\n", calcularTamanho(s1));
                break;
            case 'c':
                printf("Digite a string S2: ");
                scanf("%20s", s2);
                if (compararStrings(s1, s2) == 0) {
                    printf("As strings S1 e S2 sao iguais.\n");
                } else {
                    printf("As strings S1 e S2 sao diferentes.\n");
                }
                break;
            case 'd':
                printf("Digite a string S2: ");
                scanf("%20s", s2);
                concatenarStrings(s1, s2);
                printf("A concatenacao de S1 e S2 resulta em: %s\n", s1);
                break;
            case 'e':
                printf("S1 em ordem reversa: ");
                imprimirReverso(s1);
                break;
            case 'f':
                printf("Digite o caractere a ser contado: ");
                scanf(" %c", &c1);
                printf("O caractere '%c' aparece %d vezes na string S1.\n", c1, contarCaractere(s1, c1));
                break;
            case 'g':
                printf("Digite o caractere a ser substituido: ");
                scanf(" %c", &c1);
                printf("Digite o caractere substituto: ");
                scanf(" %c", &c2);
                substituirCaractere(s1, c1, c2);
                printf("Primeira ocorrencia de '%c' substituida por '%c': %s\n", c1, c2, s1);
                break;
            case 'h':
                printf("Digite a string S2: ");
                scanf("%20s", s2);
                if (verificarSubstring(s1, s2) != -1) {
                    printf("S2 e uma substring de S1.\n");
                } else {
                    printf("S2 nao e uma substring de S1.\n");
                }
                break;
            case 'i':
                printf("Digite a posicao inicial da substring: ");
                scanf("%d", &posicao);
                printf("Digite o tamanho da substring: ");
                scanf("%d", &tamanho);
                retornarSubstring(s1, posicao, tamanho, substring);
                printf("Substring de S1 a partir da posicao %d com tamanho %d: %s\n", posicao, tamanho, substring);
                break;
            case 's':
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (escolha != 's');

    return 0;
}

//QUESTÃO 29
#include <stdio.h>

int contemDigitos(const char *str) {
    while (*str) {
        if ((*str < '0' || *str > '9') && *str != '/') { 
            return 0;
        }
        str++;
    }
    return 1; 
}

void lerData(char *data, int *dia, int *mes, int *ano) {
    int i = 0;
    while (data[i] != '\0') {
        i++;
    }

    if (i != 10) {
        printf("Formato invalido. Tamanho incorreto.\n");
        return;
    }

    if (data[2] != '/' || data[5] != '/') {
        printf("Formato invalido. Barras devem estar nos lugares corretos.\n");
        return;
    }

    *dia = (data[0] - '0') * 10 + (data[1] - '0');
    *mes = (data[3] - '0') * 10 + (data[4] - '0');
    *ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');
}

int main() {
    char data[11];
    int dia, mes, ano;

    printf("Digite a data no formato DD/MM/AAAA: ");
    scanf("%s", data);

    if (!contemDigitos(data)) {
        printf("Formato invalido. Apenas digitos sao permitidos para DD, MM e AAAA.\n");
        return 1;
    }

    lerData(data, &dia, &mes, &ano);

    printf("Dia: %d, Mes: %d, Ano: %d\n", dia, mes, ano);

    return 0;
}

//QUESTÃO 30
#include <stdio.h>
#include <string.h>

int main() {
    char nomes[5][50];
    char nomeProcurado[50];
    int totalAlunos = 0;
    char continuar;

    do {
        printf("Digite o nome do aluno: ");
        scanf("%s", nomes[totalAlunos]);
        totalAlunos++;

        if (totalAlunos < 5) {
            printf("Deseja inserir mais um nome? (S/N): ");
            scanf(" %c", &continuar);
        } else {
            printf("Voce ja inseriu o maximo de alunos.\n");
            continuar = 'N';
        }
    } while (continuar == 'S' || continuar == 's');

    while (getchar() != '\n');

    printf("Digite o nome que deseja procurar: ");
    scanf("%s", nomeProcurado);

    int encontrado = 0;
    for (int i = 0; i < totalAlunos; i++) {
        if (strstr(nomes[i], nomeProcurado) != NULL) {
            printf("Nome encontrado: %s, Indice: %d\n", nomes[i], i);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nome nao encontrado na lista.\n");
    }

    return 0;
}