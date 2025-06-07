#pragma once
#define HASHMAP_SIZE 200
//Definim la estrcutura de un node que usara el hashmap
typedef struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
} HashNode;
//Defineix l'estructura del hashmap
typedef struct {
    HashNode* buckets[HASHMAP_SIZE];
} HashMap;
//Inicialitza el hashmap
void HashMap_init(HashMap* map);
//Actuotza o inserei una clau valor
void HashMap_put(HashMap* map, const char* key, int value);
//Busca clau i retorna el seu valor, 1 existeix i 0 no 
int HashMap_get(const HashMap* map, const char* key, int* value);
//Allibera tota la memòria usada pel hashmap
void HashMap_lliberar(HashMap* map);
//Funció hash per a claus de text
unsigned int hash(const char* key);