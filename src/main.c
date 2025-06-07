#include "lab_1.1.h"
#include "lab_1.2.h"
#include "lab_1.3.h"
#include "lab_1.4.h"
#include "lab_1.5.h"
#include "lab_2.1.h"
#include "lab_2.2.h"
#include "lab_2.3.h"
#include "lab_2.4.h"
#include "lab_2.5.h"
#include "lab_3.1.h"
#include "lab_3.2.h"
#include "lab_3.3.h"
#include "sample_lib.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#define MAX_PATH_LEN 256

int main() {
    printf("*****************\nWelcome to EDA 2!\n*****************\n");

    printf("Introduce el nombre de la carpeta de documentos: ");
    char folder[MAX_PATH_LEN];
    scanf("%255s", folder);

    // Carreguem els documents de la carpeta
    DocumentList llista;
    DocumentList_init(&llista);
    int doc_count = DocumentList_carregar_des_de_carpeta(&llista, folder);

    // Preparem un array de punters a Document per accés ràpid
    Document *docs[doc_count];
    int idx = 0;
    for (DocumentNode *node = llista.cap; node != NULL; node = node->seguent) {
        docs[idx++] = &node->doc;
    }

    // Creem el reverse index i l'omplim amb totes les paraules de tots els documents
    ReverseIndexHashmap *rev_index = create_reverse_index(200);
    for (int i = 0; i < doc_count; ++i) {
        // Fem servir 'contingut' i 'id' segons la teva estructura
        char *text = docs[i]->contingut;
        // Fem una còpia per no modificar l'original amb strtok
        char *text_copy = strdup(text ? text : "");
        char *token = strtok(text_copy, " ,.-\n\r\t");
        while (token) {
            add_word_to_reverse_index(rev_index, token, docs[i]->id);
            token = strtok(NULL, " ,.-\n\r\t");
        }
        free(text_copy);
    }

    QueryQueue recent_queries;
    queue_init(&recent_queries);

    while (1) {
        char query[100];
        char exclude[100];
        printf("Introdueix query ('exit' per sortir): ");
        scanf("%99s", query);
        if (strcmp(query, "exit") == 0) {
            break;
        }
        printf("Palabra a excluir (ENTER para ninguna): ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        fgets(exclude, 100, stdin);
        exclude[strcspn(exclude, "\n")] = 0;

        Query *q = Query_init_from_string(query);
        queue_push(&recent_queries, q);
        queue_print(&recent_queries);

        // Cerca eficient amb el reverse index
        int found_count = 0;
        int *found_docs = search_documents_by_word(rev_index, query, &found_count);

        if (found_count > 0) {
            printf("Documents trobats per '%s':\n", query);
            for (int i = 0; i < found_count; ++i) {
                printf("Document ID: %d\n", found_docs[i]);
            }
        } else {
            printf("Cap document trobat per '%s'.\n", query);
        }
        free(found_docs);

        // Si hi ha paraula a excloure, pots fer una cerca addicional aquí
        if (strlen(exclude) > 0) {
            printf("Exclusió de documents amb la paraula: %s (no implementat en aquest exemple)\n", exclude);
            // Aquí pots filtrar els found_docs si vols excloure documents que continguin 'exclude'
        }
    }

    // Alliberar memòria
    free_reverse_index(rev_index);
    DocumentList_lliberar(&llista);

    return 0;
}
