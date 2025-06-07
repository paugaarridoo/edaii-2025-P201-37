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
    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Salta la primera i segona línia
    fgets(titol_buffer, sizeof(titol_buffer), f); // id
    fgets(titol_buffer, sizeof(titol_buffer), f); // titol

    // Llegeix la resta
    char *contingut_buffer = (char*)malloc(filesize);
    size_t len = fread(contingut_buffer, 1, filesize, f);
    contingut_buffer[len] = '\0';
    doc->contingut = contingut_buffer;

    fclose(f);

    // Inicialitza la llista d'enllaços si cal
    // LinkList_init(&doc->links); // Si tens una funció d'inicialització

    return 1;
}