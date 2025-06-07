#pragma once
#include "lab_1.2.h" //Perque utilitzarem l'estrcutura Document i les seves funcions definides anteriorment

//Estrcutura per a un node de la llista enllaçada de document
typedef struct DocumentNode {
    Document doc; //El document es guarda dins d'aqeust node
    struct DocumentNode* seguent;
} DocumentNode;

//estrcutura per a la lLISTA enllaçada de document
typedef struct {
    DocumentNode* cap;
} DocumentList;

//Instruccions de les funcions que utilitzarem per gestionar la llista de document
int DocumentList_agregar(DocumentList* llista, const char* filepath); //afegigeix un document a la llista  apartir del fitxer
void DocumentList_init(DocumentList* llista); //Inicialitza la llista buida
void DocumentList_lliberar(DocumentList* llista); //aLLIBERA TOTA LA MEMORIA USADA PER LA LLISTA
int DocumentList_carregar_des_de_carpeta(DocumentList* llista, const char* folderpath);
//L'ultima funció carrega tots els document d'una carpeta 