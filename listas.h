#ifndef _LISTAS_
#define _LISTAS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct contacto {
    struct contacto *next, *prev;
    char *nome;
    char *user;
    char *dom;
    char *num;
} *Cont;


/* funcao length? */

Cont NEW(Cont c); /* criacao do novo contacto */
Cont novo_contacto(Cont c);
void insere_fim (Cont c); /* inserir elemento no final da lista */
void print();
void apaga(Cont c);
void freenode(Cont c);
void destroy();

#endif
