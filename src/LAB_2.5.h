#pragma once
//Comprova si una paraula esta a la llista d'exclsió 
int paraula_exclosa(const char* paraula, char* excloses[], int n_excloses);
//Aqesta fució retornará 1 si cap paraula exclosa apareix a la frase i 0 si alguna apareix
int frase_valida(const char* frase, char* excloses[], int n_excloses);