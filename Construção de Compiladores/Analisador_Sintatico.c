#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    INT, FLOAT, DOUBLE, CHAR, BOOLEAN, ID, NUM_INT, NUM_DEC, ASSIGN, SEMICOLON,
    LBRACE, RBRACE, LPAREN, RPAREN, COMMA, PLUS, MINUS, MULT, DIV, RETURN, EOF_TOKEN
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

Token tokens[1000];
int currentToken = 0;
int tokenCount = 0;

Token nextToken() {
    if (currentToken < tokenCount) {
        return tokens[currentToken++];
    }
    Token token;
    token.type = EOF_TOKEN;
    strcpy(token.lexeme, "EOF");
    return token;
}

Token peekToken() {
    if (currentToken < tokenCount) {
        return tokens[currentToken];
    }
    Token token;
    token.type = EOF_TOKEN;
    strcpy(token.lexeme, "EOF");
    return token;
}

TokenType tokenType(char *lexeme) {
    if (strcmp(lexeme, "int") == 0) return INT;
    if (strcmp(lexeme, "float") == 0) return FLOAT;
    if (strcmp(lexeme, "double") == 0) return DOUBLE;
    if (strcmp(lexeme, "char") == 0) return CHAR;
    if (strcmp(lexeme, "boolean") == 0) return BOOLEAN;
    if (strcmp(lexeme, "=") == 0) return ASSIGN;
    if (strcmp(lexeme, ";") == 0) return SEMICOLON;
    if (strcmp(lexeme, "{") == 0) return LBRACE;
    if (strcmp(lexeme, "}") == 0) return RBRACE;
    if (strcmp(lexeme, "(") == 0) return LPAREN;
    if (strcmp(lexeme, ")") == 0) return RPAREN;
    if (strcmp(lexeme, ",") == 0) return COMMA;
    if (strcmp(lexeme, "+") == 0) return PLUS;
    if (strcmp(lexeme, "-") == 0) return MINUS;
    if (strcmp(lexeme, "*") == 0) return MULT;
    if (strcmp(lexeme, "/") == 0) return DIV;
    if (strcmp(lexeme, "return") == 0) return RETURN;
    if (isdigit(lexeme[0])) return strchr(lexeme, '.') ? NUM_DEC : NUM_INT;
    return ID;
}

void tokenize(FILE *file) {
    char buffer[100];
    int index = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            continue;
        } else if (isalpha(c)) {
            buffer[index++] = c;
            while (isalnum(c = fgetc(file))) {
                buffer[index++] = c;
            }
            ungetc(c, file);
            buffer[index] = '\0';
            tokens[tokenCount].type = tokenType(buffer);
            strcpy(tokens[tokenCount++].lexeme, buffer);
            index = 0;
        } else if (isdigit(c)) {
            buffer[index++] = c;
            while (isdigit(c = fgetc(file))) {
                buffer[index++] = c;
            }
            if (c == '.') { 
                buffer[index++] = c;
                while (isdigit(c = fgetc(file))) {
                    buffer[index++] = c;
                }
            }
            ungetc(c, file);
            buffer[index] = '\0';
            tokens[tokenCount].type = tokenType(buffer);
            strcpy(tokens[tokenCount++].lexeme, buffer);
            index = 0;
        } else if (c == '=') {
            tokens[tokenCount].type = ASSIGN;
            strcpy(tokens[tokenCount++].lexeme, "=");
        } else if (c == ';') {
            tokens[tokenCount].type = SEMICOLON;
            strcpy(tokens[tokenCount++].lexeme, ";");
        } else if (c == '{') {
            tokens[tokenCount].type = LBRACE;
            strcpy(tokens[tokenCount++].lexeme, "{");
        } else if (c == '}') {
            tokens[tokenCount].type = RBRACE;
            strcpy(tokens[tokenCount++].lexeme, "}");
        } else if (c == '(') {
            tokens[tokenCount].type = LPAREN;
            strcpy(tokens[tokenCount++].lexeme, "(");
        } else if (c == ')') {
            tokens[tokenCount].type = RPAREN;
            strcpy(tokens[tokenCount++].lexeme, ")");
        } else if (c == ',') {
            tokens[tokenCount].type = COMMA;
            strcpy(tokens[tokenCount++].lexeme, ",");
        } else if (c == '+') {
            tokens[tokenCount].type = PLUS;
            strcpy(tokens[tokenCount++].lexeme, "+");
        } else if (c == '-') {
            tokens[tokenCount].type = MINUS;
            strcpy(tokens[tokenCount++].lexeme, "-");
        } else if (c == '*') {
            tokens[tokenCount].type = MULT;
            strcpy(tokens[tokenCount++].lexeme, "*");
        } else if (c == '/') {
            tokens[tokenCount].type = DIV;
            strcpy(tokens[tokenCount++].lexeme, "/");
        }
    }
}

int parseProgram();
int parseDeclaracao();
int parseFuncao();
int parseCorpoFuncao();
int parseParametros();
int parseExpressoes();
int parseExpressaoAritmetica();

int parseProgram() {
    Token token = peekToken();
    while (token.type != EOF_TOKEN) {
        if (!parseDeclaracao() && !parseFuncao()) {
            return 0;
        }
        token = peekToken();
    }
    return 1;
}

int parseDeclaracao() {
    Token token = peekToken();
    if (token.type == INT || token.type == FLOAT || token.type == DOUBLE || token.type == CHAR || token.type == BOOLEAN) {
        nextToken();
        Token lookahead = peekToken();
        if (lookahead.type == ID) {
            nextToken();
            Token next = peekToken();
            if (next.type == ASSIGN) {
                nextToken();
                if (!parseExpressaoAritmetica()) {
                    printf("Erro de sintaxe: Esperado expressão válida após '='\n");
                    return 0;
                }
            }
            next = peekToken();
            if (next.type == SEMICOLON) {
                nextToken();
                return 1;
            } else {
                printf("Erro de sintaxe: Esperado ';' apos declaracao\n");
                return 0;
            }
        } else {
            printf("Erro de sintaxe: Esperado identificador apos tipo\n");
            return 0;
        }
    } else {
        printf("Erro de sintaxe: Esperado tipo\n");
        return 0;
    }
}

int parseExpressaoAritmetica() {
    Token token = peekToken();
    if (token.type == NUM_INT || token.type == NUM_DEC || token.type == ID) {
        nextToken();
        token = peekToken();
        while (token.type == PLUS || token.type == MINUS || token.type == MULT || token.type == DIV) {
            nextToken();
            token = peekToken();
            if (token.type == NUM_INT || token.type == NUM_DEC || token.type == ID) {
                nextToken();
                token = peekToken();
            } else {
                printf("Erro de sintaxe: Esperado numero ou identificador apos operador aritmetico\n");
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int parseFuncao() {
    Token token = peekToken();
    if (token.type == INT || token.type == FLOAT || token.type == DOUBLE || token.type == CHAR || token.type == BOOLEAN) {
        nextToken();
        Token lookahead = peekToken();
        if (lookahead.type == ID) {
            nextToken();
            Token next = peekToken();
            if (next.type == LPAREN) {
                nextToken();
                parseParametros();
                next = peekToken();
                if (next.type == RPAREN) {
                    nextToken();
                    parseCorpoFuncao();
                    return 1;
                } else {
                    printf("Erro de sintaxe: Esperado ')' apos parametros da funcao\n");
                    return 0;
                }
            } else {
                printf("Erro de sintaxe: Esperado '(' apos nome da funcao\n");
                return 0;
            }
        }
    }
    return 0;
}

int parseParametros() {
    return 1;
}

int parseCorpoFuncao() {
    Token token = peekToken();
    if (token.type == LBRACE) {
        nextToken();
        while (peekToken().type != RBRACE) {
            parseDeclaracao();
            parseExpressoes();
        }
        nextToken();
        return 1;
    }
    return 0;
}

int parseExpressoes() {
    return 1;
}

int main() {
    FILE *file = fopen("tokens.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    tokenize(file);
    fclose(file);

    if (parseProgram()) {
        printf("True\n"); // Sucesso: pode criar a árvore sintática
    } else {
        printf("False\n"); // Erro: não pode criar a árvore sintática
    }

    return 0;
}
