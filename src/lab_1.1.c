#include "lab_1.1.h"
#include <stdlib.h>
#include <string.h>
// Inicialitza la llista enllaçada amb el punter a NULL 
void LinkList_init(LinkList* llista) {
    llista->cap = NULL;
}
//Agrega un node al final de la llista amb l'URL donat
void LinkList_agregar(LinkList* llista, const char* url) {
    LinkNode* nou = (LinkNode*)malloc(sizeof(LinkNode)); //Reserva memoria per al nou node
    nou->url = strdup(url);
    nou->seguent = NULL;

    if (!llista->cap) { //Si la llista essta buida, el nou node es converteix en el cap
        llista->cap = nou;
    } else { //Si no recorre fins el nou node 
        LinkNode* actual = llista->cap;
        while (actual->seguent) {
            actual = actual->seguent;
        }
        actual->seguent = nou;
    }
}
//Imprimeix totes les URLs emmagatzemades a la llista
void LinkList_imprimir(const LinkList* llista) {
    LinkNode* actual = llista->cap;
    int i = 1;
    while (actual) { //Recorre la llista i impremeix cada URL
        printf("%d. %s\n", i, actual->url);
        actual = actual->seguent;
        i++;
    }
}
//Llibera tota la memoria utilitzada pels nodes i la llista
void LinkList_lliberar(LinkList* llista) {
    LinkNode* actual = llista->cap;
    while (actual) {
        LinkNode* temp = actual;
        actual = actual->seguent;
        free(temp->url);
        free(temp);
    }
    llista->cap= NULL; // Deixa la llista buida