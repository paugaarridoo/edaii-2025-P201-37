#pragma once
#include "lab_3.2.h"

// Retorna un array dinàmic d'IDs de documents que contenen la paraula (o NULL si no existeix)
// La mida de l'array es retorna per referència a doc_count
int* search_documents_by_word(ReverseIndexHashmap *map, const char *word, int *doc_count);