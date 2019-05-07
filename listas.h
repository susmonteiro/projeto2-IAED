#include <stdio.h>
#include "contactos.h"

typedef struct node {
    Contacto *contacto;
    struct node *next;
} *link;

/* funcao length? */

link NEW(Contacto *c); /* alocacao de memoria para o novo no*/
link insertBegin (link head, Contacto *c);
link procura(link head, char *nome);
void print(link head);
link apaga(link head, char *nome);
void freenode(link t);
