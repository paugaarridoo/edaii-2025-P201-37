#include <windows.h>

#include "LAB_1_al_completo.c"
#include "LAB_2.1.c"
#include "LAB_2.2.c"
#include "LAB_2.3.c"
#include "LAB_2.4.c"
#include "LAB_2.5.c"
#include "LAB_3_PUNTO_1.c"
#include "LAB_3_PUNTO_2.c"
#include "LAB_3_PUNTO_3.c"
#include "LAB_3_PUNTO_4.c"
#include "LAB_4_PUNTO_1.c"
#include "LAB_4_PUNTO_1.h"
#include "LAB_4_PUNTO_2.c"
#include "punto 3_LAB_4.c"
#include "sample_lib.h"
#include "sample_lib.c"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define MAX_PATH_LEN 256

void createaleak() {
  char *foo = malloc(20 * sizeof(char));
  printf("Allocated leaking string: %s", foo);
}

int main() {
  printf("*****************\nWelcome to EDA 2!\n*****************\n");

  printf("Introduce el nombre de la carpeta de documentos: ");
    char folder[MAX_PATH_LEN];
    scanf("%255s", folder);

    
    int max_docs = 5400; // Valor máximo posible
    char *doc_paths[max_docs];
    for (int i = 0; i < max_docs; ++i) {
        doc_paths[i] = malloc(MAX_PATH_LEN);
    }

    int doc_count = load_doc_paths(folder, doc_paths, max_docs);  // Ajusta el máximo según la carpeta

    Document *docs[max_docs];
    for (int i = 0; i < doc_count; ++i) {
        docs[i] = document_desserialize(doc_paths[i]);
    }

  QueryQueue recent_queries;
  queue_init(&recent_queries);
  while(1) {
    char query[100];
    char exclude[100];
    printf("Introdueix query ('exit' per sortir):");
    scanf("%99s", &query);
    if (strcmp(query, "exit") == 0){
      break;
    }
    printf("Palabra a excluir (ENTER para ninguna):");  //Excluim una paraula de la query
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}  //Netejem el buffer d'entrada
    fgets(exclude, 100, stdin);
    exclude[strcspn(exclude, "\n")] = 0;      //Eliminem el salt de línia al final de la cadena
    Query *q = Query_init_from_string(query);
    queue_push(&recent_queries, q);
    queue_print(&recent_queries);
    if (strlen(exclude) > 0) {
      search_documents_exclude(docs, doc_count, query, exclude);
    }
    search_documents_exclude(docs, doc_count, query, NULL);
  }
  return 0;
}
