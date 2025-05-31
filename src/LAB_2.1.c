#include <stdio.h>
#include <stdlib.h>  //Para usar el malloc especificamente
#include "LAB_2.1.h"
#include <string.h>  //Para usar el strdup y strcpy
#include <windows.h>


//Creamos una función que inicializa una lista de consultas y devuelve el puntero de la lista
Query *Querylist_init() {
    Query *query_list = (Query *)malloc(sizeof(Query));
    if (query_list != NULL) {
        query_list->query = NULL;
        query_list->prev = NULL;
        query_list->next = NULL;
    }
    return query_list;
}
