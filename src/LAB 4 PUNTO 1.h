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
