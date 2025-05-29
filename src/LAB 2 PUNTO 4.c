#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LAB 2 PUNTO 1.c"
#define MAX_RECENT_QUERIES 3

typedef struct{                          //Estructura per a la cua de queries
    Query *queries[MAX_RECENT_QUERIES];
    int start;
    int count;
} QueryQueue;

void queue_init(QueryQueue *q){  // Inicialitzem la cua de queries
    q->start = 0;
    q->count = 0;
    for (int i = 0; i < MAX_RECENT_QUERIES; ++i){
        q->queries[i] = NULL;
    }
}

void queue_push(QueryQueue *q, Query *query) {  //Afegim una query a la cua
    int idx = (q->start + q->count) % MAX_RECENT_QUERIES;
    if (q->count == MAX_RECENT_QUERIES) {                  //Alliberem la memoria de la query inicial si la cua està plena
        free(q->queries[q->start]->query);
        free(q->queries[q->start]);
        q->start = (q->start + 1) % MAX_RECENT_QUERIES;
        q->count--;
    }
    q->queries[idx] = query;
    q->count++;
}

void queue_print(QueryQueue *q) {             //Imprimim les últimes queries de la cua
    printf("Últimas %d queries:\n", q->count);
    for (int i = 0; i < q->count; ++i) {
        int idx = (q->start + i) % MAX_RECENT_QUERIES;
        printf("%d: %s\n", i + 1, q->queries[idx]->query);
    }
}