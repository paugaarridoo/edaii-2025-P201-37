typedef struct WordNode{
  char *word;
  int *document_ids;
  int doc_count;
  int doc_capacity;
  struct WordNode *next;
} WordNode;               //Estructura para un nodo de la lista enlazada que almacena palabras y IDs de documentos

typedef struct{
  WordNode **buckets;
  int size;
} ReverseIndexHashmap;        //Estructura para el índice inverso