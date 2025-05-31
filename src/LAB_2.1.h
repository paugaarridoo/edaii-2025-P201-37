#include <stdio.h>
#include <stdlib.h>  //Para usar el malloc especificamente
#include <string.h>  //Para usar el strdup y strcpy


typedef struct Query { //Creamos una estrcutura que representa nuestra consulta
    char *query;       //Texto
    struct Query *prev; //Puntero al nodo anterior
    struct Query *next;  //Puntero al nodo siguiente
} Query;

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