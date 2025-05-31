#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include "LAB_4_PUNTO_1.h"
#include "LAB_1_al_completo.c"
#include "punto_3_LAB_4.h"



int compara_relevancia(const void* a, const void* b) {   //Función para comparar dos reultados de budqueda por relevancia
    const SearchResult* ra = (const SearchResult*)a;
    const SearchResult* rb = (const SearchResult*)b;
    return rb->relevance - ra->relevance; // Y ordenarlos en orden descendente
}

void sort_search_results_by_relevance(SearchResult* results, int count) {
    qsort(results, count, sizeof(SearchResult), compara_relevancia);
}  // Función para ordenar los resultados mediante QuickSort

void mostrar_resultados_ordenados(Document** docs, int* doc_ids, int num_results, DirectedGraph* graph) {
    SearchResult* results = malloc(num_results * sizeof(SearchResult));
    for (int i = 0; i < num_results; ++i) {
        for (int j = 0; docs[j] != NULL; ++j) {
            if (docs[j]->id == doc_ids[i]) {
                results[i].doc = docs[j];
                results[i].relevance = graph_get_indegree(graph, docs[j]->id);
                break;
            }
        }
    }
    sort_search_results_by_relevance(results, num_results);

    printf("Resultados ordenados por relevancia:\n");
    for (int i = 0; i < num_results; ++i) {
        printf("ID: %d | Título: %s | Relevancia: %d\n",
               results[i].doc->id, results[i].doc->title, results[i].relevance);
    }
    free(results);
}                   //Función para mostrar los resultados ordenados
 
