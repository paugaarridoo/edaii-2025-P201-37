#include <stdlib.h>
#include <stdio.h>
#include "LAB 4 PUNTO 1.h"

//creamos un grafo con nodos vacios
DirectedGraph* create_graph(int num_nodes) {
    DirectedGraph* graph = malloc(sizeof(DirectedGraph));
    graph->num_nodes = num_nodes;
    graph->adj_list = calloc(num_nodes, sizeof(GraphNode*));
    return graph;
}

//agregamos una flecha from-id to_id
void add_edge(DirectedGraph* graph, int from_id, int to_id) {
    GraphNode* new_node = malloc(sizeof(GraphNode));
    new_node->target_id = to_id;
    new_node->next = graph->adj_list[from_id];
    graph->adj_list[from_id] = new_node;
}

//vemos cuantas flechas le llegan al nodo docid
int graph_get_indegree(DirectedGraph* graph, int doc_id) {
    int indegree = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        GraphNode* current = graph->adj_list[i];
        while (current != NULL) {
            if (current->target_id == doc_id) {
                indegree++;
            }
            current = current->next;
        }
    }
    return indegree;
}

//liberamos toda la memoria del grafo
void free_graph(DirectedGraph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        GraphNode* current = graph->adj_list[i];
        while (current != NULL) {
            GraphNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adj_list);
    free(graph);
}

