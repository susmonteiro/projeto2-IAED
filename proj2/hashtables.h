#ifndef _HASH_
#define _HASH_

#include "listas.h"

#define NUMELEMS 511
#define CONST1DJB 5381
#define CONST2DJB 33

#define indice_hash(s) s%NUMELEMS


typedef struct hcont {
    struct hcont *next;
    LCont c;
} *HCont;

void init_nomes();
void init_emails();
HCont push(HCont, LCont);
HCont procura_nome(HCont, char*);
HCont h_apaga(HCont, char*);
void h_destroy();
void destroy(HCont*, int);
unsigned int djb(char*);
void insere_nomes(LCont);
void insere_emails(LCont);
void apaga_nomes(char*);
void apaga_emails(char*, char*);
HCont procura_nomes(char*);
int conta_emails(char*);

#endif