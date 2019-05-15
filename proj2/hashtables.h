/*
file: hashtables.h
autor: Susana Monteiro, 92560
data: 17/05/2019
descricao: funcoes auxiliares das hash tables que organizam os contactos por
    nome e dominio de email, bem como as funcoes das listas simplesmente ligadas, 
    utilizadas na implementacao das hash tables 
*/

#ifndef _HASH_
#define _HASH_

#include "listas.h"

#define NUMELEMS 511    /* tamanho das hash tables */
#define CONST1DJB 5381  /* constantes usadas na funcao de dispersao */
#define CONST2DJB 33

#define indice_hash(s) s%NUMELEMS   

/* estrutura das hash tables que, alem do ponteiro para o proximo elemento da lista, 
contem um ponteiro para o no da lista duplamente ligada onde se encontra este contacto */
typedef struct hcont {
    struct hcont *next;
    LCont c;
} *HCont;

/* funcoes de manipulacao das listas simplesmente ligadas */
void init_nomes();
void init_emails();
HCont push(HCont, LCont);
HCont procura(HCont, char*);
HCont h_apaga(HCont, char*);
/* funcoes de manipulacao das hash tables */
unsigned int djb(char*);
void insere_nome(LCont);
void insere_email(LCont);
void apaga_nomes(char*);
void apaga_emails(char*, char*);
HCont procura_nomes(char*);
int conta_emails(char*);
void h_destroy();
void destroy(HCont*);

#endif