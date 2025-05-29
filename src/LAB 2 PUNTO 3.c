#include <stdio.h>
#include "string.h"
#include <dirent.h>
#include "LAB 1 PUNTO 3.c"
#include "LAB 1 PUNTO 4.c"
#include "LAB 2 PUNTO 1.c"
#include "LAB 2 PUNTO 2.c"
#define MAX_PATH_LEN 256

void search_documents(Document **docs, int doc_count, const char *query) {  // Funció per a buscar documents
    int found = 0;
    for (int i = 0; i < doc_count; i++) {
        if (strstr(docs[i]->title, query) || strstr(docs[i]->body, query)) { 
            printf("Document #%d\n", i);
            printf("ID: %d\n", docs[i]->id);
            printf("Títol: %s\n", docs[i]->title);
            printf("Cos: %.60s...\n", docs[i]->body);
            printf("-------------------------\n");
            found = 1;
        }  // Es comprova que el títol o el cos del document conté la query
    }
    if (!found) {
        prinf("No s'han trobat documents.\n");
    }
}

int load_doc_paths(const char *folder, char *doc_paths[], int max_docs) {  //Funció per a carregar els camins dels documents
    DIR *dir;     // Directori de lectura dels documents
    struct dirent *entry;
    int count = 0;
    dir = opendir(folder);  // S'obre el directori seleccionat
    if (!dir) {
        perror("No se pudo abrir el directorio");
        return 0;
    }
    while ((entry = readdir(dir)) != NULL && count < max_docs) {  // Es llegeixen els fitxers del directori
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;
    const char *dot = strrchr(entry->d_name, '.');  //Es comprova si el fitxer té extensio .txt
    if (dot && strcmp(dot, ".txt") == 0) {
        snprintf(doc_paths[count], MAX_PATH_LEN, "%s/%s", folder, entry->d_name);
        count++;
        }
    }
    closedir(dir);
    return count;
}