#pragma once
//Declaració de l'estructura per a la consulta individual
typedef struct {
    char* consulta;
} Consulta;
//Declaració de la inicialització de una consulta a partir de la cadena de text
int Consulta_init_from_text(Consulta* c, const char* text);
//Funció que allibera la memòria d'una consulta 
void Consulta_lliberar(Consulta* c);