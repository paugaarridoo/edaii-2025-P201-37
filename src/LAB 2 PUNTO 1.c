#include <stdio.h>

typedef struct{
  char *query;
  Query *prev;
  Query *next;
} Query;

Query *Querylist_init(){
  Query *query_list = (Query*) malloc(sizeof(Query));
  return query_list;
}