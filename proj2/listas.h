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

#define MAXCHAR 4096    /* numero maximo de caracteres de input */   
#define MAXNOME 1024    /* numero maximo de caracteres para o nome */
#define MAXEMAIL 512    /* numero maximo de caracteres do username e dominio do email*/
#define MAXNUMERO 64    /* numero maximo de caracteres do numero do contacto */
#define NUL '\0'        /* null character */
#define SEPARADOR " "   /* caracter que separa as informacoes */ 
#define ARROBA "@"      /* caracter que separa o username do dominio do email */
#define FIM "\n"        /* final de um input */

/* estrutura que guarda as informacoes acerca do contacto na lista duplamente ligada*/
typedef struct contacto {
    struct contacto *next, *prev;
    char *nome;
    char *user;
    char *dom;
    char *num;
} *LCont;


LCont NEW();
LCont novo_contacto();
LCont cont_aux();
void insere_fim (LCont);
void print_lista_dup_ligada();
void l_apaga(LCont);
void freenode(LCont);
void l_destroy();
char *duplica_str(char*);

#endif
