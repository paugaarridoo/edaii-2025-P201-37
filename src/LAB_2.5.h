#include <stdio.h>
#include <string.h>               
#include "LAB_2.1.h"
#include "LAB_1_al_completo.h"
#include "LAB_2.2.h"

void search_documents_exclude(Document **docs, int doc_count, const char *query, const char *exclude) {
    int found = 0;
    for (int i = 0; i < doc_count; i++) {
        if ((strstr(docs[i]->title, query) || strstr(docs[i]->body, query)) &&
            (!exclude || (!strstr(docs[i]->title, exclude) && !strstr(docs[i]->body, exclude)))) {
            printf("Document #%d\n", i);
            printf("ID: %d\n", docs[i]->id);
            printf("Títol: %s\n", docs[i]->title);
            printf("Cos: %.60s...\n", docs[i]->body);
            printf("-------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No se han encontrado documentos.\n");
    }
}