/*
file: proj2.h
autor: Susana Monteiro, 92560
data: 17/05/2019
descricao: sistema de gestao de contactos, com uso de:
- uma lista duplamente ligada, onde sao guardados os contactos pela ordem 
pela qual foram adicionados (file: listas.c)
- duas hash tables, com recurso a listas simplesmente ligadas, uma com os contactos 
organizados pelo seu nome e outra segundo o dominio do seu email (file: hashtables.c)
*/

#include "hashtables.h"


/* funcoes principais */
void adiciona_contacto(); 
void lista_todos();
void procura_contacto();
void apaga_contacto();
void altera_email();
void numero_dom_email();

/* funcoes auxiliares */
HCont procura_contacto_aux();
HCont itera_contactos(char*);