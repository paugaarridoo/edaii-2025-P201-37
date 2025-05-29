#include "LAB 1 al completo.h"


typedef struct HashmapNode{
  struct HashmapNode *next;
  int key;
  Document *element;
} HashmapNode;              //Estructura para un nodo de Hashmap

typedef struct {
  HashmapNode **buckets;
  int size;
  int count;
} Hashmap;                //Estructura para el Hashmap