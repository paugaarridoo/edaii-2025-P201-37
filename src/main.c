#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

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

#define MAX_PATH_LEN 256
#define MAX_DOCS 5400

// Carrega els paths dels fitxers d'una carpeta
int load_doc_paths(const char* folder, char* doc_paths[], int max_docs) {
    DIR* dir = opendir(folder);
    if (!dir) {
        printf("No s'ha pogut obrir la carpeta.\n");
        return 0;
    }
    struct dirent* entry;
    int count = 0;
    while ((entry = readdir(dir)) && count < max_docs) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        size_t folder_len = strlen(folder);
        size_t name_len = strlen(entry->d_name);
        // Comprova que càpiga tot (folder + '/' + nom + '\0')
        if (folder_len + 1 + name_len >= MAX_PATH_LEN) {
            fprintf(stderr, "Path massa llarg: %s/%s\n", folder, entry->d_name);
            continue;
        }
        // Concatena manualment per evitar qualsevol warning
        strncpy(doc_paths[count], folder, MAX_PATH_LEN - 1);
        doc_paths[count][MAX_PATH_LEN - 1] = '\0';
        strncat(doc_paths[count], "/", MAX_PATH_LEN - strlen(doc_paths[count]) - 1);
        strncat(doc_paths[count], entry->d_name, MAX_PATH_LEN - strlen(doc_paths[count]) - 1);
        count++;
    }
    closedir(dir);
    return count;
}

// Funció per construir l'índex invers
void construir_index_invers(ReverseIndexHashmap *rev_index, Document **docs, int doc_count) {
    for (int i = 0; i < doc_count; ++i) {
        char *text = docs[i]->contingut;
        char *text_copy = strdup(text ? text : "");
        char *token = strtok(text_copy, " ,.-\n\r\t");
        while (token) {
            add_word_to_reverse_index(rev_index, token, docs[i]->id);
            token = strtok(NULL, " ,.-\n\r\t");
        }
        free(text_copy);
    }
}

int main() {
    printf("*****************\nWelcome to EDA 2!\n*****************\n");

    printf("Introdueix el nom de la carpeta de documents: ");
    char folder[MAX_PATH_LEN];
    scanf("%255s", folder);

    char* doc_paths[MAX_DOCS];
    for (int i = 0; i < MAX_DOCS; ++i) {
        doc_paths[i] = malloc(MAX_PATH_LEN);
    }

    int doc_count = load_doc_paths(folder, doc_paths, MAX_DOCS);

    // Carrega els documents
    Document* docs[MAX_DOCS];
    for (int i = 0; i < doc_count; ++i) {
        docs[i] = malloc(sizeof(Document));
        Document_init_from_file(docs[i], doc_paths[i]);
    }

    // Inicialitza el reverse index
    ReverseIndexHashmap *reverse_index = create_reverse_index(200);
    construir_index_invers(reverse_index, docs, doc_count);

    char query[256];
    while (1) {
        printf("\nIntrodueix la teva consulta ('exit' per sortir): ");
        scanf(" %[^\n]", query);
        if (strcmp(query, "exit") == 0) break;

        // Cerca eficient amb índex invers
        int found_count = 0;
        int *found_docs = search_documents_by_word(reverse_index, query, &found_count);

        printf("\nResultats de la cerca:\n");
        if (found_count > 0) {
            for (int i = 0; i < found_count; ++i) {
                printf("Document ID: %d\n", found_docs[i]);
            }
        } else {
            printf("Cap document trobat per '%s'.\n", query);
        }
        free(found_docs);
    }

    // Allibera memòria
    for (int i = 0; i < MAX_DOCS; ++i) free(doc_paths[i]);
    for (int i = 0; i < doc_count; ++i) {
        Document_lliberar(docs[i]);
        free(docs[i]);
    }
    free_reverse_index(reverse_index);

    printf("Fins aviat!\n");
    return 0;
}
