/*
file: listas.h
autor: Susana Monteiro, 92560
descricao: funcoes auxiliares do ficheiro proj2.c 
    relativas a listas duplamente ligadas
*/

#ifndef _LISTAS_
#define _LISTAS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 4096
#define MAXNOME 1024
#define MAXEMAIL 512
#define MAXNUMERO 64
#define NUL '\0'
#define SEPARADOR " "
#define ARROBA "@"
#define FIM "\n"

typedef struct contacto {
    struct contacto *next, *prev;
    char *nome;
    char *user;
    char *dom;
    char *num;
} *LCont;


LCont NEW(); /* criacao do novo contacto */
LCont novo_contacto();
LCont cont_aux();
void insere_fim (LCont); /* inserir elemento no final da lista */
void print_lista_dup_ligada();
void l_apaga(LCont);
void freenode(LCont);
void l_destroy();
char *strdup(char*);

#endif
