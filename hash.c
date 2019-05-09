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

Node procura_email(Node head, char *email) {
    Node aux;
    for (aux = head; aux != NULL; aux = aux->next)
        if (!strcmp(aux->c->dom, email))
            return aux;
    return NULL;
}

Node h_apaga(Node head, char* nome){
    Node aux, prev;
    for (aux = head, prev = NULL; aux != NULL; prev = aux, aux = aux->next) {
        if (!strcmp(aux->c->nome, nome)) {
            if (aux == head)
                head = aux->next;
            else
                prev->next = aux->next;
            free(aux);
        }
    }
    return head;
}

void h_destroy(Node head) {
    Node aux = NULL;
    while(head != NULL) {
        aux = head->next;
        free(head);
        head = aux;
    }
} 

int main() {
    return 0;
}