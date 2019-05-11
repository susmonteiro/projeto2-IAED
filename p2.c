/*
file: proj2.c
autor: Susana Monteiro, 92560
descricao: sistema de gestao de contactos
*/

#include "p2.h"

int main() {
    char c;
    init_nomes();
    init_emails();
    for (;;) {
        c = getchar();
        getchar();  /* ignora o espaco entre o comando e o resto do input */
        switch (c) {
            case 'a':
                adiciona_evento();
                break;
            case 'l':
                lista_todos();
                break;
            case 'p':
                procura_contacto();
                break;
            /*
            case 'r':
                apaga_evento();
                break;
            case 'e':
                altera_email();
                break;
            case 'c':
                numero_dom_email();
                break;
            */
            case 'x':
                /*l_destroy();*/
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Invalid input: %d\n", c);
                return EXIT_FAILURE;
        }
    }
}

/*                            FUNCOES PRINCIPAIS                             */
void adiciona_evento() {
    Cont c = NEW();
    if (procura_nomes(c->nome) != NULL)
        printf("Nome existente.\n");
    else {
        insere_fim(c);
        insere_nomes(c);
        insere_emails(c);
    }
}

void lista_todos() {
    print();
}

void procura_contacto() {
    char nome[MAXNOME];
    Node cptr = (Node)malloc(sizeof(struct node));

    fgets(nome, MAXNOME, stdin);
    nome[strlen(nome) - 1] = NUL; /* ignorar o \n do final do input */
    if ((cptr = procura_nomes(nome)) == NULL) 
        printf("Nome inexistente.\n");
    else
        printf("%s %s@%s %s\n", cptr->c->nome, cptr->c->user, cptr->c->dom, cptr->c->num);
}

