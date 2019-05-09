#ifndef _HASH_
#define _HASH_

#include "listas.h"

#define NUMNOMES 1000
#define NUMEMAILS 1000

typedef struct node {
    struct node *next;
    Cont c;
} *Node;

void init_nomes();
void init_emails();
Node push(Node head, Cont c);
Node procura_nome(Node head, char* nome);
Node procura_email(Node head, char *email);
Node h_apaga(Node head, char *nome);
void h_destroy(Node head);

#endif