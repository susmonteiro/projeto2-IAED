/*
file: listas.c
autor: Susana Monteiro, 92560
data: 17/05/2019
descricao: funcoes auxiliares do ficheiro proj2.c 
    relativas a listas duplamente ligadas
*/

#include "listas.h"

/* Neste ficheiro, grande parte das funcoes utiliza a head e/ou a tail da lista
duplamente ligada. Para facilitar o codigo, criaram-se duas variaveis estaticas 
(visiveis apenas dentro deste ficheiro), respetivamente para o inicio (head) e 
fim (tail) da lista duplamente ligada */
static LCont head = NULL;
static LCont tail = NULL;

/* cria um novo no da lista duplamente ligada 
nao tem parametros de entrada e devolve o novo contacto */
LCont NEW() {
    LCont c = novo_contacto();
    c->next = NULL;
    c->prev = NULL;
    return c;
}

/* le o input para o novo contacto e atribui-lhe as informacoes 
nao tem parametros de entrada e devolve o contacto com as informacoes recolhidas */
LCont novo_contacto() {
    char buffer[MAXCHAR];
    char *token;
    LCont c = (LCont)malloc(sizeof(struct contacto));

    fgets(buffer, MAXCHAR, stdin);
    token = strtok(buffer, SEPARADOR);
    c->nome = duplica_str(token);
    token = strtok(NULL, ARROBA);
    c->user = duplica_str(token);
    token = strtok(NULL, SEPARADOR);
    c->dom = duplica_str(token);
    token = strtok(NULL, FIM);
    c->num = duplica_str(token);
    return c;
}

/* insere o contacto c no final da lista 
recebe o contacto a adicionar e nao devolve nada */
void insere_fim(LCont c) {
    c->prev = tail;
    if (tail != NULL)
        tail->next = c;
    else
        head = c;
    tail = c;               /* nova tail */
}

/* imprime todos os contactos guardados na lista duplamente ligada 
nao tem parametros de entrada nem de saida */
void print_lista_dup_ligada() {
    LCont t;
    for (t = head; t != NULL; t = t->next)
        printf("%s %s@%s %s\n", t->nome, t->user, t->dom, t->num);
}

/* apaga um no da lista 
recebe um ponteiro para o contacto a apagar e nao devolve nada */
void l_apaga(LCont c) {
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else if (c == head) {
        head = c->next;
        head->prev = NULL;
    } else if (c == tail) {
        tail = c->prev;
        tail->next = NULL;
    } else {
        c->prev->next = c->next;
        c->next->prev = c->prev;
    }
    freenode(c);            
}

/* liberta a memoria alocada para um no da lista 
recebe o contacto que se pretende libertar e nao devolve nada*/
void freenode(LCont c) {
    free(c->nome);
    free(c->user);
    free(c->dom);
    free(c->num);
    free(c);
}

/* destroi a lista, libertando toda a memoria alocada 
nao tem parametros de entrada nem de saida */
void l_destroy() {
    LCont c = NULL;
    while (head != NULL) {
        c = head->next;
        freenode(head);
        head = c;
    }
}

/* duplica uma string, alocando a memoria necessaria para a nova string 
recebe a string a duplicar e devolve um ponteiro para ela */
char *duplica_str(char *s) {
    char *ptr;

    ptr = (char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(ptr,s);
    return ptr;
}