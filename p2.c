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
                adiciona_contacto();
                break;
            case 'l':
                lista_todos();
                break;
            case 'p':
                procura_contacto();
                break;
            case 'r':
                apaga_contacto();
                break;
            case 'e':
                altera_email();
                break;
            case 'c':
                numero_dom_email();
                break;
            case 'x':
                l_destroy();
                h_destroy();
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Invalid input: %d\n", c);
                return EXIT_FAILURE;
        }
    }
}

/*                            FUNCOES PRINCIPAIS                             */
void adiciona_contacto() {
    Cont c = NEW();
    if (procura_nomes(c->nome) != NULL) {
        printf("Nome existente.\n");
        freenode(c);
    }
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
    Node cptr = procura_contacto_aux();

    if (cptr)
        printf("%s %s@%s %s\n", cptr->c->nome, cptr->c->user, cptr->c->dom, cptr->c->num);
}

Node procura_contacto_aux() {
    char nome[MAXNOME];

    fgets(nome, MAXNOME, stdin);
    nome[strlen(nome) - 1] = NUL; /* ignorar o \n do final do input */
    return itera_contactos(nome);
}

Node itera_contactos(char *nome) {
    Node cptr;

    if ((cptr = procura_nomes(nome)) == NULL) 
        printf("Nome inexistente.\n");
    return cptr;
}

void apaga_contacto() {
    Node cptr = procura_contacto_aux();
    Cont c;

    if (!cptr) return;
    c = cptr->c;
    apaga_emails(cptr->c->nome, cptr->c->dom);
    apaga_nomes(cptr->c->nome);
    l_apaga(c);
}

void altera_email() {
    char buffer[MAXCHAR]; 
    char *nome, *user, *dom;
    Node aux;

    fgets(buffer, MAXCHAR, stdin);
    nome = strtok(buffer, SEPARADOR);
    user = strtok(NULL, ARROBA);
    dom = strtok(NULL, FIM);
    if ((aux = itera_contactos(nome)) != NULL) {
        apaga_emails(aux->c->nome, aux->c->dom);
        aux->c->user = (char*)realloc(aux->c->user, sizeof(char)*(strlen(user)+1));
        strcpy(aux->c->user, user);
        aux->c->dom = (char*)realloc(aux->c->dom, sizeof(char)*(strlen(dom)+1));
        strcpy(aux->c->dom, dom);
        insere_emails(aux->c);
    }  
}

void numero_dom_email() {
    char dom[MAXEMAIL];

    fgets(dom, MAXEMAIL, stdin);
    dom[strlen(dom) - 1] = NUL;  /* ignorar o \n do final do input */
    printf("%s:%d\n", dom, conta_emails(dom));
}
