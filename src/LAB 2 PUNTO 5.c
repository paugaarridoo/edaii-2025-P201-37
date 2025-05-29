#include <stdio.h>
#include "LAB 2 PUNTO 1.c"
#include "LAB 1 PUNTO 3.c"

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
        }     //Comprovem que el document conté la query i no conté l'exclusió
    }
    if (!found) {
        printf("No s'han trobat documents.\n");  //Si no hi ha documents que compleixin la condició, s'indica
    }
}    //Funció per a comprovar que el document conté la query i no conté l'exclusió