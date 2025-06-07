#include "lab_1.4.h"
#include <stdio.h>

//Funció que impreimeix la llista dels documents, incloent titol i index 
void DocumentList_imprimir(const DocumentList* llista) {
    const DocumentNode* actual = llista->cap; //Iniciem amb el node cap(primer) de la llista
    int i = 0;
    //Si la llista es buida, mostra un missatge i retorna
    if (!actual) {
        printf("No hi ha cap document carregat.\n");
        return;
    }
    //Bucle per recorre tots els nodes de la llista 
    while (actual) {
        printf("(%d) %s\n", i, actual->doc.titol);
        actual = actual->seguent;
        i++;
    }
}

//Aquesta funció mostra el contingut del document pel seu index
void DocumentList_mostrar_per_index(const DocumentList* llista, int index) {
    const DocumentNode* actual = llista->cap;
    int i = 0;
    //Bucle per recorre tots els nodes de la llista per trobar el node que es vol trobar
    while (actual) {
        if (i == index) {
            printf("Títol: %s\n", actual->doc.titol);
            printf("Contingut:\n%s\n", actual->doc.contingut);
            printf("Enllaços:\n"); //Imprimeix els enallaços del docuimetn
            LinkList_imprimir(&actual->doc.links);
            return;
        }
        actual = actual->seguent;
        i++;
    }
    printf("No s'ha trobat cap document amb aquest índex.\n"); //Mostra error si no s'ha trobat res
}