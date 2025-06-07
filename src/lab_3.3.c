#include "lab_3.3.h"
#include <string.h>
#include <stdlib.h>

//cerca amb el reverse index els documents que contenen la paraula
int* search_documents_by_word(ReverseIndexHashmap *map, const char *word, int *doc_count) {
    unsigned int idx = 0;
    if (map && word) {
        idx = hash_word(word, map->size); //hash_word es static a lab_3.2.c cal declarar-la a lab_3.2.h si vols reutilitzarla
        WordNode *node = map->buckets[idx];
        while (node) {
            if (strcmp(node->word, word) == 0) {
                //retorna copia dels document_ids i la mida
                int *result = (int*) malloc(node->doc_count * sizeof(int));
                for (int i = 0; i < node->doc_count; ++i)
                    result[i] = node->document_ids[i];
                *doc_count = node->doc_count;
                return result;
            }
            node = node->next;
        }
    }
    //no trobat
    *doc_count = 0;
    return NULL;
}