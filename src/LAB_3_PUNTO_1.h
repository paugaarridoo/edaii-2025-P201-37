#include <stdio.h>
#include <stdlib.h>
#include "LAB_2.2.h"
#include "LAB_1_al_completo.h"



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

Hashmap *create_hashmap(int size){
  Hashmap *new_hashmap = (Hashmap*) malloc(sizeof(Hashmap));
  new_hashmap->buckets = (HashmapNode**) calloc(size, sizeof(HashmapNode*)); // <-- Corrección aquí
  new_hashmap->size = size;
  new_hashmap->count = 0;
  return new_hashmap;
} //Función para inicializar el Hashmap

int hash_function(int id, int size){
   return id % size; 
}                         //Función de hash para obtener el índice del bucket en el Hashmap

void add_document(Document *document, Hashmap *hashmap){           
  int idx = hash_function(document->id, hashmap->size);
  HashmapNode *new_node = (HashmapNode*) malloc(sizeof(HashmapNode));
  new_node->key = document->id;
  new_node->element = document;
  new_node->next = hashmap->buckets[idx];
  hashmap->buckets[idx] = new_node;
  hashmap->count++;
}   //Función para añadir un documento al Hashmap

Document *get_document(int id, Hashmap *hashmap) {
    int idx = hash_function(id, hashmap->size);
    HashmapNode *node = hashmap->buckets[idx];
    while (node) {
        if (node->key == id) {
            return node->element;
        }
        node = node->next;
    }
    return NULL; 
}                //Función para obten er un documento del Hashmap mediante su id

void free_hashmap(Hashmap *hashmap) {
    for (int i = 0; i < hashmap->size; ++i) {
        HashmapNode *node = hashmap->buckets[i];
        while (node) {
            HashmapNode *tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(hashmap->buckets);
    free(hashmap);
}                            //Función para liberar la memoria reservada para el Hashmap