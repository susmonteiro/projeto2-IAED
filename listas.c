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
    c->nome = strdup(token);
    token = strtok(NULL, ARROBA);
    c->user = strdup(token);
    token = strtok(NULL, SEPARADOR);
    c->dom = strdup(token);
    token = strtok(NULL, FIM);
    c->num = strdup(token);
    return c;
}

void insere_fim(Cont c) {
    c->prev = tail;
    if (tail != NULL)
        tail->next = c;
    else
        head = c;
    tail = c;               /* nova tail */
}

void lista_todos() {
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

char *strdup(char *s) {
    char *ptr;

    ptr = (char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(ptr,s);
    return ptr;
}