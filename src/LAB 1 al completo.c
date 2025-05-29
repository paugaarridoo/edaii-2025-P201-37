#include <stdio.h>   //Para operaciones de entrada y salida con archivos
#include <stdlib.h>  // Para funciones como malloc
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <dirent.h> //Para operaciones con directorios y archivos

//Punto 1 LAB 1, impementación de la lista enlazada de enlaces, creamos su estructura que representará los enlaces
typedef struct Link {
    int id;                  //ID/tipologia del enlace
    struct Link *prev;       //Link previo
    struct Link *next;       //Link posterior
} Link;

//Creamos la estructura que va a representar el link
typedef struct Document {
    int id;                  //ID/tipologia del documento
    Link *list_links;        //Puntero a la lista de enlaces
    char title[512];         //EL título del documento
    char *body;              //Contenido de este (del documento)
    struct Document *next;   //Para formar una lista de documentos
} Document;

//Creamos una función que inicializa nuevos enlaces posibles
Link *LinksInit() {
    Link *listed_links = (Link *)malloc(sizeof(Link)); //Guarda memoria para un nuevo enlace

    if (listed_links) {
        listed_links->id = -1;       //Inicializamos el id del enlace a -1
        listed_links->prev = NULL;   //Inicializamos el enlace previo a NULL
        listed_links->next = NULL;   //Inicializamos el enlace posterior a NULL
    }

    return listed_links; //Devolvemos el puntero al nuevo enlace inicializado
}

// Función para deserializar un documento desde un archivo o repositorio (wikipedia repositorio)
Document *document_desserialize(char *path) {
    FILE *f = fopen(path, "r"); //Abrimos el archivo en modo lectura

    if (f == NULL) {
        fprintf(stderr, "Error opening file: %s\n", path);
        return NULL; //Si el archivo no se ha abierto bien, devolvemos la función NULL
    }

    assert(f != NULL); //Aseguramos que el archivo se ha abierto correctamente

    Document *document = (Document *)malloc(sizeof(Document)); //Reservamos memoria para un nuevo documento
    assert(document != NULL); //Aseguramos almaecnamiento memoria

    char buffer[262144];              // Creamos un buffer para guardar los datos del documento
    int bufferSize = 262144;          //Máximo buffer tamaño
    assert(bufferSize > 0);           //mínimo tamaño buffer

    int bufferIdx = 0;
    char ch;

    //Parseo del ID del documento 
    while ((ch = fgetc(f)) != '\n') {
        assert(bufferIdx < bufferSize); //Verificamos que el índice del buffer no sobrepase el tamaño del buffer
        buffer[bufferIdx++] = ch;
    }

    assert(bufferIdx < bufferSize);
    buffer[bufferIdx++] = '\0';
    document->id = atoi(buffer); // Convertimos el buffer a un número entero y lo asignamos al ID del documento

    //Leer titulo del documento
    bufferIdx = 0;

    while ((ch = fgetc(f)) != '\n' && ch != EOF) {
        assert(bufferIdx < sizeof(document->title) - 1);
        document->title[bufferIdx++] = ch;
    }

    document->title[bufferIdx] = '\0';

    //Leer body y links del documento
    bufferIdx = 0;
    Link *links_head = NULL; //Primer enlace lista
    Link *link_tail = NULL; //último enlace 
    int linkBufferIdx = 0;
    char linkBuffer[768]; //Buffer para alamacenar el/los enlace/s
    int parsingLink = 0;

    while ((ch = fgetc(f)) != EOF) { //bucle para leer el documento
        buffer[bufferIdx++] = ch;

        if (parsingLink) {
            if (ch == ')') {
                linkBuffer[linkBufferIdx] = '\0';
                int linkId = atoi(linkBuffer); //Convertimos el buffer de enlace a un número entero

                Link *newLink = (Link *)malloc(sizeof(Link)); //Reservamos memoria para un nuevo enlace como hemos hecho en la linea 28
                if (newLink) {
                    newLink->id = linkId;
                    newLink->prev = NULL;
                    newLink->next = NULL;

                    if (!links_head) {
                        links_head = newLink; //Primero enlace de la lista
                    } else {
                        link_tail->next = newLink;
                        newLink->prev = link_tail;
                    }

                    link_tail = newLink; //Actualizamos el último enlace 
                }

                parsingLink = 0; //Salimos del modo de enlace
                linkBufferIdx = 0;
            } else if (ch != '(') {
                if (linkBufferIdx < sizeof(linkBuffer) - 1) {
                    linkBuffer[linkBufferIdx++] = ch; //Sigue guardando el contenido del enlace
                }
            }
        } else if (ch == ']') {
            parsingLink = 1;
        }
    }

    buffer[bufferIdx] = '\0';
    document->body = strdup(buffer);
    document->list_links = links_head; //Asociamos la lista de enlaces al documento
    document->next = NULL;

    fclose(f); //Cierra el archivo
    return document; //Retornamos el documento deserializado
}

void document_free(Document *doc) {
    if (!doc) return;

    free(doc->body);

    Link *l = doc->list_links;
    while (l) {
        Link *tmp = l;
        l = l->next;
        free(tmp); //Liberamos cada enlace de la lista
    }

    free(doc);
}

// Cargar todos los documentos de una carpeta
Document *load_documents_from_folder(const char *folder_path) {
    DIR *dir = opendir(folder_path); //Abrir el directoria/repositorio donde hemos almacenado los documentos
    if (!dir) return NULL; //Retornamos en caso que no se haya podido abrir este

    struct dirent *entry;
    Document *head = NULL; //Primero de la lista
    Document *tail = NULL; //Ultimo de la lista

    char path[1048];

    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.') {
            continue; //Ignoramos los archivos que son ocultos, que contienen un punto al principio
        }

        snprintf(path, sizeof(path), "%s/%s", folder_path, entry->d_name);
        Document *doc = document_desserialize(path); //Intenta cargar el documento

        if (doc) {
            if (!head) {
                head = doc; //Si este es el primer documento lo asignamos como cabeza
            } else {
                tail->next = doc;
            }
            tail = doc; //Actualizamos la cola con el ultimo/nuevo documento
        }
    }

    closedir(dir);
    return head;
}

void free_documents(Document *head) {
    while (head) {
        Document *tmp = head;
        head = head->next;
        document_free(tmp); //Finalmente liberamos la memoria de cada documento
    }
}