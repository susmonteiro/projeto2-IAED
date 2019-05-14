#include "listas.h"

static Cont head = NULL;
static Cont tail = NULL;

Cont NEW() {
    Cont c = novo_contacto();
    c->next = NULL;
    c->prev = NULL;
    return c;
}

Cont novo_contacto() {
    char buffer[MAXCHAR];
    char *token;
    Cont c = (Cont)malloc(sizeof(struct contacto));

    fgets(buffer, MAXCHAR, stdin);
    token = strtok(buffer, SEPARADOR);
    c->nome = (char*)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(c->nome, token);
    token = strtok(NULL, ARROBA);
    c->user = (char*)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(c->user, token);
    token = strtok(NULL, SEPARADOR);
    c->dom = (char*)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(c->dom, token);
    token = strtok(NULL, FIM);
    c->num = (char*)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(c->num, token);
    return c;
}

/*Cont insere_inicio(Cont head, Contacto *c) {
    Cont x = NEW(c);
    x->next = head;
    head->prev = x;
    return x;    nova head 
}*/

void insere_fim(Cont c) {
    c->prev = tail;
    if (tail != NULL)
        tail->next = c;
    else
        head = c;
    tail = c;   /* nova tail */
}

/*Cont procura(Cont head, char *nome) {
    Cont t;
    for (t = head; t != NULL; t = t->next)
        if (!strcmp(t->contacto->nome,nome))
            return t;
    return NULL;
}
*/

void print() {
    Cont t;
    for (t = head; t != NULL; t = t->next)
        printf("%s %s@%s %s\n", t->nome, t->user, t->dom, t->num);
}

void l_apaga(Cont c) {
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else if (c == head) {
        head = c->next;
        head->prev = NULL;
    } else if (c == tail) {
        tail = c->prev;
        tail->next = NULL;
    } else {
        c->prev->next = c->next;
        c->next->prev = c->prev;
    }
    freenode(c);            
}

void freenode(Cont c) {
    free(c->nome);
    free(c->user);
    free(c->dom);
    free(c->num);
    free(c);
}

void l_destroy() {
    Cont c = NULL;
    while (head != NULL) {
        c = head->next;
        freenode(head);
        head = c;
    }
}