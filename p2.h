#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"
#include "contactos.h"

#define MAXCHAR 2048
#define MAXNOME 1024
#define MAXEMAIL 512
#define MAXNUMERO 64
#define NUL '\0'
#define SEPARADOR " "
#define ARROBA "@"


/* funcoes principais */
void adiciona_evento(); /*
void lista_todos();
void procura_evento();
void apaga_evento();
void altera_email();
void numero_dom_email();
*/
void cria_contacto(Contacto *c);