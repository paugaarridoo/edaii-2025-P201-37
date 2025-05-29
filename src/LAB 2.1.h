typedef struct Query { //Creamos una estrcutura que representa nuestra consulta
    char *query;       //Texto
    struct Query *prev; //Puntero al nodo anterior
    struct Query *next;  //Puntero al nodo siguiente
} Query;