#include <stdio.h>
#include "LAB_4_PUNTO_1.h" //grafo dirigido
#include "LAB_1_al_completo.c" //definicion de Document y Link
#include <windows.h>


//imprime el score de cada documento segun cuantas flechas le llegan en el grafo
void print_relevance_scores(DirectedGraph* graph, Document* documents) {
    Document* current = documents;

    while (current != NULL) {
        int relevance = graph_get_indegree(graph, current->id); //sacamos el indegree del doc

        printf("Documento ID: %d\n", current->id);
        printf("Titulo: %s\n", current->title);
        printf("Relevance score (indegree): %d\n", relevance);
        printf("----------------------------\n");

        current = current->next;
    }
}

