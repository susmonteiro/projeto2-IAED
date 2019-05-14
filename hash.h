#ifndef _HASH_
#define _HASH_

#include "listas.h"

#define NUMELEMS 511
#define CONST1DJB 5381
#define CONST2DJB 33

#define indice_hash(s) s%NUMELEMS


typedef struct node {
    struct node *next;
    Cont c;
} *Node;

void init_nomes();
void init_emails();
Node push(Node head, Cont c);
Node procura_nome(Node head, char* nome);
Node h_apaga(Node head, char* nome);
void h_destroy();
void destroy(Node *head, int max);
unsigned int djb(char *s);
void insere_nomes(Cont c);
void insere_emails(Cont c);
void apaga_nomes(char *nome);
void apaga_emails(char *nome, char *emails);
Node procura_nomes(char *nome);
int conta_emails(char *dom);

#endif