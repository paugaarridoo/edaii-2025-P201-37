#include "lab_2.3.h" //Per a la funció de busqueda lineal en els documents i les seves funcions pertinents
#include <stdio.h>
#include <string.h>

//Busqueda lineal que mostra documents que contenenla consulta o contingut 
int buscar_documents_lineal(Document** docs, int doc_count, const char* consulta) {
    int trobats = 0; //Comptador dels documetns trobats
    printf("Resultats per a la consulta: \"%s\"\n", consulta);
    for (int i = 0; i < doc_count; ++i) { //Recorre tots els documents un per un
        if (strstr(docs[i]->titol, consulta) || strstr(docs[i]->contingut, consulta)) { //Comprova si al titul/contingut de docuemnte apareix la consulta
            printf("(%d) %s\n", i, docs[i]->titol);
            trobats++;
        }
    }
    if (trobats == 0) { //si no s'ha trobat cap consulta informa
        printf("No s'ha trobat cap document amb aquesta consulta.\n");
    }
    return trobats; //retorna el nombre de documetns trobats
}