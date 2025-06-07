#pragma once
#include "lab_1.2.h"

//definim un node de paraula al reverse index
typedef struct WordNode {
    char *word;
    int *document_ids;
    int doc_count;
    int doc_capacity;
    struct WordNode *next;
} WordNode;


//estructura del reverse index hashmap
typedef struct {
    WordNode **buckets;
    int size;
} ReverseIndexHashmap;


//reserva i inicia taula hash
ReverseIndexHashmap* create_reverse_index(int size);

//afegeixuna paraula i els documents o apareix
void add_word_to_reverse_index(ReverseIndexHashmap *map, const char *word, int doc_id);
//allibera la memoria del reverse index
void free_reverse_index(ReverseIndexHashmap *map);

//funcio per distribuir les paraules
unsigned int hash_word(const char *word, int size);


//omplir el reverse index
void construir_index_invers(ReverseIndexHashmap *rev_index, Document **docs, int doc_count);