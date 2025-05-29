#include <stdlib.h>
#include <string.h>
#include "LAB 2 PUNTO 1.c"

Query *Query_init_from_string(const char *str) {   // Funció per a inicialitzar una query a patrir d'una string
    Query *q = (Query *) malloc(sizeof(Query));
    if (!q) return NULL;                          //Comprovem que s'ha pogut reservar memoria per a la query
    q->query = (char*) malloc(strlen(str) + 1);
    if (!q->query){
        free(q);            // Alliberem la memoria reservada per a la query si no s'ha pogut reservar memoria
        return NULL;
    }
    strcpy(q->query, str);           // Copiem la string a la query
    q->prev = NULL;
    q->next = NULL;
    return q;
}