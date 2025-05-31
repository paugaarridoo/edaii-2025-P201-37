#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LAB_2.1.c"
#include "LAB_2.4.h"
#define MAX_RECENT_QUERIES 3
#include <windows.h>




void queue_init(QueryQueue *q){  //Inicializamos la cola de queries
    q->start = 0;
    q->count = 0;
    for (int i = 0; i < MAX_RECENT_QUERIES; ++i){
        q->queries[i] = NULL;
    }
}

void queue_push(QueryQueue *q, Query *query) {  //Añadimos una query a la cola
    int idx = (q->start + q->count) % MAX_RECENT_QUERIES;
    if (q->count == MAX_RECENT_QUERIES) {                  //Liberamos memoria de la query incicial (más vieja) si la cola estaá llena
        free(q->queries[q->start]->query);
        free(q->queries[q->start]);
        q->start = (q->start + 1) % MAX_RECENT_QUERIES;
        q->count--;
    }
    q->queries[idx] = query;
    q->count++;
}

void queue_print(QueryQueue *q) {             //Imprimimos las ultimas queries de la cola
    printf("Últimas %d queries:\n", q->count);
    for (int i = 0; i < q->count; ++i) {
        int idx = (q->start + i) % MAX_RECENT_QUERIES;
        printf("%d: %s\n", i + 1, q->queries[idx]->query);
    }
}
