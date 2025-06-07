#pragma once
#include "lab_3.2.h"

//busca els documents que contenen una paraula
int* search_documents_by_word(ReverseIndexHashmap *map, const char *word, int *doc_count);