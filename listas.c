#include "listas.h"

link NEW(Contacto *c) {
    link x = (link)malloc(sizeof(struct node));
    x->contacto = c;
    x->next = NULL;
    return x;
}

link insertBegin(link head, Contacto *c) {
    link x = NEW(c);
    x->next = head;
    return x;   /* nova head */
}

link procura(link head, char *nome) {
    link t;
    for (t = head; t != NULL; t = t->next)
        if (!strcmp(t->contacto->nome,nome))
            return t;
    return NULL;
}

void print(link head) {
    link t;
    for (t = head; t != NULL; t = t->next)
        printf("something\n");
}

link apaga(link head, char *nome) {
    link t, prev;

    for(t = head, prev = NULL; t != NULL; prev = t, t = t->next) {
        if (!strcmp(t->contacto->nome,nome)) {
            if (t == head)
                head = t->next;
            else
                prev->next = t->next;
            freenode(t);            
        }
    }
    return head;
}

void freenode(link t) {
    free(t->next);
    free(t->contacto);
    free(t);
}