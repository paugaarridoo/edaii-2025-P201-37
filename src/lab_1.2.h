#pragma once
#include <stdio.h>
#include "lab_1.1.h" //Per a la LinkList i les seves funciones que usarem

// Estructura que representa un document
typedef struct {
    int id;             
    char* titol;
    char* contingut;
    LinkList links;
} Document;

// Inicialitza un document a partir d’un fitxer
int Document_init_from_file(Document* doc, const char* filepath);
// Allibera tota la memoria usada per un document
void Document_lliberar(Document* doc);

