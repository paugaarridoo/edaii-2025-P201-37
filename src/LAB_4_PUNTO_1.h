#include <stdlib.h>
#include <stdio.h>


#ifndef GRAPH_H
#define GRAPH_H

//nodo que guarda a donde apunta y el siguiente en la lista
typedef struct GraphNode {
    int target_id;
    struct GraphNode* next;
} GraphNode;

//grafo con cantidad de nodos y lista de adyacencia
typedef struct {
    int num_nodes;
    GraphNode** adj_list;
} DirectedGraph;

//crea el grafo
DirectedGraph* create_graph(int num_nodes);

//agrega una flecha de un nodo a otro
void add_edge(DirectedGraph* graph, int from_id, int to_id);

//cuenta cuantas flechas llegan al nodo
int graph_get_indegree(DirectedGraph* graph, int doc_id);

//libera todo
void free_graph(DirectedGraph* graph);

#endif

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