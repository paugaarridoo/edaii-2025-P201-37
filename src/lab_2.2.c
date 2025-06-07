#include "lab_2.2.h" //Per a la definició de consulta i les seves funcions pertinents
#include <stdlib.h>
#include <string.h>
//Inicialitza una consulta inciant per una caden de text
int Consulta_init_from_text(Consulta* c, const char* text) {
    if (!c || !text) return 0; //Comprova que no siguin NULL
    c->consulta = strdup(text); //Duplica la cadena de text per guardar dins de la cnsulta
    return c->consulta != NULL; //Retorna 1 si s'ha duplicat i 0 si no.
}
//Alliebera tota la memoria usada per una consulta
void Consulta_lliberar(Consulta* c) {
    if (c && c->consulta) {
        free(c->consulta);
        c->consulta = NULL;
    }
}