#include <ctype.h>
#include <string.h>
#include <windows.h>


//funcion que adapta palabras
void normalize_word(char* word) {
    int i, j = 0;
    char temp[strlen(word) + 1];

    for (i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            temp[j++] = tolower(word[i]);  //convierte las mayusculas a minusculas 
        }
    }

    temp[j] = '\0';
    strcpy(word, temp);  //cambia la palabra por la adaptada
}



