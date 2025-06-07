#include "lab_1.2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Document_init_from_file(Document* doc, const char* filepath) {
    FILE *f = fopen(filepath, "r");
    if (!f) return 0;

    // Llegeix l'id (primera línia)
    if (fscanf(f, "%d\n", &doc->id) != 1) {
        fclose(f);
        return 0;
    }

    // Llegeix el títol (segona línia)
    char titol_buffer[256];
    if (!fgets(titol_buffer, sizeof(titol_buffer), f)) {
        fclose(f);
        return 0;
    }
    titol_buffer[strcspn(titol_buffer, "\r\n")] = 0; // Elimina salt de línia
    doc->titol = strdup(titol_buffer);

    // Llegeix la resta com a contingut
    long contingut_start = ftell(f);
    fseek(f, 0, SEEK_END);
    long contingut_end = ftell(f);
    long contingut_len = contingut_end - contingut_start;
    fseek(f, contingut_start, SEEK_SET);

    char *contingut_buffer = (char*)malloc(contingut_len + 1);
    if (contingut_len > 0) {
        fread(contingut_buffer, 1, contingut_len, f);
    }
    contingut_buffer[contingut_len] = '\0';
    doc->contingut = contingut_buffer;

    fclose(f);

    // Inicialitza la llista d'enllaços si cal
    // LinkList_init(&doc->links);

    return 1;
}

void Document_lliberar(Document* doc) {
    if (doc->titol) free(doc->titol);
    if (doc->contingut) free(doc->contingut);
    // LinkList_lliberar(&doc->links); // Si tens implementació
    doc->titol = NULL;
    doc->contingut = NULL;
}
