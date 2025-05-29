#include <stdio.h>
#include <stdlib.h>
#include "LAB 2 PUNTO 2.c"
#include "LAB 1 PUNTO 3.c"

typedef struct HashmapNode{
  struct HashmapNode *next;
  int key;
  Document *element;
} HashmapNode;

typedef struct {
  HashmapNode **buckets;
  int size;
  int count;
} Hashmap;

Hashmap *create_hashmap(int size){
  Hashmap *new_hashmap = (Hashmap*) malloc(sizeof(Hashmap));
  new_hashmap->buckets = (HashmapNode*) calloc(size, sizeof(HashmapNode));
  new_hashmap->size = size;
  new_hashmap->count = 0;
  return new_hashmap;
}

int hash_function(int id, int size){
   return id % size; 
}

void add_document(Document *document, Hashmap *hashmap){
  int idx = hash_function(document->id, hashmap->size);
  HashmapNode *new_node = (HashmapNode*) malloc(sizeof(HashmapNode));
  new_node->key = document->id;
  new_node->element = document;
  new_node->next = hashmap->buckets[idx];
  hashmap->buckets[idx] = new_node;
  hashmap->count++;
}

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
}

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
}