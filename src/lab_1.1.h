#pragma once
#include <stdio.h>

// Node de la llista enllaçada 
typedef struct LinkNode {
    char* url;
    struct LinkNode* seguent; //Punter al seguent node
} LinkNode;

//Llista enllaçada de enllaços
typedef struct {
    LinkNode* cap;
} LinkList;

//Declaracions de les funcions per a la llista enllaçada
void LinkList_init(LinkList* llista);
void LinkList_agregar(LinkList* llista, const char* url);
void LinkList_imprimir(const LinkList* llista);
void LinkList_lliberar(LinkList* llista);