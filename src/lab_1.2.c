#include "lab_1.2.h" // Per l'estrcutura Document i les seves funcions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Inicialitza un document a partir d'un fitxer
int Document_init_from_file(Document* doc, const char* filepath) {
    FILE* f = fopen(filepath, "r"); //Obre aquest en mode lectura
    if (!f) return 0; //En cas de que no es pugui obrir retornara error

    char buffer[2000]; //Creem un buffer per a que pugui llegir les linies del futxer

    //Llegeix la primera linia que es el titol del document
    if (!fgets(buffer, sizeof(buffer), f)) {
        fclose(f);
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = 0; //Elimina que es pugui fer un salt de linia
    doc->titol = strdup(buffer);

    //Una vegada ha llegit el titol. llegeix el contingut del document
    size_t contingut_len = 0;
    size_t contingut_cap = 2000; //Cpacitat inicial
    char* contingut = malloc(contingut_cap);
    contingut[0] = '\0';
    //Fem un bucle per a que llegeixi tot el contingut del fitxer linia a linia
    while (fgets(buffer, sizeof(buffer), f)) {
        size_t linelen = strlen(buffer);
        if (contingut_len + linelen + 1 > contingut_cap) {
            contingut_cap *= 2;
            contingut = realloc(contingut, contingut_cap);
        }
        strcat(contingut, buffer);
        contingut_len += linelen;
    }
doc->contingut = contingut;

    //Inicialitza buidament la llista dels enlalços
    LinkList_init(&doc->links);

    fclose(f);
    return 1;
}
//Tornem a allibrera tota la memoria utlitzada pel document
void Document_lliberar(Document* doc) {
    free(doc->titol);
    free(doc->contingut);
    LinkList_lliberar(&doc->links);
}