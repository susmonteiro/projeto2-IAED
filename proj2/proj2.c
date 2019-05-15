/*
file: proj2.c
autor: Susana Monteiro, 92560
data: 17/05/2019
descricao: sistema de gestao de contactos, com uso de:
- uma lista duplamente ligada, onde sao guardados os contactos pela ordem 
pela qual foram adicionados (file: listas.c)
- duas hash tables, com recurso a listas simplesmente ligadas, uma com os contactos 
organizados pelo seu nome e outra segundo o dominio do seu email (file: hashtables.c)
*/

#include "proj2.h"

int main() {
    char c;
    init_nomes();   /* inicializar a hash table que organiza os contactos pelo nome */
    init_emails();  /* inicializar a hash table que organiza os contactos pelo email */
    for (;;) {
        c = getchar();
        getchar();  /* ignora o espaco entre o comando e o resto do input */
        switch (c) {
            case 'a':
                adiciona_contacto();
                break;
            case 'l':
                lista_todos();
                break;
            case 'p':
                procura_contacto();
                break;
            case 'r':
                apaga_contacto();
                break;
            case 'e':
                altera_email();
                break;
            case 'c':
                numero_dom_email();
                break;
            case 'x':
                l_destroy();
                h_destroy();
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Invalid input: %d\n", c);
                return EXIT_FAILURE;
        }
    }
}

/*                            FUNCOES PRINCIPAIS                             */

/* funcao principal do comando a
recebe um novo contacto e, desde que nao haja ja um contacto com o mesmo nome, 
adiciona-o a lista de contactos e as duas hash tables 
nao tem parametros de entrada nem de saida */
void adiciona_contacto() {
    LCont c = NEW();
    if (procura_nomes(c->nome) != NULL) {
        printf("Nome existente.\n");
        freenode(c);
    }
    else {
        insere_fim(c);
        insere_nome(c);
        insere_email(c);
    }
}

/* funcao principal do comando l
lista todos os eventos por ordem de adicao 
nao tem parametros de entrada nem de saida */
void lista_todos() {
    print_lista_dup_ligada();
}

/* funcao principal do comando p 
procura um contacto, com recurso a hash table com os contactos organizados por nome, 
e imprime as informacoes referentes ao contacto 
nao tem parametros de entrada nem de saida */
void procura_contacto() {
    HCont cptr = procura_contacto_aux();

    if (cptr)
        printf("%s %s@%s %s\n", cptr->c->nome, cptr->c->user, cptr->c->dom, cptr->c->num);
}

/* funcao principal do comando r
apaga um contacto, da lista e das duas hash tables
nao tem parametros de entrada nem de saida */
void apaga_contacto() {
    HCont cptr = procura_contacto_aux();
    LCont c;

    if (!cptr) return;
    c = cptr->c;
    apaga_emails(cptr->c->nome, cptr->c->dom);
    apaga_nomes(cptr->c->nome);
    l_apaga(c);
}

/* funcao principal do comando e 
altera o email de um determinado contacto 
nao tem parametros de entrada nem de saida */
void altera_email() {
    char buffer[MAXCHAR]; 
    char *nome, *user, *dom;
    HCont aux;

    fgets(buffer, MAXCHAR, stdin);
    nome = strtok(buffer, SEPARADOR);
    user = strtok(NULL, ARROBA);
    dom = strtok(NULL, FIM);
    if ((aux = itera_contactos(nome)) != NULL) {
        apaga_emails(aux->c->nome, aux->c->dom);
        aux->c->user = (char*)realloc(aux->c->user, sizeof(char)*(strlen(user)+1));
        strcpy(aux->c->user, user);
        aux->c->dom = (char*)realloc(aux->c->dom, sizeof(char)*(strlen(dom)+1));
        strcpy(aux->c->dom, dom);
        insere_email(aux->c);
    }  
}

/* funcao principal do comando c
imprime o numero de contactos de um determinado dominio 
nao tem parametros de entrada nem de saida */
void numero_dom_email() {
    char dom[MAXEMAIL];

    fgets(dom, MAXEMAIL, stdin);
    dom[strlen(dom) - 1] = NUL;  /* ignorar o \n do final do input */
    printf("%s:%d\n", dom, conta_emails(dom));
}


/*                            FUNCOES AUXILIARES                             */

/* funcao que recebe o nome de um contacto, para depois o ir procurar 
na hash table* que contem os contactos organizados pelo nome 
nao tem parametros de entrada e devolve o endereco desse contacto na hash table */
HCont procura_contacto_aux() {
    char nome[MAXNOME];

    fgets(nome, MAXNOME, stdin);
    nome[strlen(nome) - 1] = NUL; /* ignorar o \n do final do input */
    return itera_contactos(nome);
}

/* funcao que procura um contacto na hash table que os tem organizados pelo nome
recebe o nome do contacto e devolve um ponteiro para ele */
HCont itera_contactos(char *nome) {
    HCont cptr;

    if ((cptr = procura_nomes(nome)) == NULL) 
        printf("Nome inexistente.\n");
    return cptr;
}