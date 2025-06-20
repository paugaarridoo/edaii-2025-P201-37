#include "lab_3.2.h"
#include <stdlib.h>
#include <string.h>

//calcula un hash per a un word
unsigned int hash_word(const char *word, int size) {
    unsigned int hash = 5381;
    int c;
    while ((c = *word++))
        hash = ((hash << 5) + hash) + c;
    return hash % size;
}

//reserva memoria per la taula hash
ReverseIndexHashmap* create_reverse_index(int size) {
    ReverseIndexHashmap *map = (ReverseIndexHashmap*) malloc(sizeof(ReverseIndexHashmap));
    map->buckets = (WordNode**) calloc(size, sizeof(WordNode*));
    map->size = size;
    return map;
}

//afegeix una paraula al reverse index
void add_word_to_reverse_index(ReverseIndexHashmap *map, const char *word, int doc_id) {
    unsigned int idx = hash_word(word, map->size);
    WordNode *node = map->buckets[idx];
    //busca si la paraula ja existeix
    while (node) {
        if (strcmp(node->word, word) == 0) {
            //comprova si el doc_id ja hi és
            for (int i = 0; i < node->doc_count; ++i) {
                if (node->document_ids[i] == doc_id)
                    return; //ja hi es, no afegim duplicats
            }
            //afegeix el doc_id
            if (node->doc_count == node->doc_capacity) {
                node->doc_capacity *= 2;
                node->document_ids = (int*) realloc(node->document_ids, node->doc_capacity * sizeof(int));
            }
            node->document_ids[node->doc_count++] = doc_id;
            return;
        }
        node = node->next;
    }
    //si no existeix, crea un nou node
    node = (WordNode*) malloc(sizeof(WordNode));
    node->word = strdup(word);
    node->doc_capacity = 4;
    node->document_ids = (int*) malloc(node->doc_capacity * sizeof(int));
    node->document_ids[0] = doc_id;
    node->doc_count = 1;
    node->next = map->buckets[idx];
    map->buckets[idx] = node;
}

//allibera la memoria que ocupa el reverse index
void free_reverse_index(ReverseIndexHashmap *map) {
    for (int i = 0; i < map->size; ++i) {
        WordNode *node = map->buckets[i];
        while (node) {
            WordNode *tmp = node;
            node = node->next;
            free(tmp->word);
            free(tmp->document_ids);
            free(tmp);
        }
    }
    free(map->buckets);
    free(map);
}

//construix el inverse index
void construir_index_invers(ReverseIndexHashmap *rev_index, Document **docs, int doc_count) {
    for (int i = 0; i < doc_count; ++i) {
        char *text = docs[i]->contingut;
        char *text_copy = strdup(text ? text : "");
        char *token = strtok(text_copy, " ,.-\n\r\t");
        while (token) {
            add_word_to_reverse_index(rev_index, token, docs[i]->id);
            token = strtok(NULL, " ,.-\n\r\t");
        }
        free(text_copy);
    }
}