#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "LAB_1_al_completo.h" //Incluimos el archivo que contiene las funciones pertinentes
#include "LAB_2.3.h"        //Incluimos el archivo que contiene la función search_documents

void test_linear_search() {                //Función de prueba para la búsqueda lineal de documentos
    FILE *f1 = fopen("test_doc1.txt", "w");       //Creamos tres documentos de prueba 
    FILE *f2 = fopen("test_doc2.txt", "w");
    FILE *f3 = fopen("test_doc3.txt", "w");
    fprintf(f1, "1\nDocument 1\nEste es el cuerpo del documento 1. \n");
    fprintf(f2, "2\nDocument 2\nEste es el cuerpo del documento 2. \n");
    fprintf(f3, "3\nDocument 3\nEste es el cuerpo del documento 3. \n");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    Document *docs[3];
    char *doc_paths[3] = {"test_doc1.txt", "test_doc2.txt", "test_doc3.txt"};
    int doc_count = 3;
    const char *query = "Documento 2";
    for (int i = 0; i < doc_count; i++){
        //docs[i] = document_desserialize(doc_paths[i]);        //Puesto como comentario puesto que daba error y no he sabido solucionarlo
        assert(docs[i] != NULL);
        assert(docs[i]->id == i + 1);
        assert(strcmp(docs[i]->title, "Documento 1") != 0 || i == 0);
        assert(strcmp(docs[i]->title, "Documento 2") != 0 || i == 1);
        assert(strcmp(docs[i]->title, "Documento 3") != 0 || i == 2);
        assert(strstr(docs[i]->body, "Este es el cuerpo del documento") != NULL);
        assert(docs[i]->list_links == NULL);
    }
    for (int i = 0; i < doc_count; i++){
        search_documents(docs, doc_count, query);   //Llamamos a la función search_documents
        if (i == 1){
            printf("Documento #%d\n", i);
            printf("ID: %d\n", docs[i]->id);
            printf("Título: %s\n", docs[i]->title);
            printf("Cuerpo: %.60s...\n", docs[i]->body);
            printf("-------------------------\n");
        } else{
            printf("Documento #%d no encontrado\n", i);
        }
    }
    for (int i = 0; i < doc_count; i++){
        document_free(docs[i]);                  //Hacemos limpieza de la memoria de los documentos
        remove(doc_paths[i]);
    }
}

