#include <stdio.h>
#include <string.h>

/* Helper functions (no <ctype.h>) */

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c == '_');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int isWhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

/* Check if a string is a keyword */
int isKeyword(char token[]) {
    int len = strlen(token);

    if (len == 2 && token[0] == 'i' && token[1] == 'f') return 1;
    if (len == 3 && token[0] == 'i' && token[1] == 'n' && token[2] == 't') return 1;
    if (len == 4 && token[0] == 'c' && token[1] == 'h' && token[2] == 'a' && token[3] == 'r') return 1;
    if (len == 4 && token[0] == 'e' && token[1] == 'l' && token[2] == 's' && token[3] == 'e') return 1;
    if (len == 5 && token[0] == 'w' && token[1] == 'h' && token[2] == 'i' && token[3] == 'l' && token[4] == 'e') return 1;
    if (len == 5 && token[0] == 'f' && token[1] == 'l' && token[2] == 'o' && token[3] == 'a' && token[4] == 't') return 1;
    if (len == 6 && token[0] == 'r' && token[1] == 'e' && token[2] == 't' &&
        token[3] == 'u' && token[4] == 'r' && token[5] == 'n') return 1;

    return 0;
}

/* Check operators */
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

/* Check punctuation */
int isPunctuation(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' ||
            c == ';' || c == ',');
}

int main() {
    char c;
    char token[256];
    int idx = 0;

    while ((c = getchar()) != EOF) {

        /* Ignore whitespace */
        if (isWhitespace(c)) {
            if (idx > 0) {
                token[idx] = '\0';

                if (isKeyword(token))
                    printf("<KEYWORD, %s>\n", token);
                else if (isLetter(token[0]))
                    printf("<IDENTIFIER, %s>\n", token);
                else
                    printf("<NUMBER, %s>\n", token);

                idx = 0;
            }
            continue;
        }

        /* Letter or digit → build token */
        if (isLetter(c) || isDigit(c)) {
            token[idx++] = c;
            continue;
        }

        /* End current token before special char */
        if (idx > 0) {
            token[idx] = '\0';

            if (isKeyword(token))
                printf("<KEYWORD, %s>\n", token);
            else if (isLetter(token[0]))
                printf("<IDENTIFIER, %s>\n", token);
            else
                printf("<NUMBER, %s>\n", token);

            idx = 0;
        }

        /* Operator */
        if (isOperator(c)) {
            printf("<OPERATOR, %c>\n", c);
        }
        /* Punctuation */
        else if (isPunctuation(c)) {
            printf("<PUNCTUATION, %c>\n", c);
        }
        /* Unknown */
        else {
            printf("<UNKNOWN, %c>\n", c);
        }
    }

    /* Flush remaining token at EOF */
    if (idx > 0) {
        token[idx] = '\0';

        if (isKeyword(token))
            printf("<KEYWORD, %s>\n", token);
        else if (isLetter(token[0]))
            printf("<IDENTIFIER, %s>\n", token);
        else
            printf("<NUMBER, %s>\n", token);
    }

    return 0;
}
