#ifndef indice_INVERSO_H
#define indice_INVERSO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para el índice inverso
typedef struct IndicereversoNode {
    char *keyword;                // Palabra clave
    int *document_ids;            // Arreglo de IDs de documentos que contienen la palabra
    int *document_cuenta;           // Número de documentos que contienen la palabra
    struct IndicereversoNode *next;
} IndicereversoNode;

typedef struct {
    IndicereversoNode *head;
} INDICE_INVERSO;

// Funciones del índice inverso
INDICE_INVERSO* create_index();
void añade_indice(INDICE_INVERSO *index, const char *keyword, int document_id);
IndicereversoNode* busca_index(INDICE_INVERSO *indice, const char *keyword);
void print_documents_for_keyword(INDICE_INVERSO *indice, const char *keyword, const char **documents, int num_documents);
void index_vacio(INDICE_INVERSO *indice);

#endif