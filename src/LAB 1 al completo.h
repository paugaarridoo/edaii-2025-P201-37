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