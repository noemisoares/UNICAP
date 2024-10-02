#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para token
typedef struct token {
    char tipo[20];
    char valor[100];
    struct token *prox;
} Token;

// Estrutura para símbolo na tabela de símbolos
typedef struct simbolo {
    char id[100];
    int posicao;
    struct simbolo *next;
} Simbolo;

// Verifica se o lexema é uma biblioteca
int biblioteca(char *lexema) {
    char *bibliotecas[] = {"stdio.h", "stdlib.h", "string.h"};
    for (int i = 0; i < 3; i++) {
        if (strcmp(lexema, bibliotecas[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Verifica se o lexema é um número inteiro D+
int numero_inteiro(char *lexema) {
    for (int i = 0; lexema[i] != '\0'; i++) {
        if (lexema[i] < '0' || lexema[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Verifica se o lexema é um número decimal D+\.D+
int numero_decimal(char *lexema) {
    int ponto_encontrado = 0;

    for (int i = 0; lexema[i] != '\0'; i++) {
        if (lexema[i] == '.') {
            if (ponto_encontrado) {
                return 0;
            }
            ponto_encontrado = 1;
        } else if (lexema[i] < '0' || lexema[i] > '9') {
            return 0;
        }
    }
    return ponto_encontrado;
}

// Verifica se o lexema é uma palavra reservada
int palavra_reservada(char *lexema) {
    char *palavras_reservadas[] = {"int", "float", "char", "boolean", "void", "if", "else", "for", "while", "scanf", "println", "printf", "main", "return", "include"};
    for (int i = 0; i < 15; i++) {
        if (strcmp(lexema, palavras_reservadas[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Verifica se o lexema é um identificador L(L|D)*
int identificador(char *lexema) {
    if (!((lexema[0] >= 'A' && lexema[0] <= 'Z') || (lexema[0] >= 'a' && lexema[0] <= 'z'))) {
        return 0;
    }
    for (int i = 1; lexema[i] != '\0'; i++) {
        if (!(((lexema[i] >= 'A' && lexema[i] <= 'Z') || (lexema[i] >= 'a' && lexema[i] <= 'z')) || (lexema[i] >= '0' && lexema[i] <= '9'))) {
            return 0;
        }
    }
    return 1;
}

// Verifica se o lexema é uma constante de texto ".*"
int constante_texto(char *lexema) {
    return lexema[0] == '"' && lexema[strlen(lexema) - 1] == '"';
}

// Verifica se o lexema é um comentário \\.
int comentario(char *lexema) {
    return (lexema[0] == '/' && lexema[1] == '/');
}

// Verifica se o caractere é um símbolo especial
int simbolo_especial(char lexema) {
    char simbolos[] = {'(', ')', '{', '}', '[', ']', ';', ',', '.', '#'};
    for (int i = 0; i < 10; i++) {
        if (lexema == simbolos[i]) return 1;
    }
    return 0;
}

// Função para verificar se o lexema é um operador de comparação
int operador_comparacao(char *lexema) {
    char *simbolos[] = {"==", ">=", "<=", ">", "<", "!="};
    for (int i = 0; i < 6; i++) {
        if (strcmp(lexema, simbolos[i]) == 0) return 1;
    }
    return 0;
}

// Função para verificar se o lexema é um operador lógico
int operador_logico(char *lexema) {
    char *simbolos[] = {"&&", "||", "!"};
    for (int i = 0; i < 3; i++) {
        if (strcmp(lexema, simbolos[i]) == 0) return 1;
    }
    return 0;
}

// Função para verificar se o lexema é um operador aritmético
int operador_aritmetico(char lexema) {
    char simbolos[] = {'+', '-', '*', '/', '%'};
    for (int i = 0; i < 5; i++) {
        if (lexema == simbolos[i]) return 1;
    }
    return 0;
}

// Função para verificar se o lexema é um operador de atribuição
int operador_atribuicao(char lexema) {
    return lexema == '=';
}

// Função para adicionar um token à lista de tokens
void add_token(Token **head, char *tipo, char *valor) {
    Token *novo_token = (Token *)malloc(sizeof(Token));
    strcpy(novo_token->tipo, tipo);  // Copia o tipo para o novo token
    strcpy(novo_token->valor, valor);  // Copia o valor para o novo token
    novo_token->prox = NULL;

    // Se a lista estiver vazia, o novo token será o primeiro
    if (*head == NULL) {
        *head = novo_token;
    } else {
        Token *temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;  // Navega até o final da lista
        }
        temp->prox = novo_token;  // Adiciona o novo token no final da lista
    }
}

// Função para adicionar um símbolo à tabela de símbolos
void add_simbolo(Simbolo **head, char *id) {
    Simbolo *temp = *head;

    // Verifica se o símbolo já existe na tabela
    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0) {
            return;  // Não adiciona duplicatas
        }
        temp = temp->next;
    }

    Simbolo *novo_simbolo = (Simbolo *)malloc(sizeof(Simbolo));
    strcpy(novo_simbolo->id, id);  // Copia o identificador para o novo símbolo

    // Calcula a posição do novo símbolo
    int posicao = 1;
    temp = *head;
    while (temp != NULL) {
        posicao++;
        temp = temp->next;
    }
    novo_simbolo->posicao = posicao;
    novo_simbolo->next = NULL;

    // Adiciona o novo símbolo no final da lista
    if (*head == NULL) {
        *head = novo_simbolo;
    } else {
        Simbolo *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = novo_simbolo;
    }
}

// Função que processa o lexema e adiciona o token ou símbolo correspondente
void processar_lexema(char *lexema, Token **tokens, Simbolo **simbolos) {
    // Verifica o tipo de lexema e adiciona o token correspondente
    if (palavra_reservada(lexema)) {
        add_token(tokens, "Reservado", lexema);
    } else if (identificador(lexema)) {
        add_token(tokens, "Identificador", lexema);
        add_simbolo(simbolos, lexema);  // Adiciona o identificador à tabela de símbolos
    } else if (numero_inteiro(lexema)) {
        add_token(tokens, "Inteiro", lexema);
    } else if (numero_decimal(lexema)) {
        add_token(tokens, "Decimal", lexema);
    } else if (constante_texto(lexema)) {
        add_token(tokens, "Literal", lexema);
    } else if (comentario(lexema)) {
        add_token(tokens, "Comentario", lexema);
    } else if (operador_comparacao(lexema)) {
        add_token(tokens, "Comparacao", lexema);
    } else if (operador_logico(lexema)) {
        add_token(tokens, "Logico", lexema);
    } else if (operador_aritmetico(lexema[0])) {
        add_token(tokens, "Aritmetico", lexema);
    } else if (operador_atribuicao(lexema[0])) {
        add_token(tokens, "Atribuicao", lexema);
    } else if (simbolo_especial(lexema[0])) {
        add_token(tokens, "Especial", lexema);
    } else if (biblioteca(lexema)) {
        add_token(tokens, "Biblioteca", lexema);
    }
}

// Função analisar as linhas para processar a linha e atualizar a lista de tokens e tabela de símbolos
void analisar_linha(char *linha, Token **tokens, Simbolo **simbolos) {
    char lexema[100];
    int i = 0, j = 0;

    while (linha[i] != '\0') {
        char c = linha[i];

        // Ignora espaços em branco
        if (c == ' ' || c == '\t') {
            if (j > 0) {
                lexema[j] = '\0';
                processar_lexema(lexema, tokens, simbolos);
                j = 0;
            }
        }
        // Captura comentários
        else if (c == '/' && linha[i + 1] == '/') {
            if (j > 0) {
                lexema[j] = '\0';
                processar_lexema(lexema, tokens, simbolos);
                j = 0;
            }
            i += 2;
            while (linha[i] != '\n' && linha[i] != '\0') {
                lexema[j++] = linha[i++];
            }
            lexema[j] = '\0';
            add_token(tokens, "Comentario", lexema);
            j = 0;
            continue;
        }
        // Captura literais (aspas duplas e simples)
        else if (c == '"' || c == '\'') {
            if (j > 0) {
                lexema[j] = '\0';
                processar_lexema(lexema, tokens, simbolos);
                j = 0;
            }
            lexema[j++] = c;
            i++;
            while (linha[i] != c && linha[i] != '\0') {
                lexema[j++] = linha[i++];
            }
            if (linha[i] == c) {
                lexema[j++] = linha[i];
                lexema[j] = '\0';
                add_token(tokens, "Literal", lexema);
                j = 0;
            }
        }
        // Captura bibliotecas no formato <biblioteca>
        else if (c == '<') {
            if (j > 0) {
                lexema[j] = '\0';
                processar_lexema(lexema, tokens, simbolos);
                j = 0;
            }
            
            // Adiciona o símbolo de abertura
            add_token(tokens, "Comparacao", "<");
            i++;
            
            // Captura o nome da biblioteca ou número
            while (linha[i] != '>' && linha[i] != '\0' && linha[i] != ' ' && linha[i] != '\t') {
                lexema[j++] = linha[i++];
            }

            // Processa a biblioteca ou número caso tenha encontrado o símbolo de fechamento
            if (linha[i] == '>') {
                lexema[j] = '\0'; // Finaliza o nome da biblioteca ou número
                add_token(tokens, "Biblioteca", lexema); // Adiciona o nome da biblioteca ou número
                add_token(tokens, "Comparacao", ">"); // Adiciona o símbolo de fechamento
                j = 0;
            }
        }
        // Captura operadores de comparação
        else if (c == '>' || c == '<') {
            if (j > 0) {
                lexema[j] = '\0';
                processar_lexema(lexema, tokens, simbolos);
                j = 0;
            }
            lexema[j++] = c; // Adiciona o operador
            i++;
            if (c == '>') {
                // Verifica se é '>=', se próximo caractere for '='
                if (linha[i] == '=') {
                    lexema[j++] = linha[i++];
                }
            } else if (c == '<') {
                // Verifica se é '<=', se próximo caractere for '='
                if (linha[i] == '=') {
                    lexema[j++] = linha[i++];
                }
            }
            lexema[j] = '\0';
            add_token(tokens, "Comparacao", lexema);
            j = 0;
            continue;
        }
        // Captura `==` e `=` 
        else if (c == '=') {
            if (j > 0) {
                lexema[j] = '\0';
                processar_lexema(lexema, tokens, simbolos);
                j = 0;
            }
            lexema[j++] = c;
            i++;
            if (linha[i] == '=') {
                lexema[j++] = linha[i];
                i++;
                lexema[j] = '\0';
                add_token(tokens, "Comparacao", lexema); // Adiciona `==` como comparação
            } else {
                lexema[j] = '\0';
                add_token(tokens, "Atribuicao", lexema); // Adiciona `=` como atribuição
            }
            j = 0;
            continue;
        }
        // Captura números inteiros e decimais
        else if (c >= '0' && c <= '9') {
            lexema[j++] = c;
            i++;
            int eh_decimal = 0;
            while ((linha[i] >= '0' && linha[i] <= '9') || (linha[i] == '.' && !eh_decimal)) {
                if (linha[i] == '.') {
                    eh_decimal = 1;
                }
                lexema[j++] = linha[i++];
            }
            lexema[j] = '\0';
            add_token(tokens, eh_decimal ? "Decimal" : "Inteiro", lexema);
            j = 0;
            continue;
        }
        // Ignora caracteres especiais e operadores aritméticos
        else if (simbolo_especial(c) || operador_aritmetico(c)) {
            if (j > 0) {
                lexema[j] = '\0';
                processar_lexema(lexema, tokens, simbolos);
                j = 0;
            }
            lexema[j++] = c;
            lexema[j] = '\0';
            processar_lexema(lexema, tokens, simbolos);
            j = 0;
        } else {
            lexema[j++] = c;
        }
        i++;
    }

    // Processa o último lexema, se houver
    if (j > 0) {
        lexema[j] = '\0';
        processar_lexema(lexema, tokens, simbolos);
    }
}

// Função para imprimir a lista de tokens
void print_tokens(Token *head, Simbolo *simbolos) {
    Token *temp = head; // Ponteiro temporário
    
    printf("Lista de Tokens:\n");
    printf("%-20s %-30s\n", "Tipo", "Token");
    printf("-------------------------------\n");

    // Percorre a lista de tokens
    while (temp != NULL) {
        // Se o token for um identificador, procura na tabela de símbolos sua posição
        if (strcmp(temp->tipo, "Identificador") == 0) {
            Simbolo *s = simbolos;
            while (s != NULL) {
                if (strcmp(s->id, temp->valor) == 0) {
                    printf("%-20s (ID, %d)\n", temp->tipo, s->posicao);
                    break;
                }
                s = s->next;
            }
        }
        // Se for um número inteiro ou decimal, imprime com a tag correspondente
        else if (strcmp(temp->tipo, "Inteiro") == 0 || strcmp(temp->tipo, "Decimal") == 0) {
            if (strcmp(temp->tipo, "Decimal") == 0) {
                printf("%-20s (NUM, %s)\n", "Decimal", temp->valor);
            } else {
                printf("%-20s (NUM, %s)\n", "Inteiro", temp->valor);
            }
        }
        // Se for um literal (string), imprime com a tag "literal"
        else if (strcmp(temp->tipo, "Literal") == 0) {
            printf("%-20s (literal, %s)\n", temp->tipo, temp->valor);
        }
        // Se for um operador de comparação, imprime com a tag "COMP"
        else if (strcmp(temp->tipo, "Comparacao") == 0) {
            printf("%-20s (COMP, %s)\n", temp->tipo, temp->valor);
        }
        // Se for um comentário, imprime com "//" como prefixo
        else if (strcmp(temp->tipo, "Comentario") == 0) {
            printf("%-20s //%s\n", temp->tipo, temp->valor);
        }
        // Para outros tipos de tokens, imprime diretamente
        else {
            printf("%-20s %-30s\n", temp->tipo, temp->valor); 
        }
        temp = temp->prox;
    }
    printf("-------------------------------\n");
}

// Função para imprimir a tabela de símbolos com seus identificadores e posições
void print_simbolos(Simbolo *head) {
    Simbolo *temp = head; // Ponteiro temporário para percorrer a lista de símbolos
    
    printf("Tabela de Simbolos:\n");
    printf("%-5s %-20s\n", "Posicao", "ID");
    printf("------------------------------\n");
    
    // Percorre a lista de símbolos e imprime a posição e o identificador de cada símbolo
    while (temp != NULL) {
        printf("%-5d %-20s\n", temp->posicao, temp->id);
        temp = temp->next;
    }
    printf("------------------------------\n");
}

// Função principal que realiza a análise do arquivo
void analisador(FILE *arquivo) {
    char linha[1024]; // Armazenar uma linha do arquivo
    Token *lista_token = NULL; // Ponteiro para a lista de tokens
    Simbolo *tabela_simbolo = NULL; // Ponteiro para a tabela de símbolos

    // Lê cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Chama a função 'analisar_linha' para processar a linha e atualizar a lista de tokens e tabela de símbolos
        analisar_linha(linha, &lista_token, &tabela_simbolo);
    }

    // Após ler todas as linhas, imprime a lista de tokens e a tabela de símbolos
    print_tokens(lista_token, tabela_simbolo);
    print_simbolos(tabela_simbolo);
}

// Função principal que inicia a execução do programa
int main() {
    // Abre o arquivo "index.c" no modo de leitura
    FILE *arquivo = fopen("index.c", "r");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        // Se não for possível abrir o arquivo, exibe uma mensagem de erro e encerra o programa
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Chama a função analisador para processar o arquivo
    analisador(arquivo);
    // Fecha o arquivo após a análise
    fclose(arquivo);

    return 0;
}