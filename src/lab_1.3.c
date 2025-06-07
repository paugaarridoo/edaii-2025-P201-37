#include "lab_1.3.h" //Per usar la definició del DocumentList i les seves funcions pertinents
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>

// Inicialitza la llista de documents a partir d'un fitxer de manera buida
void DocumentList_init(DocumentList* llista) {
    llista->cap = NULL;
}

// Afegim un document a la llista a partir d'un fitxer
int DocumentList_agregar(DocumentList* llista, const char* filepath) {
    DocumentNode* nou = (DocumentNode*)malloc(sizeof(DocumentNode));
    if (!Document_init_from_file(&nou->doc, filepath)) {
        free(nou);
        return 0;
    }
    nou->seguent = NULL;

    if (!llista->cap) { // Si la llista és buida, el nou node es converteix en el cap
        llista->cap = nou;
    } else { // Si no, afegeix al final
        DocumentNode* actual = llista->cap;
        while (actual->seguent) actual = actual->seguent;
        actual->seguent = nou;
    }
    return 1;
}

// Allibera tota la memòria usada per la llista i els documents que la formen
void DocumentList_lliberar(DocumentList* llista) {
    DocumentNode* actual = llista->cap;
    while (actual) { 
        DocumentNode* temp = actual;
        actual = actual->seguent;
        Document_lliberar(&temp->doc); // Allibera el contingut/memòria del document 
        free(temp); // Allibera el node
    }
    llista->cap = NULL;
}

// Carrega tots els documents d'una carpeta a la llista de documents
int DocumentList_carregar_des_de_carpeta(DocumentList* llista, const char* folderpath) {
    DIR* dir = opendir(folderpath);
    if (!dir) return 0;

    struct dirent* entry;
    int count = 0;
    char filepath[512];

    while ((entry = readdir(dir)) != NULL) {
        // Ignora directoris "." i ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Opcional: filtra per extensió, per exemple només .txt
        // const char *ext = strrchr(entry->d_name, '.');
        // if (!ext || strcmp(ext, ".txt") != 0) continue;

        snprintf(filepath, sizeof(filepath), "%s/%s", folderpath, entry->d_name);
        if (DocumentList_agregar(llista, filepath)) count++;
    }
    closedir(dir); // Tanca el directori/carpeta
    return count; // Retorna el nombre de documents que has pogut carregar
}