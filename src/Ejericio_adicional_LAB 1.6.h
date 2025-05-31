#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "LAB_1_al_completo.h"

void test_document_parse_simple() { //Función de prueba para parsear un documento de prueba temporal
    
    FILE *f = fopen("test_doc.txt", "w");
    fprintf(f, "42\nTitulo de prueba\nCuerpo del documento [123) texto extra\n");
    fclose(f);
//Llamamos a la función de deserialización del documento
    Document *doc = document_desserialize("test_doc.txt");
    assert(doc != NULL);
    assert(doc->id == 42);
    assert(strcmp(doc->title, "Titulo de prueba") == 0);
    assert(strstr(doc->body, "Cuerpo del documento") != NULL);
    assert(doc->list_links != NULL);
    assert(doc->list_links->id == 123);

    //Hacer limpieza de la memoria
    document_free(doc);
    remove("test_doc.txt");
}

int main() { //Ejecutar la función.
    test_document_parse_simple();
    printf("Prueba de parseo de documento pasada.\n");
    return 0;
}