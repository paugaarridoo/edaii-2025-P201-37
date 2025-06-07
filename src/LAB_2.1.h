#pragma once

//defineix la estrcutura del node de la llista de consultes
typedef struct ConsultaNode {
    char* consulta;
    struct ConsultaNode* seguent;
} ConsultaNode;
//Estrcutra de la llista enllaçada de coonsultes 
typedef struct {
    ConsultaNode* cap;
} ConsultaList;

//Declaracions de les funcions per a la llista de consultes
void ConsultaList_init(ConsultaList* llista); //Inicialitza la llista de conusltes
void ConsultaList_agregar(ConsultaList* llista, const char* consulta); //Afegeic una consulta a la llista
void ConsultaList_imprimir(const ConsultaList* llista); //Imprimeix totes les consultes de la llista
void ConsultaList_lliberar(ConsultaList* llista); //Allibera tota la memoria de la llista