#pragma once

// Estructura per a un node de paraula al reverse index
typedef struct WordNode {
    char *word;
    int *document_ids;
    int doc_count;
    int doc_capacity;
    struct WordNode *next;
} WordNode;

// Estructura del reverse index hashmap
typedef struct {
    WordNode **buckets;
    int size;
} ReverseIndexHashmap;

// Funcions bàsiques
ReverseIndexHashmap* create_reverse_index(int size);
void add_word_to_reverse_index(ReverseIndexHashmap *map, const char *word, int doc_id);
void free_reverse_index(ReverseIndexHashmap *map);
