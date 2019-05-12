#include "hash.h"

static Node *nomes;
static Node *emails;

/* inicializacao da hashtable com os contactos organizados pelo nome */
void init_nomes() {
    int i;

    nomes = (Node*)malloc(NUMNOMES*sizeof(Node));
    for (i = 0; i < NUMNOMES; i++)
        nomes[i] = NULL;
}

/* inicializacao da hashtable com os contactos organizados 
    de acordo com o seu dominio do email*/
void init_emails() {
    int i;

    emails = (Node*)malloc(NUMEMAILS*sizeof(Node));
    for (i = 0; i < NUMEMAILS; i++)
        emails[i] = NULL;
}

Node push (Node head, Cont c) {
    Node n = (Node)malloc(sizeof(struct node));
    n->c = c;
    n->next = head;
    return n;
}

Node procura_nome(Node head, char* nome) {
    Node aux;
    for (aux = head; aux != NULL; aux = aux->next)
        if (!strcmp(aux->c->nome, nome))
            return aux;
    return NULL;
}

Node h_apaga(Node head, char* nome) {
    Node aux, prev;
    for (aux = head, prev = NULL; aux != NULL; prev = aux, aux = aux->next) {
        if (!strcmp(aux->c->nome, nome)) {
            if (aux == head) {
                head = aux->next;
            }
            else {
                prev->next = aux->next;
            }
            free(aux);
            return head;
        }
    }
    return head;
}
 
void h_destroy() {
    destroy(nomes, NUMNOMES);
    destroy(emails, NUMEMAILS);
}

void destroy(Node *head, int max) {
    int i;
    Node aux = NULL;
    for (i = 0; i < max; i++)
        while(head[i] != NULL) {
            aux = head[i]->next;
            free(head[i]);
            head[i] = aux;
    }
    free(head);
} 

/* devolve um numero gerado a partir de uma string, 
    para ser usado na funcao de dispersao*/
unsigned int djb (char *s) {
    unsigned int hash = CONST1DJB; /* CONSTANTE */
    int c;

    while ((c = *s++))
        hash = hash * CONST2DJB + c; /* CONSTANTE */
    return hash;
}

unsigned int indice_hash_nomes(char *s) {
    return (djb(s)%NUMNOMES);
}

unsigned int indice_hash_emails(char *s) {
    return (djb(s)%NUMEMAILS);
}

void insere_nomes(Cont c) {
    int i = indice_hash_nomes(c->nome);
    nomes[i] = push(nomes[i], c);
}

void insere_emails(Cont c) {
    int i = indice_hash_emails(c->dom);
    emails[i] = push(emails[i], c);
}

void apaga_nomes(char *nome) {
    int i = indice_hash_nomes(nome);
    nomes[i] = h_apaga(nomes[i], nome);
}

void apaga_emails(char *nome, char *dom) {
    int i = indice_hash_emails(dom);
    emails[i] = h_apaga(emails[i], nome);
}

Node procura_nomes(char *nome) {
    int i = indice_hash_nomes(nome);
    return procura_nome(nomes[i], nome);
}

int conta_emails(char *dom) {
    Node aux;
    int count = 0;
    int i = indice_hash_emails(dom);

    for (aux = emails[i]; aux != NULL; aux = aux->next)
        if (!strcmp(aux->c->dom, dom))
            count++;
    return count;
}