#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LAB 1 al completo.c"
#include "LAB 3 PUNTO 2.h"

unsigned int hash_word(const char *word, int size) {
    unsigned int hash = 5381;
    int c;
    while ((c = *word++))
        hash = ((hash << 5) + hash) + c;
    return hash % size;
}                                                  //Función de hash para las palabras

ReverseIndexHashmap *create_reverse_index(int size) {
    ReverseIndexHashmap *map = malloc(sizeof(ReverseIndexHashmap));
    map->buckets = calloc(size, sizeof(WordNode *));
    map->size = size;
    return map;
}                      //Función para inicializar un índice inverso

void add_word_to_index(ReverseIndexHashmap *map, const char *word, int doc_id) {
    unsigned int idx = hash_word(word, map->size);
    WordNode *node = map->buckets[idx];
    while (node) {
        if (strcmp(node->word, word) == 0) {         for (int i = 0; i < node->doc_count; ++i) {
                if (node->document_ids[i] == doc_id) return;
            }
            if (node->doc_count == node->doc_capacity) {
                node->doc_capacity *= 2;
                node->document_ids = realloc(node->document_ids, node->doc_capacity * sizeof(int));
            }
            node->document_ids[node->doc_count++] = doc_id;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(WordNode));
    node->word = strdup(word);                // Duplicamos la palabra para evitar problemas de memoria
    node->doc_capacity = 4;
    node->document_ids = malloc(node->doc_capacity * sizeof(int));
    node->document_ids[0] = doc_id;
    node->doc_count = 1;
    node->next = map->buckets[idx];
    map->buckets[idx] = node;
}                                   //Función para añadir una palabra al índice inverso

void index_text(ReverseIndexHashmap *map, const char *text, int doc_id) {
    char buffer[256];
    int j = 0;
    for (int i = 0; ; ++i) {
        char c = text[i];
        if (isalnum(c)) {                       //Comprovamos si el caracter es alfanumérico
            buffer[j++] = tolower(c);           //Pasamos a minúsculas
        } else {
            if (j > 0) {
                buffer[j] = '\0';
                add_word_to_index(map, buffer, doc_id);
                j = 0;
            }
            if (c == '\0') break;
        }
    }
}            //Función para indexar el texto de un documento, separando palabras y añadiéndolas al índice inverso


void build_reverse_index(ReverseIndexHashmap *map, Document **docs, int doc_count) {
  for (int i = 0; i < doc_count; ++i) {
        index_text(map, docs[i]->title, docs[i]->id);
        index_text(map, docs[i]->body, docs[i]->id);
    }
}       //Función para crear el índice inverso a partir de un conjunto de documentos