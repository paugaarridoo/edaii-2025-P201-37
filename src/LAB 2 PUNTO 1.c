#include <stdio.h>

typedef struct{        //Estructura per a la linked list de query
  char *query;
  Query *prev;
  Query *next;
} Query;

Query *Querylist_init(){                                 //Estructura per a inicialitzar la linked list de query
  Query *query_list = (Query*) malloc(sizeof(Query));
  return query_list;
}