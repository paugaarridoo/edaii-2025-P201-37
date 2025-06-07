#include "lab_2.1.h" //Per a la definició de la llista de consultes i les seves funcions pertinents
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//Inicialitza la llista de consultes de manera buida
void ConsultaList_init(ConsultaList* llista) {
    llista->cap = NULL;
}
//Afegeix una consulta a la llista de consultes 
void ConsultaList_agregar(ConsultaList* llista, const char* consulta) {
    ConsultaNode* nou = (ConsultaNode*)malloc(sizeof(ConsultaNode)); //Reserva memoria per al ou node
    nou->consulta = strdup(consulta); //Duplica la cadena/text de consulta per guardar-lo al node
    nou->seguent = NULL; //Si el node no apunta al seguente, no te cap segeunt

    if (!llista->cap) { //Si la llista es buida, el nou node es el cap d'aquesta
        llista->cap = nou;
    } else {
        ConsultaNode* actual = llista->cap;
        while (actual->seguent) actual = actual->seguent;
        actual->seguent = nou;
    }
}
//Imprimeix totes les consultes de la llista y les numera
void ConsultaList_imprimir(const ConsultaList* llista) {
    const ConsultaNode* actual = llista->cap;
    int i = 1;
    while (actual) {
        printf("%d. %s\n", i, actual->consulta); //Imprimeix num i consulta
        actual = actual->seguent;
        i++;
    }
}
//Allibera tota la memoria usada per la llista de consultes i els nodes que la formen
void ConsultaList_lliberar(ConsultaList* llista) {
    ConsultaNode* actual = llista->cap;
    while (actual) {
        ConsultaNode* temp = actual;
        actual = actual->seguent;
        free(temp->consulta);
        free(temp);
    }
    llista->cap = NULL;
}