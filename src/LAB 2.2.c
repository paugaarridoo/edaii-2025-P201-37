#include <stdlib.h>
#include <string.h>
#include "LA2.1.c"  //Incluimos el punto 2.1 donde hemos definido la estructura Query

//Creamos una función que inicialice un nodo Query a partir de nuestra cadena de texto
Query *Query_init_from_string(const char *str) { // Reservamos memoria con el nuevo nodo
    Query *q = (Query *)malloc(sizeof(Query));
    if (!q) return NULL;  //De nuevo, si falla, devolvemos NULL
 // Seguimos reservando memoria para guardar el contenido de la cadena
    q->query = (char *)malloc(strlen(str) + 1);
    if (!q->query) {
        free(q);           // Si esta falla, liberamos memoria
        return NULL;
    }
    // Copiamos la cadena en la estructura
    strcpy(q->query, str);

    q->prev = NULL;  
    q->next = NULL;  

    return q;        
}
