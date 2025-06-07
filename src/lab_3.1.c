#include "lab_3.1.h" //Per a la definció del Hasmap i les seves funcions pertinents
#include <stdlib.h>
#include <string.h>
#define HASHMAP_SIZE 200

//Funció hash senzilla que transforma la clau de text en un index numeric
unsigned int hash(const char* key) {
    unsigned int h = 6000; //valor inicial per a la funció hash
    int c;
    while ((c = *key++))
        h = ((h << 5) + h) + c;
    return h % HASHMAP_SIZE;
}
//Inicialitza el hashmap deixant totes les posicions buides
void HashMap_init(HashMap* map) {
    for (int i = 0; i < HASHMAP_SIZE; ++i)
        map->buckets[i] = NULL;
}
//Afegeix una taula clauvalor al hashmap
void HashMap_put(HashMap* map, const char* key, int value) {
    unsigned int idx = hash(key);
    HashNode* node = map->buckets[idx];
    while (node) { //Busca si la clua existeix
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    //Si mo existeix afegim nou node
    node = (HashNode*)malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;
    node->next = map->buckets[idx];
    map->buckets[idx] = node;
}
//Busca una clau al hashmap i retorna el seu valor si exisiteix, 1 existeix i 0 no
int HashMap_get(const HashMap* map, const char* key, int* value) {
    unsigned int idx = hash(key);
    HashNode* node = map->buckets[idx];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (value) *value = node->value;
            return 1;
        }
        node = node->next; //cONTINNUA BUSCANT EN CAS DE COLLISIONS
    }
    return 0;
}
//Funció per alliberar tota la memoria usada pel hashmap
void HashMap_lliberar(HashMap* map) {
    for (int i = 0; i < HASHMAP_SIZE; ++i) {
        HashNode* node = map->buckets[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
        map->buckets[i] = NULL;
    }
}