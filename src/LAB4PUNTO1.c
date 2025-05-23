#include <stdio.h>
#include <stdlib.h>
#include "LAB 1 PUNTO 3.c"

typedef struct{
    int num_nodes;
    Document **matrix;
} Directedgraph;

Directedgraph *create_graph(int num_nodes){
    Directedgraph *new_graph = (Directedgraph*) malloc(sizeof(Directedgraph));
    new_graph->num_nodes = num_nodes;
    new_graph->matrix = (Document**) malloc(num_nodes*sizeof(Document*));
    for (int i = 0; i < num_nodes; ++i){
        new_graph->matrix[i] = (Document*) malloc(num_nodes*sizeof(Document));
        for (int j = 0; j < num_nodes; ++j){
            new_graph->matrix[i][j] = 0;
        }
    }
    return new_graph;
}

void add_edge(Directedgraph* graph, Document* origin, Document* destiny){
    graph->matrix[origin][destiny] = 1;
}


