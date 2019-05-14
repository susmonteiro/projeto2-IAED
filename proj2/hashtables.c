#include "hash.h"

static HCont *nomes;
static HCont *emails;

/* inicializacao da hashtable com os contactos organizados pelo nome */
void init_nomes() {
    int i;

    nomes = (HCont*)malloc(NUMELEMS*sizeof(HCont));
    for (i = 0; i < NUMELEMS; i++)
        nomes[i] = NULL;
}

/* inicializacao da hashtable com os contactos organizados 
    de acordo com o seu dominio do email */
void init_emails() {
    int i;

    emails = (HCont*)malloc(NUMELEMS*sizeof(HCont));
    for (i = 0; i < NUMELEMS; i++)
        emails[i] = NULL;
}

HCont push (HCont head, LCont c) {
    HCont n = (HCont)malloc(sizeof(struct hcont));
    n->c = c;
    n->next = head;
    return n;
}

HCont procura_nome(HCont head, char* nome) {
    HCont aux;
    for (aux = head; aux != NULL; aux = aux->next)
        if (!strcmp(aux->c->nome, nome))
            return aux;
    return NULL;
}

HCont h_apaga(HCont head, char* nome) {
    HCont aux, prev;
    for (aux = head, prev = NULL; aux != NULL; prev = aux, aux = aux->next) {
        if (!strcmp(aux->c->nome, nome)) {
            if (aux == head)
                head = aux->next;
            else
                prev->next = aux->next;
            free(aux);
            return head;
        }
    }
    return head;
}
 
void h_destroy() {
    destroy(nomes, NUMELEMS);
    destroy(emails, NUMELEMS);
}

void destroy(HCont *head, int max) {
    int i;
    HCont aux = NULL;
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
    unsigned int hash = CONST1DJB;
    int c;

    while ((c = *s++))
        hash = hash * CONST2DJB + c; 
    return hash;
}

void insere_nomes(LCont c) {
    int i = indice_hash(djb(c->nome));
    nomes[i] = push(nomes[i], c);
}

void insere_emails(LCont c) {
    int i = indice_hash(djb(c->dom));
    emails[i] = push(emails[i], c);
}

void apaga_nomes(char *nome) {
    int i = indice_hash(djb(nome));
    nomes[i] = h_apaga(nomes[i], nome);
}

void apaga_emails(char *nome, char *dom) {
    int i = indice_hash(djb(dom));
    emails[i] = h_apaga(emails[i], nome);
}

HCont procura_nomes(char *nome) {
    int i = indice_hash(djb(nome));;
    return procura_nome(nomes[i], nome);
}

int conta_emails(char *dom) {
    HCont aux;
    int count = 0;
    int i = indice_hash(djb(dom));;

    for (aux = emails[i]; aux != NULL; aux = aux->next)
        if (!strcmp(aux->c->dom, dom))
            count++;
    return count;
}