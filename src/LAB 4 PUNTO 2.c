#include <stdio.h>
#include "LAB 1 PUNTO 3.c"
#include "LAB4PUNTO1.c"

Document score_in_graph(Directedgraph* graph){
    int scores_array[graph->num_nodes];
    for (int i = 0; i < graph->num_nodes; ++i){
        scores_array[i] = 0;
    }
    for (int i = 0; i < graph->num_nodes; ++i){
        for (int j = 0; j < graph->num_nodes; ++j){
            if (graph->matrix[i][j] == 1){
                scores_array[j]++;
            }
        }
    }
}