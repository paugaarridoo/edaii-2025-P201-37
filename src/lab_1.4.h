#pragma once
#include "lab_1.3.h" //Per usar la definició del DocumentList i les seves funcions
//Aquesta funció declarada imprimeox la llista de documents mostrant el titol de cada i el seu index 
void DocumentList_imprimir(const DocumentList* llista);
//Aquesta funció declarada ens enseña el contingut del document seleccionat pel seu index
void DocumentList_mostrar_per_index(const DocumentList* llista, int index);