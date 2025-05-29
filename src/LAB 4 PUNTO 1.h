#ifndef GRAPH_H
#define GRAPH_H

typedef struct GraphNode {
    int target_id;
    struct GraphNode* next;
} GraphNode;

typedef struct {
    int num_nodes;
    GraphNode** adj_list;
} DirectedGraph;

DirectedGraph* create_graph(int num_nodes);
void add_edge(DirectedGraph* graph, int from_id, int to_id);
int graph_get_indegree(DirectedGraph* graph, int doc_id);
void free_graph(DirectedGraph* graph);

#endif
