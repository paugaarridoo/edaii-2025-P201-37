#include "LAB_1_al_completo.h"
#include <windows.h>



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