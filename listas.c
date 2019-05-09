#include "listas.h"

static Cont head;
static Cont tail;

Cont NEW(Cont c) {
    Cont x = novo_contacto(c);
    x->next = NULL;
    x->prev = NULL;
    return x;
}

Cont novo_contacto(Cont c) {
    Cont t = (Cont)malloc(sizeof(struct contacto));
    t->nome = (char*)malloc(sizeof(char)*(strlen(c->nome)+1));
    strcpy(t->nome, c->nome);
    t->user = (char*)malloc(sizeof(char)*(strlen(c->user)+1));
    strcpy(t->user, c->user);
    t->dom = (char*)malloc(sizeof(char)*(strlen(c->dom)+1));
    strcpy(t->dom, c->dom);
    t->num = (char*)malloc(sizeof(char)*(strlen(c->num)+1));
    strcpy(t->num, c->num);
    return t;
}

/*Cont insere_inicio(Cont head, Contacto *c) {
    Cont x = NEW(c);
    x->next = head;
    head->prev = x;
    return x;    nova head 
}*/

void insere_fim(Cont c) {
    Cont x = NEW(c);
    x->prev = tail;
    if (tail != NULL)
        tail->next = x;
    else
        head = x;
    tail = x;   /* nova tail */
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
        printf("something\n");
}

void l_apaga(Cont c) {
    if (c == head) {
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
        freenode(c);
        head = c;
    }
}

int main() {
    return 0;
}