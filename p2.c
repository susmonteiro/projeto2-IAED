/*
file: proj2.c
autor: Susana Monteiro, 92560
descricao: sistema de gestao de contactos
*/

#include "p2.h"

int main() {
    char c;
    for (;;) {
        c = getchar();
        getchar();  /* ignora o espaco entre o comando e o resto do input */
        switch (c) {
            case 'a':
                adiciona_evento();
                break;
            /*case 'l':
                lista_todos();
                break;
            case 'p':
                procura_evento();
                break;
            case 'r':
                apaga_evento();
                break;
            case 'e':
                altera_email();
                break;
            case 'c':
                numero_dom_email();
                break;
            case 'x':
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Invalid input: %d\n", c);
                return EXIT_FAILURE; */
        }
    }
}

/*                            FUNCOES PRINCIPAIS                             */
void adiciona_evento() {
    Contacto *c;

    cria_contacto(c);
}

void cria_contacto(Contacto *c) {
    char buffer[MAXCHAR];
    char *token;

    fgets(buffer, MAXCHAR, stdin);
    buffer[strlen(buffer) - 1] = NUL;   /* ignorar o \n do final do input */
    token = strtok(buffer, SEPARADOR);
    strcpy(c->nome, token);
    token = strtok(NULL, ARROBA);
    strcpy(c->local, token);
    token = strtok(NULL, SEPARADOR);
    strcpy(c->dominio, token);
    token = strtok(NULL, token);
    strcpy(c->numero, token);
}

