#include <windows.h>

#define MAX_RECENT_QUERIES 3


typedef struct{                          //Estructura para la cola de queries
    Query *queries[MAX_RECENT_QUERIES];
    int start;
    int count;
} QueryQueue;