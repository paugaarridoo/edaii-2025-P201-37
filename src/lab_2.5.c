#include "lab_2.5.h" //Per a la definició de les funcions per a la valdiació de frases i paraules excloses
#include "lab_2.1.h" //Per a la definició de la llista de consultes i les seves funcions pertinents
#include <string.h>
#include <stdio.h>
//Funció que retorna 1 si la paraula està a la llista d'exclusió i 0 si no 
int paraula_exclosa(const char* paraula, char* excloses[], int n_excloses) {
    for (int i = 0; i < n_excloses; ++i) {
        if (strcmp(paraula, excloses[i]) == 0) return 1; //Compara paraula amb cadascuna de la llista d'exclusio
    }
    return 0; //frase no valida
}
//Funció que retorna 1 si la frase NO conté cap paraula exclosa, 0 si alguna paraula exclosa sorgeix 
int frase_valida(const char* frase, char* excloses[], int n_excloses) {
    char buffer[2000]; //Buffer per a copiar la frase i evitar modificar la frase original
    strncpy(buffer, frase, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    char* paraula = strtok(buffer, " \t\n\r");
    while (paraula) { //Bucle per a que recorri totes les paraules de la frase 
        if (paraula_exclosa(paraula, excloses, n_excloses)) return 0;
        paraula = strtok(NULL, " \t\n\r");
    }
    return 1; //frase valida
}