#include <stdio.h>
#include <stdlib.h>
#include <string.h>     
#include <dirent.h>
#include "LAB 1 al completo.c"
#include "LAB 2.1.c"
#include "LAB 2.2c"

#define MAX_PATH_LEN 256

void search_documents(Document **docs, int doc_count, const char *query) {  //Función para buscar documents
    int found = 0;

    for (int i = 0; i < doc_count; i++) {
        //Se comprueba que el titulo y su contenido contenga query
        if (strstr(docs[i]->title, query) || strstr(docs[i]->body, query)) {
            printf("Document #%d\n", i);
            printf("ID: %d\n", docs[i]->id);
            printf("Títol: %s\n", docs[i]->title);
            printf("Cos: %.60s...\n", docs[i]->body);  //Mostramos solo los 60 primeros caracteres 
            printf("-------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No s'han trobat documents.\n");  // Corregimos 'print' a 'printf'
    }
}

int load_doc_paths(const char *folder, char *doc_paths[], int max_docs) {  //Funció per a carregar els camins dels documents
    DIR *dir;  
    struct dirent *entry;
    int count = 0;

    dir = opendir(folder);  //Se abre el directorio especifico
    if (!dir) {
        perror("No se pudo abrir el directorio");
        return 0;
    }

    //Se leen los fitxeros del directorio
    while ((entry = readdir(dir)) != NULL && count < max_docs) {
        // Ignorem fitxers "." i ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        //Se comprueba si el fitxero tiene extensión 
        const char *dot = strrchr(entry->d_name, '.');
        if (dot && strcmp(dot, ".txt") == 0) {
            snprintf(doc_paths[count], MAX_PATH_LEN, "%s/%s", folder, entry->d_name);
            count++;
        }
    }

    closedir(dir);
    return count;
}
