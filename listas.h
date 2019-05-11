#ifndef _LISTAS_
#define _LISTAS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 2048
#define MAXNOME 1024
#define MAXEMAIL 512
#define MAXNUMERO 64
#define NUL '\0'
#define SEPARADOR " "
#define ARROBA "@"

typedef struct contacto {
    struct contacto *next, *prev;
    char *nome;
    char *user;
    char *dom;
    char *num;
} *Cont;


/* funcao length? */

Cont NEW(); /* criacao do novo contacto */
Cont novo_contacto();
Cont cont_aux();
void insere_fim (Cont c); /* inserir elemento no final da lista */
void print();
void l_apaga(Cont c);
void freenode(Cont c);
void l_destroy();

#endif
