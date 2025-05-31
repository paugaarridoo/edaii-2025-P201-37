#include <stdio.h>
#include <string.h>
#include "LAB_3_PUNTO 2.c"
#include "LAB_1_al_completo.c"
#include <windows.h>


WordNode* find_word_in_index(ReverseIndexHashmap *map, const char *word) {
    unsigned int idx = hash_word(word, map->size);
    WordNode *node = map->buckets[idx];
    while (node) {
        if (strcmp(node->word, word) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}                          // Función para buscar una palabra en el índice inverso

// Busca documentos por palabra clave usando el índice inverso
void search_documents_by_word(ReverseIndexHashmap *map, Document **docs, int doc_count, const char *word) {
    char lower_word[256];
    int i;
    for (i = 0; word[i] && i < 255; ++i)
        lower_word[i] = tolower(word[i]);      // Pasamos a minúsculas
    lower_word[i] = '\0';

    WordNode *node = find_word_in_index(map, lower_word);
    if (!node) {
        printf("No se encontraron documentos para la palabra: %s\n", word);
        return;
    }
    printf("Documentos que contienen la palabra '%s':\n", word);
    for (int i = 0; i < node->doc_count; ++i) {
        int doc_id = node->document_ids[i];
        // Busca el documento por id
        for (int j = 0; j < doc_count; ++j) {
            if (docs[j]->id == doc_id) {
                printf("ID: %d | Título: %s\n", docs[j]->id, docs[j]->title);
                break;
            }
        }
    }
}              //Función para buscar documentos por palabra clave usando el índice inverso
