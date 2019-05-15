/*
file: hashtables.c
autor: Susana Monteiro, 92560
data: 17/05/2019
descricao: funcoes auxiliares das hash tables que organizam os contactos por
    nome e dominio de email, bem como as funcoes das listas simplesmente ligadas, 
    utilizadas na implementacao das hash tables 
*/

#include "hashtables.h"

/* As duas hash tables (uma que organiza os contactos por nome e outra que os
organiza pelo dominio do email) sao globais e visiveis apenas dentro deste ficheiro */
static HCont *nomes;
static HCont *emails;


/*          FUNCOES DE MANIPULACAO DAS LISTAS SIMPLESMENTE LIGADAS            */

/* inicializacao da hashtable com os contactos organizados pelo nome 
nao tem parametros de entrada nem de saida */
void init_nomes() {
    int i;

    nomes = (HCont*)malloc(NUMELEMS*sizeof(HCont));
    for (i = 0; i < NUMELEMS; i++)
        nomes[i] = NULL;
}

/* inicializacao da hashtable com os contactos organizados 
    de acordo com o seu dominio do email 
nao tem parametros de entrada nem de saida */
void init_emails() {
    int i;

    emails = (HCont*)malloc(NUMELEMS*sizeof(HCont));
    for (i = 0; i < NUMELEMS; i++)
        emails[i] = NULL;
}

/* introduz novo elemento no topo da respetiva lista 
recebe o ponteiro para o topo da lista e o contacto a inserir, retorna um 
ponteiro para o novo topo da lista */
HCont push (HCont head, LCont c) {
    HCont n = (HCont)malloc(sizeof(struct hcont));
    n->c = c;
    n->next = head;
    return n;
}

/* percorre a lista ate encontrar um contacto com o nome especificado 
recebe um ponteiro para o topo da lista e o nome a encontrar.
Se encontrar o contacto retorna um ponteiro para ele, em caso contrario devolve NULL */
HCont procura(HCont head, char* nome) {
    HCont aux;
    for (aux = head; aux != NULL; aux = aux->next)
        if (!strcmp(aux->c->nome, nome))
            return aux;
    return NULL;
}

/* apaga, com procura, um no da lista 
recebe um ponteiro para o topo da lista e o nome do contacto a remover, 
devolve o novo topo da lista */
HCont h_apaga(HCont head, char* nome) {
    HCont aux, prev;    
    /* como a lista e simplesmente ligada, e necessario guardar o endereco do 
    elemento anterior aquele que vai ser apagado (prev) */
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
 

/*              FUNCOES DE MANIPULACAO DAS HASH TABLES                        */

/* funcao de dispersao 
recebe uma string e devolve um numero gerado a partir dela */
unsigned int djb (char *s) {
    unsigned int hash = CONST1DJB;
    int c;

    while ((c = *s++))
        hash = hash * CONST2DJB + c; 
    return hash;
}

/* insere um contacto no topo da hash table dos nomes
recebe um ponteiro para o contacto e nao devolve nada */
void insere_nome(LCont c) {
    int i = indice_hash(djb(c->nome));
    nomes[i] = push(nomes[i], c);
}

/* insere um contacto no topo da hash table dos emails
recebe um ponteiro para o contacto e nao devolve nada */
void insere_email(LCont c) {
    int i = indice_hash(djb(c->dom));
    emails[i] = push(emails[i], c);
}

/* apaga um contacto da hash table dos nomes 
recebe o nome do contacto e nao devolve nada */
void apaga_nomes(char *nome) {
    int i = indice_hash(djb(nome));
    nomes[i] = h_apaga(nomes[i], nome);
}

/* apaga um contacto da hash table dos emails 
recebe o nome do contacto e o dominio e nao devolve nada */
void apaga_emails(char *nome, char *dom) {
    int i = indice_hash(djb(dom));
    emails[i] = h_apaga(emails[i], nome);
}

/* procura um contacto com um determinado nome na hash table dos nomes 
recebe o nome do contacto e devolve o contacto com o nome do parametro de entrada */
HCont procura_nomes(char *nome) {
    int i = indice_hash(djb(nome));;
    return procura(nomes[i], nome);
}

/* conta o numero de contactos com o dominio dom 
recebe o dominio em causa e devolve o numero de ocorrencias */
int conta_emails(char *dom) {
    HCont aux;
    int count = 0;
    int i = indice_hash(djb(dom));;

    for (aux = emails[i]; aux != NULL; aux = aux->next)
        if (!strcmp(aux->c->dom, dom))
            count++;
    return count;
}

/*  destroi as duas hash tables, libertando toda a memoria alocada 
nao tem parametros de entrada nem de saida*/
void h_destroy() {
    destroy(nomes);
    destroy(emails);
}

/* destroi todas as listas da hash table dada como parametro de entrada 
recebe um ponteiro para a hash table a destruir e nao devolve nada */
void destroy(HCont *head) {
    int i;
    HCont aux = NULL;
    for (i = 0; i < NUMELEMS; i++)
        while(head[i] != NULL) {
            aux = head[i]->next;
            free(head[i]);
            head[i] = aux;
    }
    free(head);
} 