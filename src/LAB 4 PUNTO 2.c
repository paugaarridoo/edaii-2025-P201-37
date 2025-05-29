#include <stdio.h>
#include "LAB 4 PUNTO 1.h"    // tu grafo dirigido
#include "document.h" // tu definición de Document y Link

void print_relevance_scores(DirectedGraph* graph, Document* documents) {
    Document* current = documents;

    while (current != NULL) {
        int relevance = graph_get_indegree(graph, current->id);

        printf("Documento ID: %d\n", current->id);
        printf("Título: %s\n", current->title);
        printf("Relevance score (indegree): %d\n", relevance);
        printf("----------------------------\n");

        current = current->next;
    }
}
