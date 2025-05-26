#include <stdio.h>
#include <stdlib.h>
#include "LAB 2 PUNTO 2.c"
#include "LAB 1 PUNTO 3.c"

struct HashmapNode{
  struct HashmapNode *next;
  int key;
  Document *element;
};

typedef struct {
  struct HashmapNode* node;
  int size;
  int count;
} Hashmap;

Hashmap *create_hashmap(int size){
  Hashmap *new_hashmap = (Hashmap*) malloc(sizeof(Hashmap));
  new_hashmap->node = (struct HashmapNode*) calloc(size, sizeof(struct HashmapNode));
  new_hashmap->size = size;
  new_hashmap->count = 0;
  return new_hashmap;
}

int hash_function(int id, int size){
  int index = id % size;
  return index;
}

void add_document(Document *document, Hashmap *hashmap){
  if (hashmap->count = hashmap->size){
    printf("No se pudo introducir el documento, el hashmap está lleno!");
  }
  hashmap->node = (struct HashmapNode*) malloc(sizeof(struct HashmapNode));
  hashmap->node->next = NULL;
  hashmap->node->key = hash_function(document->id, hashmap->size);
  hashmap->node->element = document;
  hashmap->count++;
}