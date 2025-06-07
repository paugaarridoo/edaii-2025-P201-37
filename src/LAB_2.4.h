#pragma once
#include <stddef.h>
//Declaració de l'estructura per a una consulta individual
typedef struct {
    char* consulta;
} Consulta;
//Declaració per a la cua de les ultimes tres consultes
typedef struct {
    Consulta consultes[3];
    int inici;   //índex primer element (inici) 
    int fi;      //índex on afegim el seguent 
    int mida;    //mIDA ACTUAL DE LA CUA
} ConsultaQueue;
//Inicialitza la cua 
void ConsultaQueue_init(ConsultaQueue* q);
//Afegeix una nova consulta a la cua  
void ConsultaQueue_push(ConsultaQueue* q, const char* consulta);
//Mostra les tres ultimes consultes
void ConsultaQueue_mostrar(const ConsultaQueue* q);
//Allibera la memoria usada per la cua 
void ConsultaQueue_lliberar(ConsultaQueue* q);